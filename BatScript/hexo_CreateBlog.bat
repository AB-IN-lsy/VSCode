@echo off

rem hexo createArticle bat
rem Powered by AB-IN
rem Last edit: 2023/5/4


D:
cd "D:\Code\Hexo"
set /p type=Please input article type (cp, pb): 
set /p platform=Please input the platform (Acwing, Article, AtCoder, Codeforces, GPLT, LanQiao, Leetcode, Nowcoder, Luogu, etc): 
set d=%date:~0,10%
set da=%d:/=-%

echo %d%

hexo new %type% %platform%%da%
code %platform%%da%.md