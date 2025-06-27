/*
  © 2022 Microchip Technology Inc. and its subsidiaries

  Subject to your compliance with these terms, you may use Microchip software
  and any derivatives exclusively with Microchip products. You're responsible
  for complying with 3rd party license terms applicable to your use of 3rd party
  software (including open source software) that may accompany Microchip software.
  SOFTWARE IS "AS IS." NO WARRANTIES, WHETHER EXPRESS, IMPLIED OR STATUTORY,
  APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED WARRANTIES OF NON-INFRINGEMENT,
  MERCHANTABILITY, OR FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT WILL MICROCHIP
  BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, INCIDENTAL OR CONSEQUENTIAL LOSS,
  DAMAGE, COST OR EXPENSE OF ANY KIND WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER
  CAUSED, EVEN IF MICROCHIP HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE
  FORESEEABLE. TO THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP?S TOTAL LIABILITY
  ON ALL CLAIMS RELATED TO THE SOFTWARE WILL NOT EXCEED AMOUNT OF FEES, IF ANY,
  YOU PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
*/

#include "PAC193x.h"

int16_t PAC193x_GetDeviceIDProcess(PAC193X_PDEVICE_CONTEXT pdevice);
int16_t PAC193x_GetCtrl_regProcess(PAC193X_PDEVICE_CONTEXT pdevice);
int16_t PAC193x_GetAccumulatorCountProcess(PAC193X_PDEVICE_CONTEXT pdevice);
int16_t PAC193x_GetVACCn_regProcess(PAC193X_PDEVICE_CONTEXT pdevice);
int16_t PAC193x_GetVACCn_mWProcess(PAC193X_PDEVICE_CONTEXT pdevice);
int16_t PAC193x_GetEnergy_mWhProcess(PAC193X_PDEVICE_CONTEXT pdevice);
int16_t PAC193x_GetTimedEnergy_mWhProcess(PAC193X_PDEVICE_CONTEXT pdevice);
int16_t PAC193x_GetVBUSn_regProcess(PAC193X_PDEVICE_CONTEXT pdevice);
int16_t PAC193x_GetVBUSn_mVProcess(PAC193X_PDEVICE_CONTEXT pdevice);
int16_t PAC193x_GetVSENSEn_regProcess(PAC193X_PDEVICE_CONTEXT pdevice);
int16_t PAC193x_GetVSENSEn_mVProcess(PAC193X_PDEVICE_CONTEXT pdevice);
int16_t PAC193x_GetISENSEn_mAProcess(PAC193X_PDEVICE_CONTEXT pdevice);
int16_t PAC193x_GetVBUSn_AVG_regProcess(PAC193X_PDEVICE_CONTEXT pdevice);
int16_t PAC193x_GetVBUSn_AVG_mVProcess(PAC193X_PDEVICE_CONTEXT pdevice);
int16_t PAC193x_GetVSENSEn_AVG_regProcess(PAC193X_PDEVICE_CONTEXT pdevice);
int16_t PAC193x_GetVSENSEn_AVG_mVProcess(PAC193X_PDEVICE_CONTEXT pdevice);
int16_t PAC193x_GetISENSEn_AVG_mAProcess(PAC193X_PDEVICE_CONTEXT pdevice);
int16_t PAC193x_GetVPOWERn_regProcess(PAC193X_PDEVICE_CONTEXT pdevice);
int16_t PAC193x_GetVPOWERn_mWProcess(PAC193X_PDEVICE_CONTEXT pdevice);
int16_t PAC193x_GetChannelDisSMBus_regProcess(PAC193X_PDEVICE_CONTEXT pdevice);
int16_t PAC193x_SetChannelDisSMBus_regProcess(PAC193X_PDEVICE_CONTEXT pdevice);
int16_t PAC193x_GetNegPwr_regProcess(PAC193X_PDEVICE_CONTEXT pdevice);
int16_t PAC193x_GetSlow_regProcess(PAC193X_PDEVICE_CONTEXT pdevice);


int16_t PAC193x_UpdateContext_ChannelPolarity(PAC193X_PDEVICE_CONTEXT pdevice);
int16_t PAC193x_UpdateContext_ChannelPolarityProcess(PAC193X_PDEVICE_CONTEXT pdevice);

int16_t PAC193x_UpdateContext_Ctrl(PAC193X_PDEVICE_CONTEXT pdevice);
int16_t PAC193x_UpdateContext_CtrlProcess(PAC193X_PDEVICE_CONTEXT pdevice);

void PAC193x_I2CEventHandler(PAC193X_I2C_TRANSFER_EVENT event, PAC193X_I2C_TRANSFER_HANDLE transferHandle, uintptr_t context);

///////////////////////////////////////////////////////////////////////////////
/*
 * Target platform adaptation functions 
 */

/* MUTEX support functions */

static inline bool PAC193x_MUTEX_Create(PAC193X_MUTEX *pmutex){
    if( OSAL_MUTEX_Create(pmutex) != OSAL_RESULT_TRUE )
        return false;
    else
        return true;
}

static inline bool PAC193x_MUTEX_Lock(PAC193X_MUTEX *pmutex){
    if( OSAL_MUTEX_Lock(pmutex, OSAL_WAIT_FOREVER) == OSAL_RESULT_FALSE )
        return false;
    else
        return true;
}

static inline void PAC193x_MUTEX_Unlock(PAC193X_MUTEX *pmutex){
    OSAL_MUTEX_Unlock(pmutex);
}

static inline PAC193X_I2C_TRANSFER_EVENT PAC193x_I2C_TransferStatusGet(
    const PAC193X_I2C_TRANSFER_HANDLE transferHandle
){
    return DRV_I2C_TransferStatusGet(transferHandle);
}

static inline void PAC193x_I2C_WriteReadTransferAdd (
    const PAC193X_PDEVICE_CONTEXT pdevice,
    void* const writeBuffer,
    const size_t writeSize,
    void* const readBuffer,
    const size_t readSize,
    PAC193X_I2C_TRANSFER_HANDLE* const transferHandle
){
    DRV_I2C_WriteReadTransferAdd(pdevice->i2cHandle, pdevice->i2cAddress, writeBuffer, writeSize, readBuffer, readSize, transferHandle);

#if defined(I2C_EVENT_CALLBACK_UNSUPPORTED)
    PAC193X_I2C_TRANSFER_EVENT event;
    event = PAC193X_I2C_TRANSFER_EVENT_PENDING;
    do{
        event = PAC193x_I2C_TransferStatusGet(*transferHandle);
    }while(event == PAC193X_I2C_TRANSFER_EVENT_PENDING);
    
    PAC193x_I2CEventHandler(event, *transferHandle, (uintptr_t)pdevice);
#endif
};

static inline void PAC193x_I2C_WriteTransferAdd(
    const PAC193X_PDEVICE_CONTEXT pdevice,
    void* const buffer,
    const size_t size,
    PAC193X_I2C_TRANSFER_HANDLE* const transferHandle
){
    DRV_I2C_WriteTransferAdd(pdevice->i2cHandle, pdevice->i2cAddress, buffer, size, transferHandle);

#if defined(I2C_EVENT_CALLBACK_UNSUPPORTED)
    PAC193X_I2C_TRANSFER_EVENT event;
    event = PAC193X_I2C_TRANSFER_EVENT_PENDING;
    do{
        event = PAC193x_I2C_TransferStatusGet(*transferHandle);
    }while(event == PAC193X_I2C_TRANSFER_EVENT_PENDING);
    
    PAC193x_I2CEventHandler(event, *transferHandle, (uintptr_t)pdevice);
#endif    
}

static inline void PAC193x_I2C_TransferEventHandlerSet(
    const PAC193X_I2C_HANDLE handle,
    const PAC193X_P_I2C_TRANSFER_EVENT_HANDLER eventHandler,
    const uintptr_t context
){
#if defined(I2C_EVENT_CALLBACK_SUPPORTED)
    DRV_I2C_TransferEventHandlerSet(handle, (DRV_I2C_TRANSFER_EVENT_HANDLER)eventHandler, context);
#else
    return;
#endif
}

static inline bool PAC193x_I2C_TransferSetup( const PAC193X_I2C_HANDLE handle, PAC193X_I2C_TRANSFER_SETUP *setup ){
    return DRV_I2C_TransferSetup(handle, setup);
}

static inline PAC193X_I2C_HANDLE PAC193x_I2C_Open(
    const SYS_MODULE_INDEX drvIndex,
    const DRV_IO_INTENT ioIntent
){
    return DRV_I2C_Open(drvIndex, ioIntent);
}

////////////////////////////////////////////////////////////////////////////////

/*
 * Library functions, target platform independent 
 */

void PAC193x_Timeout(uintptr_t deviceContext){

    // lock the mutexProcState mutex
    if( PAC193x_MUTEX_Lock(&(((PAC193X_PDEVICE_CONTEXT)deviceContext)->mutexProcState)) == false )
    {
        // abort, the processing state is already being changed elsewhere
        return;
    }
    
    // Check if the processing state has been already changed to "Idle" or "Sync"
    // (by PAC193x_I2CEventHandler or PAC193x_I2CEventHandlerError)
    if( (((PAC193X_PDEVICE_CONTEXT)deviceContext)->processingState == Idle) || 
        (((PAC193X_PDEVICE_CONTEXT)deviceContext)->processingState == Sync)  ){
        
        PAC193x_MUTEX_Unlock(&(((PAC193X_PDEVICE_CONTEXT)deviceContext)->mutexProcState));
        return;
    }
    
    //drop any remaining i2c transfers from the current lib request
    ((PAC193X_PDEVICE_CONTEXT)deviceContext)->transferHandle         = PAC193X_I2C_TRANSFER_HANDLE_INVALID;
    ((PAC193X_PDEVICE_CONTEXT)deviceContext)->transferHandle_negPwr  = PAC193X_I2C_TRANSFER_HANDLE_INVALID;
    ((PAC193X_PDEVICE_CONTEXT)deviceContext)->transferHandle_ctrl    = PAC193X_I2C_TRANSFER_HANDLE_INVALID;       
    
    // advance the state machine to "Idle" or "Sync"
    if ( ((PAC193X_PDEVICE_CONTEXT)deviceContext)->syncMode == true){
        ((PAC193X_PDEVICE_CONTEXT)deviceContext)->processingState = Sync;
    }else
    {    
        ((PAC193X_PDEVICE_CONTEXT)deviceContext)->processingState = Idle;
    }
   
    //call the user call-back if there is one registered
    if(((PAC193X_PDEVICE_CONTEXT)deviceContext)->userCallback != NULL){
        PAC193X_EVENT_HANDLER userCallback;
        PAC193X_EVENT event;
        uintptr_t userContext; 
        
        userCallback = ((PAC193X_PDEVICE_CONTEXT)deviceContext)->userCallback;
        ((PAC193X_PDEVICE_CONTEXT)deviceContext)->deviceEventStatus = PAC193X_EVENT_TIMEOUT;
        event = ((PAC193X_PDEVICE_CONTEXT)deviceContext)->deviceEventStatus;
        userContext = ((PAC193X_PDEVICE_CONTEXT)deviceContext)->userContext;
        userCallback(event, userContext);
    }
    
    //unlock the mutexProcState mutex
    PAC193x_MUTEX_Unlock(&(((PAC193X_PDEVICE_CONTEXT)deviceContext)->mutexProcState));
}


/* !!!  PAC193x_I2CEventHandlerError must not be called outside of PAC193x_I2CEventHandler() !!! */
void PAC193x_I2CEventHandlerError( uintptr_t context){

    // lock the mutexProcState mutex
    if( PAC193x_MUTEX_Lock(&(((PAC193X_PDEVICE_CONTEXT)context)->mutexProcState)) == false )
    {
        // abort, the processing state is already being changed elsewhere
        return;
    }
    
    // Check if the processing state has been already changed to "Idle" or "Sync"
    // (by PAC193x_Timeout)
    if( (((PAC193X_PDEVICE_CONTEXT)context)->processingState == Idle) || 
        (((PAC193X_PDEVICE_CONTEXT)context)->processingState == Sync)  ){
        
        PAC193x_MUTEX_Unlock(&(((PAC193X_PDEVICE_CONTEXT)context)->mutexProcState));
        return;
    }
    
    //drop any remaining i2c transfers from the current lib request
    ((PAC193X_PDEVICE_CONTEXT)context)->transferHandle         = PAC193X_I2C_TRANSFER_HANDLE_INVALID;
    ((PAC193X_PDEVICE_CONTEXT)context)->transferHandle_negPwr  = PAC193X_I2C_TRANSFER_HANDLE_INVALID;
    ((PAC193X_PDEVICE_CONTEXT)context)->transferHandle_ctrl    = PAC193X_I2C_TRANSFER_HANDLE_INVALID;       
    
    // advance the state machine to "Idle" 
    if ( ((PAC193X_PDEVICE_CONTEXT)context)->syncMode == true){
        ((PAC193X_PDEVICE_CONTEXT)context)->processingState = Sync;
    }else
    {    
        ((PAC193X_PDEVICE_CONTEXT)context)->processingState = Idle;
    }
   
    //call the user call-back if there is one registered
    if(((PAC193X_PDEVICE_CONTEXT)context)->userCallback != NULL){
        PAC193X_EVENT_HANDLER userCallback;
        PAC193X_EVENT event;
        uintptr_t userContext; 
        
        userCallback = ((PAC193X_PDEVICE_CONTEXT)context)->userCallback;
        event = ((PAC193X_PDEVICE_CONTEXT)context)->deviceEventStatus;
        userContext = ((PAC193X_PDEVICE_CONTEXT)context)->userContext;
        userCallback(event, userContext);
    }
    
    //unlock the mutexProcState mutex
    PAC193x_MUTEX_Unlock(&(((PAC193X_PDEVICE_CONTEXT)context)->mutexProcState));
}


void PAC193x_I2CEventHandler(PAC193X_I2C_TRANSFER_EVENT event, PAC193X_I2C_TRANSFER_HANDLE transferHandle, uintptr_t context)
{
    int16_t ret = PAC193X_SUCCESS;
    
    if(context == 0){ 
        return;
    }
    
    if( (((PAC193X_PDEVICE_CONTEXT)context)->transferHandle == PAC193X_I2C_TRANSFER_HANDLE_INVALID) &&
        (((PAC193X_PDEVICE_CONTEXT)context)->transferHandle_negPwr == PAC193X_I2C_TRANSFER_HANDLE_INVALID) &&
        (((PAC193X_PDEVICE_CONTEXT)context)->transferHandle_ctrl == PAC193X_I2C_TRANSFER_HANDLE_INVALID) ) 
    {
        return; // ignore the remaining i2c transfers (if any) for the invalidated requests due to previous errors
    }
    
    // handles the I2C events:        
    switch(event)
    {
        case PAC193X_I2C_TRANSFER_EVENT_PENDING:
            return;
        
        case PAC193X_I2C_TRANSFER_EVENT_COMPLETE:
        /* I2C Transfer Complete. */
        ((PAC193X_PDEVICE_CONTEXT)context)->deviceEventStatus = PAC193X_EVENT_REQUEST_COMPLETE;
        
            switch((((PAC193X_PDEVICE_CONTEXT)context)->processingState))
            {
                case RefreshReq:
                case RefreshGReq:
                case RefreshVReq:
                    break;
                case GetDeviceIDReq:
                    PAC193x_GetDeviceIDProcess((PAC193X_PDEVICE_CONTEXT)context);
                    break;
                case GetCtrlRegisterReq:
                    PAC193x_GetCtrl_regProcess((PAC193X_PDEVICE_CONTEXT)context);
                    break;
                case SetCtrlRegisterReq:
                    break;
                case GetAccCountReq:
                    PAC193x_GetAccumulatorCountProcess((PAC193X_PDEVICE_CONTEXT)context);
                    break;
                case GetVACCnRegisterReq:
                    PAC193x_GetVACCn_regProcess((PAC193X_PDEVICE_CONTEXT)context);
                    break;                    
                case GetVACCnValueReq:
                    if(transferHandle == ((PAC193X_PDEVICE_CONTEXT)context)->transferHandle_negPwr){
                        ret = PAC193x_UpdateContext_ChannelPolarityProcess((PAC193X_PDEVICE_CONTEXT)context);
                        if(ret == PAC193X_SUCCESS) {
                            ((PAC193X_PDEVICE_CONTEXT)context)->deviceEventStatus = PAC193X_EVENT_REQUEST_PENDING;
                        }else{
                            ((PAC193X_PDEVICE_CONTEXT)context)->deviceEventStatus = PAC193X_EVENT_REQUEST_ERROR;
                            PAC193x_I2CEventHandlerError(context);
                        }
                        return;
                    }                    
                    if(transferHandle == ((PAC193X_PDEVICE_CONTEXT)context)->transferHandle){
                        ret = PAC193x_GetVACCn_mWProcess((PAC193X_PDEVICE_CONTEXT)context);
                        if (ret != PAC193X_SUCCESS){
                            ((PAC193X_PDEVICE_CONTEXT)context)->deviceEventStatus = PAC193X_EVENT_REQUEST_ERROR;
                            PAC193x_I2CEventHandlerError(context);                        
                        }
                    }
                    break;
                case GetEnergyReq:
                    if(transferHandle == ((PAC193X_PDEVICE_CONTEXT)context)->transferHandle_ctrl){
                        PAC193x_UpdateContext_CtrlProcess((PAC193X_PDEVICE_CONTEXT)context);
                        return;
                    }
                    if(transferHandle == ((PAC193X_PDEVICE_CONTEXT)context)->transferHandle_negPwr){
                        ret = PAC193x_UpdateContext_ChannelPolarityProcess((PAC193X_PDEVICE_CONTEXT)context);
                        if(ret == PAC193X_SUCCESS) {
                            ((PAC193X_PDEVICE_CONTEXT)context)->deviceEventStatus = PAC193X_EVENT_REQUEST_PENDING;
                        }else{
                            ((PAC193X_PDEVICE_CONTEXT)context)->deviceEventStatus = PAC193X_EVENT_REQUEST_ERROR;
                            PAC193x_I2CEventHandlerError(context);
                        }                        
                        return;
                    }
                    if(transferHandle == ((PAC193X_PDEVICE_CONTEXT)context)->transferHandle){
                        ret = PAC193x_GetEnergy_mWhProcess((PAC193X_PDEVICE_CONTEXT)context);
                        if (ret != PAC193X_SUCCESS){
                            ((PAC193X_PDEVICE_CONTEXT)context)->deviceEventStatus = PAC193X_EVENT_REQUEST_ERROR;
                            PAC193x_I2CEventHandlerError(context);                        
                        }                        
                    }
                    break;
                case GetTimedEnergyReq:
                    if(transferHandle == ((PAC193X_PDEVICE_CONTEXT)context)->transferHandle_ctrl){
                        PAC193x_UpdateContext_CtrlProcess((PAC193X_PDEVICE_CONTEXT)context);
                        return;
                    }
                    if(transferHandle == ((PAC193X_PDEVICE_CONTEXT)context)->transferHandle_negPwr) {
                        ret = PAC193x_UpdateContext_ChannelPolarityProcess((PAC193X_PDEVICE_CONTEXT)context);
                        if(ret == PAC193X_SUCCESS) {
                            ((PAC193X_PDEVICE_CONTEXT)context)->deviceEventStatus = PAC193X_EVENT_REQUEST_PENDING;
                        }else{
                            ((PAC193X_PDEVICE_CONTEXT)context)->deviceEventStatus = PAC193X_EVENT_REQUEST_ERROR;
                            PAC193x_I2CEventHandlerError(context);
                        }                        
                        return;
                    }  
                    if(transferHandle == ((PAC193X_PDEVICE_CONTEXT)context)->transferHandle){
                        ret = PAC193x_GetTimedEnergy_mWhProcess((PAC193X_PDEVICE_CONTEXT)context);
                        if (ret != PAC193X_SUCCESS){
                            ((PAC193X_PDEVICE_CONTEXT)context)->deviceEventStatus = PAC193X_EVENT_REQUEST_ERROR;
                            PAC193x_I2CEventHandlerError(context);                        
                        }                        
                    }
                    break;
                case GetVBUSnRegisterReq:
                    PAC193x_GetVBUSn_regProcess((PAC193X_PDEVICE_CONTEXT)context);
                    break;
                case GetVBUSnValueReq:
                    if(transferHandle == ((PAC193X_PDEVICE_CONTEXT)context)->transferHandle_negPwr){
                        ret = PAC193x_UpdateContext_ChannelPolarityProcess((PAC193X_PDEVICE_CONTEXT)context);
                        if(ret == PAC193X_SUCCESS) {
                            ((PAC193X_PDEVICE_CONTEXT)context)->deviceEventStatus = PAC193X_EVENT_REQUEST_PENDING;
                        }else{
                            ((PAC193X_PDEVICE_CONTEXT)context)->deviceEventStatus = PAC193X_EVENT_REQUEST_ERROR;
                            PAC193x_I2CEventHandlerError(context);
                        }
                        return;
                    }
                    if(transferHandle == ((PAC193X_PDEVICE_CONTEXT)context)->transferHandle){
                        ret = PAC193x_GetVBUSn_mVProcess((PAC193X_PDEVICE_CONTEXT)context);
                        if (ret != PAC193X_SUCCESS){
                            ((PAC193X_PDEVICE_CONTEXT)context)->deviceEventStatus = PAC193X_EVENT_REQUEST_ERROR;
                            PAC193x_I2CEventHandlerError(context);                        
                        }                        
                    }
                    break;
                case GetVSENSEnRegisterReq:
                    PAC193x_GetVSENSEn_regProcess((PAC193X_PDEVICE_CONTEXT)context);
                    break;
                case GetVSENSEnValueReq:
                    if(transferHandle == ((PAC193X_PDEVICE_CONTEXT)context)->transferHandle_negPwr){
                        ret = PAC193x_UpdateContext_ChannelPolarityProcess((PAC193X_PDEVICE_CONTEXT)context);
                        if(ret == PAC193X_SUCCESS) {
                            ((PAC193X_PDEVICE_CONTEXT)context)->deviceEventStatus = PAC193X_EVENT_REQUEST_PENDING;
                        }else{
                            ((PAC193X_PDEVICE_CONTEXT)context)->deviceEventStatus = PAC193X_EVENT_REQUEST_ERROR;
                            PAC193x_I2CEventHandlerError(context);
                        }
                        return;
                    }
                    if(transferHandle == ((PAC193X_PDEVICE_CONTEXT)context)->transferHandle){
                        ret = PAC193x_GetVSENSEn_mVProcess((PAC193X_PDEVICE_CONTEXT)context);
                        if (ret != PAC193X_SUCCESS){
                            ((PAC193X_PDEVICE_CONTEXT)context)->deviceEventStatus = PAC193X_EVENT_REQUEST_ERROR;
                            PAC193x_I2CEventHandlerError(context);                        
                        }                        
                    }
                    break;
                case GetISENSEnValueReq:
                    if(transferHandle == ((PAC193X_PDEVICE_CONTEXT)context)->transferHandle_negPwr){
                        ret = PAC193x_UpdateContext_ChannelPolarityProcess((PAC193X_PDEVICE_CONTEXT)context);
                        if(ret == PAC193X_SUCCESS) {
                            ((PAC193X_PDEVICE_CONTEXT)context)->deviceEventStatus = PAC193X_EVENT_REQUEST_PENDING;
                        }else{
                            ((PAC193X_PDEVICE_CONTEXT)context)->deviceEventStatus = PAC193X_EVENT_REQUEST_ERROR;
                            PAC193x_I2CEventHandlerError(context);
                        }
                        return;
                    }
                    if(transferHandle == ((PAC193X_PDEVICE_CONTEXT)context)->transferHandle){
                        ret = PAC193x_GetISENSEn_mAProcess((PAC193X_PDEVICE_CONTEXT)context);
                        if (ret != PAC193X_SUCCESS){
                            ((PAC193X_PDEVICE_CONTEXT)context)->deviceEventStatus = PAC193X_EVENT_REQUEST_ERROR;
                            PAC193x_I2CEventHandlerError(context);                        
                        }                        
                    }
                    break;
                case GetVBUSnAVGRegisterReq:
                    PAC193x_GetVBUSn_AVG_regProcess((PAC193X_PDEVICE_CONTEXT)context);
                    break;
                case GetVBUSnAVGValueReq:
                    if(transferHandle == ((PAC193X_PDEVICE_CONTEXT)context)->transferHandle_negPwr){
                        ret = PAC193x_UpdateContext_ChannelPolarityProcess((PAC193X_PDEVICE_CONTEXT)context);
                        if(ret == PAC193X_SUCCESS) {
                            ((PAC193X_PDEVICE_CONTEXT)context)->deviceEventStatus = PAC193X_EVENT_REQUEST_PENDING;
                        }else{
                            ((PAC193X_PDEVICE_CONTEXT)context)->deviceEventStatus = PAC193X_EVENT_REQUEST_ERROR;
                            PAC193x_I2CEventHandlerError(context);
                        }
                        return;
                    }
                    if(transferHandle == ((PAC193X_PDEVICE_CONTEXT)context)->transferHandle){
                        ret = PAC193x_GetVBUSn_AVG_mVProcess((PAC193X_PDEVICE_CONTEXT)context);
                        if (ret != PAC193X_SUCCESS){
                            ((PAC193X_PDEVICE_CONTEXT)context)->deviceEventStatus = PAC193X_EVENT_REQUEST_ERROR;
                            PAC193x_I2CEventHandlerError(context);                        
                        }                        
                    }
                    break;
                case GetVSENSEnAVGRegisterReq:
                    PAC193x_GetVSENSEn_AVG_regProcess((PAC193X_PDEVICE_CONTEXT)context);
                    break;
                case GetVSENSEnAVGValueReq:
                    if(transferHandle == ((PAC193X_PDEVICE_CONTEXT)context)->transferHandle_negPwr){
                        ret = PAC193x_UpdateContext_ChannelPolarityProcess((PAC193X_PDEVICE_CONTEXT)context);
                        if(ret == PAC193X_SUCCESS) {
                            ((PAC193X_PDEVICE_CONTEXT)context)->deviceEventStatus = PAC193X_EVENT_REQUEST_PENDING;
                        }else{
                            ((PAC193X_PDEVICE_CONTEXT)context)->deviceEventStatus = PAC193X_EVENT_REQUEST_ERROR;
                            PAC193x_I2CEventHandlerError(context);
                        }
                        return;
                    }
                    if(transferHandle == ((PAC193X_PDEVICE_CONTEXT)context)->transferHandle){
                        ret = PAC193x_GetVSENSEn_AVG_mVProcess((PAC193X_PDEVICE_CONTEXT)context);
                        if (ret != PAC193X_SUCCESS){
                            ((PAC193X_PDEVICE_CONTEXT)context)->deviceEventStatus = PAC193X_EVENT_REQUEST_ERROR;
                            PAC193x_I2CEventHandlerError(context);                        
                        }                        
                    }
                    break;
                case GetISENSEnAVGValueReq:                    
                    if(transferHandle == ((PAC193X_PDEVICE_CONTEXT)context)->transferHandle_negPwr){
                        ret = PAC193x_UpdateContext_ChannelPolarityProcess((PAC193X_PDEVICE_CONTEXT)context);
                        if(ret == PAC193X_SUCCESS) {
                            ((PAC193X_PDEVICE_CONTEXT)context)->deviceEventStatus = PAC193X_EVENT_REQUEST_PENDING;
                        }else{
                            ((PAC193X_PDEVICE_CONTEXT)context)->deviceEventStatus = PAC193X_EVENT_REQUEST_ERROR;
                            PAC193x_I2CEventHandlerError(context);
                        }
                        return;
                    }
                    if(transferHandle == ((PAC193X_PDEVICE_CONTEXT)context)->transferHandle){
                        ret = PAC193x_GetISENSEn_AVG_mAProcess((PAC193X_PDEVICE_CONTEXT)context);
                        if (ret != PAC193X_SUCCESS){
                            ((PAC193X_PDEVICE_CONTEXT)context)->deviceEventStatus = PAC193X_EVENT_REQUEST_ERROR;
                            PAC193x_I2CEventHandlerError(context);                        
                        }                        
                    }
                    break;
                case GetVPOWERnRegisterReq:
                    PAC193x_GetVPOWERn_regProcess((PAC193X_PDEVICE_CONTEXT)context);
                    break;
                case GetVPOWERnValueReq:
                    if(transferHandle == ((PAC193X_PDEVICE_CONTEXT)context)->transferHandle_negPwr){
                        ret = PAC193x_UpdateContext_ChannelPolarityProcess((PAC193X_PDEVICE_CONTEXT)context);
                        if(ret == PAC193X_SUCCESS) {
                            ((PAC193X_PDEVICE_CONTEXT)context)->deviceEventStatus = PAC193X_EVENT_REQUEST_PENDING;
                        }else{
                            ((PAC193X_PDEVICE_CONTEXT)context)->deviceEventStatus = PAC193X_EVENT_REQUEST_ERROR;
                            PAC193x_I2CEventHandlerError(context);
                        }
                        return;
                    }
                    if(transferHandle == ((PAC193X_PDEVICE_CONTEXT)context)->transferHandle){
                        ret = PAC193x_GetVPOWERn_mWProcess((PAC193X_PDEVICE_CONTEXT)context);
                        if (ret != PAC193X_SUCCESS){
                            ((PAC193X_PDEVICE_CONTEXT)context)->deviceEventStatus = PAC193X_EVENT_REQUEST_ERROR;
                            PAC193x_I2CEventHandlerError(context);                        
                        }                        
                    }
                    break;
                case GetChDisRegisterReq:
                    PAC193x_GetChannelDisSMBus_regProcess((PAC193X_PDEVICE_CONTEXT)context);
                    break;
                case SetChDisRegisterReq:
                    PAC193x_SetChannelDisSMBus_regProcess((PAC193X_PDEVICE_CONTEXT) context);
                    break;
                case GetNegPWRRegisterReq:
                    PAC193x_GetNegPwr_regProcess((PAC193X_PDEVICE_CONTEXT)context);
                    break;
                case SetNegPWRRegisterReq:
                    break;
                case GetSlowRegisterReq:
                    PAC193x_GetSlow_regProcess((PAC193X_PDEVICE_CONTEXT)context);
                    break;
                case SetSlowRegisterReq:
                    break;
                default:
                    //we are in either IDLE, SYNC or Uninitialized
                    return; // we should ignore this i2c transfer, nobody waits for it
            }
        break;
        
        case PAC193X_I2C_TRANSFER_EVENT_ERROR:
            ((PAC193X_PDEVICE_CONTEXT)context)->deviceEventStatus = PAC193X_EVENT_TRANSFER_ERROR;
            PAC193x_I2CEventHandlerError(context);
            return;
        case PAC193X_I2C_TRANSFER_EVENT_HANDLE_EXPIRED:        
        // to be safe we should handle this as unknown error (like "DRV_I2C_TRANSFER_EVENT_HANDLE_INVALID")
        // the error code comment is: "Transfer Handle given is expired. 
        // It means transfer is completed but with or without error is not known."
        default:
            // - DRV_I2C_TRANSFER_EVENT_HANDLE_INVALID
            ((PAC193X_PDEVICE_CONTEXT)context)->deviceEventStatus = PAC193X_EVENT_UNKNOWN_ERROR;
            PAC193x_I2CEventHandlerError(context);
            return;
    }
    
    // Lock the mutexProcState mutex
    if( PAC193x_MUTEX_Lock(&(((PAC193X_PDEVICE_CONTEXT)context)->mutexProcState)) == false )
    {
        // abort, the processing state is already being changed elsewhere
        return;
    }
    
    // Check if the processing state has been already changed to "Idle" or "Sync"
    // (by PAC193x_Timeout)
    if( (((PAC193X_PDEVICE_CONTEXT)context)->processingState == Idle) || 
        (((PAC193X_PDEVICE_CONTEXT)context)->processingState == Sync)  ){
        
        PAC193x_MUTEX_Unlock(&(((PAC193X_PDEVICE_CONTEXT)context)->mutexProcState));
        return;
    }    
    
    // advance the state machine to "Idle" or "Sync"
    if ( ((PAC193X_PDEVICE_CONTEXT)context)->syncMode == true){
        ((PAC193X_PDEVICE_CONTEXT)context)->processingState = Sync;
    }else
    {    
        ((PAC193X_PDEVICE_CONTEXT)context)->processingState = Idle;
    }
   
    //call the user call-back if there is one registered
    if(((PAC193X_PDEVICE_CONTEXT)context)->userCallback != NULL){
        PAC193X_EVENT_HANDLER userCallback;
        PAC193X_EVENT event;
        uintptr_t userContext; 
        
        userCallback = ((PAC193X_PDEVICE_CONTEXT)context)->userCallback;
        event = ((PAC193X_PDEVICE_CONTEXT)context)->deviceEventStatus;
        userContext = ((PAC193X_PDEVICE_CONTEXT)context)->userContext;
        userCallback(event, userContext);
    }
    
    // Unlock the Timeout mutex
    PAC193x_MUTEX_Unlock(&(((PAC193X_PDEVICE_CONTEXT)context)->mutexProcState));
    
}


bool PAC193x_Device_IsInitialized(PAC193X_PDEVICE_CONTEXT pdevice){
    if (pdevice == NULL){ 
        return false;   // return "false" if pdevice is NULL
    }else{
        return (pdevice->processingState != Uninitialized);
    }
}


bool PAC193x_Device_IsBusy(PAC193X_PDEVICE_CONTEXT pdevice)
{
    bool deviceIsBusy = false;
    bool i2cIsBusy = false;
    
    if (pdevice == NULL) return true;   // return "true" is pdevice is NULL

    if ( PAC193X_I2C_TRANSFER_EVENT_PENDING == PAC193x_I2C_TransferStatusGet(pdevice->transferHandle) ||
     PAC193X_I2C_TRANSFER_EVENT_PENDING == PAC193x_I2C_TransferStatusGet(pdevice->transferHandle_ctrl) || 
     PAC193X_I2C_TRANSFER_EVENT_PENDING == PAC193x_I2C_TransferStatusGet(pdevice->transferHandle_negPwr) )         
    {
        i2cIsBusy = true;
        //printf("I2C Device Transfer Pending\r\n ");
    }
    
    if( (i2cIsBusy == true) || (pdevice->processingState != Idle) )
    {
        deviceIsBusy = true; 
       // printf("I2C Device Transfer idle\r\n ");
    }
    
    return deviceIsBusy;
}


int16_t PAC193x_Device_Initialize(PAC193X_PDEVICE_CONTEXT pdevice, PAC193X_DEVICE_INIT deviceInit) {
    int16_t errorCode = PAC193X_SUCCESS;
    int i;
    
    if (pdevice == NULL) return PAC193X_INVALID_PARAMETER;
    
    //step 1 - initialize the device context
    memset(pdevice, 0, sizeof(PAC193X_DEVICE_CONTEXT));

    // Create the processingState mutex
    if( PAC193x_MUTEX_Create(&(pdevice->mutexProcState)) == false )
    {
        return PAC193X_MUTEX_INVALID;
    }
    
    // lock the processingState mutex
    if( PAC193x_MUTEX_Lock(&(pdevice->mutexProcState)) == false )
    {
        return PAC193X_MUTEX_FAIL;
    }
    
    pdevice->processingState = Uninitialized;
    pdevice->deviceEventStatus = PAC193X_EVENT_NO_EVENT;
    
    //step2 - configure the I2C communication
    pdevice->i2cAddress = deviceInit.i2cAddress;
    pdevice->i2cHandle = deviceInit.i2cHandle;
    
    if (pdevice->i2cHandle != PAC193X_I2C_HANDLE_INVALID)
    {
        /* Register I2C transfer complete Event Handler for this device */
        
        PAC193x_I2C_TransferEventHandlerSet(pdevice->i2cHandle, PAC193x_I2CEventHandler, (uintptr_t)pdevice);        
    }
    else
    {
        /* Handle error */
        errorCode = PAC193X_I2C_INVALID_PARAM;
        goto initialize_error;
    }

    //step3 - set the initial device configuration
    
    //NOTE: use synchronous communication for the device initial configuration.
    //reset the device configuration (similar to POR)
    pdevice->syncMode = true;
    pdevice->processingState = Idle; // set the state machine to Idle to allow function calls
    
    //unlock the processingState mutex
    PAC193x_MUTEX_Unlock(&(pdevice->mutexProcState));
    
    pdevice->ENABLE_BYTE_COUNT_FLAG = false;
    //initialize the cached registers in the device context
    pdevice->deviceID_cached = false;
    pdevice->negPwr_LAT_cached = false;
    pdevice->ctrl_LAT_cached = false;
    pdevice->sampleRate = 1024;
    
    //make sure that the I2C protocol is set to default configuration: I2C version (not SMBUS)
    PAC193X_CHANNEL_DIS_SMBUS_REGISTER ChDisSMBus_reg = {0,0,0,0,0,0,0};
    errorCode = PAC193x_SetChannelDisSMBus_reg(pdevice, ChDisSMBus_reg);
    if(errorCode != PAC193X_SUCCESS) goto initialize_error;
    
    //read and store the device IDs in the device context
    errorCode = PAC193x_GetDeviceID(pdevice, &(pdevice->deviceID)); 
    if(errorCode != PAC193X_SUCCESS) goto initialize_error;
    
    //set the device specific properties in the device context
    
    switch (pdevice->deviceID.product){
        //PAC193x family
        case 0b01011000:{               //0b01011000 - PAC1931
            pdevice->HwChannels = 1;
            break;
        }
        case 0b01011001:{               //0b01011001 - PAC1932
            pdevice->HwChannels = 2;
            break;
        }
        case 0b01011010:{               //0b01011010 - PAC1933
            pdevice->HwChannels = 3;
            break;
        }
        case 0b01011011:{               //0b01011011 - PAC1934
            pdevice->HwChannels = 4;
            break;
        }
        default:
            errorCode = PAC193X_INVALID_DEVICE;
            return errorCode;
    }
    
    for(i = 0; i < PAC193X_MAX_CH_COUNT; i++){
        float PowerLSB;
        float IsenseLSB;
        
        pdevice->rsense[i] = deviceInit.rsense[i];        
        //IsenseLSB
        if(deviceInit.rsense[i] != 0){
            IsenseLSB = (float)PAC193X_VSENSE_FSR_MV * 1000000.0 / 65536.0;   // 1000000 due to rsense uOhm scale
            IsenseLSB /= (float)deviceInit.rsense[i];
        }else{
            IsenseLSB = 0.0;
        }
        pdevice->IsenseLSB[i] = (float)IsenseLSB;
        
        //PowerLSB
        if(deviceInit.rsense[i] != 0){
            PowerLSB = (float)PAC193X_VPOWER_FSR_MW * 1000000.0 / (float)0x10000000; // 1000000 due to rsense uOhm scale
            PowerLSB /= (float)deviceInit.rsense[i];

        }else{
            PowerLSB = 0.0;
        }
        pdevice->VPowerLSB[i] = PowerLSB;
    }
        
    // Configure CTRL - 0x00
    PAC193X_CTRL_REGISTER Ctrl;
    Ctrl.OVF_STATUS = 0b0;
    Ctrl.OVF_ALERT = 0b0;
    Ctrl.ALERT_CC = 0b0;
    Ctrl.ALRT_PIN = 0b0;
    Ctrl.SINGLE_SHOT = 0b0;
    Ctrl.SLEEP = 0b0;
    Ctrl.SAMPLE_RATE = 0b0;
    errorCode = PAC193x_SetCtrl_reg(pdevice, Ctrl);    
    if(errorCode != PAC193X_SUCCESS) goto initialize_error;
  
    // Configure NEG_PWR_FSR - 0x00
    PAC193X_NEG_PWR_REGISTER NegPwr;
    NegPwr.CH4_BIDV = 0b0;
    NegPwr.CH3_BIDV = 0b0;
    NegPwr.CH2_BIDV = 0b0;
    NegPwr.CH1_BIDV = 0b0;
    NegPwr.CH4_BIDI = 0b1;
    NegPwr.CH3_BIDI = 0b1;
    NegPwr.CH2_BIDI = 0b1;
    NegPwr.CH1_BIDI = 0b1;
    errorCode = PAC193x_SetNegPwr_reg(pdevice, NegPwr);    
    if(errorCode != PAC193X_SUCCESS) goto initialize_error;   

    // Configure SLOW - 0x15
    PAC193X_SLOW_REGISTER Slow;
    Slow.POR = 0b1;
    Slow.RefreshVFall = 0b0;
    Slow.RefreshFall = 0b1;    
    Slow.RefreshVRise = 0b0;
    Slow.RefreshRise = 0b1;
    Slow.SlowHighLow = 0b0;
    Slow.SlowLowHigh = 0b0;
    Slow.Slow = 0b0;
    
    errorCode = PAC193x_SetSlow_reg(pdevice, Slow);
    if(errorCode != PAC193X_SUCCESS) goto initialize_error;
        
    errorCode = PAC193x_Refresh(pdevice);    // the REFRESH ensures that the configuration
                                             // changes are applied
    if(errorCode != PAC193X_SUCCESS) goto initialize_error; 

    pdevice->syncMode = deviceInit.syncMode;    // set the user sync mode selection

    //device initialization success. device ready to execute commands
    return errorCode;
    
initialize_error:
    pdevice->processingState = Uninitialized;
    pdevice->syncMode = deviceInit.syncMode;    // set the user sync mode selection
    PAC193x_MUTEX_Unlock(&(pdevice->mutexProcState));    
    return errorCode;
}


int16_t PAC193x_SetUserCallback(
    const PAC193X_PDEVICE_CONTEXT pdevice,
    const PAC193X_EVENT_HANDLER userCallback,
    const uintptr_t userContext
){
    if( (pdevice == NULL) || (userCallback == NULL) ){
        return PAC193X_INVALID_PARAMETER;
    }

    //check if new device request is allowed
    // lock the processingState mutex
    if( PAC193x_MUTEX_Lock(&(pdevice->mutexProcState)) == false )    
    {
        return PAC193X_MUTEX_FAIL;
    }    
    
    if(pdevice->processingState == Idle){
        // set the callback
        pdevice->userCallback = userCallback;
        pdevice->userContext = userContext;
        PAC193x_MUTEX_Unlock(&(pdevice->mutexProcState));        
        return PAC193X_SUCCESS;
    }else
    {
        // reject new request
        PAC193x_MUTEX_Unlock(&(pdevice->mutexProcState));
        return PAC193X_BUSY;
    }  
}

int16_t PAC193x_GetEventStatus(PAC193X_PDEVICE_CONTEXT pdevice, PAC193X_PEVENT pevent){
    if (pdevice == NULL) return PAC193X_INVALID_PARAMETER;
    *pevent = pdevice->deviceEventStatus;
    return PAC193X_SUCCESS;
}

int16_t PAC193x_GetDeviceID(PAC193X_PDEVICE_CONTEXT pdevice, PAC193X_PdeviceID pdeviceID){
    if ((pdevice == NULL) || (pdeviceID == NULL)) return PAC193X_INVALID_PARAMETER;
    
    //check if new device request is allowed
    // lock the processingState mutex
    if( PAC193x_MUTEX_Lock(&(pdevice->mutexProcState)) == false )    
    {
        return PAC193X_MUTEX_FAIL;
    }
    
    if(pdevice->processingState == Idle){
        // start new request 
        pdevice->processingState = GetDeviceIDReq;
        pdevice->deviceEventStatus = PAC193X_EVENT_NO_EVENT;
        PAC193x_MUTEX_Unlock(&(pdevice->mutexProcState));
    }else
    {
        // reject new request
        PAC193x_MUTEX_Unlock(&(pdevice->mutexProcState));
        return PAC193X_BUSY;
    }
    
    if(pdevice->deviceID_cached == true){
        *pdeviceID = pdevice->deviceID;
        pdevice->processingState = Idle;
        return PAC193X_ALREADY_CACHED;
    }
    
    pdevice->outData = (void*)pdeviceID;
    pdevice->i2cTxBuffer[0] = PAC193X_PRODUCT_ID_ADDR;
    pdevice->transferHandle = PAC193X_I2C_TRANSFER_HANDLE_INVALID;
    unsigned int i2cRxSize = sizeof(PAC193X_deviceID);
    if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) i2cRxSize += 3; //there is one byteCount reported before each ID register value
    PAC193x_I2C_WriteReadTransferAdd(pdevice, (void*) pdevice->i2cTxBuffer, 1, (void*) pdevice->i2cRxBuffer, i2cRxSize, &(pdevice->transferHandle)); 
    
    if(pdevice->transferHandle == PAC193X_I2C_TRANSFER_HANDLE_INVALID)
    {
        // Error handling here
        pdevice->processingState = Idle;
        return PAC193X_I2C_INVALID_PARAM;
    }
    
    //wait here for the request processing completion if the library is in SYNC mode
    if(pdevice->syncMode == true){ 
        while (pdevice->processingState != Sync);
        pdevice->processingState = Idle;     //the request is fully completed here
        if( pdevice->deviceEventStatus != PAC193X_EVENT_REQUEST_COMPLETE ){
            return PAC193X_REQUEST_FAIL;
        }
    }    
    
    return PAC193X_SUCCESS;    
}


int16_t PAC193x_GetDeviceIDProcess(PAC193X_PDEVICE_CONTEXT pdevice){
    uint8_t* pRawValue;
    int idx = 0;

    pRawValue = pdevice->i2cRxBuffer;
    //Product ID
    if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) idx++;
    pdevice->deviceID.product = pRawValue[idx];
    ((PAC193X_PdeviceID)pdevice->outData)->product = pRawValue[idx++];
    
    //Manufacturer ID    
    if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) idx++;
    pdevice->deviceID.manufacturer = pRawValue[idx];
    ((PAC193X_PdeviceID)pdevice->outData)->manufacturer = pRawValue[idx++];

    //Revision ID
    if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) idx++;
    pdevice->deviceID.revision = pRawValue[idx];
    ((PAC193X_PdeviceID)pdevice->outData)->revision = pRawValue[idx];
    
    pdevice->deviceID_cached = true;
    return PAC193X_SUCCESS;   
}


int16_t PAC193x_Refresh(PAC193X_PDEVICE_CONTEXT pdevice){
    if (pdevice == NULL) return PAC193X_INVALID_PARAMETER;
    
    // check if new device request is allowed
    // lock the processingState mutex
    if( PAC193x_MUTEX_Lock(&(pdevice->mutexProcState)) == false )    
    {
        return PAC193X_MUTEX_FAIL;
    }
    
    if(pdevice->processingState == Idle){
        // start new request 
        pdevice->processingState = RefreshReq;
        pdevice->deviceEventStatus = PAC193X_EVENT_NO_EVENT;
        PAC193x_MUTEX_Unlock(&(pdevice->mutexProcState));        
    }else
    {
        // reject new request
        PAC193x_MUTEX_Unlock(&(pdevice->mutexProcState));        
        return PAC193X_BUSY;
    }
    
    // invalidate the device context cache flags
    pdevice->negPwr_LAT_cached = false;
    pdevice->ctrl_LAT_cached = false;
    
    pdevice->i2cTxBuffer[0] = PAC193X_REFRESH_CMD_ADDR;
    pdevice->transferHandle = PAC193X_I2C_TRANSFER_HANDLE_INVALID;
    PAC193x_I2C_WriteTransferAdd(pdevice, (void*) pdevice->i2cTxBuffer, 1, &(pdevice->transferHandle));    
    
    if(pdevice->transferHandle == PAC193X_I2C_TRANSFER_HANDLE_INVALID)
    {
        // Error handling here
        pdevice->processingState = Idle;
        return PAC193X_I2C_INVALID_PARAM;
    }
       
    //wait here for the request processing completion if the library is in SYNC mode
    if(pdevice->syncMode == true){ 
        while (pdevice->processingState != Sync);
        pdevice->processingState = Idle;     //the request is fully completed here
        if( pdevice->deviceEventStatus != PAC193X_EVENT_REQUEST_COMPLETE ){
            return PAC193X_REQUEST_FAIL;
        }
    }    
    
    return PAC193X_SUCCESS;
}


int16_t PAC193x_RefreshG(PAC193X_PDEVICE_CONTEXT pdevice){
    if (pdevice == NULL) return PAC193X_INVALID_PARAMETER;
    
    //check if new device request is allowed
    // lock the processingState mutex
    if( PAC193x_MUTEX_Lock(&(pdevice->mutexProcState)) == false )    
    {
        return PAC193X_MUTEX_FAIL;
    }
    
    if(pdevice->processingState == Idle){
        // start new request 
        pdevice->processingState = RefreshGReq;
        pdevice->deviceEventStatus = PAC193X_EVENT_NO_EVENT;
        PAC193x_MUTEX_Unlock(&(pdevice->mutexProcState));        
    }else
    {
        // reject new request
        PAC193x_MUTEX_Unlock(&(pdevice->mutexProcState));
        return PAC193X_BUSY;
    }
    
    // invalidate the device context cache flags
    pdevice->negPwr_LAT_cached = false;
    pdevice->ctrl_LAT_cached = false;    
    
    pdevice->i2cTxBuffer[0] = PAC193X_REFRESH_G_CMD_ADDR;
    pdevice->transferHandle = PAC193X_I2C_TRANSFER_HANDLE_INVALID;   
    PAC193x_I2C_WriteTransferAdd(pdevice, (void*) pdevice->i2cTxBuffer, 1, &(pdevice->transferHandle));        
    if(pdevice->transferHandle == PAC193X_I2C_TRANSFER_HANDLE_INVALID)
    {
        // Error handling here
        pdevice->processingState = Idle;
        return PAC193X_I2C_INVALID_PARAM;
    }
       
    //wait here for the request processing completion if the library is in SYNC mode
    if(pdevice->syncMode == true){ 
        while (pdevice->processingState != Sync);
        pdevice->processingState = Idle;     //the request is fully completed here
        if( pdevice->deviceEventStatus != PAC193X_EVENT_REQUEST_COMPLETE ){
            return PAC193X_REQUEST_FAIL;
        }
    }    
    
    return PAC193X_SUCCESS;
}


int16_t PAC193x_RefreshV(PAC193X_PDEVICE_CONTEXT pdevice){
    if (pdevice == NULL) return PAC193X_INVALID_PARAMETER;
    
    // check if new device request is allowed
    // lock the processingState mutex
    if( PAC193x_MUTEX_Lock(&(pdevice->mutexProcState)) == false )    
    {
        return PAC193X_MUTEX_FAIL;
    }
    
    if(pdevice->processingState == Idle){
        // start new request 
        pdevice->processingState = RefreshVReq;
        pdevice->deviceEventStatus = PAC193X_EVENT_NO_EVENT;
        PAC193x_MUTEX_Unlock(&(pdevice->mutexProcState));        
    }else
    {
        // reject new request
        PAC193x_MUTEX_Unlock(&(pdevice->mutexProcState));        
        return PAC193X_BUSY;
    }
    
    // invalidate the device context cache flags
    pdevice->negPwr_LAT_cached = false;
    pdevice->ctrl_LAT_cached = false;
    
    pdevice->i2cTxBuffer[0] = PAC193X_REFRESH_V_CMD_ADDR;
    pdevice->transferHandle = PAC193X_I2C_TRANSFER_HANDLE_INVALID;   
    PAC193x_I2C_WriteTransferAdd(pdevice, (void*) pdevice->i2cTxBuffer, 1, &(pdevice->transferHandle));        
    if(pdevice->transferHandle == PAC193X_I2C_TRANSFER_HANDLE_INVALID)
    {
        // Error handling here
        pdevice->processingState = Idle;
        return PAC193X_I2C_INVALID_PARAM;
    }
       
    //wait here for the request processing completion if the library is in SYNC mode
    if(pdevice->syncMode == true){ 
        while (pdevice->processingState != Sync);
        pdevice->processingState = Idle;     //the request is fully completed here
        if( pdevice->deviceEventStatus != PAC193X_EVENT_REQUEST_COMPLETE ){
            return PAC193X_REQUEST_FAIL;
        }
    }    
    
    return PAC193X_SUCCESS;
}


int16_t PAC193x_GetCtrl_reg(PAC193X_PDEVICE_CONTEXT pdevice, uint8_t reg_select, PAC193X_PCTRL_REGISTER pCtrl_reg){
    uint8_t registerAddr;
    
    if (pdevice == NULL) return PAC193X_INVALID_PARAMETER;
    switch(reg_select){
        case 1:
            registerAddr = PAC193X_CTRL_ADDR;
            break;
        case 2:
            registerAddr = PAC193X_CTRL_ACT_ADDR;
            break;
        case 3:
            registerAddr = PAC193X_CTRL_LAT_ADDR;
            break;
        default:
            return PAC193X_INVALID_PARAMETER;      
    }    
    
    //check if new device request is allowed
    // lock the processingState mutex
    if( PAC193x_MUTEX_Lock(&(pdevice->mutexProcState)) == false )    
    {
        return PAC193X_MUTEX_FAIL;
    }
    
    if(pdevice->processingState == Idle){
        // start new request 
        pdevice->processingState = GetCtrlRegisterReq;
        pdevice->deviceEventStatus = PAC193X_EVENT_NO_EVENT;
        PAC193x_MUTEX_Unlock(&(pdevice->mutexProcState));
    }else
    {
        // reject new request
        PAC193x_MUTEX_Unlock(&(pdevice->mutexProcState));        
        return PAC193X_BUSY;
    }
    
    pdevice->outData = (void*)pCtrl_reg;
    pdevice->i2cTxBuffer_ctrl[0] = registerAddr;
    pdevice->transferHandle_ctrl = PAC193X_I2C_TRANSFER_HANDLE_INVALID;
    unsigned int i2cRxSize = PAC193X_CTRL_SZ;
    if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) i2cRxSize++;   
    PAC193x_I2C_WriteReadTransferAdd(pdevice, (void*) pdevice->i2cTxBuffer_ctrl, 1, (void*) pdevice->i2cRxBuffer_ctrl, i2cRxSize, &(pdevice->transferHandle_ctrl));        
 
    if(pdevice->transferHandle_ctrl == PAC193X_I2C_TRANSFER_HANDLE_INVALID)
    {
        // Error handling here
        pdevice->processingState = Idle;
        return PAC193X_I2C_INVALID_PARAM;
    }
    
    //wait here for the request processing completion if the library is in SYNC mode
    if(pdevice->syncMode == true){ 
        while (pdevice->processingState != Sync);
        pdevice->processingState = Idle;     //the request is fully completed here
        if( pdevice->deviceEventStatus != PAC193X_EVENT_REQUEST_COMPLETE ){
            return PAC193X_REQUEST_FAIL;
        }
    }    
    
    return PAC193X_SUCCESS;
}


int16_t PAC193x_GetCtrl_regProcess(PAC193X_PDEVICE_CONTEXT pdevice){
    uint8_t* pRawValue;
    
    pRawValue = pdevice->i2cRxBuffer_ctrl;
    if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) pRawValue++;

    *((uint8_t*)pdevice->outData) = pRawValue[0];
    // cache the LAT register value in context 
    if(pdevice->i2cTxBuffer_ctrl[0] == PAC193X_CTRL_LAT_ADDR){    
        PAC193x_UpdateContext_CtrlProcess(pdevice);
    }
    
    return PAC193X_SUCCESS;    
}


int16_t PAC193x_SetCtrl_reg(PAC193X_PDEVICE_CONTEXT pdevice, PAC193X_CTRL_REGISTER Ctrl_reg){
    void *pwriteBuffer;
    if (pdevice == NULL) return PAC193X_INVALID_PARAMETER;
    
    // check if new device request is allowed
    // lock the processingState mutex
    if( PAC193x_MUTEX_Lock(&(pdevice->mutexProcState)) == false )    
    {
        return PAC193X_MUTEX_FAIL;
    }
    
    if(pdevice->processingState == Idle){
        // start new request 
        pdevice->processingState = SetCtrlRegisterReq;
        pdevice->deviceEventStatus = PAC193X_EVENT_NO_EVENT;
        PAC193x_MUTEX_Unlock(&(pdevice->mutexProcState));        
    }else
    {
        // reject new request
        PAC193x_MUTEX_Unlock(&(pdevice->mutexProcState));        
        return PAC193X_BUSY;
    }
    
    pwriteBuffer = &Ctrl_reg;
    pdevice->i2cTxBuffer[0] = PAC193X_CTRL_ADDR;
    memcpy( (pdevice->i2cTxBuffer)+1, (uint8_t*)pwriteBuffer, sizeof(PAC193X_CTRL_REGISTER));   
    pdevice->transferHandle = PAC193X_I2C_TRANSFER_HANDLE_INVALID;  
    PAC193x_I2C_WriteTransferAdd(pdevice, (void*) pdevice->i2cTxBuffer, 2, &(pdevice->transferHandle));        
    if(pdevice->transferHandle == PAC193X_I2C_TRANSFER_HANDLE_INVALID)
    {
        // Error handling here
        pdevice->processingState = Idle;
        return PAC193X_I2C_INVALID_PARAM;
    }
       
    //wait here for the request processing completion if the library is in SYNC mode
    if(pdevice->syncMode == true){ 
        while (pdevice->processingState != Sync);
        pdevice->processingState = Idle;     //the request is fully completed here
        if( pdevice->deviceEventStatus != PAC193X_EVENT_REQUEST_COMPLETE ){
            return PAC193X_REQUEST_FAIL;
        }
    }    
    
    return PAC193X_SUCCESS;
}


int16_t PAC193x_GetAccumulatorCount(PAC193X_PDEVICE_CONTEXT pdevice, uint32_t* pregister_val){

    if (pdevice == NULL) return PAC193X_INVALID_PARAMETER;
    
    // check if new device request is allowed
    // lock the processingState mutex
    if( PAC193x_MUTEX_Lock(&(pdevice->mutexProcState)) == false )    
    {
        return PAC193X_MUTEX_FAIL;
    }
    
    if(pdevice->processingState == Idle){
        // start new request 
        pdevice->processingState = GetAccCountReq;
        pdevice->deviceEventStatus = PAC193X_EVENT_NO_EVENT;
        PAC193x_MUTEX_Unlock(&(pdevice->mutexProcState));        
    }else
    {
        // reject new request
        PAC193x_MUTEX_Unlock(&(pdevice->mutexProcState));        
        return PAC193X_BUSY;
    }
    
    pdevice->outData = (void*)pregister_val;

    pdevice->i2cTxBuffer[0] = PAC193X_ACC_COUNT_ADDR;
    pdevice->transferHandle = PAC193X_I2C_TRANSFER_HANDLE_INVALID;
    unsigned int i2cRxSize = PAC193X_ACC_COUNT_SZ;
    if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) i2cRxSize++;   
    PAC193x_I2C_WriteReadTransferAdd(pdevice, (void*) pdevice->i2cTxBuffer, 1, (void*) pdevice->i2cRxBuffer, i2cRxSize, &(pdevice->transferHandle));        
    
    if(pdevice->transferHandle == PAC193X_I2C_TRANSFER_HANDLE_INVALID)
    {
        // Error handling here
        pdevice->processingState = Idle;
        return PAC193X_I2C_INVALID_PARAM;
    }
    
    //wait here for the request processing completion if the library is in SYNC mode
    if(pdevice->syncMode == true){ 
        while (pdevice->processingState != Sync);
        pdevice->processingState = Idle;     //the request is fully completed here
        if( pdevice->deviceEventStatus != PAC193X_EVENT_REQUEST_COMPLETE ){
            return PAC193X_REQUEST_FAIL;
        }
    }    
    
    return PAC193X_SUCCESS;
}


int16_t PAC193x_GetAccumulatorCountProcess(PAC193X_PDEVICE_CONTEXT pdevice){
    uint8_t* pRawValue;
    uint32_t regVal;
        
    pRawValue = pdevice->i2cRxBuffer;
    if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) pRawValue++;
    
    regVal = ((uint32_t)pRawValue[0] << 8) | (uint32_t)pRawValue[1];
    regVal = (regVal << 8) | (uint32_t)pRawValue[2];
    *((uint32_t*)pdevice->outData) = regVal;
    
    return PAC193X_SUCCESS;
}


int16_t PAC193x_GetVACCn_reg(PAC193X_PDEVICE_CONTEXT pdevice, uint8_t channelNo, uint64_t* pregister_val){
    uint8_t registerAddr;
    
    if (pdevice == NULL) return PAC193X_INVALID_PARAMETER;
    
    // check if new device request is allowed
    // lock the processingState mutex
    if( PAC193x_MUTEX_Lock(&(pdevice->mutexProcState)) == false )    
    {
        return PAC193X_MUTEX_FAIL;
    }
    
    if(pdevice->processingState == Idle){
        // start new request 
        pdevice->processingState = GetVACCnRegisterReq;
        pdevice->deviceEventStatus = PAC193X_EVENT_NO_EVENT;
        PAC193x_MUTEX_Unlock(&(pdevice->mutexProcState));        
    }else
    {
        // reject new request
        PAC193x_MUTEX_Unlock(&(pdevice->mutexProcState));        
        return PAC193X_BUSY;
    }
    
    pdevice->outData = (void*)pregister_val;
    switch(channelNo){
        case 1:
            registerAddr = PAC193X_VPOWER1_ACC_ADDR;
            break;
        case 2:
            registerAddr = PAC193X_VPOWER2_ACC_ADDR;
            break;
        case 3:
            registerAddr = PAC193X_VPOWER3_ACC_ADDR;
            break;
        case 4:
            registerAddr = PAC193X_VPOWER4_ACC_ADDR;
            break;
        default:
            pdevice->processingState = Idle;
            return PAC193X_INVALID_PARAMETER;      
    }
    pdevice->i2cTxBuffer[0] = registerAddr;
    pdevice->channelNo = channelNo;
    pdevice->transferHandle = PAC193X_I2C_TRANSFER_HANDLE_INVALID;
    unsigned int i2cRxSize = PAC193X_VACCN_SZ;
    if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) i2cRxSize++;  
    PAC193x_I2C_WriteReadTransferAdd(pdevice, (void*) pdevice->i2cTxBuffer, 1, (void*) pdevice->i2cRxBuffer, i2cRxSize, &(pdevice->transferHandle));        
    
    if(pdevice->transferHandle == PAC193X_I2C_TRANSFER_HANDLE_INVALID)
    {
        // Error handling here
        pdevice->processingState = Idle;
        return PAC193X_I2C_INVALID_PARAM;
    }
    
    //wait here for the request processing completion if the library is in SYNC mode
    if(pdevice->syncMode == true){ 
        while (pdevice->processingState != Sync);
        pdevice->processingState = Idle;     //the request is fully completed here
        if( pdevice->deviceEventStatus != PAC193X_EVENT_REQUEST_COMPLETE ){
            return PAC193X_REQUEST_FAIL;
        }
    }    
    
    return PAC193X_SUCCESS;
}


int16_t PAC193x_GetVACCn_regProcess(PAC193X_PDEVICE_CONTEXT pdevice){
    uint8_t* pRawValue;
    uint64_t regVal;
    
    pRawValue = pdevice->i2cRxBuffer;
    if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) pRawValue++;
    
    regVal = ((uint64_t)pRawValue[0] << 8) | (uint64_t)pRawValue[1];
    regVal = (regVal << 8) | (uint64_t)pRawValue[2];
    regVal = (regVal << 8) | (uint64_t)pRawValue[3];
    regVal = (regVal << 8) | (uint64_t)pRawValue[4];
    regVal = (regVal << 8) | (uint64_t)pRawValue[5];

    *((uint64_t*)pdevice->outData) = regVal;
    
    return PAC193X_SUCCESS;
}


int16_t PAC193x_GetVACCn_mW(PAC193X_PDEVICE_CONTEXT pdevice, uint8_t channelNo, float* pvalue){
    uint8_t registerAddr;
    int16_t errorCode = PAC193X_SUCCESS;
    
    if (pdevice == NULL) return PAC193X_INVALID_PARAMETER;
    
    // validate channelNo parameter
    if ( (channelNo == 0) || (channelNo > pdevice->HwChannels) ){
        errorCode = PAC193X_INVALID_PARAMETER;
        return errorCode;       
    }    
    
    // channel shunt value must be non-zero
    if (pdevice->rsense[channelNo-1] == 0) return PAC193X_INVALID_SHUNT_VALUE;
    
    // check if new device request is allowed
    // lock the processingState mutex
    if( PAC193x_MUTEX_Lock(&(pdevice->mutexProcState)) == false )    
    {
        return PAC193X_MUTEX_FAIL;
    }
    
    if(pdevice->processingState == Idle){
        // start new request 
        pdevice->processingState = GetVACCnValueReq;
        pdevice->deviceEventStatus = PAC193X_EVENT_NO_EVENT;
        PAC193x_MUTEX_Unlock(&(pdevice->mutexProcState));        
    }else
    {
        // reject new request
        PAC193x_MUTEX_Unlock(&(pdevice->mutexProcState));        
        return PAC193X_BUSY;
    }
           
    switch(channelNo){
        case 1:
            registerAddr = PAC193X_VPOWER1_ACC_ADDR;
            break;
        case 2:
            registerAddr = PAC193X_VPOWER2_ACC_ADDR;
            break;
        case 3:
            registerAddr = PAC193X_VPOWER3_ACC_ADDR;
            break;
        case 4:
            registerAddr = PAC193X_VPOWER4_ACC_ADDR;
            break;
        default:
            pdevice->processingState = Idle;
            return PAC193X_INVALID_PARAMETER;      
    }
    
    pdevice->channelNo = channelNo;
    
    //Read NegPwr
    errorCode = PAC193x_UpdateContext_ChannelPolarity((PAC193X_PDEVICE_CONTEXT)pdevice);
    if (errorCode == PAC193X_I2C_INVALID_PARAM)
    {
        pdevice->processingState = Idle;
        return errorCode;
    }
    
    pdevice->outData = (void*)pvalue;
    
    pdevice->i2cTxBuffer[0] = registerAddr;
    
    pdevice->transferHandle = PAC193X_I2C_TRANSFER_HANDLE_INVALID;
    unsigned int i2cRxSize = PAC193X_VACCN_SZ;
    if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) i2cRxSize++;  
    PAC193x_I2C_WriteReadTransferAdd(pdevice, (void*) pdevice->i2cTxBuffer, 1, (void*) pdevice->i2cRxBuffer, i2cRxSize, &(pdevice->transferHandle));        
    if(pdevice->transferHandle == PAC193X_I2C_TRANSFER_HANDLE_INVALID)
    {
        // Error handling here
        // discard any pending i2c transfer
        pdevice->transferHandle_negPwr = PAC193X_I2C_TRANSFER_HANDLE_INVALID;
        pdevice->processingState = Idle;
        return PAC193X_I2C_INVALID_PARAM;
    }
    
    //wait here for the request processing completion if the library is in SYNC mode
    if(pdevice->syncMode == true){ 
        while (pdevice->processingState != Sync);
        pdevice->processingState = Idle;     //the request is fully completed here
        if( pdevice->deviceEventStatus != PAC193X_EVENT_REQUEST_COMPLETE ){
            return PAC193X_REQUEST_FAIL;
        }
    }    
    
    return PAC193X_SUCCESS;    
}


int16_t PAC193x_GetVACCn_mWProcess(PAC193X_PDEVICE_CONTEXT pdevice){
    uint8_t* pRawValue;
    uint64_t regVal;
    uint64_t VpowerAccRaw;
    float VpowerAccReal, PowerUnit;
    
    pRawValue = pdevice->i2cRxBuffer;
    if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) pRawValue++;
    
    regVal = ((uint64_t)pRawValue[0] << 8) | (uint64_t)pRawValue[1];
    regVal = (regVal << 8) | (uint64_t)pRawValue[2];
    regVal = (regVal << 8) | (uint64_t)pRawValue[3];
    regVal = (regVal << 8) | (uint64_t)pRawValue[4];
    regVal = (regVal << 8) | (uint64_t)pRawValue[5];
    
    VpowerAccRaw = regVal;

    PowerUnit = pdevice->VPowerLSB[pdevice->channelNo-1];
    if(pdevice->IsSignedPower[pdevice->channelNo-1] == 1){    
        if((VpowerAccRaw & 0x800000000000) == 0x800000000000){
            VpowerAccRaw = VpowerAccRaw | 0xFFFF800000000000;       //sign extension
        }
        VpowerAccReal = (float)((int64_t)VpowerAccRaw);
        PowerUnit *= 2;
    }else{
        VpowerAccReal = (float)VpowerAccRaw;
    }
    VpowerAccReal = VpowerAccReal * PowerUnit;
    *((float*)pdevice->outData) = VpowerAccReal;
    
    return PAC193X_SUCCESS;
}

//reports energy in mWh
int16_t PAC193x_GetEnergy_mWh(PAC193X_PDEVICE_CONTEXT pdevice, uint8_t channelNo, float* pvalue){
    uint8_t registerAddr;
    int16_t errorCode = PAC193X_SUCCESS;
    
    if (pdevice == NULL) return PAC193X_INVALID_PARAMETER;
    
    // validate channelNo parameter
    if ( (channelNo == 0) || (channelNo > pdevice->HwChannels) ){
        errorCode = PAC193X_INVALID_PARAMETER;
        return errorCode;       
    }    
    
    // channel shunt value must be non-zero
    if (pdevice->rsense[channelNo-1] == 0) return PAC193X_INVALID_SHUNT_VALUE;
    
    // check if new device request is allowed
    // lock the processingState mutex
    if( PAC193x_MUTEX_Lock(&(pdevice->mutexProcState)) == false )    
    {
        return PAC193X_MUTEX_FAIL;
    }
    
    if(pdevice->processingState == Idle){
        // start new request 
        pdevice->processingState = GetEnergyReq;
        pdevice->deviceEventStatus = PAC193X_EVENT_NO_EVENT;
        PAC193x_MUTEX_Unlock(&(pdevice->mutexProcState));        
    }else
    {
        // reject new request
        PAC193x_MUTEX_Unlock(&(pdevice->mutexProcState));        
        return PAC193X_BUSY;
    }
            
    switch(channelNo){
        case 1:
            registerAddr = PAC193X_VPOWER1_ACC_ADDR;
            break;
        case 2:
            registerAddr = PAC193X_VPOWER2_ACC_ADDR;
            break;
        case 3:
            registerAddr = PAC193X_VPOWER3_ACC_ADDR;
            break;
        case 4:
            registerAddr = PAC193X_VPOWER4_ACC_ADDR;
            break;
        default:
            pdevice->processingState = Idle;
            return PAC193X_INVALID_PARAMETER;      
    }
    
    pdevice->channelNo = channelNo;
    
    //Read Ctrl & NegPwr
    errorCode = PAC193x_UpdateContext_Ctrl((PAC193X_PDEVICE_CONTEXT)pdevice);
    if (errorCode == PAC193X_I2C_INVALID_PARAM)
    {
        pdevice->processingState = Idle;
        return errorCode;
    }
    
    errorCode = PAC193x_UpdateContext_ChannelPolarity((PAC193X_PDEVICE_CONTEXT)pdevice);
    if (errorCode == PAC193X_I2C_INVALID_PARAM)
    {
        //discard any pending i2c transfer
        pdevice->transferHandle_ctrl = PAC193X_I2C_TRANSFER_HANDLE_INVALID;
        pdevice->processingState = Idle;
        return errorCode;
    }
    
    pdevice->outData = (void*)pvalue;
    
    pdevice->i2cTxBuffer[0] = registerAddr;
    
    pdevice->transferHandle = PAC193X_I2C_TRANSFER_HANDLE_INVALID;

    unsigned int i2cRxSize = PAC193X_VACCN_SZ;
    if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) i2cRxSize++;   
    PAC193x_I2C_WriteReadTransferAdd(pdevice, (void*) pdevice->i2cTxBuffer, 1, (void*) pdevice->i2cRxBuffer, i2cRxSize, &(pdevice->transferHandle));    
    if(pdevice->transferHandle == PAC193X_I2C_TRANSFER_HANDLE_INVALID)
    {
        // Error handling here
        // discard any pending i2c transfer
        pdevice->transferHandle_negPwr = PAC193X_I2C_TRANSFER_HANDLE_INVALID;
        pdevice->transferHandle_ctrl = PAC193X_I2C_TRANSFER_HANDLE_INVALID;
        pdevice->processingState = Idle;
        return PAC193X_I2C_INVALID_PARAM;
    }
    
    //wait here for the request processing completion if the library is in SYNC mode
    if(pdevice->syncMode == true){ 
        while (pdevice->processingState != Sync);
        pdevice->processingState = Idle;     //the request is fully completed here
        if( pdevice->deviceEventStatus != PAC193X_EVENT_REQUEST_COMPLETE ){
            return PAC193X_REQUEST_FAIL;
        }
    }
           
    return PAC193X_SUCCESS;
}


int16_t PAC193x_GetEnergy_mWhProcess(PAC193X_PDEVICE_CONTEXT pdevice){
    uint8_t singleShotBit;
    float powerAccReal, energyVal;
    float EnergyUnit = ENERGY_UNIT_CONVERSION;
    uint8_t* pRawValue;
    uint64_t regVal;
    uint64_t VpowerAccRaw;
    float VpowerAccReal, PowerUnit;
    
    singleShotBit = pdevice->ctrl_LAT.SINGLE_SHOT;
    if(singleShotBit != 0){
        return PAC193X_ERR_SINGLE_SHOT_MODE;
    }    
    
    pRawValue = pdevice->i2cRxBuffer;
    if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) pRawValue++;
    
    regVal = ((uint64_t)pRawValue[0] << 8) | (uint64_t)pRawValue[1];
    regVal = (regVal << 8) | (uint64_t)pRawValue[2];
    regVal = (regVal << 8) | (uint64_t)pRawValue[3];
    regVal = (regVal << 8) | (uint64_t)pRawValue[4];
    regVal = (regVal << 8) | (uint64_t)pRawValue[5];
    
    VpowerAccRaw = regVal;
    PowerUnit = pdevice->VPowerLSB[pdevice->channelNo-1];
    if(pdevice->IsSignedPower[pdevice->channelNo-1] == 1){
        if((VpowerAccRaw & 0x800000000000) == 0x800000000000){
            VpowerAccRaw = VpowerAccRaw | 0xFFFF800000000000;       //sign extension
        }
        VpowerAccReal = (float)((int64_t)VpowerAccRaw);
        PowerUnit *= 2;
    }else{
        VpowerAccReal = (float)VpowerAccRaw;
    }
    
    powerAccReal = VpowerAccReal * PowerUnit;
    energyVal = (powerAccReal / pdevice->sampleRate) * EnergyUnit;

    *((float*)pdevice->outData) = energyVal;
    return PAC193X_SUCCESS;
}

//reports energy in mWh
int16_t PAC193x_GetTimedEnergy_mWh(PAC193X_PDEVICE_CONTEXT pdevice, uint8_t channelNo, float* pvalue, uint32_t time){
    uint8_t registerAddr;
    int16_t errorCode = PAC193X_SUCCESS;
    
    if (pdevice == NULL) return PAC193X_INVALID_PARAMETER;
    
    // validate channelNo parameter
    if ( (channelNo == 0) || (channelNo > pdevice->HwChannels) ){
        errorCode = PAC193X_INVALID_PARAMETER;
        return errorCode;       
    } 
    
    // channel shunt value must be non-zero
    if (pdevice->rsense[channelNo-1] == 0) return PAC193X_INVALID_SHUNT_VALUE;
            
    // check if new device request is allowed
    // lock the processingState mutex
    if( PAC193x_MUTEX_Lock(&(pdevice->mutexProcState)) == false )    
    {
        return PAC193X_MUTEX_FAIL;
    }
    
    if(pdevice->processingState == Idle){
        // start new request 
        pdevice->processingState = GetTimedEnergyReq;
        pdevice->deviceEventStatus = PAC193X_EVENT_NO_EVENT;
        PAC193x_MUTEX_Unlock(&(pdevice->mutexProcState));        
    }else
    {
        // reject new request
        PAC193x_MUTEX_Unlock(&(pdevice->mutexProcState));        
        return PAC193X_BUSY;
    }
    
    switch(channelNo){
        case 1:
            registerAddr = PAC193X_VPOWER1_ACC_ADDR;
            break;
        case 2:
            registerAddr = PAC193X_VPOWER2_ACC_ADDR;
            break;
        case 3:
            registerAddr = PAC193X_VPOWER3_ACC_ADDR;
            break;
        case 4:
            registerAddr = PAC193X_VPOWER4_ACC_ADDR;
            break;
        default:
            pdevice->processingState = Idle;
            return PAC193X_INVALID_PARAMETER;      
    }
    
    //Read Ctrl & NegPwr
    errorCode = PAC193x_UpdateContext_Ctrl((PAC193X_PDEVICE_CONTEXT)pdevice);
    if (errorCode == PAC193X_I2C_INVALID_PARAM)
    {
        pdevice->processingState = Idle;
        return errorCode;
    }
    
    errorCode = PAC193x_UpdateContext_ChannelPolarity((PAC193X_PDEVICE_CONTEXT)pdevice);
    if (errorCode == PAC193X_I2C_INVALID_PARAM)
    {
        //discard any pending i2c transfer
        pdevice->transferHandle_ctrl = PAC193X_I2C_TRANSFER_HANDLE_INVALID;
        pdevice->processingState = Idle;
        return errorCode;
    }
    
    pdevice->outData = (void*)pvalue;
    pdevice->channelNo = channelNo;
    pdevice->time = time;
    
    pdevice->i2cTxBuffer[0] = registerAddr;
    
    pdevice->transferHandle = PAC193X_I2C_TRANSFER_HANDLE_INVALID;
    
    unsigned int i2cRxSize = PAC193X_VACCN_SZ;
    if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) i2cRxSize++;    
    PAC193x_I2C_WriteReadTransferAdd(pdevice, (void*) pdevice->i2cTxBuffer, 1, (void*) pdevice->i2cRxBuffer, i2cRxSize, &(pdevice->transferHandle));        
    if(pdevice->transferHandle == PAC193X_I2C_TRANSFER_HANDLE_INVALID)
    {
        // Error handling here
        // discard any pending i2c transfer
        pdevice->transferHandle_ctrl = PAC193X_I2C_TRANSFER_HANDLE_INVALID;        
        pdevice->transferHandle_negPwr = PAC193X_I2C_TRANSFER_HANDLE_INVALID;
        pdevice->processingState = Idle;
        return PAC193X_I2C_INVALID_PARAM;
    }
    
    //wait here for the request processing completion if the library is in SYNC mode
    if(pdevice->syncMode == true){ 
        while (pdevice->processingState != Sync);
        pdevice->processingState = Idle;     //the request is fully completed here
        if( pdevice->deviceEventStatus != PAC193X_EVENT_REQUEST_COMPLETE ){
            return PAC193X_REQUEST_FAIL;
        }
    }  
    
    return PAC193X_SUCCESS;
}

int16_t PAC193x_GetTimedEnergy_mWhProcess(PAC193X_PDEVICE_CONTEXT pdevice){
    uint8_t singleShotBit;
    float powerAccReal, energyVal;
    float EnergyUnit = ENERGY_UNIT_CONVERSION; 
    uint8_t* pRawValue;
    uint64_t regVal;
    uint64_t VpowerAccRaw;
    float VpowerAccReal, PowerUnit;
    
    singleShotBit = pdevice->ctrl_LAT.SINGLE_SHOT;
    if(singleShotBit != 1){
        return PAC193X_ERR_NO_SINGLE_SHOT_MODE;
    }
    
    pRawValue = pdevice->i2cRxBuffer;
    
    if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) pRawValue++;
    regVal = ((uint64_t)pRawValue[0] << 8) | (uint64_t)pRawValue[1];
    regVal = (regVal << 8) | (uint64_t)pRawValue[2];
    regVal = (regVal << 8) | (uint64_t)pRawValue[3];
    regVal = (regVal << 8) | (uint64_t)pRawValue[4];
    regVal = (regVal << 8) | (uint64_t)pRawValue[5];
    
    VpowerAccRaw = regVal;
    
    PowerUnit = pdevice->VPowerLSB[pdevice->channelNo-1];
    
    // Power is bipolar if either Vbus or Vsense are bipolar (or both)
    if(pdevice->IsSignedPower[pdevice->channelNo-1] == 1){
        if((VpowerAccRaw & 0x800000000000) == 0x800000000000){
            VpowerAccRaw = VpowerAccRaw | 0xFFFF800000000000;       //sign extension
        }
        VpowerAccReal = (float)((int64_t)VpowerAccRaw);
        PowerUnit *= 2;
    }else{
        VpowerAccReal = (float)VpowerAccRaw;
    }
    
    powerAccReal = VpowerAccReal * PowerUnit;
    
    energyVal = powerAccReal * ((pdevice->time) / 1000.0) * EnergyUnit;    //time parameter unit is 1ms -> convert it back to 1 sec
    
    *((float*)pdevice->outData) = energyVal;
    
    return PAC193X_SUCCESS;
}

int16_t PAC193x_GetVBUSn_reg(PAC193X_PDEVICE_CONTEXT pdevice, uint8_t channelNo, uint16_t* pregister_val){
    uint8_t registerAddr;
    
    if (pdevice == NULL) return PAC193X_INVALID_PARAMETER;
    
    // check if new device request is allowed
    // lock the processingState mutex
    if( PAC193x_MUTEX_Lock(&(pdevice->mutexProcState)) == false )    
    {
        return PAC193X_MUTEX_FAIL;
    }
    
    if(pdevice->processingState == Idle){
        // start new request 
        pdevice->processingState = GetVBUSnRegisterReq;
        pdevice->deviceEventStatus = PAC193X_EVENT_NO_EVENT;
        PAC193x_MUTEX_Unlock(&(pdevice->mutexProcState));        
    }else
    {
        // reject new request
        PAC193x_MUTEX_Unlock(&(pdevice->mutexProcState));        
        return PAC193X_BUSY;
    }
    
    pdevice->outData = (void*)pregister_val;
    switch(channelNo){
        case 1:
            registerAddr = PAC193X_VBUS1_ADDR;
            break;
        case 2:
            registerAddr = PAC193X_VBUS2_ADDR;
            break;
        case 3:
            registerAddr = PAC193X_VBUS3_ADDR;
            break;
        case 4:
            registerAddr = PAC193X_VBUS4_ADDR;
            break;
        default:
            pdevice->processingState = Idle;
            return PAC193X_INVALID_PARAMETER;      
    }
    pdevice->i2cTxBuffer[0] = registerAddr;
    pdevice->channelNo = channelNo;
    pdevice->transferHandle = PAC193X_I2C_TRANSFER_HANDLE_INVALID;
    
    unsigned int i2cRxSize = PAC193X_VBUS_VSENSE_SZ;
    if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) i2cRxSize++; 
    PAC193x_I2C_WriteReadTransferAdd(pdevice, (void*) pdevice->i2cTxBuffer, 1, (void*) pdevice->i2cRxBuffer, i2cRxSize, &(pdevice->transferHandle));        
    if(pdevice->transferHandle == PAC193X_I2C_TRANSFER_HANDLE_INVALID)
    {
        // Error handling here
        pdevice->processingState = Idle;
        return PAC193X_I2C_INVALID_PARAM;
    }
    
    //wait here for the request processing completion if the library is in SYNC mode
    if(pdevice->syncMode == true){ 
        while (pdevice->processingState != Sync);
        pdevice->processingState = Idle;     //the request is fully completed here
        if( pdevice->deviceEventStatus != PAC193X_EVENT_REQUEST_COMPLETE ){
            return PAC193X_REQUEST_FAIL;
        }
    }    
    
    return PAC193X_SUCCESS;
}


int16_t PAC193x_GetVBUSn_regProcess(PAC193X_PDEVICE_CONTEXT pdevice){
    uint8_t* pRawValue;
    uint16_t regVal;
    
    pRawValue = pdevice->i2cRxBuffer;    
    if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) pRawValue++;    
    regVal = ((uint16_t)pRawValue[0] << 8) | (uint16_t)pRawValue[1];
    *((uint16_t*)pdevice->outData) = regVal;
    
    return PAC193X_SUCCESS;
}

//pvalue reported as mV
int16_t PAC193x_GetVBUSn_mV(PAC193X_PDEVICE_CONTEXT pdevice, uint8_t channelNo, float* pvalue){
    uint8_t registerAddr;
    int16_t errorCode = PAC193X_SUCCESS;
    
    if (pdevice == NULL) return PAC193X_INVALID_PARAMETER;
    
    // check if new device request is allowed
    // lock the processingState mutex
    if( PAC193x_MUTEX_Lock(&(pdevice->mutexProcState)) == false )    
    {
        return PAC193X_MUTEX_FAIL;
    }
    
    if(pdevice->processingState == Idle){
        // start new request 
        pdevice->processingState = GetVBUSnValueReq;
        pdevice->deviceEventStatus = PAC193X_EVENT_NO_EVENT;
        PAC193x_MUTEX_Unlock(&(pdevice->mutexProcState));        
    }else
    {
        // reject new request
        PAC193x_MUTEX_Unlock(&(pdevice->mutexProcState));        
        return PAC193X_BUSY;
    }
    
    pdevice->outData = (void*)pvalue;
    switch(channelNo){
        case 1:
            registerAddr = PAC193X_VBUS1_ADDR;
            break;
        case 2:
            registerAddr = PAC193X_VBUS2_ADDR;
            break;
        case 3:
            registerAddr = PAC193X_VBUS3_ADDR;
            break;
        case 4:
            registerAddr = PAC193X_VBUS4_ADDR;
            break;
        default:
            pdevice->processingState = Idle;
            return PAC193X_INVALID_PARAMETER;      
    }
    
    pdevice->channelNo = channelNo;
    
    //Read NegPwr
    errorCode = PAC193x_UpdateContext_ChannelPolarity((PAC193X_PDEVICE_CONTEXT)pdevice);
    if (errorCode == PAC193X_I2C_INVALID_PARAM)
    {
        pdevice->processingState = Idle;
        return errorCode;
    }
    
    pdevice->i2cTxBuffer[0] = registerAddr;
    pdevice->transferHandle = PAC193X_I2C_TRANSFER_HANDLE_INVALID;
    unsigned int i2cRxSize = PAC193X_VBUS_VSENSE_SZ;
    if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) i2cRxSize++;  
    PAC193x_I2C_WriteReadTransferAdd(pdevice, (void*) pdevice->i2cTxBuffer, 1, (void*) pdevice->i2cRxBuffer, i2cRxSize, &(pdevice->transferHandle));        
    if(pdevice->transferHandle == PAC193X_I2C_TRANSFER_HANDLE_INVALID)
    {
        // Error handling here
        // discard any pending i2c transfer
        pdevice->transferHandle_negPwr = PAC193X_I2C_TRANSFER_HANDLE_INVALID;
        pdevice->processingState = Idle;
        return PAC193X_I2C_INVALID_PARAM;
    }
    
    //wait here for the request processing completion if the library is in SYNC mode
    if(pdevice->syncMode == true){ 
        while (pdevice->processingState != Sync);
        pdevice->processingState = Idle;     //the request is fully completed here
        if( pdevice->deviceEventStatus != PAC193X_EVENT_REQUEST_COMPLETE ){
            return PAC193X_REQUEST_FAIL;
        }
    }    
    return PAC193X_SUCCESS;
}


int16_t PAC193x_GetVBUSn_mVProcess(PAC193X_PDEVICE_CONTEXT pdevice){
    uint8_t* pRawValue;
    uint16_t VbusRaw;
    float VbusReal, VbusLsb;
    
    pRawValue = pdevice->i2cRxBuffer;
    if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) pRawValue++;
    
    VbusRaw = ((uint16_t)pRawValue[0] << 8) | (uint16_t)pRawValue[1];
    
    if(pdevice->IsSignedVbus[pdevice->channelNo-1] == 1){
        VbusLsb = PAC193X_VBUS_FSR_MV * 2.0 / 65536.0;
        VbusReal = (float)((short)VbusRaw);
    }else{
        VbusLsb = PAC193X_VBUS_FSR_MV / 65536.0;
        VbusReal = (float)VbusRaw;
    }
    VbusReal = VbusReal * VbusLsb;      //mV

    *((float*)pdevice->outData) = VbusReal;

        
    return PAC193X_SUCCESS;
}


int16_t PAC193x_GetVSENSEn_reg(PAC193X_PDEVICE_CONTEXT pdevice, uint8_t channelNo, uint16_t* pregister_val){
    uint8_t registerAddr;
    
    if (pdevice == NULL) return PAC193X_INVALID_PARAMETER;
    
    // check if new device request is allowed
    // lock the processingState mutex
    if( PAC193x_MUTEX_Lock(&(pdevice->mutexProcState)) == false )    
    {
        return PAC193X_MUTEX_FAIL;
    }
    
    if(pdevice->processingState == Idle){
        // start new request 
        pdevice->processingState = GetVSENSEnRegisterReq;
        pdevice->deviceEventStatus = PAC193X_EVENT_NO_EVENT;
        PAC193x_MUTEX_Unlock(&(pdevice->mutexProcState));        
    }else
    {
        // reject new request
        PAC193x_MUTEX_Unlock(&(pdevice->mutexProcState));        
        return PAC193X_BUSY;
    }
    
    pdevice->outData = (void*)pregister_val;
    switch(channelNo){
        case 1:
            registerAddr = PAC193X_VSENSE1_ADDR;
            break;
        case 2:
            registerAddr = PAC193X_VSENSE2_ADDR;
            break;
        case 3:
            registerAddr = PAC193X_VSENSE3_ADDR;
            break;
        case 4:
            registerAddr = PAC193X_VSENSE4_ADDR;
            break;
        default:
            pdevice->processingState = Idle;
            return PAC193X_INVALID_PARAMETER;      
    }
    pdevice->i2cTxBuffer[0] = registerAddr;
    pdevice->channelNo = channelNo;
    pdevice->transferHandle = PAC193X_I2C_TRANSFER_HANDLE_INVALID;
    unsigned int i2cRxSize = PAC193X_VBUS_VSENSE_SZ;
    if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) i2cRxSize++;   
    PAC193x_I2C_WriteReadTransferAdd(pdevice, (void*) pdevice->i2cTxBuffer, 1, (void*) pdevice->i2cRxBuffer, i2cRxSize, &(pdevice->transferHandle));        
    if(pdevice->transferHandle == PAC193X_I2C_TRANSFER_HANDLE_INVALID)
    {
        // Error handling here
        pdevice->processingState = Idle;
        return PAC193X_I2C_INVALID_PARAM;
    }
    
    //wait here for the request processing completion if the library is in SYNC mode
    if(pdevice->syncMode == true){ 
        while (pdevice->processingState != Sync);
        pdevice->processingState = Idle;     //the request is fully completed here
        if( pdevice->deviceEventStatus != PAC193X_EVENT_REQUEST_COMPLETE ){
            return PAC193X_REQUEST_FAIL;
        }
    }    
    
    return PAC193X_SUCCESS;
}


int16_t PAC193x_GetVSENSEn_regProcess(PAC193X_PDEVICE_CONTEXT pdevice){
    uint8_t* pRawValue;
    uint16_t regVal;
    
    pRawValue = pdevice->i2cRxBuffer;
    if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) pRawValue++;    
    regVal = ((uint16_t)pRawValue[0] << 8) | (uint16_t)pRawValue[1];
    *((uint16_t*)pdevice->outData) = regVal;
    
    return PAC193X_SUCCESS;
}


int16_t PAC193x_GetVSENSEn_mV(PAC193X_PDEVICE_CONTEXT pdevice, uint8_t channelNo, float* pvalue){
    uint8_t registerAddr;
    int16_t errorCode = PAC193X_SUCCESS;
    
    if (pdevice == NULL) return PAC193X_INVALID_PARAMETER;
    
    // check if new device request is allowed
    // lock the processingState mutex
    if( PAC193x_MUTEX_Lock(&(pdevice->mutexProcState)) == false )    
    {
        return PAC193X_MUTEX_FAIL;
    }
    
    if(pdevice->processingState == Idle){
        // start new request 
        pdevice->processingState = GetVSENSEnValueReq;
        pdevice->deviceEventStatus = PAC193X_EVENT_NO_EVENT;
        PAC193x_MUTEX_Unlock(&(pdevice->mutexProcState));        
    }else
    {
        // reject new request
        PAC193x_MUTEX_Unlock(&(pdevice->mutexProcState));        
        return PAC193X_BUSY;
    }
    
    pdevice->outData = (void*)pvalue;
    switch(channelNo){
        case 1:
            registerAddr = PAC193X_VSENSE1_ADDR;
            break;
        case 2:
            registerAddr = PAC193X_VSENSE2_ADDR;
            break;
        case 3:
            registerAddr = PAC193X_VSENSE3_ADDR;
            break;
        case 4:
            registerAddr = PAC193X_VSENSE4_ADDR;
            break;
        default:
            pdevice->processingState = Idle;
            return PAC193X_INVALID_PARAMETER;      
    }
      
    pdevice->channelNo = channelNo;
    //Read NegPwr
    errorCode = PAC193x_UpdateContext_ChannelPolarity((PAC193X_PDEVICE_CONTEXT)pdevice);
    if (errorCode == PAC193X_I2C_INVALID_PARAM)
    {
        pdevice->processingState = Idle;
        return errorCode;
    }
    
    pdevice->i2cTxBuffer[0] = registerAddr;
    pdevice->transferHandle = PAC193X_I2C_TRANSFER_HANDLE_INVALID;
    unsigned int i2cRxSize = PAC193X_VBUS_VSENSE_SZ;
    if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) i2cRxSize++;   
    PAC193x_I2C_WriteReadTransferAdd(pdevice, (void*) pdevice->i2cTxBuffer, 1, (void*) pdevice->i2cRxBuffer, i2cRxSize, &(pdevice->transferHandle));        
    if(pdevice->transferHandle == PAC193X_I2C_TRANSFER_HANDLE_INVALID)
    {
        // Error handling here
        // discard any pending i2c transfer
        pdevice->transferHandle_negPwr = PAC193X_I2C_TRANSFER_HANDLE_INVALID;
        pdevice->processingState = Idle;
        return PAC193X_I2C_INVALID_PARAM;
    }
    
    //wait here for the request processing completion if the library is in SYNC mode
    if(pdevice->syncMode == true){ 
        while (pdevice->processingState != Sync);
        pdevice->processingState = Idle;     //the request is fully completed here
        if( pdevice->deviceEventStatus != PAC193X_EVENT_REQUEST_COMPLETE ){
            return PAC193X_REQUEST_FAIL;
        }
    }    
    
    return PAC193X_SUCCESS;
}


int16_t PAC193x_GetVSENSEn_mVProcess(PAC193X_PDEVICE_CONTEXT pdevice){
    uint8_t* pRawValue;
    uint16_t VsenseRaw;
    float VsenseReal, VsenseLsb;
    
    pRawValue = pdevice->i2cRxBuffer;
    if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) pRawValue++;
    
    VsenseRaw = ((uint16_t)pRawValue[0] << 8) | (uint16_t)pRawValue[1];
    
    if(pdevice->IsSignedVsense[pdevice->channelNo-1] == 1){
        VsenseLsb = 2 * PAC193X_VSENSE_FSR_MV / 65536.0;
        VsenseReal = (float)((short)VsenseRaw);
    }else{
        VsenseLsb = PAC193X_VSENSE_FSR_MV / 65536.0;
        VsenseReal = (float)VsenseRaw;
    }
    VsenseReal = VsenseReal * VsenseLsb;        //mV

    *((float*)pdevice->outData) = VsenseReal;
    
    return PAC193X_SUCCESS;
}


int16_t PAC193x_GetISENSEn_mA(PAC193X_PDEVICE_CONTEXT pdevice, uint8_t channelNo, float* pvalue){
    uint8_t registerAddr;
    int16_t errorCode = PAC193X_SUCCESS;
    
    if (pdevice == NULL) return PAC193X_INVALID_PARAMETER;
    
    // validate channelNo parameter
    if ( (channelNo == 0) || (channelNo > pdevice->HwChannels) ) return PAC193X_INVALID_PARAMETER;

    // channel shunt value must be non-zero
    if (pdevice->rsense[channelNo-1] == 0) return PAC193X_INVALID_SHUNT_VALUE;    
    
    // check if new device request is allowed
    // lock the processingState mutex
    if( PAC193x_MUTEX_Lock(&(pdevice->mutexProcState)) == false )    
    {
        return PAC193X_MUTEX_FAIL;
    }
    
    if(pdevice->processingState == Idle){
        // start new request 
        pdevice->processingState = GetISENSEnValueReq;
        pdevice->deviceEventStatus = PAC193X_EVENT_NO_EVENT;
        PAC193x_MUTEX_Unlock(&(pdevice->mutexProcState));        
    }else
    {
        // reject new request
        PAC193x_MUTEX_Unlock(&(pdevice->mutexProcState));        
        return PAC193X_BUSY;
    }
    
    pdevice->outData = (void*)pvalue;
    switch(channelNo){
        case 1:
            registerAddr = PAC193X_VSENSE1_ADDR;
            break;
        case 2:
            registerAddr = PAC193X_VSENSE2_ADDR;
            break;
        case 3:
            registerAddr = PAC193X_VSENSE3_ADDR;
            break;
        case 4:
            registerAddr = PAC193X_VSENSE4_ADDR;
            break;
        default:
            pdevice->processingState = Idle;
            return PAC193X_INVALID_PARAMETER;      
    }
   
    pdevice->channelNo = channelNo;
    
    //Read NegPwr
    errorCode = PAC193x_UpdateContext_ChannelPolarity((PAC193X_PDEVICE_CONTEXT)pdevice);
    if (errorCode == PAC193X_I2C_INVALID_PARAM)
    {
        pdevice->processingState = Idle;
        return errorCode;
    }
    
    pdevice->i2cTxBuffer[0] = registerAddr;
    pdevice->transferHandle = PAC193X_I2C_TRANSFER_HANDLE_INVALID;
    unsigned int i2cRxSize = PAC193X_VBUS_VSENSE_SZ;
    if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) i2cRxSize++;   
    PAC193x_I2C_WriteReadTransferAdd(pdevice, (void*) pdevice->i2cTxBuffer, 1, (void*) pdevice->i2cRxBuffer, i2cRxSize, &(pdevice->transferHandle));        
    if(pdevice->transferHandle == PAC193X_I2C_TRANSFER_HANDLE_INVALID)
    {
        // Error handling here
        // discard any pending i2c transfer
        pdevice->transferHandle_negPwr = PAC193X_I2C_TRANSFER_HANDLE_INVALID;  
        pdevice->processingState = Idle;
        return PAC193X_I2C_INVALID_PARAM;
    }
    
    //wait here for the request processing completion if the library is in SYNC mode
    if(pdevice->syncMode == true){ 
        while (pdevice->processingState != Sync);
        pdevice->processingState = Idle;     //the request is fully completed here
        if( pdevice->deviceEventStatus != PAC193X_EVENT_REQUEST_COMPLETE ){
            return PAC193X_REQUEST_FAIL;
        }
    }    
    
    return PAC193X_SUCCESS;
}


int16_t PAC193x_GetISENSEn_mAProcess(PAC193X_PDEVICE_CONTEXT pdevice){
    uint8_t* pRawValue;
    uint16_t VsenseRaw;
    float VsenseReal;
    float IsenseReal;
    float IsenseUnit;
    
    pRawValue = pdevice->i2cRxBuffer;
    
    if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) pRawValue++;
    
    VsenseRaw = ((uint16_t)pRawValue[0] << 8) | (uint16_t)pRawValue[1];
    
    IsenseUnit = pdevice->IsenseLSB[pdevice->channelNo-1];
    
    if(pdevice->IsSignedVsense[pdevice->channelNo-1] == 1){
        VsenseReal = (float)((short)VsenseRaw);
        IsenseUnit *= 2;
    }else{
        VsenseReal = (float)VsenseRaw;
    }
    
    IsenseReal = VsenseReal * IsenseUnit;

    *((float*)pdevice->outData) = IsenseReal;
    
    return PAC193X_SUCCESS;
}


int16_t PAC193x_GetVBUSn_AVG_reg(PAC193X_PDEVICE_CONTEXT pdevice, uint8_t channelNo, uint16_t* pregister_val){
    uint8_t registerAddr;
    
    if (pdevice == NULL) return PAC193X_INVALID_PARAMETER;
    
    // check if new device request is allowed
    // lock the processingState mutex
    if( PAC193x_MUTEX_Lock(&(pdevice->mutexProcState)) == false )    
    {
        return PAC193X_MUTEX_FAIL;
    }
    
    if(pdevice->processingState == Idle){
        // start new request 
        pdevice->processingState = GetVBUSnAVGRegisterReq;
        pdevice->deviceEventStatus = PAC193X_EVENT_NO_EVENT;
        PAC193x_MUTEX_Unlock(&(pdevice->mutexProcState));        
    }else
    {
        // reject new request
        PAC193x_MUTEX_Unlock(&(pdevice->mutexProcState));        
        return PAC193X_BUSY;
    }
    
    pdevice->outData = (void*)pregister_val;
    switch(channelNo){
        case 1:
            registerAddr = PAC193X_VBUS1_AVG_ADDR;
            break;
        case 2:
            registerAddr = PAC193X_VBUS2_AVG_ADDR;
            break;
        case 3:
            registerAddr = PAC193X_VBUS3_AVG_ADDR;
            break;
        case 4:
            registerAddr = PAC193X_VBUS4_AVG_ADDR;
            break;
        default:
            pdevice->processingState = Idle;
            return PAC193X_INVALID_PARAMETER;      
    }
    pdevice->i2cTxBuffer[0] = registerAddr;
    pdevice->channelNo = channelNo;
    pdevice->transferHandle = PAC193X_I2C_TRANSFER_HANDLE_INVALID;
    unsigned int i2cRxSize = PAC193X_VBUS_VSENSE_SZ;
    if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) i2cRxSize++;    
    PAC193x_I2C_WriteReadTransferAdd(pdevice, (void*) pdevice->i2cTxBuffer, 1, (void*) pdevice->i2cRxBuffer, i2cRxSize, &(pdevice->transferHandle));        
    if(pdevice->transferHandle == PAC193X_I2C_TRANSFER_HANDLE_INVALID)
    {
        // Error handling here
        pdevice->processingState = Idle;
        return PAC193X_I2C_INVALID_PARAM;
    }
    
    //wait here for the request processing completion if the library is in SYNC mode
    if(pdevice->syncMode == true){ 
        while (pdevice->processingState != Sync);
        pdevice->processingState = Idle;     //the request is fully completed here
        if( pdevice->deviceEventStatus != PAC193X_EVENT_REQUEST_COMPLETE ){
            return PAC193X_REQUEST_FAIL;
        }
    }    
    
    return PAC193X_SUCCESS;  
}


int16_t PAC193x_GetVBUSn_AVG_regProcess(PAC193X_PDEVICE_CONTEXT pdevice){
    uint8_t* pRawValue;
    uint16_t regVal;
    
    pRawValue = pdevice->i2cRxBuffer;
    if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) pRawValue++;    
    regVal = ((uint16_t)pRawValue[0] << 8) | (uint16_t)pRawValue[1];
    *((uint16_t*)pdevice->outData) = regVal;
    
    return PAC193X_SUCCESS;
}


int16_t PAC193x_GetVBUSn_AVG_mV(PAC193X_PDEVICE_CONTEXT pdevice, uint8_t channelNo, float* pvalue){
    uint8_t registerAddr;
    int16_t errorCode = PAC193X_SUCCESS;
    
    if (pdevice == NULL) return PAC193X_INVALID_PARAMETER;
    
    // check if new device request is allowed
    // lock the processingState mutex
    if( PAC193x_MUTEX_Lock(&(pdevice->mutexProcState)) == false )    
    {
        return PAC193X_MUTEX_FAIL;
    }
    
    if(pdevice->processingState == Idle){
        // start new request 
        pdevice->processingState = GetVBUSnAVGValueReq;
        pdevice->deviceEventStatus = PAC193X_EVENT_NO_EVENT;
        PAC193x_MUTEX_Unlock(&(pdevice->mutexProcState));        
    }else
    {
        // reject new request
        PAC193x_MUTEX_Unlock(&(pdevice->mutexProcState));        
        return PAC193X_BUSY;
    }
    
    pdevice->outData = (void*)pvalue;
    switch(channelNo){
        case 1:
            registerAddr = PAC193X_VBUS1_AVG_ADDR;
            break;
        case 2:
            registerAddr = PAC193X_VBUS2_AVG_ADDR;
            break;
        case 3:
            registerAddr = PAC193X_VBUS3_AVG_ADDR;
            break;
        case 4:
            registerAddr = PAC193X_VBUS4_AVG_ADDR;
            break;
        default:
            pdevice->processingState = Idle;
            return PAC193X_INVALID_PARAMETER;      
    }
        
    pdevice->channelNo = channelNo;
    
    //Read NegPwr
    errorCode = PAC193x_UpdateContext_ChannelPolarity((PAC193X_PDEVICE_CONTEXT)pdevice);
    if (errorCode == PAC193X_I2C_INVALID_PARAM)
    {
        pdevice->processingState = Idle;
        return errorCode;
    }
    
    pdevice->i2cTxBuffer[0] = registerAddr;
    pdevice->transferHandle = PAC193X_I2C_TRANSFER_HANDLE_INVALID;
    unsigned int i2cRxSize = PAC193X_VBUS_VSENSE_SZ;
    if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) i2cRxSize++; 
    PAC193x_I2C_WriteReadTransferAdd(pdevice, (void*) pdevice->i2cTxBuffer, 1, (void*) pdevice->i2cRxBuffer, i2cRxSize, &(pdevice->transferHandle));        
    if(pdevice->transferHandle == PAC193X_I2C_TRANSFER_HANDLE_INVALID)
    {
        // Error handling here
        // discard any pending i2c transfer
        pdevice->transferHandle_negPwr = PAC193X_I2C_TRANSFER_HANDLE_INVALID;  
        pdevice->processingState = Idle;
        return PAC193X_I2C_INVALID_PARAM;
    }
    
    //wait here for the request processing completion if the library is in SYNC mode
    if(pdevice->syncMode == true){ 
        while (pdevice->processingState != Sync);
        pdevice->processingState = Idle;     //the request is fully completed here
        if( pdevice->deviceEventStatus != PAC193X_EVENT_REQUEST_COMPLETE ){
            return PAC193X_REQUEST_FAIL;
        }
    }    
    
    return PAC193X_SUCCESS;  
}


int16_t PAC193x_GetVBUSn_AVG_mVProcess(PAC193X_PDEVICE_CONTEXT pdevice){
    uint8_t* pRawValue;
    uint16_t VbusRaw;
    float VbusReal, VbusLsb;
    
    pRawValue = pdevice->i2cRxBuffer;
    if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) pRawValue++;
    
    VbusRaw = ((uint16_t)pRawValue[0] << 8) | (uint16_t)pRawValue[1];
    
    if(pdevice->IsSignedVbus[pdevice->channelNo-1] == 1){    
        VbusLsb = 2.0 * PAC193X_VBUS_FSR_MV / 65536.0;
        VbusReal = (float)((short)VbusRaw);
    }else{
        VbusLsb = PAC193X_VBUS_FSR_MV / 65536.0;
        VbusReal = (float)VbusRaw;
    }
    VbusReal = VbusReal * VbusLsb;      //mV

    *((float*)pdevice->outData) = VbusReal;
            
    return PAC193X_SUCCESS;
}


int16_t PAC193x_GetVSENSEn_AVG_reg(PAC193X_PDEVICE_CONTEXT pdevice, uint8_t channelNo, uint16_t* pregister_val){
    uint8_t registerAddr;
    
    if (pdevice == NULL) return PAC193X_INVALID_PARAMETER;
    
    // check if new device request is allowed
    // lock the processingState mutex
    if( PAC193x_MUTEX_Lock(&(pdevice->mutexProcState)) == false )    
    {
        return PAC193X_MUTEX_FAIL;
    }
    
    if(pdevice->processingState == Idle){
        // start new request 
        pdevice->processingState = GetVSENSEnAVGRegisterReq;
        pdevice->deviceEventStatus = PAC193X_EVENT_NO_EVENT;
        PAC193x_MUTEX_Unlock(&(pdevice->mutexProcState));        
    }else
    {
        // reject new request
        PAC193x_MUTEX_Unlock(&(pdevice->mutexProcState));        
        return PAC193X_BUSY;
    }
    
    pdevice->outData = (void*)pregister_val;
    switch(channelNo){
        case 1:
            registerAddr = PAC193X_VSENSE1_AVG_ADDR;
            break;
        case 2:
            registerAddr = PAC193X_VSENSE2_AVG_ADDR;
            break;
        case 3:
            registerAddr = PAC193X_VSENSE3_AVG_ADDR;
            break;
        case 4:
            registerAddr = PAC193X_VSENSE4_AVG_ADDR;
            break;
        default:
            pdevice->processingState = Idle;
            return PAC193X_INVALID_PARAMETER;      
    }
    pdevice->i2cTxBuffer[0] = registerAddr;
    pdevice->channelNo = channelNo;
    pdevice->transferHandle = PAC193X_I2C_TRANSFER_HANDLE_INVALID;
    unsigned int i2cRxSize = PAC193X_VBUS_VSENSE_SZ;
    if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) i2cRxSize++;   
    PAC193x_I2C_WriteReadTransferAdd(pdevice, (void*) pdevice->i2cTxBuffer, 1, (void*) pdevice->i2cRxBuffer, i2cRxSize, &(pdevice->transferHandle));        
    if(pdevice->transferHandle == PAC193X_I2C_TRANSFER_HANDLE_INVALID)
    {
        // Error handling here
        pdevice->processingState = Idle;
        return PAC193X_I2C_INVALID_PARAM;
    }
    
    //wait here for the request processing completion if the library is in SYNC mode
    if(pdevice->syncMode == true){ 
        while (pdevice->processingState != Sync);
        pdevice->processingState = Idle;     //the request is fully completed here
        if( pdevice->deviceEventStatus != PAC193X_EVENT_REQUEST_COMPLETE ){
            return PAC193X_REQUEST_FAIL;
        }
    }    
    
    return PAC193X_SUCCESS;
}


int16_t PAC193x_GetVSENSEn_AVG_regProcess(PAC193X_PDEVICE_CONTEXT pdevice){
    uint8_t* pRawValue;
    uint16_t regVal;
    
    pRawValue = pdevice->i2cRxBuffer;
    if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) pRawValue++;    
    regVal = ((uint16_t)pRawValue[0] << 8) | (uint16_t)pRawValue[1];
    *((uint16_t*)pdevice->outData) = regVal;
    
    return PAC193X_SUCCESS;
}


int16_t PAC193x_GetVSENSEn_AVG_mV(PAC193X_PDEVICE_CONTEXT pdevice, uint8_t channelNo, float* pvalue){
    uint8_t registerAddr;
    int16_t errorCode = PAC193X_SUCCESS;
    
    if (pdevice == NULL) return PAC193X_INVALID_PARAMETER;
    
    // check if new device request is allowed
    // lock the processingState mutex
    if( PAC193x_MUTEX_Lock(&(pdevice->mutexProcState)) == false )    
    {
        return PAC193X_MUTEX_FAIL;
    }
    
    if(pdevice->processingState == Idle){
        // start new request 
        pdevice->processingState = GetVSENSEnAVGValueReq;
        pdevice->deviceEventStatus = PAC193X_EVENT_NO_EVENT;
        PAC193x_MUTEX_Unlock(&(pdevice->mutexProcState));        
    }else
    {
        // reject new request
        PAC193x_MUTEX_Unlock(&(pdevice->mutexProcState));        
        return PAC193X_BUSY;
    }
    
    pdevice->outData = (void*)pvalue;
    switch(channelNo){
        case 1:
            registerAddr = PAC193X_VSENSE1_AVG_ADDR;
            break;
        case 2:
            registerAddr = PAC193X_VSENSE2_AVG_ADDR;
            break;
        case 3:
            registerAddr = PAC193X_VSENSE3_AVG_ADDR;
            break;
        case 4:
            registerAddr = PAC193X_VSENSE4_AVG_ADDR;
            break;
        default:
            pdevice->processingState = Idle;
            return PAC193X_INVALID_PARAMETER;      
    }
    
    pdevice->channelNo = channelNo;
    
    //Read NegPwr
    errorCode = PAC193x_UpdateContext_ChannelPolarity((PAC193X_PDEVICE_CONTEXT)pdevice);
    if (errorCode == PAC193X_I2C_INVALID_PARAM)
    {
        pdevice->processingState = Idle;
        return errorCode;
    }
    
    pdevice->i2cTxBuffer[0] = registerAddr;
    pdevice->transferHandle = PAC193X_I2C_TRANSFER_HANDLE_INVALID;
    unsigned int i2cRxSize = PAC193X_VBUS_VSENSE_SZ;
    if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) i2cRxSize++;    
    PAC193x_I2C_WriteReadTransferAdd(pdevice, (void*) pdevice->i2cTxBuffer, 1, (void*) pdevice->i2cRxBuffer, i2cRxSize, &(pdevice->transferHandle));        
    if(pdevice->transferHandle == PAC193X_I2C_TRANSFER_HANDLE_INVALID)
    {
        // Error handling here
        //discard any pending i2c transfer
        pdevice->transferHandle_negPwr = PAC193X_I2C_TRANSFER_HANDLE_INVALID; 
        pdevice->processingState = Idle;
        return PAC193X_I2C_INVALID_PARAM;
    }
    
    //wait here for the request processing completion if the library is in SYNC mode
    if(pdevice->syncMode == true){ 
        while (pdevice->processingState != Sync);
        pdevice->processingState = Idle;     //the request is fully completed here
        if( pdevice->deviceEventStatus != PAC193X_EVENT_REQUEST_COMPLETE ){
            return PAC193X_REQUEST_FAIL;
        }
    }    
    
    return PAC193X_SUCCESS; 
}


int16_t PAC193x_GetVSENSEn_AVG_mVProcess(PAC193X_PDEVICE_CONTEXT pdevice){
    uint8_t* pRawValue;
    uint16_t VsenseRaw;
    float VsenseReal, VsenseLsb;
    
    pRawValue = pdevice->i2cRxBuffer;
    if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) pRawValue++;
    
    VsenseRaw = ((uint16_t)pRawValue[0] << 8) | (uint16_t)pRawValue[1];
    if(pdevice->IsSignedVsense[pdevice->channelNo-1] == 1){    
        VsenseLsb = 2 * PAC193X_VSENSE_FSR_MV / 65536.0;
        VsenseReal = (float)((short)VsenseRaw);
    }else{
        VsenseLsb = PAC193X_VSENSE_FSR_MV / 65536.0;
        VsenseReal = (float)VsenseRaw;
    }
    VsenseReal = VsenseReal * VsenseLsb;        //mV

    *((float*)pdevice->outData) = VsenseReal;
            
    return PAC193X_SUCCESS;
}


int16_t PAC193x_GetISENSEn_AVG_mA(PAC193X_PDEVICE_CONTEXT pdevice, uint8_t channelNo, float* pvalue){
    uint8_t registerAddr;
    int16_t errorCode = PAC193X_SUCCESS;
    
    if (pdevice == NULL) return PAC193X_INVALID_PARAMETER;
        
    // validate channelNo parameter
    if ( (channelNo == 0) || (channelNo > pdevice->HwChannels) ) return PAC193X_INVALID_PARAMETER;
    
    // channel shunt value must be non-zero
    if (pdevice->rsense[channelNo-1] == 0) return PAC193X_INVALID_SHUNT_VALUE;     
    
    //check if new device request is allowed
    // lock the processingState mutex
    if( PAC193x_MUTEX_Lock(&(pdevice->mutexProcState)) == false )    
    {
        return PAC193X_MUTEX_FAIL;
    }
    
    if(pdevice->processingState == Idle){
        // start new request 
        pdevice->processingState = GetISENSEnAVGValueReq;
        pdevice->deviceEventStatus = PAC193X_EVENT_NO_EVENT;
        PAC193x_MUTEX_Unlock(&(pdevice->mutexProcState));        
    }else
    {
        // reject new request
        PAC193x_MUTEX_Unlock(&(pdevice->mutexProcState));        
        return PAC193X_BUSY;
    }
    
    pdevice->outData = (void*)pvalue;
    switch(channelNo){
        case 1:
            registerAddr = PAC193X_VSENSE1_ADDR;
            break;
        case 2:
            registerAddr = PAC193X_VSENSE2_ADDR;
            break;
        case 3:
            registerAddr = PAC193X_VSENSE3_ADDR;
            break;
        case 4:
            registerAddr = PAC193X_VSENSE4_ADDR;
            break;
        default:
            pdevice->processingState = Idle;
            return PAC193X_INVALID_PARAMETER;      
    }
    
    pdevice->channelNo = channelNo;
    
    //Read NegPwr
    errorCode = PAC193x_UpdateContext_ChannelPolarity((PAC193X_PDEVICE_CONTEXT)pdevice);
    if (errorCode == PAC193X_I2C_INVALID_PARAM)
    {
        pdevice->processingState = Idle;
        return errorCode;
    }
    
    pdevice->i2cTxBuffer[0] = registerAddr;
    pdevice->transferHandle = PAC193X_I2C_TRANSFER_HANDLE_INVALID;
    unsigned int i2cRxSize = PAC193X_VBUS_VSENSE_SZ;
    if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) i2cRxSize++;  
    PAC193x_I2C_WriteReadTransferAdd(pdevice, (void*) pdevice->i2cTxBuffer, 1, (void*) pdevice->i2cRxBuffer, i2cRxSize, &(pdevice->transferHandle));        
    if(pdevice->transferHandle == PAC193X_I2C_TRANSFER_HANDLE_INVALID)
    {
        // Error handling here
        // discard any pending i2c transfer
        pdevice->transferHandle_negPwr = PAC193X_I2C_TRANSFER_HANDLE_INVALID; 
        pdevice->processingState = Idle;
        return PAC193X_I2C_INVALID_PARAM;
    }
    
    //wait here for the request processing completion if the library is in SYNC mode
    if(pdevice->syncMode == true){ 
        while (pdevice->processingState != Sync);
        pdevice->processingState = Idle;     //the request is fully completed here
        if( pdevice->deviceEventStatus != PAC193X_EVENT_REQUEST_COMPLETE ){
            return PAC193X_REQUEST_FAIL;
        }
    }    
    
    return PAC193X_SUCCESS;
}


int16_t PAC193x_GetISENSEn_AVG_mAProcess(PAC193X_PDEVICE_CONTEXT pdevice){
    uint8_t* pRawValue;
    uint16_t VsenseRaw;
    float VsenseReal;
    float IsenseReal;
    float IsenseUnit;
    
    pRawValue = pdevice->i2cRxBuffer;
    if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) pRawValue++;
    
    VsenseRaw = ((uint16_t)pRawValue[0] << 8) | (uint16_t)pRawValue[1];
    IsenseUnit = pdevice->IsenseLSB[pdevice->channelNo-1];
    if(pdevice->IsSignedVsense[pdevice->channelNo-1] == 1){
        VsenseReal = (float)((short)VsenseRaw);
        IsenseUnit *= 2;
    }else{
        VsenseReal = (float)VsenseRaw;
    }
    
    IsenseReal = VsenseReal * IsenseUnit;

    *((float*)pdevice->outData) = IsenseReal;
            
    return PAC193X_SUCCESS;
}


int16_t PAC193x_GetVPOWERn_reg(PAC193X_PDEVICE_CONTEXT pdevice, uint8_t channelNo, uint32_t* pregister_val){
    uint8_t registerAddr;
    
    if (pdevice == NULL) return PAC193X_INVALID_PARAMETER;
    
    // check if new device request is allowed
    // lock the processingState mutex
    if( PAC193x_MUTEX_Lock(&(pdevice->mutexProcState)) == false )    
    {
        return PAC193X_MUTEX_FAIL;
    }
    
    if(pdevice->processingState == Idle){
        // start new request 
        pdevice->processingState = GetVPOWERnRegisterReq;
        pdevice->deviceEventStatus = PAC193X_EVENT_NO_EVENT;
        PAC193x_MUTEX_Unlock(&(pdevice->mutexProcState));        
    }else
    {
        // reject new request
        PAC193x_MUTEX_Unlock(&(pdevice->mutexProcState));        
        return PAC193X_BUSY;
    }
    
    pdevice->outData = (void*)pregister_val;
    switch(channelNo){
        case 1:
            registerAddr = PAC193X_VPOWER1_ADDR;
            break;
        case 2:
            registerAddr = PAC193X_VPOWER2_ADDR;
            break;
        case 3:
            registerAddr = PAC193X_VPOWER3_ADDR;
            break;
        case 4:
            registerAddr = PAC193X_VPOWER4_ADDR;
            break;
        default:
            pdevice->processingState = Idle;
            return PAC193X_INVALID_PARAMETER;      
    }
    pdevice->i2cTxBuffer[0] = registerAddr;
    pdevice->channelNo = channelNo;
    pdevice->transferHandle = PAC193X_I2C_TRANSFER_HANDLE_INVALID;
    
    unsigned int i2cRxSize = PAC193X_VPOWERN_SZ;
    if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) i2cRxSize++;  
    PAC193x_I2C_WriteReadTransferAdd(pdevice, (void*) pdevice->i2cTxBuffer, 1, (void*) pdevice->i2cRxBuffer, i2cRxSize, &(pdevice->transferHandle));    
    if(pdevice->transferHandle == PAC193X_I2C_TRANSFER_HANDLE_INVALID)
    {
        // Error handling here
        pdevice->processingState = Idle;
        return PAC193X_I2C_INVALID_PARAM;
    }
    
    //wait here for the request processing completion if the library is in SYNC mode
    if(pdevice->syncMode == true){ 
        while (pdevice->processingState != Sync);
        pdevice->processingState = Idle;     //the request is fully completed here
        if( pdevice->deviceEventStatus != PAC193X_EVENT_REQUEST_COMPLETE ){
            return PAC193X_REQUEST_FAIL;
        }
    }    
    
    return PAC193X_SUCCESS;
}


int16_t PAC193x_GetVPOWERn_regProcess(PAC193X_PDEVICE_CONTEXT pdevice){
    uint8_t* pRawValue;
    uint32_t regVal;
    
    pRawValue = pdevice->i2cRxBuffer;
    if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) pRawValue++;
    
    regVal = ((uint32_t)pRawValue[0] << 8) | (uint32_t)pRawValue[1];
    regVal = (regVal << 8) | (uint32_t)pRawValue[2];
    regVal = (regVal << 8) | (uint32_t)pRawValue[3];

    *((uint32_t*)pdevice->outData) = regVal;
    
    return PAC193X_SUCCESS;
}

// pvalue reported as milli-Watt
int16_t PAC193x_GetVPOWERn_mW(PAC193X_PDEVICE_CONTEXT pdevice, uint8_t channelNo, float* pvalue){
    uint8_t registerAddr;
    int16_t errorCode = PAC193X_SUCCESS;
    
    if (pdevice == NULL) return PAC193X_INVALID_PARAMETER;
    
    // validate channelNo parameter
    if ( (channelNo == 0) || (channelNo > pdevice->HwChannels) ){
        errorCode = PAC193X_INVALID_PARAMETER;
        return errorCode;       
    }  
    
    // channel shunt value must be non-zero
    if (pdevice->rsense[channelNo-1] == 0) return PAC193X_INVALID_SHUNT_VALUE;    
    
    // check if new device request is allowed
    // lock the processingState mutex
    if( PAC193x_MUTEX_Lock(&(pdevice->mutexProcState)) == false )    
    {
        return PAC193X_MUTEX_FAIL;
    }
    
    if(pdevice->processingState == Idle){
        // start new request 
        pdevice->processingState = GetVPOWERnValueReq;
        pdevice->deviceEventStatus = PAC193X_EVENT_NO_EVENT;
        PAC193x_MUTEX_Unlock(&(pdevice->mutexProcState));        
    }else
    {
        // reject new request
        PAC193x_MUTEX_Unlock(&(pdevice->mutexProcState));        
        return PAC193X_BUSY;
    }
    
    switch(channelNo){
        case 1:
            registerAddr = PAC193X_VPOWER1_ADDR;
            break;
        case 2:
            registerAddr = PAC193X_VPOWER2_ADDR;
            break;
        case 3:
            registerAddr = PAC193X_VPOWER3_ADDR;
            break;
        case 4:
            registerAddr = PAC193X_VPOWER4_ADDR;
            break;
        default:
            pdevice->processingState = Idle;
            return PAC193X_INVALID_PARAMETER;      
    }
    
    pdevice->channelNo = channelNo;
    
    //Read NegPwr
    errorCode = PAC193x_UpdateContext_ChannelPolarity((PAC193X_PDEVICE_CONTEXT)pdevice);
    if (errorCode == PAC193X_I2C_INVALID_PARAM)
    {
        pdevice->processingState = Idle;
        return errorCode;
    }
    
    pdevice->outData = (void*)pvalue;
    
    pdevice->i2cTxBuffer[0] = registerAddr;
    
    pdevice->transferHandle = PAC193X_I2C_TRANSFER_HANDLE_INVALID;
    
    unsigned int i2cRxSize = PAC193X_VPOWERN_SZ;
    if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) i2cRxSize++;   
    PAC193x_I2C_WriteReadTransferAdd(pdevice, (void*) pdevice->i2cTxBuffer, 1, (void*) pdevice->i2cRxBuffer, i2cRxSize, &(pdevice->transferHandle));    
    if(pdevice->transferHandle == PAC193X_I2C_TRANSFER_HANDLE_INVALID)
    {
        // Error handling here
        // discard any pending i2c transfer
        pdevice->transferHandle_negPwr = PAC193X_I2C_TRANSFER_HANDLE_INVALID;        
        pdevice->processingState = Idle;
        return PAC193X_I2C_INVALID_PARAM;
    }
    
    //wait here for the request processing completion if the library is in SYNC mode
    if(pdevice->syncMode == true){ 
        while (pdevice->processingState != Sync);
        pdevice->processingState = Idle;     //the request is fully completed here
        if( pdevice->deviceEventStatus != PAC193X_EVENT_REQUEST_COMPLETE ){
            return PAC193X_REQUEST_FAIL;
        }
    }    
    
    return PAC193X_SUCCESS;
}


int16_t PAC193x_GetVPOWERn_mWProcess(PAC193X_PDEVICE_CONTEXT pdevice){
    uint8_t* pRawValue;
    uint32_t regVal;
    uint32_t VpowerRaw;
    float VpowerReal, PowerUnit;
    
    pRawValue = pdevice->i2cRxBuffer;
    
    if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) pRawValue++;
    
    regVal = ((uint32_t)pRawValue[0] << 8) | (uint32_t)pRawValue[1];
    regVal = (regVal << 8) | (uint32_t)pRawValue[2];
    regVal = (regVal << 8) | (uint32_t)pRawValue[3];
    
    VpowerRaw = regVal;
    PowerUnit = pdevice->VPowerLSB[pdevice->channelNo-1];
    if(pdevice->IsSignedPower[pdevice->channelNo-1] == 1){
        VpowerReal = (float)((int32_t)VpowerRaw);
        PowerUnit *= 2;
    }else{
        VpowerReal = (float)VpowerRaw;
    }
    
    VpowerReal = (VpowerReal * PowerUnit) / 16;

    *((float*)pdevice->outData) = VpowerReal;
    
    return PAC193X_SUCCESS;
}


int16_t PAC193x_GetChannelDisSMBus_reg(PAC193X_PDEVICE_CONTEXT pdevice, PAC193X_PCHANNEL_DIS_SMBUS_REGISTER pChDisSMBus_reg){
    
    if (pdevice == NULL) return PAC193X_INVALID_PARAMETER;
    
    // check if new device request is allowed
    // lock the processingState mutex
    if( PAC193x_MUTEX_Lock(&(pdevice->mutexProcState)) == false )    
    {
        return PAC193X_MUTEX_FAIL;
    }
    
    if(pdevice->processingState == Idle){
        // start new request 
        pdevice->processingState = GetChDisRegisterReq;
        pdevice->deviceEventStatus = PAC193X_EVENT_NO_EVENT;
        PAC193x_MUTEX_Unlock(&(pdevice->mutexProcState));        
    }else
    {
        // reject new request
        PAC193x_MUTEX_Unlock(&(pdevice->mutexProcState));        
        return PAC193X_BUSY;
    }
    
    pdevice->outData = (void*)pChDisSMBus_reg;
    pdevice->i2cTxBuffer[0] = PAC193X_CHANNEL_DIS_ADDR;
    pdevice->transferHandle = PAC193X_I2C_TRANSFER_HANDLE_INVALID;
    unsigned int i2cRxSize = PAC193X_CH_DIS_SZ;
    if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) i2cRxSize++;    
    PAC193x_I2C_WriteReadTransferAdd(pdevice, (void*) pdevice->i2cTxBuffer, 1, (void*) pdevice->i2cRxBuffer, i2cRxSize, &(pdevice->transferHandle));        
    if(pdevice->transferHandle == PAC193X_I2C_TRANSFER_HANDLE_INVALID)
    {
        // Error handling here
        pdevice->processingState = Idle;
        return PAC193X_I2C_INVALID_PARAM;
    }
    
    //wait here for the request processing completion if the library is in SYNC mode
    if(pdevice->syncMode == true){ 
        while (pdevice->processingState != Sync);
        pdevice->processingState = Idle;     //the request is fully completed here
        if( pdevice->deviceEventStatus != PAC193X_EVENT_REQUEST_COMPLETE ){
            return PAC193X_REQUEST_FAIL;
        }
    }    
    
    return PAC193X_SUCCESS;
}


int16_t PAC193x_GetChannelDisSMBus_regProcess(PAC193X_PDEVICE_CONTEXT pdevice){
    uint8_t* pRawValue;
    
    pRawValue = pdevice->i2cRxBuffer;
    if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) pRawValue++;
    *((uint8_t*)pdevice->outData) = pRawValue[0];
    
    // cache the BYTE_COUNT flag into device context
    pdevice->ENABLE_BYTE_COUNT_FLAG = ( ((PAC193X_PCHANNEL_DIS_SMBUS_REGISTER)(pdevice->outData))->BYTE_COUNT == 1 ) ? true: false;    
    
    return PAC193X_SUCCESS; 
}


int16_t PAC193x_SetChannelDisSMBus_reg(PAC193X_PDEVICE_CONTEXT pdevice, PAC193X_CHANNEL_DIS_SMBUS_REGISTER ChDisSMBus_reg){
    void *pwriteBuffer;
    if (pdevice == NULL) return PAC193X_INVALID_PARAMETER;
    
    // check if new device request is allowed
    // lock the processingState mutex
    if( PAC193x_MUTEX_Lock(&(pdevice->mutexProcState)) == false )    
    {
        return PAC193X_MUTEX_FAIL;
    }
    
    if(pdevice->processingState == Idle){
        // start new request 
        pdevice->processingState = SetChDisRegisterReq;
        pdevice->deviceEventStatus = PAC193X_EVENT_NO_EVENT;
        PAC193x_MUTEX_Unlock(&(pdevice->mutexProcState));        
    }else
    {
        // reject new request
        PAC193x_MUTEX_Unlock(&(pdevice->mutexProcState));        
        return PAC193X_BUSY;
    }
    
    pwriteBuffer = &ChDisSMBus_reg;
    pdevice->i2cTxBuffer[0] = PAC193X_CHANNEL_DIS_ADDR;
    memcpy( (pdevice->i2cTxBuffer)+1, (uint8_t*)pwriteBuffer, sizeof(PAC193X_CHANNEL_DIS_SMBUS_REGISTER));   
    pdevice->transferHandle = PAC193X_I2C_TRANSFER_HANDLE_INVALID;
    PAC193x_I2C_WriteTransferAdd(pdevice, (void*) pdevice->i2cTxBuffer, 2, &(pdevice->transferHandle));
    if(pdevice->transferHandle == PAC193X_I2C_TRANSFER_HANDLE_INVALID)
    {
        // Error handling here
        pdevice->processingState = Idle;
        return PAC193X_I2C_INVALID_PARAM;
    }
     
    //wait here for the request processing completion if the library is in SYNC mode
    if(pdevice->syncMode == true){ 
        while (pdevice->processingState != Sync);
        pdevice->processingState = Idle;     //the request is fully completed here
        if( pdevice->deviceEventStatus != PAC193X_EVENT_REQUEST_COMPLETE ){
            return PAC193X_REQUEST_FAIL;
        }
    }    
    
    return PAC193X_SUCCESS;
}


int16_t PAC193x_SetChannelDisSMBus_regProcess(PAC193X_PDEVICE_CONTEXT pdevice){
    void *pwriteBuffer;
    
    pwriteBuffer = (void*)(pdevice->i2cTxBuffer + 1);   //address of the value just written into PAC193X_CHANNEL_DIS_SMBUS_REGISTER
    
    // cache the BYTE_COUNT flag into device context
    pdevice->ENABLE_BYTE_COUNT_FLAG = ( ((PAC193X_PCHANNEL_DIS_SMBUS_REGISTER)(pwriteBuffer))->BYTE_COUNT == 1 ) ? true: false;    
    
    return PAC193X_SUCCESS; 
}


int16_t PAC193x_GetNegPwr_reg(PAC193X_PDEVICE_CONTEXT pdevice, uint8_t reg_select, PAC193X_PNEG_PWR_REGISTER pNegPwr_reg){
    uint8_t registerAddr;
    
    if (pdevice == NULL) return PAC193X_INVALID_PARAMETER;
    
    switch(reg_select){
        case 1:
            registerAddr = PAC193X_NEG_PWR_ADDR;
            break;
        case 2:
            registerAddr = PAC193X_NEG_PWR_ACT_ADDR;
            break;
        case 3:
            registerAddr = PAC193X_NEG_PWR_LAT_ADDR;
            break;
        default:
            return PAC193X_INVALID_PARAMETER;      
    }    
    
    // check if new device request is allowed
    // lock the processingState mutex
    if( PAC193x_MUTEX_Lock(&(pdevice->mutexProcState)) == false )    
    {
        return PAC193X_MUTEX_FAIL;
    }
    
    if(pdevice->processingState == Idle){
        // start new request 
        pdevice->processingState = GetNegPWRRegisterReq;
        pdevice->deviceEventStatus = PAC193X_EVENT_NO_EVENT;
        PAC193x_MUTEX_Unlock(&(pdevice->mutexProcState));        
    }else
    {
        // reject new request
        PAC193x_MUTEX_Unlock(&(pdevice->mutexProcState));        
        return PAC193X_BUSY;
    }
    
    pdevice->outData = (void*)pNegPwr_reg;
    pdevice->i2cTxBuffer_negPwr[0] = registerAddr;
    pdevice->transferHandle_negPwr = PAC193X_I2C_TRANSFER_HANDLE_INVALID;
    
    unsigned int i2cRxSize = PAC193X_NEG_PWR_SZ;
    if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) i2cRxSize++;   
    PAC193x_I2C_WriteReadTransferAdd(pdevice, (void*) pdevice->i2cTxBuffer_negPwr, 1, (void*) pdevice->i2cRxBuffer_negPwr, i2cRxSize, &(pdevice->transferHandle_negPwr));        
    if(pdevice->transferHandle_negPwr == PAC193X_I2C_TRANSFER_HANDLE_INVALID)
    {
        // Error handling here
        pdevice->processingState = Idle;
        return PAC193X_I2C_INVALID_PARAM;
    }
    
    //wait here for the request processing completion if the library is in SYNC mode
    if(pdevice->syncMode == true){ 
        while (pdevice->processingState != Sync);
        pdevice->processingState = Idle;     //the request is fully completed here
        if( pdevice->deviceEventStatus != PAC193X_EVENT_REQUEST_COMPLETE ){
            return PAC193X_REQUEST_FAIL;
        }
    }    
    
    return PAC193X_SUCCESS;  
}


int16_t PAC193x_GetNegPwr_regProcess(PAC193X_PDEVICE_CONTEXT pdevice){
    uint8_t* pRawValue;
    pRawValue = pdevice->i2cRxBuffer_negPwr;
    if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) pRawValue++;    
    *((uint8_t*)pdevice->outData) = pRawValue[0];
    
    if(pdevice->i2cTxBuffer_negPwr[0] == PAC193X_NEG_PWR_LAT_ADDR){
        PAC193x_UpdateContext_ChannelPolarityProcess((PAC193X_PDEVICE_CONTEXT)pdevice);  
    }
    
    return PAC193X_SUCCESS;   
}


int16_t PAC193x_SetNegPwr_reg(PAC193X_PDEVICE_CONTEXT pdevice, PAC193X_NEG_PWR_REGISTER NegPwr_reg){
    void *pwriteBuffer;
    if (pdevice == NULL) return PAC193X_INVALID_PARAMETER;
    
    // check if new device request is allowed
    // lock the processingState mutex
    if( PAC193x_MUTEX_Lock(&(pdevice->mutexProcState)) == false )    
    {
        return PAC193X_MUTEX_FAIL;
    }
    
    if(pdevice->processingState == Idle){
        // start new request 
        pdevice->processingState = SetNegPWRRegisterReq;
        pdevice->deviceEventStatus = PAC193X_EVENT_NO_EVENT;
        PAC193x_MUTEX_Unlock(&(pdevice->mutexProcState));        
    }else
    {
        // reject new request
        PAC193x_MUTEX_Unlock(&(pdevice->mutexProcState));        
        return PAC193X_BUSY;
    }
    
    pwriteBuffer = &NegPwr_reg;
    pdevice->i2cTxBuffer[0] = PAC193X_NEG_PWR_ADDR;
    memcpy( (pdevice->i2cTxBuffer)+1, (uint8_t*)pwriteBuffer, sizeof(PAC193X_NEG_PWR_REGISTER));   
    pdevice->transferHandle = PAC193X_I2C_TRANSFER_HANDLE_INVALID;  
    PAC193x_I2C_WriteTransferAdd(pdevice, (void*) pdevice->i2cTxBuffer, 2, &(pdevice->transferHandle));        
    if(pdevice->transferHandle == PAC193X_I2C_TRANSFER_HANDLE_INVALID)
    {
        // Error handling here
        pdevice->processingState = Idle;
        return PAC193X_I2C_INVALID_PARAM;
    }
       
    //wait here for the request processing completion if the library is in SYNC mode
    if(pdevice->syncMode == true){ 
        while (pdevice->processingState != Sync);
        pdevice->processingState = Idle;     //the request is fully completed here
        if( pdevice->deviceEventStatus != PAC193X_EVENT_REQUEST_COMPLETE ){
            return PAC193X_REQUEST_FAIL;
        }
    }    
    
    return PAC193X_SUCCESS;  
}


int16_t PAC193x_GetSlow_reg(PAC193X_PDEVICE_CONTEXT pdevice, PAC193X_PSLOW_REGISTER pSlow_reg){
    
    if (pdevice == NULL) return PAC193X_INVALID_PARAMETER;
    
    // check if new device request is allowed
    // lock the processingState mutex
    if( PAC193x_MUTEX_Lock(&(pdevice->mutexProcState)) == false )    
    {
        return PAC193X_MUTEX_FAIL;
    }
    
    if(pdevice->processingState == Idle){
        // start new request 
        pdevice->processingState = GetSlowRegisterReq;
        pdevice->deviceEventStatus = PAC193X_EVENT_NO_EVENT;
        PAC193x_MUTEX_Unlock(&(pdevice->mutexProcState));        
    }else
    {
        // reject new request
        PAC193x_MUTEX_Unlock(&(pdevice->mutexProcState));        
        return PAC193X_BUSY;
    }
    
    pdevice->outData = (void*)pSlow_reg;
    pdevice->i2cTxBuffer[0] = PAC193X_SLOW_ADDR;
    pdevice->transferHandle = PAC193X_I2C_TRANSFER_HANDLE_INVALID;
    unsigned int i2cRxSize = PAC193X_SLOW_SZ;
    if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) i2cRxSize++;   
    PAC193x_I2C_WriteReadTransferAdd(pdevice, (void*) pdevice->i2cTxBuffer, 1, (void*) pdevice->i2cRxBuffer, i2cRxSize, &(pdevice->transferHandle));        
    if(pdevice->transferHandle == PAC193X_I2C_TRANSFER_HANDLE_INVALID)
    {
        // Error handling here
        pdevice->processingState = Idle;
        return PAC193X_I2C_INVALID_PARAM;
    }
    
    //wait here for the request processing completion if the library is in SYNC mode
    if(pdevice->syncMode == true){ 
        while (pdevice->processingState != Sync);
        pdevice->processingState = Idle;     //the request is fully completed here
        if( pdevice->deviceEventStatus != PAC193X_EVENT_REQUEST_COMPLETE ){
            return PAC193X_REQUEST_FAIL;
        }
    }    
    
    return PAC193X_SUCCESS;
}


int16_t PAC193x_GetSlow_regProcess(PAC193X_PDEVICE_CONTEXT pdevice){
    uint8_t* pRawValue;
    
    pRawValue = pdevice->i2cRxBuffer;
    if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) pRawValue++;
    
    *((uint8_t*)pdevice->outData) = pRawValue[0];
    
    return PAC193X_SUCCESS;     
}


int16_t PAC193x_SetSlow_reg(PAC193X_PDEVICE_CONTEXT pdevice, PAC193X_SLOW_REGISTER Slow_reg){
    void *pwriteBuffer;
    if (pdevice == NULL) return PAC193X_INVALID_PARAMETER;
    
    // check if new device request is allowed
    // lock the processingState mutex
    if( PAC193x_MUTEX_Lock(&(pdevice->mutexProcState)) == false )    
    {
        return PAC193X_MUTEX_FAIL;
    }
    
    if(pdevice->processingState == Idle){
        // start new request 
        pdevice->processingState = SetSlowRegisterReq;
        pdevice->deviceEventStatus = PAC193X_EVENT_NO_EVENT;
        PAC193x_MUTEX_Unlock(&(pdevice->mutexProcState));        
    }else
    {
        // reject new request
        PAC193x_MUTEX_Unlock(&(pdevice->mutexProcState));        
        return PAC193X_BUSY;
    }
    
    pwriteBuffer = &Slow_reg;
    pdevice->i2cTxBuffer[0] = PAC193X_SLOW_ADDR;
    memcpy( (pdevice->i2cTxBuffer)+1, (uint8_t*)pwriteBuffer, sizeof(PAC193X_SLOW_REGISTER));   
    pdevice->transferHandle = PAC193X_I2C_TRANSFER_HANDLE_INVALID;
    PAC193x_I2C_WriteTransferAdd(pdevice, (void*) pdevice->i2cTxBuffer, 2, &(pdevice->transferHandle));        
    if(pdevice->transferHandle == PAC193X_I2C_TRANSFER_HANDLE_INVALID)
    {
        // Error handling here
        pdevice->processingState = Idle;
        return PAC193X_I2C_INVALID_PARAM;
    }
       
    //wait here for the request processing completion if the library is in SYNC mode
    if(pdevice->syncMode == true){ 
        while (pdevice->processingState != Sync);
        pdevice->processingState = Idle;     //the request is fully completed here
        if( pdevice->deviceEventStatus != PAC193X_EVENT_REQUEST_COMPLETE ){
            return PAC193X_REQUEST_FAIL;
        }
    }    
    
    return PAC193X_SUCCESS; 
}


int16_t PAC193x_UpdateContext_ChannelPolarity(PAC193X_PDEVICE_CONTEXT pdevice){
    uint8_t registerAddr;
    uint16_t errorCode = PAC193X_SUCCESS;

    // Check if the cached negPwrFsr_LAT is valid
    if(pdevice->negPwr_LAT_cached == false){
        registerAddr = PAC193X_NEG_PWR_LAT_ADDR;
                
        pdevice->i2cTxBuffer_negPwr[0] = registerAddr;
        pdevice->transferHandle_negPwr = PAC193X_I2C_TRANSFER_HANDLE_INVALID;
        
        unsigned int i2cRxSize = PAC193X_NEG_PWR_SZ;
        if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) i2cRxSize++;  
        PAC193x_I2C_WriteReadTransferAdd(pdevice, (void*) pdevice->i2cTxBuffer_negPwr, 1, (void*) pdevice->i2cRxBuffer_negPwr, i2cRxSize, &(pdevice->transferHandle_negPwr));            
        if(pdevice->transferHandle_negPwr == PAC193X_I2C_TRANSFER_HANDLE_INVALID)
        {
            // Error handling here
            return PAC193X_I2C_INVALID_PARAM;
        }
    }
    else
    {
        errorCode = PAC193X_ALREADY_CACHED;
    }
    
   return errorCode; 
}


int16_t PAC193x_UpdateContext_ChannelPolarityProcess(PAC193X_PDEVICE_CONTEXT pdevice){
    uint8_t* pRawValue;
    void *pBuffer;
    uint8_t isSignedPower = 0;
    uint8_t isSignedVbus = 0;
    uint8_t isSignedVsense = 0;
    uint8_t cfgVSense = 0;
    uint8_t cfgVBus = 0;
    
    uint16_t errorCode = PAC193X_SUCCESS;
    int channelNo;
    
    pRawValue = pdevice->i2cRxBuffer_negPwr;
    if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) pRawValue++;
    
    pBuffer = &(pdevice->negPwr_LAT);
    *((uint8_t*)pBuffer) = pRawValue[0];
    pdevice->negPwr_LAT_cached = true;
    
    // Update the cached channel polarity info
    //
    // Check the cached NEG_PWR register.
    // - If either VSense or VBus is bipolar, the chanel is bipolar
    // - If either VSense or VBus is FSR/2, the channel is "FSR/2 mode" and bipolar
    //
    for(channelNo = 1; channelNo <= pdevice->HwChannels; channelNo++){
        switch (channelNo){ 
            case 1:{
                cfgVSense = pdevice->negPwr_LAT.CH1_BIDI;     // NegPwr.CH1_BIDI;
                cfgVBus = pdevice->negPwr_LAT.CH1_BIDV;       // NegPwr.CH1_BIDV;
                break;
            }

            case 2:{
                cfgVSense = pdevice->negPwr_LAT.CH2_BIDI;     // NegPwr.CH2_BIDI;
                cfgVBus = pdevice->negPwr_LAT.CH2_BIDV;       // NegPwr.CH2_BIDV;

                break;
            }

            case 3:{
                cfgVSense = pdevice->negPwr_LAT.CH3_BIDI;     // NegPwr.CH3_BIDI;
                cfgVBus = pdevice->negPwr_LAT.CH3_BIDV;       // NegPwr.CH3_BIDV;
                break;
            }

            case 4:{
                cfgVSense = pdevice->negPwr_LAT.CH4_BIDI;     // NegPwr.CH4_BIDI;
                cfgVBus = pdevice->negPwr_LAT.CH4_BIDV;       // NegPwr.CH4_BIDV;
                break;
            }

            default:{
                errorCode = PAC193X_INVALID_PARAMETER;
                return errorCode;   
            }
        }

        isSignedPower = 0;
        isSignedVbus = 0;
        isSignedVsense = 0;        
        
        if ( cfgVSense  != 0x0) {
            isSignedPower  = 1;     // either Vbus or Vsense are bipolar or FSR/2
            isSignedVsense = 1;     // Vsense is bipolar
        }

        if ( cfgVBus != 0x0) {
            isSignedPower = 1;      // either Vbus or Vsense are bipolar or FSR/2
            isSignedVbus  = 1;      // Vbus is bipolar
        }    

        (pdevice->IsSignedPower[channelNo - 1]) = isSignedPower;
        (pdevice->IsSignedVsense[channelNo - 1]) = isSignedVsense;
        (pdevice->IsSignedVbus[channelNo - 1]) = isSignedVbus;
    }
    
    return PAC193X_SUCCESS;
}


int16_t PAC193x_UpdateContext_Ctrl(PAC193X_PDEVICE_CONTEXT pdevice){
    uint16_t errorCode = PAC193X_SUCCESS;
    uint8_t registerAddr;
         
    //check if cached CTRL_LAT is valid
    //if NOT valid, update the cache
    if(pdevice->ctrl_LAT_cached == false){
        registerAddr = PAC193X_CTRL_LAT_ADDR;
        pdevice->i2cTxBuffer_ctrl[0] = registerAddr;
        pdevice->transferHandle_ctrl = PAC193X_I2C_TRANSFER_HANDLE_INVALID;
        
        unsigned int i2cRxSize = PAC193X_CTRL_SZ;
        if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) i2cRxSize++;   
        PAC193x_I2C_WriteReadTransferAdd(pdevice, (void*) pdevice->i2cTxBuffer_ctrl, 1, (void*) pdevice->i2cRxBuffer_ctrl, i2cRxSize, &(pdevice->transferHandle_ctrl));            
        if(pdevice->transferHandle_ctrl == PAC193X_I2C_TRANSFER_HANDLE_INVALID)
        {
            // Error handling here
            return PAC193X_I2C_INVALID_PARAM;
        }
    }
    else
    {
        errorCode = PAC193X_ALREADY_CACHED;
    }
    
    return errorCode;
}

int16_t PAC193x_UpdateContext_CtrlProcess(PAC193X_PDEVICE_CONTEXT pdevice){
    uint8_t* pRawValue;
    void *pBuffer;
    
    pRawValue = pdevice->i2cRxBuffer_ctrl;
    if(pdevice->ENABLE_BYTE_COUNT_FLAG == true) pRawValue++;
    
    pBuffer = &(pdevice->ctrl_LAT);
    *((uint8_t*)pBuffer) = pRawValue[0];
    //update the cached sample rate
    switch(pdevice->ctrl_LAT.SAMPLE_RATE){
        case 0:
            pdevice->sampleRate = 1024;
            break;
        case 1:
            pdevice->sampleRate = 256;
            break;
        case 2:
            pdevice->sampleRate = 64;
            break;
        case 3:
            pdevice->sampleRate = 8;
            break;
    }    
    pdevice->ctrl_LAT_cached = true;
    
    return PAC193X_SUCCESS;
}