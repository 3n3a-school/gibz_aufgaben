
namespace GeoFigures
{
    public class Coordinate
    {
        public float X;
        public float Y;

        public Coordinate(float X, float Y) {
            X = X;
            Y = Y;
        }
    }

    public abstract class Figure
    {
        public Coordinate location {get;set;}
        private int _scaleFactor;

        public Figure( float X = 100.0, float Y = 100.0 ) {
            location = new Coordinate(X, Y);
        }

        public abstract void PrintPosition();
    }

    public class Rect : Figure
    {
        public float _width;
        public float Width {
            get => _width;
            set {
                _width = Math.Abs(value);
        }}

        public float _height;
        public float Height {
            get => _height;
            set {
                _height = Math.Abs(value);
        }}

        public Rect(float SideLength): base() {
            Width = SideLength;
            Height = SideLength;
        }

        public Rect(float Width, float Height): base() {
            Width = Width;
            Height = Height;
        }

        public Rect(float X, float Y, float Width = 100f, float Height = 100f): base(X, Y) {
            Width = Width;
            Height = Height;
        }

        private Coordinate CalculateLowerRightPoint() {
            return new Coordinate(location.X + Width, location.Y + Height);
        }

        public override void PrintPosition()
        {
            Coordinate upperleft = location;
            Coordinate lowerright = CalculateLowerRightPoint();
            Console.WriteLine($"Rectangle Upper Left Point: X: {upperleft.X} Y: {upperleft.Y}");
            Console.WriteLine($"Rectangle Lower Right Point: X: {lowerright.X} Y: {lowerright.Y}");
        }
    }

    public class Circle : Figure
    {
        public float _radius;
        public float Radius {
            get => _radius;
            set {
                _radius = Math.Abs(value);
        }}

        public Circle(float radius): base() {
            Radius = Radius;
        }

        public Circle(float X, float Y, float radius = 100f): base(X, Y) {
            Radius = Radius;
        }

        private Coordinate CalculateMiddlepoint() {
            return new Coordinate(location.X + Radius, location.Y + Radius);
        }

        public override void PrintPosition()
        {
            Coordinate middlepoint = CalculateMiddlepoint();
            Console.WriteLine($"Circle Middlepoint: X: {middlepoint.X} Y: {middlepoint.Y}");
        }
    }

    public class Program
    {
        public static void Main(string[] args) {

        }
    }
}