namespace ContactData;

public class EMailAddress : ContactData
{
    public string Email { get; set; }

    public EMailAddress(string email)
    {
        Email = email;
    }
    
    // in c#, in every "object" subclass, can override "toString" for custom implementation
    public override string ToString() => $" ✉️ {Email}";
}
