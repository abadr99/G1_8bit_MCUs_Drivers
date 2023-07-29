# !/bin/bash/

# remove installed binaries
sudo apt remove avr-libc 
sudo apt remove gcc-avr
sudo apt remove binutils-avr
# remove binaries
make clean -C C
