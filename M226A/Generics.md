# Generics in Software Engineering

## Usecases

* Generally define a class which can take inputs of variable types
* Provide a parameter when defining a datatype, _tell a list what types are allowed_
    * Example a `List<T>` is generic, but an `ArrayList` not
    * handling Data in Generic List is way more performant
* Guarantee type safety, makes for less errors
* Code applicable to multiple types, like `Dictionary<t1, t2>`

## Examples

* [ContactData Generic Getter](./contactdata-gipe/Person.cs) [#91]

* [Json Serializer](./json-serializer/Serializer.cs) [#20]
```csharp
public class Serializer<T> {
    private T _obj;
    private StringBuilder _sb;

    public Serializer(T obj) {
        _obj = obj;
        _sb = new StringBuilder();
    }

    public string toJson() {
        // implementation omitted
    }
}
```