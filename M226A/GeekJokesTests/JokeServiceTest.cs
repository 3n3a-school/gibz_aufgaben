using Xunit;
using FluentAssertions;
using System.Threading.Tasks;
using Moq;
using GeekJokes.Services;
using GeekJokes.Models;
using System.Net.Http;

namespace GeekJokesTests
{
    public class JokeServiceTest
    {

        [Theory]
        [InlineData("I don't see women as objects. I consider each to be in a class of her own.", 171, 40, 2)]
        public async Task RetrieveAndAnalyzeJokeTest(string jokeText, int wordCount, int charCount, int funiness)
        {
            // arrange
            HttpClient httpClient = MockHttpClient.Create(jokeText);
            JokeService jokeService = new StaticJokeService(new Mock<JokeProvider>(httpClient).Object, new Mock<JokeAnalyzer>().Object,
                jokeText, wordCount, charCount, funiness);

            // act
            Joke joke = await jokeService.RetrieveAndAnalyzeJoke();

            // assert
            joke.Should().NotBeNull();
            joke.JokeText.Should().Be(jokeText);
            joke.Analytics.WordCount.Should().Be(wordCount);
            joke.Analytics.CharCount.Should().Be(charCount);
            joke.Analytics.Funniness.Should().Be(funiness);
            joke.Analytics.Funniness.Should().BeInRange(1, 5);
        }
    }
}