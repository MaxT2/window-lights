arduino-cli compile -b arduino:avr:nano
arduino-cli upload -b arduino:avr:nano:cpu=atmega328old -p /dev/ttyUSB0 -t -v
