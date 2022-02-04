# Notizen SW12

## Sichere Passwörter

* mind. 8 Zeichen, je mehr desto besser
* mix von Klein-/Grossbuchstaben
* mix von Buchstaben und Zahlen
* mind. 1 Spezialcharakter

### Weitere Tipps

* Öfters ändern
* Niemals wiederverwenden
* Niemals weitererzählen
* Niemals aufschreiben, Zettel
* Gutes Passwort sollte merken können

## NAT und PAT

### NAT

* Network Address Translation Protocol
* Clients im lokalen Netzwerk, keine Public IP
* Damit diese clients trotzdem mit dem öffentlichen Internet kommunizieren können, braucht NAT
* NAT ersetzt bei Anfrage ins öffentliche Internet die Private-IP von einem Client mit seiner eigenen, oder umgekehrt, bei Empfang

### Ablauf SNAT

_das Verfahren die Source-IP durch die des Routers zu ersetzen -> SNAT_

1. Client A sendet Paket mit IP und TCP-Port an Standard Gateway (NAT-Router)
2. Der Router speichert LAN-Adresse und Port in der NAT-Tabelle + auch der WAN Port (öffentl. Netzwerk)
3. Server angefragt mit WAN Port, sendet Antwort WAN Port
4. Router schaut in NAT-Tabelle und sendet an LAN Adresse:Port mit WAN-Port

### Ablauf DNAT

_DNAT - Destination Network Address Translation (Port Forwarding)_

_DNAT ist SNAT für eine längere Zeit_

1. DNAT macht ein Port auf einem Client dauerhaft aus dem WAN-Net verfügbar
2. Bsp: Port 80 (WAN) -> 192.168.0.2:8888

### PAT

_Port and Address Translation / Network Address Port Translation (NAPT) -> 1:n NAT_

1. mehrere interne IP:Port Adressen
2. Diese werden im Router _forwarded_ auf die einzige öffentl. Adresse
2.1. Können auch andere öffentl. Ports haben, als lokale quell-Ips