#!/bin/bash

readonly BASE_PATH="input"
readonly POSTFIX=".txt"

if [ $# -eq 2 ]
then
	g++ $1 -o $2
	for number in {1..11..1}
	do
		./$2 "$BASE_PATH$number$POSTFIX"
	done
	rm -i $2
else
	echo "[Error] Enter <filename.cpp> <filename.out>"
fi
exit 0

