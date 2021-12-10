# Übungen IP Rechnen

## Aufgabe 3

- ip adresse: 21.30.50.26
- subnetzmaske: 255.240.0.0

```ip
11111111.11110000.00000000.00000000
```

- alternative subnetz: /12 (=> 12 Nullen)
- Standard Klasse: C

---

# Übungen Versicherungs AG

## Aufgabe 1

* `100|1 0111 . 0000 0010`
* 255.255.`111|0 0000 . 0000 0000` -> `/19`
* Klasse A
* No. Mögl. Hosts: 2^13
* Netz-ID: 88.149.128.0
* Broadcast: 88.149.159.2
* Host-ID: 0.0.23.2

## Aufgabe 2

* `/24`

## Aufgabe 3

* 32

## Subnetting

1. Binär umwandeln (IP & Sunetmask)
2. Bits in Netzteil der IP, bestimmen wo Hostanteil aufhört
   => 2^(anzahl nullen im netzanteil v Subnet) = anzahl adressen im netzwerk

* 108 Clients => 192.168.1.0-127 : 255.255.255.128
* 52 Servers => 192.168.1.128-191 : 255.255.255.192
* 23 Printers => 192.168.1.192-223 : 255.255.255.224
* how many left => 192.168.1.224-255 : 255.255.255.224
