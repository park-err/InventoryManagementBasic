using InventoryBasic2.InvMngmt;
using System;
using System.IO;

namespace InventoryBasic2
{
    class RunProgram
    {
        static void Main()
        {
            string init = "C:\\Users\\pwhel\\source\\repos\\InventoryBasic2\\InventoryBasic2\\itemList.txt";
            if (!File.Exists(@init))
            {
                Console.WriteLine("Fatal Error: Could not initialize");
            }
            else
            {
                ConsoleAppMenu run = new ConsoleAppMenu(init);
            }
        }
    }
}