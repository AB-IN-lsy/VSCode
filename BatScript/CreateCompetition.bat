@echo off
setlocal enabledelayedexpansion

rem vscode task CreateCompetition 
rem Powered by AB-IN

rem %1: folderName
rem %2: typeName
rem %3: suffixName
rem %4: NumberOfQuestion

if not exist %1 (
	md %1	
	echo %1 competition creation completed.
) else (
	echo Warning. The %1 competition has already been created.
)

rem echo Now we enter the folder.


cd %1
set /a cnt=0
for %%i in (a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p,q,r,s,t,u,v,w,x,y,z) do (
	set /a cnt+=1
	
	if not exist %%i (
		md %%i	
	)
	
	cd %%i
	if not exist %%i.%3 (
		type %TemplatePath%\\template%2.%3 > %%i.%3
		echo The %%i.%3 creation completed.
	) else (
		echo Warning. The %%i.%3 has already been created.
	)
	
	cd ..
	if !cnt! == %4 exit
)
