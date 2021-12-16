# Notizen Berechtigungen

* Explizite: nur für ein Objekt
* Vererbte: Berechtigung übernommen von übergeordnetem Ordner
* Verschiedene Berechtigungen:
  * volle Kontrolle
  * nur Bearbeiten
  * nur Lesen & Ausführen
  * Nur auflisten
  * Nur Lesen
  * Nur Schreiben
  * Spezialberechtigungen
* Gruppe "Jeder angemeldete" besser für Berechtigungen
* Windows: nur bei NTFS kann Sicherheitseinstellungen machen
* Vererbung kann bei Windows (Properties>Security>Advanced>Disable Inheritance) ausgeschaltet werden
* "Sicherheit" bezieht sich nur auf Lokale Berechtigung
* "Freigabe" ist Berechtigung über Netzwerk (SMB)
* Kopieren & Einfügen: Berechtigung von Zielsystem
* Ausschneiden & Einfügen: Berechtigung von Anfangsort
* Versteckte Freigabe:
    1. Advanced Sharing in Sharing
    2. Hinter "Share Name": dollarzeichen
    3. Bedeutet diese Freigabe ist _versteckt_
    4. Damit darauf zugegriffen werden kann muss Name wissen
* Administrative Freigaben:
    1. Computer Managment > Shared Folders > Shares
    2. {Admin$, C$, E$ ...} -> verschiedene verstecke Freigaben
    3. Windows installiert, gibt es C-Laufwerk automatisch dem Administrator "frei"
* Berechtigungen überprüfen:
    1. Properties > Security > Advanced Security > Auditing
    2. Auswerten wer hat Zugriff
    3. Log machen von Zugriffen
