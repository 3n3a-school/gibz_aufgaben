param(
$Number1 = 1,
$Number2 = 100
)
$Sum = 0
$i = $Number1
while ($i -le $Number2) {
    $Sum = $Sum + $i
    $i = $i + 1
}
write-host $Sum
