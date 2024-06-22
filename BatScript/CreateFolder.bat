@echo off

:: VSCode Task: CreateFolder
:: Powered by AB-IN
:: Rewrite the previous code and implement them through scripts
:: Last edit: 2024/6/22

:: Arguments:
:: %1: folderName
:: %2: typeName
:: %3: suffixName

:: Set descriptive variable names
set "folderName=%~1"
set "typeName=%~2"
set "suffixName=%~3"

:: Check if the folder exists, if not, create it
IF NOT EXIST "%folderName%" (
    MD "%folderName%"
)

:: Navigate to the folder
CD /D "%folderName%"

:: Check if the file exists, if not, create it from template
IF NOT EXIST "%folderName%.%suffixName%" (
    TYPE "%TemplatePath%\template%typeName%.%suffixName%" > "%folderName%.%suffixName%"
    ECHO The file "%folderName%.%suffixName%" has been created successfully.
    code "%folderName%.%suffixName%"
) ELSE (
    ECHO Warning: The file "%folderName%.%suffixName%" already exists.
)

:: Exit the script
EXIT /B 0
