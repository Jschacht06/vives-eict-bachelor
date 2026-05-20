# Magic numbers have no meaning

The following code snippet calculates the total invoice amount that has to be paid. The calculation of the total amount contains a magic number. Can you fix it?

```cpp
double invoiceAmount = 2342.12;   // Just a random value

double totalInvoice = 0.21 * invoiceAmount;   // 0.21 ?
```

fix:

```cpp
double invoiceAmount = 2342.12;   // Just a random value
const double BTW = 0.21;
double totalInvoice = BTW * invoiceAmount;   
```
