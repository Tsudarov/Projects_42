#!/bin/sh
touch -A -000001 bomb.txt | stat bomb.txt | rev | cut -c100- | rev | cut -c67-
