
set MATLAB=F:\progs\matlab_2022

cd .

if "%1"=="" ("F:\progs\matlab_2022\bin\win64\gmake"  -f controller.mk all) else ("F:\progs\matlab_2022\bin\win64\gmake"  -f controller.mk %1)
@if errorlevel 1 goto error_exit

exit /B 0

:error_exit
echo The make command returned an error of %errorlevel%
exit /B 1