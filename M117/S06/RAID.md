# Verschiedene Raid Typen

## RAID 0

* two disks
* for speed
* striping

* high performance, no redundancy

## RAID 1

* two disks
* ultimate backup -> two datacenters
* mirroring

* read performance ok, increased cost because 2x drives

## RAID 5

* three disks
* striping
* single parity drive
  * one drive can fail

* high rw, not suited large file transfer & disk fail impacts system

## RAID 6

* four disks
* striping
* two parity drives

* avoids losing data, not ideal for small files & longer time to write, two parity blocks

## RAID 10 (1+0)

* four disks
* striping + mirroring

* moderate capacity, quite expensive double amount drives


# Usage

|Typ | RAID |
|---|---|
|Betriebsssystem | RAID 0 |
|Game-PC | RAID 0 |
|Entwicklungs-PC | RAID 5 |
| Datenbanksysteme | RAID 10 |
|Webserver | RAID 5 |
|Datenarchiv | RAID 6 |
