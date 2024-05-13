using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Threading.Tasks;

namespace InventoryBasic2.InvMngmt
{
    internal class Items
    {
        public void CreateItem()
        {
            // in the future, create item will append an item file
            // the item file will keep track of items created
            // the file will be read and each line will create an instance of Item
            // after the use of the program, the items will be destroyed, until needed again

            // cins will only be for console build. Once moved to GUI this will be changed
            // string createDescription; int createCount; double createCost, createRetail;

            Console.WriteLine("Enter item description: ");
            string createDescription = Console.ReadLine();
            Console.WriteLine("Enter item count: ");
            int createCount = Convert.ToInt32(Console.Read());
            Console.WriteLine("Enter item cost per unit: ");
            double createCost = Convert.ToDouble(Console.Read());
            Console.WriteLine("Enter item retail price per unit: ");
            double createRetail = Convert.ToDouble(Console.Read());

            PrintInv(createDescription, createCount, createCost, createRetail);
        }

        public void PrintInv(string desc, int count, double cost, double retail)
        {
            Console.WriteLine($"{desc} {count} {cost} {retail}");
        }
    }
}
