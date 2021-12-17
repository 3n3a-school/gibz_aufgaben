[int] $Number1 = Read-host "Enter number 1"
[int] $Number2 = Read-Host "Enter number 2"
$Sum = 0
$i = $Number1
while ($i -le $Number2) {
    $Sum = $Sum + $i
    $i = $i + 1
}
write-host $Sum




[int] $number1 = Read-Host "Enter number 1"
[int] $number2 = Read-Host "Enter number 2"

[int] $Sum = 0

for (;$number1 -le $number2;$number1++){ $Sum +=$number1}
write-host $Sum


[int] $number1 = Read-Host "Enter number 1"
[int] $number2 = Read-Host "Enter number 2"

[int] $Sum = 0

($number1..$number2) | ForEach({$Sum +=$_})
write-host $Sum