using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SoloLearn
{
    class Program
    {
        static void Main(string[] args)
        {
            double discount = Convert.ToInt32(Console.ReadLine());

            Dictionary<string, double> coffee = new Dictionary<string, double>();
            coffee.Add("Americano", 50);
            coffee.Add("Latte", 70);
            coffee.Add("Flat White", 60);
            coffee.Add("Espresso", 60);
            coffee.Add("Cappuccino", 80);
            coffee.Add("Mocha", 90);


           
          
                discount/=100;
                coffee["Americano"] -= (coffee["Americano"]*discount);
                coffee["Latte"] -= (coffee["Latte"]*discount);
                coffee["Flat White"] -= (coffee["Flat White"]*discount);
                coffee["Espresso"] -= (coffee["Espresso"]*discount);
                coffee["Cappuccino"] -= (coffee["Cappuccino"]*discount);
                coffee["Mocha"] -= (coffee["Mocha"]*discount);

            
                    foreach (var k in coffee)
                    Console.WriteLine(k.Key+": "+k.Value);

        }
    }
}
