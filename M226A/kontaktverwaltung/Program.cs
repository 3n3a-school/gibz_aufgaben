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
        public void PrintPersonInfos(ref InternalPerson person) {
            PropertyInfo[] properties = typeof(person).GetProperties();
            foreach (PropertyInfo property in properties)
            {
                Console.WriteLine("{0} - type {1}", property,
                    property.GetType().Name);
            }
        }
        public static void Main(string[] args) {
            InternalPerson internalPerson = new();
            ExternalPerson externalPerson = new();
            PrintPersonInfos(ref internalPerson);
        }
    }
}
