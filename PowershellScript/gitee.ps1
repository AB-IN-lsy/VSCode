param($a, $b, $c)
$c = pwd
$c = $c.Path
cd D:\v2rayN\
.\v2rayN.exe
echo 'Wait a second, Turnning VPN on'
Start-Sleep -s 1
echo 'Successful Turning'
cd "$c"
$a = git branch
$a = $a.Substring(2)
$b = Get-Date -Format 'yyyy.M.d'
echo "Commit info = $b"
git add .
git commit -m "$b"
git push origin "$a"