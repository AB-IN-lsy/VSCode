@echo off


rem hexo deploy bat
rem Powered by AB-IN
rem Last edit: 2023/5/4


D:
cd "D:\Code\Hexo"
set HEXO_ALGOLIA_INDEXING_KEY=483f4ee8a687ed876e44dc2c27d52939
hexo clean & hexo g & hexo algolia & hexo deploy