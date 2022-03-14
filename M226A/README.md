# M226a

Prüfungsvorbereitung
===

## Vererbung und Polymorphie

* Polymorphie erklären (anhand Bsp), Einsatzmöglichkeiten dieser
    * Game: `Entity`-Class aller objekte im Game
    * Biz: Collections, in C# can implement own functions for default Collection-Actions
* Welche Member werden vererbt von Super-, zu Subklasse?
* Konsequenzen der Vererbung, bei Instanzierung von Objekten, Anwendung der Konstruktoren?
* Zugriffsmodifizierer [public, private, protected] innerhalb der Vererbung erklären?
    * public: Subklasse hat Zugriff
    * private: Subklasse hat keinen Zugriff
    * protected: _tbd_
* Syntax zur Deklaration der _Generalisierung_?
* `</>`: Vererbungshierarchie entwickeln, 3-6 Klassen, implementieren
* `</>`: Methoden und Eigenschaften überschreiben können
    * superclass' method: `virtual ...`
    * subclass' method: `override ...`
* `</>`: Member der Superklasse in der Subklasse verbergen, durch neue Implementation
    * `new ...`
* `</>`: Anwenden von _new_ und _override_
* unterscheiden zwischen `override` und `new`

## UML (Unified Modeling Language)

* Klassendiagramme
    * _Attribut_
    * _Operation_
* Arten von Assoziationen \
    | Assoziationsnamen | Rollennamen | Multiplizitäten |
    | --- | --- | --- |
    | |||
* `</>`: Klassendiagramme erstellen anhand vorgaben
* `</>`: UML Diagramm in C# abbilden

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

# Testing

## Default Pattern

* Arrange (instantiate objects, prepare data)
* Act (execute method)
* Assert: (Check Result)

_Arrange could also be missing, and be defined in constructor_

## Unit Tests

* Don't have access to filesystem, database, networking ...
* These tests should use mocking (C# -> Moq)

## Integration Tests

* Have access to system, network resources
* Test how a function integrates into these services

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

Wenn Deklaration = Instantzierung, dann wird in eine Methode X, der Superklasse, mit virtual, direkt gesprungen und ausgeführt, bei _new_ und _override_. 

Wenn Deklaration [Superklasse] = Instanzierung [Subklasse], dann, wird nur _override_ einer Subklasse ausgeführt, aber nicht bei _new_.

### Definitions

**new**: forced den Compiler, dass gleichnahmige Methode wie in Parentclass existieren soll.

**override**: reimplementiert explizit eine Methode der Parentklasse.

## Deklaration und Instanzierung

* üblich gleich deklariert wie instanziert
* `<deklarations-typ> perosn = new <instanzierungs-typ>();` 