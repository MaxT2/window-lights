
# kill all running putty processes to free the serial port
#killall putty

arduino-cli compile -b arduino:avr:nano
arduino-cli upload -b arduino:avr:nano:cpu=atmega328old -p /dev/ttyUSB0 -t -v

# start putty
# & causes it to run in the background so it doesn't block the terminal
#sudo putty /dev/ttyUSB0 -serial -sercfg 9600,8,n,1,N
