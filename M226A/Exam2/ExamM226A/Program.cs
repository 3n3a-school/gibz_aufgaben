using System;

namespace ExamM226A
{
    class Program
    {
        static void Main(string[] args)
        {
            Partner pg = new Partner(new ContactPerson(), 3);
            Competition c = new IndividualCompetition("Test");
        }
    }
}