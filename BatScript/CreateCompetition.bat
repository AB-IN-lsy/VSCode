@echo off
setlocal enabledelayedexpansion

rem vscode task CreateCompetition 
rem Powered by AB-IN

rem %1: folderName
rem %2: typeName
rem %3: suffixName
rem %4: NumberOfQuestion

md %1
cd %1
set /a cnt=0
for %%i in (a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z) do (
	set /a cnt+=1
	md %%i
	cd %%i
	type %TemplatePath%\\template%2.%3 > %%i.%3
	cd ..
	if !cnt! == %4 exit
)