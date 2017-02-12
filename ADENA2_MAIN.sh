#!/bin/bash

while [ 1 ]; do
	clear
#	Header
	echo -e "\n"
	echo -e "  \e[1;33m####################################################\e[0m"
	echo -e "  \e[1;33m#                                                  #\e[0m"
	echo -e "  \e[1;33m#                \e[1;37m     ADENA 2    \e[1;33m                  #\e[0m"
	echo -e "  \e[1;33m#                                                  #\e[0m"
	echo -e "  \e[1;33m####################################################\e[0m"

#	List most recent data
	NEWSNAP=$(ls /var/www/html/stills | sort -gr | sed -n 1p)
#	else; NEWSNAP="NO IMAGE DATA"
	COMPDATA=$(less /ADENA2/sensors/compass/comp_readings.txt | tail -1)
#	else; COMPDATA="NO COMPASS DATA"
	TAPDATA=$(less /ADENA2/sensors/tap/tap_readings.txt | tail -1)
#	else; TAPDATA="NO SENSOR DATA"

	echo -e "\e[1;37m  -LATEST DATA-\e[0m"
	echo -e "  Compass heading: \e[1;37m$COMPDATA\e[0m"
	echo -e "  Temp, pres, alt: \e[1;37m$TAPDATA\e[0m"
	echo -e "  Image filename: \e[1;37m$NEWSNAP\e[0m"

#	Menu
	echo -e "\n  \e[1;37mHere are your options:\e[0m"
	echo -e "  \e[1;37mExample: f 10 -> drive forward for 10 seconds\e[0m"

	echo -e "\n\e[1;36m   KEY	ACTION\e[0m"
	echo -e "\e[1;37m  ( F )	Forward\e[0m"
	echo -e "\e[1;37m  ( B )	Backward\e[0m"
	echo -e "\e[1;37m  ( R )	Turn right\e[0m"
	echo -e "\e[1;37m  ( L )	Turn left\e[0m"
	echo -e "\e[1;37m  ( P )	Capture image\e[0m"
	echo -e "\e[1;37m  ( C )	Compass reading\e[0m"
	echo -e "\e[1;37m  ( S )	Sensor readings\e[0m"
	echo -e "  ( Q )	Quit\n"

        echo -n "#> _ __ "
        #echo -en "\b\b\b\b\b"
        tput cub 5
        read DIRECTION DURATION
        case $DIRECTION in

                F|f)python /ADENA2/motors/forward.py $DURATION & ;;
                B|b)python /ADENA2/motors/backward.py $DURATION & ;;
                R|r)python /ADENA2/motors/right.py $DURATION & ;;
                L|l)python /ADENA2/motors/left.py $DURATION & ;;
		P|p)export SNAPDATE=$(date +"%Y-%m-%d_%H:%M")
			/ADENA2/sensors/camera/snapshot.sh &
			echo -e "\n  Image filename: \e[1;37m$SNAPDATE\e[0m"
			sleep 3 ;;
		C|c)sudo python /ADENA2/sensors/compass/comp_display.py &
			sleep 3
			COMPDATA=$(less /ADENA2/sensors/compass/comp_readings.txt | tail -1)
			echo -e "\n  COMPASS HEADING:  \e[1;37m$COMPDATA\e[0m"
			sleep 5 ;;
		S|s)sudo python /ADENA2/sensors/tap/tap_display.py &
			sleep 3
			TAPDATA=$(less /ADENA2/sensors/tap/tap_readings.txt | tail -1)
			echo -e "\n  TEMP, PRES, ALT:  \e[1;37m$TAPDATA\e[0m"
			sleep 5 ;;
		Q|q)clear
			exit ;;
		*)	echo -e "\n  Please enter a valid selection... "
			sleep 2 ;;
		esac

	done
