using System;
using System.Collections.Generic;
using System.Text;

namespace Reversal
{
    public class StringReverser
    {
        public string Reverse(string text)
        {
            string reversed = "";

            // TODO Reverse the character order of the text and put the result in reversed.
            for (int i = text.Length -1   ; i  >= 0; i--) // -1 want start bij 0 en niet 1
            {
                char character = text[i];
                reversed += character;
            }

            // Please dont change the code below (automatic unit tests)
            return reversed;
        }
    }
}
