@echo off

rem vscode task CreateFolder
rem Powered by AB-IN
rem Rewrite the previous Code and implement them through scripts
rem Last edit: 2023/1/30

rem %1: folderName
rem %2: typeName
rem %3: suffixName


md %1
cd %1
type %TemplatePath%\\template%2.%3 > %1.%3