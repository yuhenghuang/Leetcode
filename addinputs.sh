#!/bin/sh

cppfile=$1
ext=${cppfile#*.}
if [ "$ext" = "cpp" ] || [ "$ext" = "java" ]
then
  txtfile="Inputs/${cppfile%.*}.txt"
  touch -m $txtfile
  printf "\"$txtfile\"" | xclip -selection c
  if [ -x "$(command -v code)" ]
  then
    code $txtfile
    # code $cppfile
  fi
fi
