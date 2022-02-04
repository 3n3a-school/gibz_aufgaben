# # # #
# Program: Aufgabe_1.ps1
# Version: 1.0.0
# Datum: 7.1.22
# Autor: Enea K
# # # #

﻿[string[]] $noten = @()

for ($i=0; $i -le 20; $i++) {
    $number = (Get-Random -Maximum 6.0 -Minimum 1.0).ToString("#.#")
    $noten += $number
}

$res = $noten | Measure-Object -Maximum -Minimum -Average

Write-Host "Tiefste Note:" $res.Minimum

Write-Host "Höchste Note:" $res.Maximum

Write-Host "Notendurchschnitt:" $res.Average.ToString("#.#")
