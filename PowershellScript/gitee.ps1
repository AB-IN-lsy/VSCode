param($a, $b)
echo 'Wait a second, Turnning VPN on'
cd C:\Users\liusy\Desktop\Daily\
.\v2rayN.lnk
echo 'Successful Turning'
$a = Read-Host 'Commit Info?'
cd d:\Code\Vscode
git add .
git commit -m "$a"
git push origin NEW