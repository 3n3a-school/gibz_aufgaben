namespace ContactData;

public class ExternalPerson : Person
{
    public string Company { get; set; }

    public override void PrintPersonData()
    {
        base.PrintPersonData();
        Console.ForegroundColor = ConsoleColor.DarkGreen;
        Console.WriteLine($"Company: {Company}");
    }
}
