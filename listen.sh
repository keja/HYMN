while true; do
	DEVICE="`ls /dev/ | grep cu.usbmodem | awk '{print $1}'`"
	if [ "${DEVICE}" != "" ]; then
		clear
		echo "Connected to: ${DEVICE}"
		echo "Listing for incoming events"
		cat /dev/${DEVICE} #> tmp.innoevent
		#todo: http request on event.
	else
		clear
        echo "Awaiting logic board"
        sleep 1
	fi
done
