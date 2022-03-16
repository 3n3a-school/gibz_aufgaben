namespace ContactData;

class Program
{
    static void Main(string[] args)
    {
        Person jamal = new InternalPerson
        {
            FirstName = "Jamal",
            LastName = "Habib",
            Gender = EGender.MALE,
            Birthday = new DateTime(1999, 8, 22),
            Department = "Testing",
            EntryDate = new DateTime(2008, 5, 1)
        };

        jamal.AddContactData(
            new EMailAddress("jamalh@outlook.com"),
            new PhoneNumber("+41 77 746 65 61", EPhoneNumberType.MOBILE),
            new PostalAddress("Brunnweg 128", 6331, "Hünenberg")
        );

        Person jessica = new ExternalPerson
        {
            FirstName = "Jessica",
            LastName = "Maritz",
            Gender = EGender.FEMALE,
            Birthday = new DateTime(2001, 5, 31),
            Company = "IT & Stuff GmbH"
        };

        jessica.AddContactData(
            new EMailAddress("jm@it-stuff.com"),
            new EMailAddress("jessi@bluewin.ch"),
            new PostalAddress("Mühlacker 42a", 6301, "Zug")
        );

        InternalPerson jules = new InternalPerson
        {
            FirstName = "Jules",
            LastName = "Martin",
            Gender = EGender.MALE,
            Birthday = new DateTime(1998, 2, 6),
            Department = "Accounting",
            EntryDate = new DateTime(2020, 8, 1)
        };

        jules.AddContactData(
            new EMailAddress("jm@digitalstube.ch"),
            new PhoneNumber("+41 41 728 10 10"),
            new PhoneNumber("+41 58 450 18 18"),
            new PhoneNumber("+41 79 118 14 44", EPhoneNumberType.MOBILE)
        );

        ExternalPerson jamie = new ExternalPerson
        {
            FirstName = "Jamie",
            LastName = "Olivera",
            Gender = EGender.UNKNOWN,
            Birthday = new DateTime(1992, 12, 31),
            Company = "Bits & Bytes"
        };

        jamie.AddContactData(
            new EMailAddress("jamie.o@b-and-b.io"),
            new PostalAddress("Untergrund 8", 6300, "Zug")
        );

        Console.Clear();

        Console.ForegroundColor = ConsoleColor.Red;
        Console.WriteLine("\n>>>>>>>>>>>>>>>>>>>> START PRINTING  <<<<<<<<<<<<<<<<<<<<");

        jamal.Print();      // Person           InternalPerson      PrintPersonData of base class
        jessica.Print();    // Person           ExternalPerson      PrintPersonData of derived class
        jules.Print();      // InternalPerson   InternalPerson      PrintPersonData of base class       !!!
        jamie.Print();      // ExternalPerson   ExternalPerson      PrintPersonData of derived class

        jamal.PrintPersonData();        // PrintPersonData of base class
        jessica.PrintPersonData();      // PrintPersonData of derived class
        jules.PrintPersonData();        // PrintPersonData of derived class     !!!
        jamie.PrintPersonData();        // PrintPersonData of derived class
    }
}
