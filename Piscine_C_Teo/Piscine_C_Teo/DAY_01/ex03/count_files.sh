#!/bin/sh
Find . -type f -o -type d | wc -l | bc
