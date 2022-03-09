
using Moq;
using System.Net.Http;
using Moq.Protected;
using System.Threading.Tasks;
using System.Threading;
using System.Net;

namespace GeekJokesTests
{
    public class MockHttpClient
    {

        // Not mocking the HttpClient, but mocking the HttpMessageHandler
        // this will then be injected into HttpClient and will return whatever
        // Source: https://stackoverflow.com/a/56146338
        public static HttpClient Create(string returnValue)
        {
            var handlerMock = new Mock<HttpMessageHandler>(MockBehavior.Strict);
            handlerMock
               .Protected()
               // Setup the PROTECTED method to mock
               .Setup<Task<HttpResponseMessage>>(
                  "SendAsync",
                  ItExpr.IsAny<HttpRequestMessage>(),
                  ItExpr.IsAny<CancellationToken>()
               )
               // prepare the expected response of the mocked http call
               .ReturnsAsync(new HttpResponseMessage()
               {
                   StatusCode = HttpStatusCode.OK,
                   Content = new StringContent($"{{\"joke\": \"{returnValue}\"}}"),
               })
               .Verifiable();

            return new HttpClient(handlerMock.Object);
        }
    }
}