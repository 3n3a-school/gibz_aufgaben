namespace ContactData;

public class InternalPerson : Person
{
    public string Department { get; set; }
    public DateTime EntryDate { get; set; }

    public new void PrintPersonData()
    {
        base.PrintPersonData(); // needs to be right after signature
        Console.ForegroundColor = ConsoleColor.DarkCyan;
        Console.WriteLine($"Department: {Department}");
        Console.WriteLine($"Entry date: {EntryDate.ToString("dd.MM.yyyy")}");
    }
}
