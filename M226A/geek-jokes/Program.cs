using GeekJokes.Models;
using GeekJokes.Services;
using System;
using System.Threading.Tasks;

namespace GeekJokes
{
    class Program
    {
        static async Task Main(string[] args)
        {
            JokeService jokeService = new JokeService(
                new JokeProvider(
                    new System.Net.Http.HttpClient()
                    ),
                new JokeAnalyzer()
                );
            bool printMoreJokes;

            System.Console.Clear();
            
            do
            {
                Joke joke = await jokeService.RetrieveAndAnalyzeJoke();
                Console.WriteLine(joke);

                Console.Write("\n=> Would you like to enjoy one more joke? [Y/n] ");
                var key = Console.ReadKey();
                Console.WriteLine("\n");
                printMoreJokes = key.KeyChar.ToString().ToLower() != "n";
                if (printMoreJokes)
                {
                    Console.Clear();
                }
            } while (printMoreJokes);
        }
    }
}
