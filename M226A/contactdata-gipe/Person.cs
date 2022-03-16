namespace ContactData;

public abstract class Person
{
    public string FirstName { get; set; }
    public string LastName { get; set; }
    public DateTime Birthday { get; set; }
    public EGender Gender { get; set; }

    private List<ContactData> _contactData;

    private ContactData[] _primaryContactData = new ContactData[ContactData.Types.Length];

    public Person(List<ContactData> contactData = null)
    {
        _contactData = contactData ?? new List<ContactData>();
    }

    public virtual void Print()
    {
        PrintPersonData();
        PrintContactData();
    }

    public virtual void PrintPersonData()
    {
        Console.ForegroundColor = ConsoleColor.Black;
        Console.WriteLine("\n");
        string birthdayAndGender = $"{Gender.ToString().ToLower()} | {Birthday.ToString("dd.MM.yyyy")}";
        PrintFramed($"{FirstName} {LastName} [{birthdayAndGender}]");
    }

    private void PrintContactData()
    {
        Console.ForegroundColor = ConsoleColor.Black;
        foreach (ContactData contactData in _contactData)
        {
            contactData.Print(_primaryContactData.Contains(contactData));
        }
    }

    private void PrintFramed(string output)
    {
        int outputLength = output.Length;
        string horizontalFrame = string.Join("", Enumerable.Repeat('-', outputLength + 4));
        Console.WriteLine($"{horizontalFrame}\n| {output} |\n{horizontalFrame}");
    }

    public EMailAddress PrimaryEMailAddress
    {
        get => _primaryContactData[Array.IndexOf(ContactData.Types, typeof(EMailAddress))] as EMailAddress;
        set => SetPrimary(value);
    }

    public PhoneNumber PrimaryPhoneNumber
    {
        get => _primaryContactData[Array.IndexOf(ContactData.Types, typeof(PhoneNumber))] as PhoneNumber;
        set => SetPrimary(value);
    }

    public PostalAddress PrimaryPostalAddress
    {
        get => _primaryContactData[Array.IndexOf(ContactData.Types, typeof(PostalAddress))] as PostalAddress;
        set => SetPrimary(value);
    }

    public void AddContactData(params ContactData[] contactData)
    {
        for (int i = 0; i < contactData.Length; i++)
        {
            _contactData.Add(contactData[i]);

            if (_primaryContactData[Array.IndexOf(ContactData.Types, contactData[i].GetType())] == null)
            {
                SetPrimary(contactData[i]);
            }
        }
    }

    private void SetPrimary(ContactData contactData)
    {
        if (!_contactData.Contains(contactData))
        {
            _contactData.Add(contactData);
        }

        int index = Array.IndexOf(ContactData.Types, contactData.GetType());
        _primaryContactData[index] = contactData;
    }
}