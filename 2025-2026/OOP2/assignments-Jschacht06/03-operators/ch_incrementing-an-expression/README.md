# Incrementing an expression

Knowing what you know now, could you answer the following question? Would it be possible to use the increment operator on an expression as demonstrated in the following code snippet?

```cpp
int x = 12;
int y = 34;

int z = (x + y)++;
```
No this would not work because incrementing can only be done on variables not on literal values. This application will first do x+y so result in a literal value 46 and then try to do 46++ but thats not possible you would have to do a second line that says z++