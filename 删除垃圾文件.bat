@echo off

:query 
set info="y"
set /p info=�Ƿ�ʼɾ�������ļ�?(y/n):
if /i "%info%" == "n" (goto end)
if /i "%info%" == "y" (goto begin)
goto query

:begin
del /Q *.sdf
rd /Q /S ipch
del /Q Debug\*.ilk
del /Q Debug\*.pdb
del /Q Release\*.ilk
del /Q Release\*.pdb

rd /Q /S Multi\Debug
rd /Q /S Multi\Release

pause
exit

:end
exit