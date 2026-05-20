using System;
using System.Collections.Generic;
using System.Text;

namespace Solution
{
    public class PangramChecker
    {
        public bool IsPangram(string text)
        {
            bool isAPangram = true;

            // TODO Check if text is a pangram and thereby contains all the letters of the alphabet
            // TODO Convert text to lowercase first

            char ch = 'a'; // beginnen bij het begin van het alfabet
            while (isAPangram && ch <= 'z') // loop alle letters van het alfabet
            {
                if (text.IndexOf(ch) < 0) // output -1 als een character niet is gevonden
                {
                    isAPangram = false;
                }
                ch++; // volgende letter testen
            }

            return isAPangram;
        }
    }
}
