# Verschiedene Raid Typen

## RAID 0

* two disks
* for speed
* striping
* combines multiple disks, no matter the size

* high performance, no redundancy

## RAID 1

* two disks
  * smallest disk size
* ultimate backup -> two datacenters
* mirroring

* read performance ok, increased cost because 2x drives

## RAID 5

* three disks
* striping
* single parity drive
  * one drive can fail
  * creates parity bit from each drive, spread out over all drives -> parity bits

* high rw, not suited large file transfer & disk fail impacts system
  * slower than 0 or 1

## RAID 6

* four disks
* striping
* two parity drives
  * double spread out parity

* avoids losing data, not ideal for small files & longer time to write, two parity blocks

## RAID 10 (1+0)

* four disks
* striping + mirroring

* moderate capacity, quite expensive double amount drives
* realtime with redundancy


# Usage

|Typ | RAID |
|---|---|
|Betriebsssystem | RAID 1 |
|Game-PC | RAID 0 |
|Entwicklungs-PC | RAID 1 |
| Datenbanksysteme | RAID 10 |
|Webserver | RAID 5 |
|Datenarchiv | RAID 5 / 6 |
