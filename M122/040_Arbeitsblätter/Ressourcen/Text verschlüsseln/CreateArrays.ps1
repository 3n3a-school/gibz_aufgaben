###############################################################################
# Programm: CreateArrays.ps1
# Version 1.0 / 04.11.2015
# Roger Müller GIBZ
###############################################################################
$Alphabet = 'a','b','c','d','e','f','g', 'h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',' '

#Abfüllen des Substitutionsarrays damit auch 26 Platzhalter vorhanden sind
$Key = Get-content .\key.ini 
[char[]] $Substitution = $Alphabet.Clone()


for ($i=0; $i -lt $Key.Length ; $i +=1 ) {
    $Substitution[$i] = $Key[$i]
}

$Substractor = 0 #Der Substractor wird gebraucht um die nicht verwendeten Buchstaben des Aplphabet Arrays vom Index abzuziehen 

for ($i=0; $i -lt ($Alphabet.Length)  ; $i +=1 ) {
    if ($Key[0.. $Key.Length] -contains $Alphabet[$i]) { #Falls das Zeichen im Key enthalten darf es nicht gezählt werden
        $Substractor += 1
    }
    else {
        $Substitution[$Key.Length + $i - $substractor] = $Alphabet[$i]
    }
}
$Substitution

$Alphabet