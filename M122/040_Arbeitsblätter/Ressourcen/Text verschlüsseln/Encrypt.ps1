###############################################################################
# Programm: Encrypt.ps1
# Version 1.0 / 04.11.2015
# Roger Müller GIBZ
###############################################################################
<#
.SYNOPSIS  
    Dieses Skript erstellt eine Verschlüsselung  mit Hilfe des Substitutionsverfahrens.
    Es gibt keine Eingabeparameter!
.DESCRIPTION  
    Das Programm benötigt für die Ausführung einen "geheimen" Schlüssel. Dieser wird aus dem Key.ini 
    gelesen. Der Klartext wird aus der Datei klartext.txt gelesen und der verschlüsselte Text wird in die Datei 
    verschluesselt.txt abgelegt.
    Alle drei Dateien (key.ini, klartext.txt und verschluesselt.txt) müssen im gleichen Verzeichnis wie das Script liegen.
    Weiter wird noch ein Hilfsscript verwendet: createarrays.ps1. Auch dieses muss im gleichen Pfad vorhanden sein.  
.LINK  
    Für weitere Informationen loggen Sie sich unter 
    https://moodle.gibz.ch ein      

#>

. .\CreateArrays.ps1   #Dot-Sourcing

#Kontrollausgabe des Alphabet und des Substitutuins Arrays
for ($i=0; $i -lt $Substitution.Length ; $i +=1 ) {
    write-host $i " " $Alphabet[$i] " " $Substitution[$i]
}

#Lesen des Klartext Files
$StreamReader = New-Object System.IO.StreamReader(".\klartext.txt")

#Ersetzen der Zeichen und erstellen des verschlüsselten Strings (CryptLine)
if (Test-Path ".\verschluesselt.txt"){
  clear-content ".\verschluesselt.txt"   
}

While ($StreamReader.Endofstream -eq $False){
    $Line=$StreamReader.ReadLine()
    [char[]] $CryptLine = $Line
    #Write-host  $Line  #Testzwecke zur Klaransicht einschalten
    for ($i=0; $i -lt $Line.Length ; $i +=1 ) {
        #Write-host $Line[$i]
        $Index = $Alphabet.IndexOf([string]$Line[$i])
        #Write-host "i:= " $i "Index: " $Index
        $CryptLine[$i] = $Substitution[$Index]
    }

    #Anhängen der Zeile im verschlüsselt Skript
    [string] $CryptLine >> ".\verschluesselt.txt"      
}