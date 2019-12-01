#!/bin/sh

while true; do

        openssl enc -pass file:password -aes-128-cbc -in testfile -out enctestf$
        sftp pi@192.168.1.134: <<< $'put enctestfile'
        echo "File sent"
        sleep 20
done
