using System;
using System.Collections.Generic;
using System.Text;

namespace SuperStringTheory
{
    public class SuperString
    {
        // Text getter method
        // TODO - Replace with property
    public string Text
    {
        get { return text; }
        set { if (value == null) { value = ""; } text = value; }
        }
        public SuperString(string initialText = "")
        {
            Text = initialText;
        }


        public void Append(string text)
        {
            // TODO - Append the local argument text behind the attribute text
            Text += text;

        }


        // TODO - Add a Prepend() method
        public void Prepend(string text) {
            Text = text + Text;
        }

        public void TrimStart()
        {
            int startIndex = 0;
            while (startIndex < Text.Length && Text[startIndex] == ' ')
            {
                startIndex++;
            }
            Text = Text.Substring(startIndex);
        }

        public void TrimEnd()
        {
            int endIndex = Text.Length - 1;
            while (endIndex >= 0 && Text[endIndex] == ' ')
            {
                endIndex--;
            }
            Text = Text.Substring(0, endIndex + 1);
        }

        public void Trim()
        {
            TrimStart();
            TrimEnd();
        }
        public bool IsValidNumber()
        {
            text = text.Trim();
            if (text.Length == 0) return false;

            for (int i = 0; i < text.Length; i++)
            {
                if (text[i] < '0' || text[i] > '9')
                    return false;
            }

            return true;
        }

        // Attributes
        private string text = "";
    }
}
