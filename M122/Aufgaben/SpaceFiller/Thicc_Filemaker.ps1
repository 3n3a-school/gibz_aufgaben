#################################################
#               SpaceFiller1000                 #
#                   by 3n3a                     #
#################################################

$filename = $env:USERPROFILE+'\Downloads\thicc_file.txt'
[console]::beep(500,300)

Write-Host $filename

function getFreeSpace($disk_label) {
    $space_left = Get-CimInstance -ClassName Win32_LogicalDisk | Where-Object {$_.DeviceID -eq $disk_label+":"} | Select-Object -Property FreeSpace
    $space_left.FreeSpace
}

$space_left = getFreeSpace('C')

$file = New-Object -TypeName System.IO.FileStream -ArgumentList $filename,Create,ReadWrite
$file.SetLength($space_left)
$file.Close()
Write-Host $space_left "bytes in Datei" $filename "geschrieben"