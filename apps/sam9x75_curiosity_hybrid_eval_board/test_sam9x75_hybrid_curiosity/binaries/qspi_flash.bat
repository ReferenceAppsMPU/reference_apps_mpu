sam-ba -p serial -b sam9x75-curiosity -a qspiflash -c erase
sam-ba -p serial -b sam9x75-curiosity -a qspiflash -c writeboot:boot.bin -c verifyboot:boot.bin
sam-ba -p serial -b sam9x75-curiosity -a qspiflash -c write:harmony.bin:0x40000 -c verify:harmony.bin:0x40000
