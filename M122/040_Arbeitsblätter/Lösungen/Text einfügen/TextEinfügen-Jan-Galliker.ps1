$Message = "/* Copyright Musterfirma AG, 2015-2025 Alle Rechte vorbehalten! */
/* Jegliche Verwendung dieses Programmcodes ausserhalb der */
/* dafür vorgesehenen Anwendung ist strengstens verboten! */

"

Set-Location C:\_Berufsschule\M122\
Get-ChildItem * -Recurse -Include '*.c' | ForEach-Object { $Message + (Get-Content $_.FullName -Delimiter "   ") |Set-Content $_.FullName}