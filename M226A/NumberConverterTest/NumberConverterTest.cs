using Xunit;
using FluentAssertions;
using UnitTestingBasics;

using System.Collections;
using System.Collections.Generic;

namespace NumberConverterTest;

// Fact: parameterless test
// Theory: parametrised, test

class RoundDownDataGenerator : IEnumerable<object[]>
{
    public IEnumerator<object[]> GetEnumerator()
    {
        yield return new object[] { 12.4, 12};
        yield return new object[] { -1.2, -1 };
    }

    IEnumerator IEnumerable.GetEnumerator() => this.GetEnumerator();
}

class RoundToPowerOfTenDataGenerator : IEnumerable<object[]>
{
    // poweroften, input, expected
    public IEnumerator<object[]> GetEnumerator()
    {
        yield return new object[] { 2, 50, 100 };
        yield return new object[] { 2, 10, 0 };
    }

    IEnumerator IEnumerable.GetEnumerator() => this.GetEnumerator();
}

public class RoundingTest
{
    private readonly NumberConverter nc;
    public RoundingTest() {
        this.nc = new NumberConverter();
    }

    [Theory]
    [InlineData(12.5f, 13)]
    [InlineData(-1, -1)]
    [InlineData(float.MinValue, -3)]
    [InlineData(int.MinValue, int.MinValue)]
    public void RoundUp(float numberNow, int numberRounded)
    {
        nc.RoundUp(numberNow)
            .Should().Be(numberRounded);
    }

    [Theory]
    [ClassData(typeof(RoundDownDataGenerator))]
    public void RoundDown(float input, int expected)
    {
       nc.RoundDown(input).Should().Be(expected);
    }

    [Theory]
    [ClassData(typeof(RoundToPowerOfTenDataGenerator))]
    public void RoundToPowerOfTen(int powerOfTen, float input, int expected) {
        nc.RoundToPowerOfTen(input, powerOfTen).Should().Be(expected);
    }
}