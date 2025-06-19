Steps to run the demo on SAM9X75 Curiosity:
(i)  Copy the boot.bin and harmony.bin from binaries folder to a MicroSD Card.
(ii) Insert the SD card to J14 MicroSD slot on the SAM9X75 Curiosity development board.
(iii)Connect Waveshare 720*720 round MIPI display.
(iv) Press start button followed by the reset button.
(v)  The demo is ready.
(vi) To connect Wifi: Use the WIFI hotspot from mobile with Username:DEMO_AP & Password: password
(vii) MQTT server: broker.emqx.io
(viii) MQTT publish topic: $MCHP/Wireless/device02
       MQTT Subscribe topic: $MCHP/Wireless/device02
	   When publishing message: status ==> You will get status of the thermostat.
	                            Mode OFF ==> Thermostst mode set to OFF/ Check display
								Mode HOT ==> Thermostst mode set to HOT/ Check display
(ix) To connect to bluetooth use: "Microchip Bluetooth Data" mobile application downloaded from Google Play store.
     Send the message from bluetooth: status ==> You will receive status of the thermostat.
	                                  Mode OFF ==> Thermostst receive set to OFF/ Check display
								      Mode HOT ==> Thermostst receive set to HOT/ Check display   