@echo off
TITLE Bienvenid@ %USERNAME%
:inicio 
cls
echo.
echo ------------------------------------------------------------------------------------------------------------------------
echo        %DATE% ^| %TIME% 
echo ------------------------------------------------------------------------------------------------------------------------
echo        1    Makefile Limpiar  
echo        2    Makefile Recosntruir
echo        3    Makefile Compilar   
echo        4    Buscar Palabra   
echo        5    Abrir   
echo        6    Salir
echo ------------------------------------------------------------------------------------------------------------------------
echo.
set /p var="Seleccione una opcion [1-6]:" 
if "%var%"=="1" goto op1 
if "%var%"=="2" goto op2 
if "%var%"=="3" goto op3 
if "%var%"=="4" goto op4 
if "%var%"=="5" goto op5 
if "%var%"=="6" goto salir 

::Mensaje de error, validación cuando se selecciona una opción fuera de rango 
echo. El numero "%var%" no es una opcion valida, por favor intente de nuevo. 
echo. 
pause 
echo. 
goto inicio 

:op1
    echo.
    echo ------------------------------------------------------------------------------------------------------------------------
    echo. Limpiando 
    echo ------------------------------------------------------------------------------------------------------------------------
    echo.

    make limpiar
    pause
    goto:inicio

:op2
    echo.
    echo ------------------------------------------------------------------------------------------------------------------------
    echo. Reconstruir 
    echo ------------------------------------------------------------------------------------------------------------------------
    echo.

    make reconstruir
    pause
    goto:inicio

:op3
    echo.
    echo ------------------------------------------------------------------------------------------------------------------------
    echo. Construir 
    echo ------------------------------------------------------------------------------------------------------------------------
    echo.

    make
    pause
    goto:inicio
   
:op4
    SET palabra=0
    echo.
    echo ------------------------------------------------------------------------------------------------------------------------
    echo. Buscar palabra 
    echo ------------------------------------------------------------------------------------------------------------------------
    echo.

    SET /p palabra= "Texto a buscar:" 
    find /I /N "%palabra%" *.cpp 
    find /I /N "%palabra%" *.h 
    cd objet
    find /I /N "%palabra%" *.cpp
    find /I /N "%palabra%" *.h
    cd ...
    pause
    goto:inicio

:op5
    if not exist "Ejecutable.exe" make reconstruir
    start cmd /k Ejecutable.exe
    goto:inicio
:salir
    @cls&exit