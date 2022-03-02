using System;
using System.Reflection;
using System.Collections.Generic;

namespace ContactManagment
{
    enum Gender
    {
        Male,
        Female,
        Other
    }

    enum PhoneNumType {
        Mobile,
        Landline
    }

    class ContactType
    {
        int PrimaryOptionIndex {get;set;}
    }

    class Phonenumber : ContactType {
        string Number {get;set;}
        PhoneNumType Type {get ;set;}
    }

    class Email : ContactType
    {
        string EmailAddress {get;set;}
    }

    class Address : ContactType
    {
        string Street {get;set;}
        string Postcode {get;set;}
        string City {get;set;}
    }

    class ContactData {
        List<Email> Emails {get;set;}
        List<Phonenumber> Phonenumbers {get;set;}
        List <Address> Addresses {get;set;}
    }

    public class Person
    {
        string FirstName {get; set;}
        string LastName {get;set;}
        DateTime Birthday {get;set;}
        Gender Gender {get;set;}
        ContactData ContactOptions {get;set;}
    }

    public class InternalPerson : Person
    {
        string Department { get;set; }
        DateTime StartingDate {get; set;}
    }

    public class ExternalPerson : Person {
        string Company {get;set;}
    }

    public class Program
    {
        public void PrintPersonInfos(Person p) {
            string[] fields = new string[] {
                "FirstName",
                "LastName"
            };

            foreach (string field in fields)
            {
                Console.WriteLine($"{field}: {p.GetField(field)}");
            }
        }
        public static void Main(string[] args) {
            InternalPerson internalPerson = new();
            ExternalPerson externalPerson = new();
            PrintPersonInfos(internalPerson);
        }
    }
}
