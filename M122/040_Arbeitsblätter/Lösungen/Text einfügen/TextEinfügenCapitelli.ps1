$Dateiliste = Get-ChildItem * -include "*.c"
$Copyright = "/*Copyright Musterfirma AG, 2015-2025. Alle Rechte vorbehalten!*/" + [System.Environment]::NewLine
$Copyright = $Copyright + "Jegliche Verwendung dieses Programmcodes ausserhalb der       */" + [System.Environment]::NewLine
$Copyright = $Copyright + "dafür vorgesehenen Anwendung ist strengstens verboten!        */" + [System.Environment]::NewLine

ForEach ($Datei in $Dateiliste) {
$Content = Get-Content -Path $Datei.FullName -Delimiter "   "
$ReturnContent = $Copyright + "`n" + $Content
Set-Content -Path $Datei.FullName $ReturnContent
}