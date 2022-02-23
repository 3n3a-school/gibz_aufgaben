using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace A1 {
    class A
    {
        public A() {
            Console.Write("A ");
        }
    }

    class B:A 
    {
        public B() {
            Console.Write("B ");
        }
    }

    class C:B
    {
        public C() {
            Console.Write("C ");
        }
    }

    class Program
    {
        static void Main(string[] args) {
            C cObj = new C();
            Console.Write("| ");
            B bObj = new B();
        }
    }
}
