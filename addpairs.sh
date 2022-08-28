#!/bin/sh

cppfile=$1
ext=${cppfile#*.}

if [ "$ext" = "cpp" ] || [ "$ext" = "java" ]
then

  # avoid unexpected overwrite
  if [ ! -f $cppfile ]
  then # flush header and clipboard
  
    printf "#include <local_leetcode.hpp>\n\n" >> ${cppfile}

    # wsl or not
    if [ -x "$(command -v powershell.exe)" ]
    then
      template=$(powershell.exe -Command get-clipboard)
    else
      template=$(xclip -selection c -o)
    fi

    # remove line numbers
    template=$(echo "$template" | sed -E 's/^[0-9]+//')
    
    printf "${template}" >> $cppfile;
    # create main() and flush
    method=$(echo $template | sed -E 's/.*[a-zA-Z<>\\*]+\s([a-zA-Z]+)\s?\(.*/\1/')
    printf "\n\n\nint main() {\n  EXECS(Solution::${method});\n  return 0;\n}" >> ${cppfile}
  fi

  # create input file
  txtfile="Inputs/${cppfile%.*}.txt"
  touch -m $txtfile
  if [ -x "$(command -v code)" ]
  then
    # open $cppfile first and return to it last
    code $cppfile
    code $txtfile
    code $cppfile
  fi
fi