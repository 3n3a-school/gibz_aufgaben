namespace ContactData;

public abstract class ContactData
{
    public static Type[] Types = new Type[]
    {
            typeof(EMailAddress),
            typeof(PhoneNumber),
            typeof(PostalAddress),
    };

    // prints itself (with prefix iif primary contact method)
    // itself can be subclass :)
    public void Print(bool isPrimary)
    {
        string primarySuffix = isPrimary ? " (⭐️)" : "";
        // "this" is equal to "this.toString"
        Console.WriteLine(this + primarySuffix);
    }
}
