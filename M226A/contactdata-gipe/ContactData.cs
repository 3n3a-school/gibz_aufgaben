namespace ContactData;

public abstract class ContactData
{
    public static Type[] Types = new Type[]
    {
            typeof(EMailAddress),
            typeof(PhoneNumber),
            typeof(PostalAddress),
    };

    public void Print(bool isPrimary)
    {
        string primarySuffix = isPrimary ? " (⭐️)" : "";
        Console.WriteLine(this + primarySuffix);
    }
}
