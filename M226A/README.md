# M226a

Prüfungsvorbereitung
===

## Vererbung und Polymorphie

* Polymorphie erklären (anhand Bsp), Einsatzmöglichkeiten dieser
    * Game: `Entity`-Class aller objekte im Game
    * Biz: Collections, in C# can implement own functions for default Collection-Actions
* Welche Member werden vererbt von Super-, zu Subklasse?
    * nicht vererbt: statische Member, Konstruktoren, Finalizer
* Konsequenzen der Vererbung, bei Instanzierung von Objekten, Anwendung der Konstruktoren?
    * Wenn Deklaration und Instanzierung die gleiche Klasse aufweisen, dann wird in eine Methode X, der Superklasse, mit virtual, direkt gesprungen und ausgeführt, bei _new_ und _override_. 
    * Wenn Deklaration [Superklasse] = Instanzierung [Subklasse], dann, wird nur bei _override_ die Methode einer Subklasse ausgeführt, aber nicht so bei _new_.
* Zugriffsmodifizierer [public, private, protected] innerhalb der Vererbung erklären?
    * public: Subklasse hat Zugriff
    * private: Subklasse hat keinen Zugriff
    * protected: In Klasse selbst und in subklassen
* Syntax zur Deklaration der _Generalisierung_?
    ```csharp
    public class A {}

    public class B : A {}
    ```
* `</>`: Vererbungshierarchie entwickeln, 3-6 Klassen, implementieren
* `</>`: Methoden und Eigenschaften überschreiben können
    * superclass' method: `virtual ...`
    * subclass' method: `override ...`
* `</>`: Member der Superklasse in der Subklasse verbergen, durch neue Implementation
    * `new ...`
* `</>`: Anwenden von _new_ und _override_
* unterscheiden zwischen `override` und `new`
    * **new**: forced den Compiler, dass gleichnahmige Methode wie in Parentclass existieren soll.
    * **override**: reimplementiert explizit eine Methode der Parentklasse.

## UML (Unified Modeling Language)

* Klassendiagramme
    * _Attribut_: Teil einer Klasse
    * _Operation_: Aktion welche ein Teil der Klasse auführen soll
* Arten von Assoziationen: Siehe[ Zusammenfassung BBZW](https://gh.3n3a.ch/my-notes/berufsschule/m226a-objektorientiertes-programmieren.html)
  * [Zusammenfassung Klassendiagramme](https://gh.3n3a.ch/my-notes/berufsschule/m226a-klassendiagramme.html)
* `</>`: Klassendiagramme erstellen anhand vorgaben
* `</>`: UML Diagramm in C# abbilden

## Klassendiagramme

#### Begriffe

| Symbol | Beschreibung |
|---------|----------------------------|
| `- - ->` |Abhängigkeit |
| `----->` | unidirektionale Assoziation |
| `-------` | bidirektionale Assoziation |
| `<>-----` | Aggregation |
| `◀▶-----` | Zusammensetzung |
| * | unendlich (kann assc. sein) |
| 1..2 | Bereich (hängt davon ab, ob assc.) |
| 1 | konstante (muss assc. sein) |

### Klassen

_Rechtecke mit Feldern_

| Zahl | Bezeichnung | Notiz |
| ---- | ----------- | --- |
| 1    | Name Klasse | |
| 2    | Felder mit Namen und deren Typ | <-- definiert die Werte (Interface/Constructor) |
| 3    | Methoden mit Namen, Parametern und deren Return-Typen | --> gibt/setzt Werte (getters/setters) |

### Relationships

#### Abhängigkeit

* Klasse kann abhängig von anderer Klasse sein
    * Bsp: Buch kann im Besitz von Person sein

Wenn Variable, wie in Klasse _Person_, nicht definiert ist im constructor, von anderer Klasse kommt, dann modeliert mit `- - ->` Pfeil


#### Direkte Assoziation

* Klasse speichert andere Klasse in Feld
   * Bsp: Person kann im Besitz von _n_ Büchern sein, ein Buch kann besessen werden von _n_ Personen

#### Bidirektional Assoziation

* Beide Klassen speichern sich gegenseitig in ihren Feldern ab
    * Bsp: Person speichert alle Bücher in Besitz, \
    Buch speichert alle Personen welche es besitzen.

#### Aggregation (Sammlung/Gruppe)

* Klasse eins _"besitzt"_ Klasse zwei.
    * Klasse zwei ist ein Teil von Klasse eins

_**Linie**: eine P. viele Bücher; ein Buch, eine P._

Fast schon als ob eine Person im echten Leben ein Buch besitzt, und egal ob das Buch einer anderen Person den gleichen Titel und Inhalt hat - es ist ein anderes Buch.

#### Komposition (Zusammensetzung)

* Klasse eins _"besitzt"_ Klasse zwei.
    * wenn eins _"stirbt"_, dann stirbt zwei auch \
    (gleiche Lifetime)

_In idealer Welt gibt es Ebooks mit DRM, wo das DRM nur von einer einzigen Person benutzt werden kann und dann sozusagen das Buch als solches nur lesbar ist solange die Person am leben ist._

### Vererbung

* Eine Klasse erweiter eine andere Klasse
    * Mutter, Tochterklassen
    * 
_Email ist eine Erweiterung der Dokument-Klasse. Benutzt Dokument als Grundbaustein_

## Testing

### Default Pattern

* Arrange (instantiate objects, prepare data)
* Act (execute method)
* Assert: (Check Result)

_Arrange could also be missing, and be defined in constructor_

### Unit Tests

* Don't have access to filesystem, database, networking ...
* These tests should use mocking (C# -> Moq)

### Integration Tests

* Have access to system, network resources
* Test how a function integrates into these services

## Glossary

* **Generalisierung:** Benutzung eines Lösungsweges für andere, ähnliche Probleme durch anpassung des originalen Weges.
* **Vererbung:** Eine Klasse kann ein, oder mehrere Eigenschaften einer anderen Klasse übernehmen. Dient der Abstraktion / Vereinfachung.
* **Superklasse:** Eine Klasse von der andere Klassen Code erben.
* **Subklasse:** Eine Klasse welche von einer Superklasse Code erbt.
* **UML:** eine etablierte, objektorientierte, standardisierte und werkzeugunterstützte Modellierungssprache für die Visualisierung, Beschreibung, Spezifikation und Dokumentation von Systemen.

---

# Dependency Injection

* by using constructor
    * dependency is provided for all methods in class
    * robust
    * not flexible (constructor executed at instanciation)
* by setting a dependency
    * not certain that dependency is in existence
    * almost no robustness
    * flexible
* by providing parameter for method
    * often changing in source of dependency
    * flexible and robust, often changing

**inversion of control**
controller is responsible for providing dependencies

* [Explanation Dependency Injection on StackOverflow](https://stackoverflow.com/a/140655)


---

# Polymorphism, inheritance etc.

## Difference Between `new` and `override`

* new: überdecken
* override: überschreiben
* superclass's implementaiton kann mit `base.<name>` aufgerufen werden
* methode der superklasse muss `virtual` modifer haben

---

### Bsp _new_ und _override_:
* Bsp Verdeckung: https://gitlab.com/gibz-informatik/infawu2021/m226a-contactdata/-/blob/main/InternalPerson.cs
* Bsp OVerride : https://gitlab.com/gibz-informatik/infawu2021/m226a-contactdata/-/blob/main/ExternalPerson.cs

Wenn Deklaration und Instanzierung die gleiche Klasse aufweisen, dann wird in eine Methode X, der Superklasse, mit virtual, direkt gesprungen und ausgeführt, bei _new_ und _override_. 

Wenn Deklaration [Superklasse] = Instanzierung [Subklasse], dann, wird nur bei _override_ die Methode einer Subklasse ausgeführt, aber nicht so bei _new_.

### Definitions

**new**: forced den Compiler, dass gleichnahmige Methode wie in Parentclass existieren soll.

**override**: reimplementiert explizit eine Methode der Parentklasse.

## Deklaration und Instanzierung

* üblich gleich deklariert wie instanziert
* `<deklarations-typ> perosn = new <instanzierungs-typ>();` 
