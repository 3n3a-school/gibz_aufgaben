$n=1
$max = $args[0]
Write-Host $max
foreach ($a in $args) {
if ($a -gt $max) {$max = $a; $pos = $n}
$n++
}
echo "Maximum $max at Position $pos"