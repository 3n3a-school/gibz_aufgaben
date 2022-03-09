namespace UnitTestingBasics;
public class NumberConverter
{

    private StringConverter _stringConverter;
    public NumberConverter(StringConverter sc) {
        _stringConverter = sc;
    } 

    // Source Floor / Ceil implementations: https://math.stackexchange.com/a/2886808
    public float Floor(float value) {
        // f(x) = x - (x mod 1)
        return value - (value % 1);
    }

    public float Ceiling(float value) {
        // f(x) = x - (1 - (x mod 1))
        return value + (1-(value % 1));
    }

    public int RoundUp(float value)
    {
        return (int)Ceiling(value);
    }

    public int RoundDown(float value)
    {
        return (int)Floor(value);
    }

    public int RoundToPowerOfTen(float value, int precisionExponent = 1)
    {
        // round value to 10^exponent
        int precision = (int)Math.Pow(10, precisionExponent);
        MidpointRounding mode = value >= 0 ? MidpointRounding.AwayFromZero : MidpointRounding.ToZero;
        return (int)Math.Round(value/precision, mode) * precision;
    }

    public int RoundToPowerOfTen(string numericString, int precisionExponent = 1)
    {
        int number = _stringConverter.ConvertToInt(numericString);
        return RoundToPowerOfTen(number, precisionExponent);
    }
}