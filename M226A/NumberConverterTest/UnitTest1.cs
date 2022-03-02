using Xunit;
using FluentAssertions;
using UnitTestingBasics;

namespace NumberConverterTest;

public class RoundingTest
{
    private readonly NumberConverter nc;
    public RoundingTest() {
        this.nc = new NumberConverter();
    }

    [Fact]
    public void RoundUp()
    {
        nc.RoundUp(12.5f).Should().Be(13);
    }
}