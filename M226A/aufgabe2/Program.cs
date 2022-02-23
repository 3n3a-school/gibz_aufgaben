
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace M226A_AP_00005_V2
{
    class A
    {
        public A()
        {
            Console.Write("A ");
        }
    }

    class B : A
    {
        public B()
        {
            Console.Write("B ");
        }
    }

    class C
    {
        private A mA;
        private B mB;

        public C()
        {
            mA = new A();
            mB = new B();
            Console.Write("C ");
        }
    }

    class D : B
    {
        public D()
        {
            Console.Write("D ");
        }
    }

    class E : C
    {
        private D mD;
        public E()
        {
            mD = new D();
            Console.Write("E ");
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            E mE = new E();
        }
    }
}