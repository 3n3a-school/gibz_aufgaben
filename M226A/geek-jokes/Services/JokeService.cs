using GeekJokes.Models;
using System.Threading.Tasks;

namespace GeekJokes.Services
{
    /// <summary>
    /// The joke service is the central piece of the application.
    /// It might be used to retrieve a joke containing full analytics.
    /// </summary>
    public class JokeService
    {
        readonly JokeProvider _jokeProvider;
        readonly JokeAnalyzer _jokeAnalyzer;

        public JokeService(JokeProvider jokeProvider, JokeAnalyzer jokeAnalyzer)
        {
            _jokeProvider = jokeProvider;
            _jokeAnalyzer = jokeAnalyzer;
        }

        /// <summary>
        /// This method retrieves a joke using an instance of JokeProvider and
        /// analyzes that joke using an instance of JokeAnalyzer.
        /// </summary>
        /// <param name="includeSpecialChars">Whether non-alphanumeric characters should be counted in the joke analytics.</param>
        /// <param name="includeWhitespaces">Whether whitespace characters should be counted in the joke analytics.</param>
        /// <returns></returns>
        public virtual async Task<Joke> RetrieveAndAnalyzeJoke(bool includeSpecialChars = true, bool includeWhitespaces = true)
        {
            // Retrieve joke
            Joke joke = await _jokeProvider.GetJoke();

            // Analyze Joke
            int wordCount = _jokeAnalyzer.GetWordCount(joke);
            int charCount = _jokeAnalyzer.GetCharCount(joke, includeSpecialChars, includeWhitespaces);
            int funnyness = _jokeAnalyzer.GetFunniness(joke);

            // Data Model of JokeAnalytics
            JokeAnalytics analytics = new JokeAnalytics(wordCount, charCount, funnyness);
            joke.Analytics = analytics;

            return joke;
        }
    }
}
