# Themen

## IP-Adressen

### Lernziele

* [X] Umrechnung von Binär nach Dezimal und umgekehrt
    * _mit Taschenrechner_
* [X] IP Adress-Klassen
* [X] Schreibweisen von Subnetmasken (Prefix)
* [X] Private Adressbereiche
* [X] Bestimmen von gültigen IP Adressen
* [X] Berechnen oder Bestimmen von Netz ID, Host ID, Anzahl Host, Broadcast, Anzahl mögliche Subnetz
* [X] IP Subnetting
* [X] IPv6 Adresse kürzen

### IP Adress-Klassen

| Class | Adress Range  | No. Hosts  | Network-ID   | _ |
|-------|---------------|------------|--------------|---|
| A     | 1-127.x.y.z   | 16'777'214 | one octet    | 🟦🔲🔲🔲 |
| B     | 128-191.x.y.z | 65'534     | two octets   | 🟦🟦🔲🔲 |
| C     | 192-223.x.y.z | 254        | three octets | 🟦🟦🟦🔲 |

### IP Subnetting

Subnetting helps by getting the router to decide, according to subnets, to which part of the network it sends packets

![](https://flylib.com/books/2/707/1/html/2/images/fig6-1.jpg)

#### Subnet Mask

* 32-bit number
* minimum network-id: 8 bits (1111 1111) = 255 --> 0 clients

<!--
**(long) Calculate Network-ID**

1. convert ip & subnet mask to binary
2. perform logical AND (only 1 if both 1)
3. tadahhh!!
-->

**Subnetting**

1. In the Host-Id part of an IP, each subnet has 32 IPs

```
Subnet 
192.168.5.0 
 
192.168.5.32

192.168.5.64 

192.168.5.96 

192.168.5.128 

192.168.5.160 

192.168.5.192

192.168.5.224 
```
2. So there are 8 possible subnets for each subnet-mask (can be done otherwise)
3. for calculating broadcast look below
```
Subnet         Broadcast
192.168.5.0 -> 192.168.5.0+31
```

#### Calculations

**Calculation Net-ID**

1. Host-ID part of IP Address in binary, replace with 0's
2. Then convert back to decimal
3. tadaaah!!

**Calculation Host-ID**

1. Replace everything in Net-ID part with 0's
2. Then convert Host-ID part back to decimal
3. tadaaaah!!

**Calculate Broadcast Address**

1. IP Address, set all bits in Host-ID Part to 1's
2. convert back to decimal
3. tadaaah!

**Calculate Max No. Hosts**

1. number of bits in Host-ID
2. `2^(no host-id bits) - 2`
3. tadahhh!!

**Calculate alternative subnetmask**

1. Count number of 1's at beginning
2. this number is what goes after the `/xx`

### IPv6

**Prüfungsrelevant**:

* anzahl mit folgenden nullen (zwei gleiche Felder mit Nullen)
  * kann dargestellt werden als `::`
  * wenn mehrere Sequenzen von Nullen: längere Nullsequenz wird zu `::` gekürzt
* alle führenden Nullen weglassen
* alles Null am schluss auch `::`
* ein Feld mit nur Nullen => `:0`

**Übungen**

1. `2001:0404:0001:1000:0000:0000:0EF0:BC00` => `2001:404:1:1000::EF0:BC00`
2. `2001:0db8:0000:0000:f054:00ff:0000:2eb` => `2001:db8::f054:ff:0:2eb`
3. `FE00:0000:0000:0001:0000:0000:0000:0056` => `FE00:0:0:1::56`

### Private Address Spaces

| Subnet Mask   | Address Range               |
|---------------|-----------------------------|
| 255.0.0.0     | 10.0.0.1-10.255.255.254     |
| 255.255.240.0 | 172.16.1.1-172.31.255.254   |
| 255.255.0.0   | 192.168.0.1-192.168.255.254 |

### Gültige IP Adresse

* kann nicht Broadcast sein
* keine Netzadresse
* keine Private (172)
* keine Loopback
* keine Host

### Links 
* [SW07 - IP Adressen](SW07/Ip-Adressen.md)
  * [Notes](SW07/Notes.md)
* [SW09 - IP Rechnen](SW09/IP-Calculation.md)
* [SW10 - IPv6](SW10/IPv6.md)
* [IP Adressrechner - Heise.de (Easy)](https://www.heise.de/netze/tools/netzwerkrechner/)
* [IP Adresscalc (Advanced)](http://jodies.de/ipcalc)

## Prüfung 3 (6 Jan)

### Lernziele

* [Berechtigung Windows](SW11/Notes.md)
  * [MindMap](SW11/../SW12/MindMap%20Berechtigung.PNG)
* [Freigaben, Sicherheit, Versteckte und Administrative Freigaben](SW11/Notes.md)
* [Sichere Passwörter](SW12/Notes.md)
* [Troubleshooting Netzwerk](SW12/toubleshoot.png)
* [NAT/PAT](SW12/Notes.md)
  * [Youtube Video](https://youtu.be/A8dl1wqUhSE)
* [ARP Ablauf](https://youtu.be/ttgXMAvkJfo)

### Stoff

* [SW11](SW11)
* [SW12](SW12)