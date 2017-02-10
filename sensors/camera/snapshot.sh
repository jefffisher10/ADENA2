#!/bin/bash

raspistill -vf -hf -w 1000 -h 750 -n -o /var/www/html/stills/$SNAPDATE.jpg

# Testing:
# sudo touch "/var/www/html/stills/$SNAPDATE.jpg"
