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

    // make func "overwritable" in subclasses
    public virtual void PrintPersonData()
    {
        Console.ForegroundColor = ConsoleColor.Gray;
        Console.WriteLine("\n");
        string birthdayAndGender = $"{Gender.ToString().ToLower()} | {Birthday.ToString("dd.MM.yyyy")}";
        PrintFramed($"{FirstName} {LastName} [{birthdayAndGender}]");
    }

    private void PrintContactData()
    {
        Console.ForegroundColor = ConsoleColor.Gray;
        foreach (ContactData contactData in _contactData)
        {
            contactData.Print(_primaryContactData.Contains(contactData));
        }

        // Print each primary info separately
        foreach (ContactData primaryContact in new ContactData[] {PrimaryEMailAddress, PrimaryPhoneNumber, PrimaryPostalAddress})
        {
            if (!object.ReferenceEquals(null, primaryContact)) {
                var primaryName = primaryContact.GetType().Name;   
                Console.WriteLine($"Primary {primaryName}: {primaryContact}");
            }
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
        get => GetPrimary<EMailAddress>();
        set => SetPrimary(value);
    }

    public PhoneNumber PrimaryPhoneNumber
    {
        get => GetPrimary<PhoneNumber>();
        set => SetPrimary(value);
    }

    public PostalAddress PrimaryPostalAddress
    {
        get => GetPrimary<PostalAddress>();
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

    // Generic GetPrimary for PrimaryContactData
    // constrained on ContactData (Subclasses have to have parent of type Contactdata)
    private T GetPrimary<T>() where T : ContactData {
        int primarIndex = Array.IndexOf(ContactData.Types, typeof(T));
        return (T)_primaryContactData[primarIndex];
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