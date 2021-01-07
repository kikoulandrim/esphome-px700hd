# esphome-px700hd
esphome-projector-uart-custom-component

This is a esphome custom component to switch on and off a px700hd projector.
It also return the state of the ph700hd.

It only use the last 2 bytes returned by the px700hd.


The capture of the response to the state :

###########
##  OFF  ##
###########

[01:44:14][VV][uart_esp8266:132]:     Read 0b00000101 (0x05)
[01:44:14][VV][uart_esp8266:132]:     Read 0b00010100 (0x14)
[01:44:14][VV][uart_esp8266:132]:     Read 0b00000000 (0x00)
[01:44:14][VV][uart_esp8266:132]:     Read 0b00000011 (0x03)
[01:44:14][VV][uart_esp8266:132]:     Read 0b00000000 (0x00)
[01:44:14][VV][uart_esp8266:132]:     Read 0b00000000 (0x00)
[01:44:14][VV][uart_esp8266:132]:     Read 0b00000000 (0x00)
[01:44:14][VV][uart_esp8266:132]:     Read 0b00000000 (0x00)
[01:44:14][VV][uart_esp8266:132]:     Read 0b00010111 (0x17)

0x05 0x14 0x00 0x03 0x00 0x00 0x00 0x00 0x17

##########
##  ON  ##
##########

[01:45:44][VV][uart_esp8266:132]:     Read 0b00000101 (0x05)
[01:45:44][VV][uart_esp8266:132]:     Read 0b00010100 (0x14)
[01:45:44][VV][uart_esp8266:132]:     Read 0b00000000 (0x00)
[01:45:44][VV][uart_esp8266:132]:     Read 0b00000011 (0x03)
[01:45:44][VV][uart_esp8266:132]:     Read 0b00000000 (0x00)
[01:45:44][VV][uart_esp8266:132]:     Read 0b00000000 (0x00)
[01:45:44][VV][uart_esp8266:132]:     Read 0b00000000 (0x00)
[01:45:44][VV][uart_esp8266:132]:     Read 0b00000001 (0x01)
[01:45:44][VV][uart_esp8266:132]:     Read 0b00011000 (0x18)

#################
##  STARTING   ##
#################

[14:19:43][VV][uart_esp8266:132]:     Read 0b00000011 (0x03)
[14:19:43][VV][uart_esp8266:132]:     Read 0b00010100 (0x14)
[14:19:43][VV][uart_esp8266:132]:     Read 0b00000000 (0x00)
[14:19:43][VV][uart_esp8266:132]:     Read 0b00000000 (0x00)
[14:19:43][VV][uart_esp8266:132]:     Read 0b00000000 (0x00)
[14:19:43][VV][uart_esp8266:132]:     Read 0b00010100 (0x14)

##############
## STOPPING ##
##############

[14:21:03][VV][uart_esp8266:132]:     Read 0b00000011 (0x03)
[14:21:03][VV][uart_esp8266:132]:     Read 0b00010100 (0x14)
[14:21:03][VV][uart_esp8266:132]:     Read 0b00000000 (0x00)
[14:21:03][VV][uart_esp8266:132]:     Read 0b00000000 (0x00)
[14:21:03][VV][uart_esp8266:132]:     Read 0b00000000 (0x00)
[14:21:03][VV][uart_esp8266:132]:     Read 0b00010100 (0x14)
