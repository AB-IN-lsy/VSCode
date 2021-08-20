param($a, $b)
echo 'Do not forget turn VPN on'
$a = Read-Host 'Commit Info?'
cd d:\Code\Vscode
git add .
git commit -m "$a"
git push origin NEW