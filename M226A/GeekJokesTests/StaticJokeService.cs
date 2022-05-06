using System.Threading.Tasks;
using GeekJokes.Services;
using GeekJokes.Models;

namespace GeekJokesTests
{
    public class StaticJokeService : JokeService {

        string _jokeText;
        int _wordCount;
        int _charCount;
        int _funiness;

        public StaticJokeService(JokeProvider jokeProvider, JokeAnalyzer jokeAnalyzer, string jokeText, int wordCount, int charCount, int funiness)
            : base(jokeProvider, jokeAnalyzer) {
            _jokeText = jokeText;
            _wordCount = wordCount;
            _charCount = charCount;
            _funiness = funiness;
        }

        public override async Task<Joke> RetrieveAndAnalyzeJoke(bool includeSpecialChars = true, bool includeWhitespaces = true)
        {
            return new Joke()
            {
                JokeText = _jokeText,
                Analytics = new JokeAnalytics(_wordCount, _charCount, _funiness)
            };
        }
    }
}