param($a, $b, $c, $d)
$c = pwd
$c = $c.Path

git branch
$d = $?
if ($d -eq $false){
    continue
}
cd D:\Program Files\Clash for Windows
.\Clash for Windows.exe
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