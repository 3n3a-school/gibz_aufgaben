namespace ContactData;

public class PostalAddress : ContactData
{
    public string Street { get; set; }
    public int ZipCode { get; set; }
    public string City { get; set; }

    public PostalAddress(string street, int zipCode, string city)
    {
        Street = street;
        ZipCode = zipCode;
        City = city;
    }

    public override string ToString() => $"📪 {Street}, {ZipCode} {City}";
}
