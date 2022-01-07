# # # #
# Program: Aufgabe_2.ps1
# Version: 1.0.0
# Datum: 7.1.22
# Autor: Enea K
# # # #

﻿[string] $strLogfileDate = Get-Date -Format "yyyy-MM-dd_HH-mm-ss"
[string] $strLogfile = "logfile.log"
[string] $fileSrc = ".\Backups"
[string] $fileDest = ".\CurrentBackup"
$freeSpace = (Get-WmiObject Win32_LogicalDisk -Filter "name='c:'" | select freespace).freespace

function log([string] $logTxt) {
    $logTextDate = $strLogfileDate + " " + $logTxt
    Add-Content -Path $strLogfile -Value $logTextDate -Encoding UTF8
    Write-Host $logTextDate
}

function copyNewestBackup() {
    # Lade Datei aus Quellordner
    $neusteDatei = Get-ChildItem $fileSrc | Sort-Object -Property LastWriteTime | Select-Object -Last 1

    # Kopiere Datei in Zielordner
    Copy-Item -Path $fileSrc\$neusteDatei -Destination $fileDest -Force

    # Ergänze Logile, dass Kopieren erfolgt
    log ("Datei: " + $neusteDatei.Name + " wurde erfolgreich nach " + $fileDest + " verschoben")
}

copyNewestBackup
if ($freespace -lt (10 * $neusteDatei.Size)) {
    log ("Speicherplatz wird knapp")
}
