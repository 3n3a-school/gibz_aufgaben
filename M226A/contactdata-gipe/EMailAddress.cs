namespace ContactData;

public class EMailAddress : ContactData
{
    public string Email { get; set; }

    public EMailAddress(string email)
    {
        Email = email;
    }

    public override string ToString() => $" ✉️ {Email}";
}
