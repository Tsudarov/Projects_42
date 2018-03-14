#!/bin/sh
ldapsearch -Q sn | grep -i 'sn: bon' | sed "s/sn: //g" | wc -l | bc
