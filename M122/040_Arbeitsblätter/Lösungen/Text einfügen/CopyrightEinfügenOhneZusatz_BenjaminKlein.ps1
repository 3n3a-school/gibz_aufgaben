$copyright = @( "/* Copyright Musterfirma AG, 2015-2025. Alle Rechte vorbehalten!",
"Jegliche Verwendung dieses Programmcodes ausserhalb der",
"dafür vorgesehenen Anwendung ist strengstens verboten! */" )

Get-ChildItem -Recurse -Include *.c | ForEach-Object { $copyright + (Get-Content $_.FullName) | Set-Content $_.FullName }
