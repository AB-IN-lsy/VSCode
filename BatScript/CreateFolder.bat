@echo off

rem vscode task CreateFolder
rem Powered by AB-IN
rem Rewrite the previous Code and implement them through scripts
rem Last edit: 2023/2/23

rem %1: folderName
rem %2: typeName
rem %3: suffixName

if not exist %1 (
	md %1	
)

rem echo Now we enter the folder.

cd %1

if not exist %1.%3 (
	type %TemplatePath%\template%2.%3 > %1.%3 
	echo The %1.%3 creation completed.
) else (
	echo Warning. The %1.%3 has already been created.
)

