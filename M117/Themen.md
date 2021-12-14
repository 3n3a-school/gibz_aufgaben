# Themen

## IP-Adressen

### Lernziele

* [X] Umrechnung von Binär nach Dezimal und umgekehrt
    * _mit Taschenrechner_
* [X] IP Adress-Klassen
* Schreibweisen von Subnetmasken (Prefix)
* Private Adressbereiche
* Bestimmen von gültigen IP Adressen
* Berechnen oder Bestimmen von Netz ID, Host ID, Anzahl Host, Broadcast, Anzahl mögliche Subnetz
* [X] IP Subnetting
* IPv6 Adresse kürzen

### IP Adress-Klassen

| Class | Adress Range  | No. Hosts  | Network-ID   | _ |
|-------|---------------|------------|--------------|---|
| A     | 1-126.x.y.z   | 16'777'214 | one octet    | 🟦🔲🔲🔲 |
| B     | 128-191.x.y.z | 65'534     | two octets   | 🟦🟦🔲🔲 |
| C     | 192-223.x.y.z | 254        | three octets | 🟦🟦🟦🔲 |

### IP Subnetting

Subnetting helps by getting the router to decide, according to subnets, to which part of the network it sends packets

![](https://flylib.com/books/2/707/1/html/2/images/fig6-1.jpg)

#### Subnet Mask

* 32-bit number
* minimum network-id: 8 bits (1111 1111) = 255 --> 0 clients

**Calculate**

1. convert ip & subnet mask to binary
2. perform logical AND (only 1 if both 1)
3. tadahhh!!

## Ist gültige IP?

* kann nicht Broadcast sein, keine Netzadresse, keine Private (172), keine Loopback, keine Host


* [SW07 - IP Adressen](SW07/Ip-Adressen.md)
  * [Notes](SW07/Notes.md)
* [SW09 - IP Rechnen](SW09/IP-Calculation.md)
* [SW10 - IPv6](SW10/IPv6.md)

