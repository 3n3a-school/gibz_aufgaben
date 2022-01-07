# # # #
# Program: Aufgabe_4.ps1
# Version: 1.0.0
# Datum: 7.1.22
# Autor: Enea K
# # # #

$trigger = New-JobTrigger -Daily -At 19:00
Register-ScheduledJob -Name Sicherheitskopie -FilePath ".\Aufgabe 2\Aufgabe_2.ps1"
Add-JobTrigger -Trigger $trigger -Name Sicherheitskopie
