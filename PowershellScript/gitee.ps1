param($a, $b)
$a = Read-Host 'Date?'
cd d:\Code\Vscode
git add .
git commit -m "$a"
git push origin NEW