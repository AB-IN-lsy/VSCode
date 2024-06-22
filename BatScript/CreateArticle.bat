@echo off

:: Hexo createArticle script
:: Powered by AB-IN
:: Last edit: 2023/5/4

:: Arguments:
:: %1: articleType
:: %2: platform

:: Set descriptive variables
set "hexoPath=D:\Code\Hexo"
set "articleType=%~1"
set "platform=%~2"
set "currentDate=%date:~0,10%"
set "formattedDate=%currentDate:/=-%"

echo %formattedDate%

:: Navigate to Hexo directory
D:
cd "%hexoPath%"

:: Create new article
hexo new %articleType% %platform%%formattedDate%
code "%platform%%formattedDate%.md"
