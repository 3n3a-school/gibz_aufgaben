Version bis und mit 5.0:
(Get-WmiObject -Query "Select Name From Win32_Service Where StartMode='auto'").Name

Ab Version 5.1
Get-Service | where-object {$_.starttype -eq "automatic"}

get-service | select-object -Property name, starttype | Where-Object starttype -eq "automatic"

