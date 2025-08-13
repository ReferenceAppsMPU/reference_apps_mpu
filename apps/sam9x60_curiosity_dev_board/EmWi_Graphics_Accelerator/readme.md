Graphics accelerator is an application developed to measure CPU Load and FPS using FreeRTOS:

Embedded Wizard with 100% CPU Load, achievable frame rate 58FPS :

Embedded Wizard with 48% CPU Load, achievable frame rate 26FPS :


Changes made:
(i) Included a MACRO FREERTOS in definitions.h
(ii) Task priority/periodicity of static void lAPP_Tasks(void *pvParameters) in app.c can be modified to achieve higher frame rate.
