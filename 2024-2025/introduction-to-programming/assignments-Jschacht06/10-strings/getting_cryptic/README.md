# Getting Cryptic

Start a new Console Application in C#.

1. Make a methode to ask the user for the input a word and returns it as a string.
2. Make a methode to encrypt each letter of this word in the following way:
* It takes the first and the last digit from the ASCII code of the letter and concatenates them into a string, which will represent the result.
* In the beginning of the string, which represents the result, we will insert the symbol which matches the following condition:
    * ASCII code of the letter + the last digit of the ASCII code of the letter.
* After that in the end of the string, which represents the result, you concatenate the character which matches the following condition:
    * ASCII code of the letter - the first digit of the ASCII code of the letter.
* The method should return the encrypted string.

Example for the letter j:

* j → p16i
    * ASCII code of j is 106 → First digit – 1, last digit – 6.
    * We concatenate the first and the last digit → 16.
    * At the beginning of the string, which represents the result, concatenate the symbol, which you get from the sum of the ASCII code + the last digit → 106 + 6 → 112 → p.
    * At the end of the string, which represents the result, concatenate the symbol, which you get from subtracting the ASCII code – the first digit → 106 - 1 → 105 → i.

Now make use of both these methods in the main method of your program and output the result.

If you enter the word SoftUni you should get:
`V83Kp11nh12ez16sZ85Mn10mn15h`