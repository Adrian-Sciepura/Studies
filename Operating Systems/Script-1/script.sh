#!/bin/bash 
touch result.txt
grep "OK DOWNLOAD" cdlinux.ftp.log | cut -d '"' -f 2,4 | sort | uniq | cut -d '"' -f 1,2 >> result.txt
cut -d " " -f 1,7,9 cdlinux.www.log | grep "20.$" | cut -d ":" -f 2 | cut -d " " -f 1,2 >> result.txt
sort result.txt | uniq | cut -d " " -f 2 | cut -d '"' -f 2 | sed "s#.*/##" | grep "\.iso" | cut -d "F" -f 5 | cut -d "?" -f 1 | sort | uniq -c | sort -g 
rm result.txt
