param($a, $b)
echo 'Wait a second, Turnning VPN on'
cd D:\v2rayN\
.\v2rayN.exe
echo 'Successful Turning'
$b = Get-Date -Format 'yyyy.M.d'
echo "Commit info = $b"
cd d:\Code\Vscode
git add .
git commit -m "$b"
git push origin NEW