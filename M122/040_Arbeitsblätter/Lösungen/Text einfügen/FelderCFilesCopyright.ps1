$Dateiliste = Get-childitem * -include *.c
$Copyright = "/* Copyright Musterfirma AG, 2015-2025. Alle Rechte vorbehalten! */" + [System.Environment]::NewLine
$Copyright = $Copyright + "/* Jegliche Verwendung dieses Programmcodes ausserhalb der */"+ [System.Environment]::NewLine
$Copyright = $Copyright + "/* dafür vorgesehenen Anwendung ist strengstens verboten! */"+ [System.Environment]::NewLine

ForEach ($Datei in $Dateiliste) {
      $Einfügen | Set-Content tempfile.txt
   Get-Content $Datei -ReadCount 5000 |    Add-Content tempfile.txt
   Remove-item $Datei
   Rename-Item tempfile.txt -NewName $Datei
}
