using System;
using System.Collections.Generic;
using System.Text;

namespace ParenthesesChecker
{
    public class CodeLinter
    {
        public bool HasMatchingParentheses(string code)
        {

            bool isValid = true;
            int counter = 0;

            // TODO Determine if the code has matching parentheses
            for (int i = 0; i < code.Length; i++)
            {
                char character = code[i];
                if (character == '(')
                {
                    counter++;
                }
                else if (character == ')')
                {
                    counter--;
                }
                if (counter < 0)
                {
                    isValid = false;
                }
                    
            }
            if (counter != 0) 
            {
                isValid = false;
            }
                // Please dont change the code below (automatic unit tests)
                return isValid;
        }
    }
}
