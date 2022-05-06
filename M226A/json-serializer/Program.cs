

namespace JsonSerializer;

public class Program {
	public static void Main() {
		Puppet puppet = new();
		Computer pc = new();

		Serializer<Puppet> s = new Serializer<Puppet>(puppet);
		System.Console.WriteLine(s.toJson());
		
        Serializer<Computer> s2 = new Serializer<Computer>(pc);
		System.Console.WriteLine(s2.toJson());
	}
}