using System;
using System.Collections.Generic;
using System.Text;

namespace BinaryNibble
{
    public class NumberSystemConverter
    {
        public string DecimalToBinary(int decimalValue)
        {
            // TODO Convert the decimal value to
            // binary string representation
            string formattedBinary = Convert.ToString(decimalValue, 10).PadLeft(8, '0'); // Convert.ToString(decimalValue, 2) Zet een int om naar een string volgens een bepaald stelsel  de , 2 maakt duidelijk dat we een binair stelsel willen als je hier een 10 zou zetten kom je terug hetzelfde getal uit  
            string binary = formattedBinary.Substring(0, 4) + " " + formattedBinary.Substring(4, 4); //Substring(0, 4) maakt een nieuwe string die begint bij de index van het eerste (0) charcter en 4 chars lang is

            // Please dont change the code below (automatic unit tests)
            return binary;
        }
    }
}
