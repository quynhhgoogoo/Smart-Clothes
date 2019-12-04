#!/bin/sh

while true	#This should be changeds as "when wifi connection do"
        do
                openssl enc -pass file:password -aes-256-cbc -in data -out encdata
                sftp pi@192.168.10.4: <<< $'put encdata' -yes	#IP needs to be changed to universal
                echo "File sent"
                sleep 20	#Time of sleep can be increased or decreased
        done
