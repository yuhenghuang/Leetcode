@echo off

:: cppfile and filename without extension
set cppfile=%1
set nefile=%~n1

:: echo "./addpairs.sh %cppfile%"
:: disabled last block of opening generated files
bash -c "./addpairs.bat.sh %cppfile%"

:: suppress useless errors
code %cppfile% 2>nul & code Inputs\%nefile%.txt 2>nul
