﻿using System;

namespace InventoryBasic2.InvMngmt
{
    public class ConsoleAppMenu
    {

        public ConsoleAppMenu(string init)
        {
            int temp1; int temp2;
            Items items = new Items();
            char keepGoing = 'y';
            while (keepGoing == 'y')
            {
                Console.WriteLine("Pick one:\n");
                Console.WriteLine("	1. Create item\n");
                Console.WriteLine("	2. Check inventory\n");
                Console.WriteLine("	3. Check sales\n");
                Console.WriteLine("	4. Import sales\n");
                Console.WriteLine("	5. Export inventory\n");

                char input = (char)Console.Read();
                temp1 = Console.Read();
                temp2 = Console.Read();

                switch (input)
                {
                    case '1': items.CreateItem(init); break;
                    case '2': Console.WriteLine(input); break;
                    case '3': Console.WriteLine(input); break;
                    case '4': Console.WriteLine(input); break;
                    default: Console.WriteLine(input); break;
                }

                keepGoing = (char)Console.Read();
                temp1 = Console.Read();
                temp2 = Console.Read();
            }
        }
    }
}
