namespace ContactManagment
{
    public enum Gender
    {
        Male,
        Female,
        Other
    }

    public enum PhoneNumType {
        Mobile,
        Landline
    }

    public enum ContactTypes {
        Phonenumber,
        Email,
        Address
    }

    public class Phonenumber {
        public string Number {get;set;}
        public PhoneNumType Type {get;set;}
    }

    public class Email
    {
        public string EmailAddress {get;set;}
    }

    public class Address
    {
        public string Street {get;set;}
        public string Postcode {get;set;}
        public string City {get;set;}
    }

    public class ContactData {
        public ContactTypes PrimaryOption {get;set;}
        public int[] PrimaryOptionIndexes {get;set;} = new int[] {0,0,0};

        public List<Email> Emails {get;set;}
        public List<Phonenumber> Phonenumbers {get;set;}
        public List <Address> Addresses {get;set;}

        
        // Gets the PrimaryOption's Primary Contact Oprtion 😎
        public object GetPrimary() {
            switch (PrimaryOption)
            {
                case ContactTypes.Email:
                    return Emails[PrimaryOptionIndexes[0]];
                
                case ContactTypes.Phonenumber:
                    return Phonenumbers[PrimaryOptionIndexes[1]];
                
                case ContactTypes.Address:
                    return Addresses[PrimaryOptionIndexes[2]];
                
                default:
                    return null;
            }
        }
    }

    public class Person
    {
        public string FirstName {get; set;}
        public string LastName {get;set;}
        public DateTime Birthday {get;set;}
        public Gender Gender {get;set;}
        public ContactData ContactOptions {get;set;}
    }

    public class InternalPerson : Person
    {
        public string Department { get;set; }
        public DateTime StartingDate {get; set;}
    }

    public class ExternalPerson : Person {
        public string Company {get;set;}
    }

    public class Program
    {
        public static List<Person> Contacts = new List<Person>();
        public static void Main(string[] args) {
            Person p = new Person() {
                FirstName = "Hans",
                LastName = "Zimmer",
                Birthday = new DateTime(2020, 12, 1),
                Gender = Gender.Female,
                ContactOptions = new ContactData() {
                    PrimaryOption = ContactTypes.Email,
                    Addresses = new List<Address>() {
                        new Address() {
                            City = "Lucerne",
                            Postcode = "6005",
                            Street = "Mainstreet 1"
                        }
                    },
                    Emails = new List<Email>() {
                        new Email() {
                            EmailAddress = "test@enea.tech"
                        }
                    },
                    Phonenumbers = new List<Phonenumber>() {
                        new Phonenumber() {
                            Number = "+417942334400",
                            Type = PhoneNumType.Mobile
                        }
                    }
                }
            };
            Contacts.Add(p);
            Console.WriteLine(
                ObjectDumper.Dump(Contacts[0])
            );
        }
    }
}
