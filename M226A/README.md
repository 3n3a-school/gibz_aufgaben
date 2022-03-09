# M226a

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