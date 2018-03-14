#!/bin/sh
cat -$1 | grep 'Bomber' | grep 'Nicolas' | cut -c16-27
