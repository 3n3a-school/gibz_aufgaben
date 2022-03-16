namespace ContactData;

public class PhoneNumber : ContactData
{
    public string Number { get; set; }
    public EPhoneNumberType PhoneNumberType { get; set; }

    public string Icon => PhoneNumberType switch
    {
        EPhoneNumberType.LANDLINE => " ☏",
        EPhoneNumberType.MOBILE => "📱",
        _ => " ✆"
    };

    public PhoneNumber(string number, EPhoneNumberType type = EPhoneNumberType.LANDLINE)
    {
        Number = number;
        PhoneNumberType = type;
    }

    public override string ToString() => $"{Icon} {Number}";
}
