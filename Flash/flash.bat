@echo off
title Weight Scale Installer

echo =====================================
echo      Weight Scale Firmware Tool
echo =====================================
echo.

echo Available COM Ports:
wmic path Win32_SerialPort get DeviceID,Description

echo.
set /p port=Enter COM port (e.g. COM9): 

echo.
echo Flashing firmware, please wait...
echo.

esptool.exe --chip esp32p4 --port %port% --baud 115200 write-flash 0x0 firmware.bin

echo.
echo =====================================
echo   Flash process completed
echo =====================================
pause