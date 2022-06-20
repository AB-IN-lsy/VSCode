﻿param($a, $b, $c, $d, $e)
$c = pwd
$c = $c.Path

# 判断是否有git仓库
git branch
$d = $?
if ($d -eq $false){
    echo 'Do not have git repository'
    continue
}

#打开VPN
cd 'D:\Program Files\Clash for Windows\'
& '.\Clash for Windows.exe'
echo 'Wait a second, Turnning VPN on'
Start-Sleep -s 1
echo 'Successful Turning'
cd "$c"

#获取分支
$a = git branch
$a = $a.Substring(2)

#获取日期
$b = Get-Date -Format 'yyyy.M.d' 
echo "Today is $b"

#获取commitInfo
git log --oneline
$e = Read-Host "Commit info = "

#进行提交
git add .
git commit -m "$e"
git push origin "$a"