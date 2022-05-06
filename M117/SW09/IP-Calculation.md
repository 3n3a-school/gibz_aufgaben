# IP Adressen Rechnen

## Netzanteil / Hostanteil: 
* Netzanteil:
	* Subnetzmaske in Binär (alle Zahlen separat zu binär)
	* anzahl nullen am schluss = /(nullen in Hostanteil v. Subnetzmaske)
* Hostanteil:
	* übertragen auf Ip Adresse, ab Hostanteil

## Get Host Part: (Hostanteil)
* alle 255 sind gleich 8, danach Zahl in Binär
* 1-en am Anfang zählen + die Anzahl 255 * 8
	* => `/(zahl)`

## Number of ip adresses in Network:
* take every number of subnet and convert to binary, octal
	* 255 = 1111 1111
	* 0 = 0000 0000
		then count all the 0s
* 2^(no. zeroes in host-id-part)

## Calculate Netz-ID: 
* Ip Addresse in binär
* Host Anteil mit nullen ersetzen
* then calculate Network part in decimal

## Calculate Host ID:
* Everything in Host Part is zero (in Binary)
* everything in network part is normal

## Calculate Broadcast:
* Hostanteil, alles zu eins
	
#EXAMPLE:
`IP-Adresse: 212.245.88.186 mit Subnetmaske 255.255.255.248`

```
212.245.88.1011 1|010
                 ,-- ab hier Hostanteil
255.255.255.1111 1|000
```
* alternative Schreibweise Subnetzmaske: /29
* Klasse C
* Anzahl Hosts in Subnet: 8
* Netz-ID: 212.245.88.184
* Broadcast: 212.245.88.191
* host-id: 0.0.0.2
