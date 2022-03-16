using System.Reflection;
using System.Text;

namespace JsonSerializer;

// enforces type-safety of serializable object
public class Serializer<T> {
    private T _obj;
    private StringBuilder _sb;

    public Serializer(T obj) {
        _obj = obj;
        _sb = new StringBuilder();
    }

    // serializes all fields of a given object
    // into a json-like string
    public string toJson() {

        FieldInfo[] fields = _obj.GetType().GetFields(BindingFlags.Public | BindingFlags.Instance);

		_sb.AppendLine("{\n");
		
        foreach (var fieldInfo in fields)
        {
            _sb.AppendLine($"  \"{fieldInfo.Name}\": \"{fieldInfo.GetValue(_obj)}\",");
        }
		
		_sb.AppendLine("\n}");

        return _sb.ToString();
    }
}
