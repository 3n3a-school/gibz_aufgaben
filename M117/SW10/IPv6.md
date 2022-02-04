# IPv6

* ipv4 ausgeschöpft seit 2011
* ipv6, 16bit-felder, in hex, 128bit
* erste 3 Felder sind Standortpräfix (1. 48 Bit)
  * des ISP usw
* 4. Feld, subnet (65'000 Subnets möglich)
* Anycast => Broadcast des ipv6

**Prüfungsrelevant**:

* anzahl mit folgenden nullen (zwei gleiche Felder mit Nullen)
  * kann dargestellt werden als `::`
  * wenn mehrere Sequenzen von Nullen: längere Nullsequenz wird zu `::` gekürzt
* alle führenden Nullen weglassen
* alles Null am schluss auch `::`
* ein Feld mit nur Nullen => `:0`

## Übungen

1. `2001:0404:0001:1000:0000:0000:0EF0:BC00` => `2001:404:1:1000::EF0:BC00`
2. `2001:0db8:0000:0000:f054:00ff:0000:2eb` => `2001:db8::f054:ff:0:2eb`
3. `FE00:0000:0000:0001:0000:0000:0000:0056` => `FE00:0:0:1::56`
