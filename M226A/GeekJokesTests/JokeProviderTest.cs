using Xunit;
using FluentAssertions;
using System.Threading.Tasks;

using GeekJokes;
using GeekJokes.Services;
using GeekJokes.Models;

namespace GeekJokesTests
{
    public class JokeProviderTest
    {
        JokeProvider _jokeProvider;
        public JokeProviderTest()
        {
            _jokeProvider = new JokeProvider(
                MockHttpClient.Create("I don't see women as objects. I consider each to be in a class of her own.")
                );
        }

        [Fact]
        public async Task GetJokeTestAsync()
        {
            Joke joke = await _jokeProvider.GetJoke();
            joke.JokeText.Should().Be("I don't see women as objects. I consider each to be in a class of her own.");
            joke.Analytics.Should().Be(null); // Analytics not yet set
        }
    }
}