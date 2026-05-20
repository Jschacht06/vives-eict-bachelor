using System;
using System.Collections.Generic;
using System.Text;

namespace NumberManipulator
{
    public class Manipulator
    {
        public static int Reverse(int value)
        {
            int reversed = 0;
            while (value > 0)
            {
                int digit = value % 10; // rest is altijd je laatste nummer 123 / 10 =        12 met rest 3   3463463 / 10 = 346346 MET REST 3
                reversed = reversed * 10 + digit; 
                value /= 10; // laatste digit verwijderen
            }
            return reversed;
        }

        public static int Complement(int value)
        {
            int complement = 0;
            int placeValue = 1; // digits op de juist eplek

            while (value > 0)
            {
                int digit = value % 10; 
                complement += (9 - digit) * placeValue; // bereik is 1-9 dus  9 - het getal
                placeValue *= 10; // volgende positie door stapjes van 10: 10 100 1000 10000
                value /= 10; // laatste digit weg
            }

            return complement;
        }

        public static int DigitSum(int value)
        {
            int sum = 0;
            while (value > 0)
            {
                sum += value % 10; 
                value /= 10; 
            }
            return sum;
        }
    }
}
