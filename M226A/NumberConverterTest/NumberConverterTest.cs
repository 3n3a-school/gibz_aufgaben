using Xunit;
using FluentAssertions;
using UnitTestingBasics;

namespace NumberConverterTest;

// Fact: parameterless test
// Theory: parametrised, test

public class RoundingTest
{
    private readonly NumberConverter nc;
    public RoundingTest() {
        this.nc = new NumberConverter();
    }

    [Theory]
    [InlineData(12.5f, 13)]
    [InlineData(-1, -1)]
    [InlineData(int.MinValue, int.MinValue)]
    public void RoundUp(int numberNow, int numberRounded)
    {
        nc.RoundUp(numberNow)
            .Should().Be(numberRounded);
    }

    [Fact]
    public void RoundDown()
    {
       nc.RoundDown(12.5f).Should().Be(12);
    }
}