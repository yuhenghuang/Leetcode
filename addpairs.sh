#!/bin/sh

cppfile=$1

cpppath="src/$cppfile"
ext=${cppfile#*.}

if [ "$ext" = "cpp" ] || [ "$ext" = "java" ]
then

  # avoid unexpected overwrite
  if [ ! -f $cpppath ]
  then # flush header and clipboard
  
    printf "#include <local_leetcode.hpp>\n\n" >> ${cpppath}

    # wsl or not
    if [ -x "$(command -v powershell.exe)" ]
    then
      template=$(powershell.exe -Command get-clipboard)
    # macos or not
    elif [ -x "$(command -v pbpaste)" ]
    then
      template=$(pbpaste)
    else
      template=$(xclip -selection c -o)
    fi

    # remove line numbers
    template=$(echo "$template" | sed -E 's/^[0-9]+//')
    
    printf "${template}" >> $cpppath;
    # create main() and flush
    method=$(echo $template | sed -E 's/.*[a-zA-Z<>\\*]+\s([a-zA-Z]+)\s?\(.*/\1/')
    printf "\n\n\nint main() {\n  EXECS(Solution::${method});\n  return 0;\n}" >> ${cpppath}
  fi

  # create input file
  txtfile="Inputs/${cppfile%.*}.txt"
  touch -m $txtfile
  if [ -x "$(command -v code)" ]
  then
    # open $cppfile first and return to it last
    code $cpppath
    code $txtfile
    code $cpppath
  fi
fi
