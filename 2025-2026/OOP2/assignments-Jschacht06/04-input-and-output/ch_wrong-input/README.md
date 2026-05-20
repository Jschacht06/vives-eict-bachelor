# Wrong input

What happens when the user inputs something different than a number. For example a character `b` or a string `Hello`? Can you explain what happens? How can we detect this?

```cpp
cout << "Please enter a number: ";

int number;
cin >> number;
```

It will not crash the application like in C# it will instead just fail the conversion and put up an error flag. You can check this with cin.fail() this will go to true if the conversion failed.

You could make an if statement if this is true it displays a message to the user and then you can clear the error again with cin.clear()