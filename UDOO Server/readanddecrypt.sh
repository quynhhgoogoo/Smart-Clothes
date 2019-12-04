#!/bin/sh

#this should be run in same folder data is received, this also needs inotify-tools installed
inotifywait -e attrib,close_write,moved_to,create -m. |
while read -r directory events filename; do
        if [ "$filename" = "encdata" ]; then

                openssl enc -d -pass file:password -aes-256-cbc -in encdata -out decdata
                rm encdata
                cat decdata
        fi
done