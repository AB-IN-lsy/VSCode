@echo off

rem hexo createArticle bat
rem Powered by AB-IN
rem Last edit: 2023/5/4


D:
cd "D:\Code\Hexo"
set /p type=�������������� (cp, pb): 
set /p platform=������ƽ̨ (Acwing, Article, AtCoder, Codeforces, GPLT, LanQiao, Leetcode, Nowcoder, etc): 
set d=%date:~0,10%

hexo new %type% %platform%%d%