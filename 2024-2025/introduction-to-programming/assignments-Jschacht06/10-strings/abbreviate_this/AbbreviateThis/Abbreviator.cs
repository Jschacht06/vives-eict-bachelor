using System;
using System.Collections.Generic;
using System.Text;

namespace AbbreviateThis
{
    public class Abbreviator
    {
        public string Abbreviate(string text)
        {
            string letters = "";
            bool firstLetter = true;

            // TODO Convert text to an abbreviation
            // TODO Make sure that the end result contains upper-case letters only
            // TODO If text is empty, than so should letters be
            for (int i = 0; i < text.Length; i++)
            {
                char character = text[i];
                if (text[i] != ' ' && text[i] != '\n' && text[i] != '\r') // als er een letter is
                {
                    if (firstLetter == true)
                    {
                        letters += character;
                        firstLetter = false; // enkel de eerste letter 
                    }
                }
                else
                {
                    firstLetter = true; // nieuw woord dus een nieuwe firstLetter
                }
                
            }

                    return letters.ToUpper(); 
        }
    }
}
