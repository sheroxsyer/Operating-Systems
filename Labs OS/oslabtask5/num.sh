#!/bin/bash

LOG_FILE="/var/log/num.log"
echo "printed at $(date)" >> "/var/log/num.log"

for ((i=2; i<=20; i+=2)); 
do
    echo $i  >> "/var/log/num.log"
done
echo "____________________" >> "/var/log/num.log"
echo "even numbers from 1 to 20 have been written to $LOG_FILE." 


