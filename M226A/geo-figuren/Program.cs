
namespace GeoFigures
{
    public class Coordinate
    {
        public float X {get;set;}
        public float Y {get;set;}

        public Coordinate(float _x, float _y) {
            X = _x;
            Y = _y;
        }
    }

    public abstract class Figure
    {
        protected Coordinate location {get;set;}
        protected int _scaleFactor;

        public Figure( float x = 100f, float y = 100f ) {
            location = new Coordinate(x, y);
        }

        public virtual void PrintPosition() {
            Console.WriteLine($"Figure Upper Left Point: X: {location.X} Y: {location.Y}");
        }

        public abstract void PrintArea();
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

        public Rect(float sideLength): base() {
            Width = sideLength;
            Height = sideLength;
        }

        public Rect(float width, float height): base() {
            Width = width;
            Height = height;
        }

        public Rect(float x, float y, float width = 100f, float height = 100f): base(x, y) {
            Width = width;
            Height = height;
        }

        private Coordinate CalculateLowerRightPoint() {
            return new Coordinate(location.X + Width, location.Y + Height);
        }

        public override void PrintPosition()
        {
            base.PrintPosition();
            Coordinate lowerright = CalculateLowerRightPoint();
            Console.WriteLine($"Rectangle Lower Right Point: X: {lowerright.X} Y: {lowerright.Y}");
        }

        public override void PrintArea()
        {
            float area = Width * Height;
            Console.WriteLine($"Rectangle Area {area} Scale Factor {_scaleFactor}");
        }
    }

    public class Triangle : Figure {
        protected new double _scaleFactor;
        public override void PrintArea()
        {
            throw new NotImplementedException();
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

        public override void PrintArea()
        {
            throw new NotImplementedException();
        }
    }

    public class Program
    {
        public static void Main(string[] args) {
            Circle c1 = new Circle(50);
            c1.PrintPosition();

            Circle c2 = new Circle(50, 50, 99);
            c2.PrintPosition();

            Rect r1 = new Rect(50);
            r1.PrintPosition();

            Rect r2 = new Rect(34, 45);
            r2.PrintPosition();
            r2.PrintArea();

            Rect r3 = new Rect(34, 45, 99, 88);
            r3.PrintPosition();
        }
    }
}