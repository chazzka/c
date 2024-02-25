#include <stdio.h>

typedef struct Result {
    double value;
    char error;
} Result;

Result add(double a, double b) {
    return (Result) {a + b, '0'};
}

Result subtract(double a, double b) {
    return (Result) {a - b, '0'};
}

Result multiply(double a, double b) {
    return (Result) {a * b, '0'};
}

Result divide(double a, double b) {
    if (b == 0)
        return (Result) {0, '1'};

    return (Result) {a / b, '0'};
}

//Rekurzivní funkce, která snižuje hodnotu exponentu dokud je hodnota a větší než 1
//To znamená, že funkce uvnitř funkce se znovu volá dokud je hodnota a větší než 1
int recursive_factorial(int a) {
    if(a > 1)
        return a * recursive_factorial(a - 1);
}

Result factorial(int a) {
    int sum = 1;

    if (a < 0)
        return (Result) {0, '1'};
    else if (a == 0)
        return (Result) {sum, '0'};
    else 
        sum = recursive_factorial(a);
        return (Result) {sum, '0'};
}

//Rekurzivní funkce, která snižuje hodnotu exponentu dokud je exponent větší než 1
//To znamená, že funkce uvnitř funkce se znovu volá dokud je hodnota n větší než 1
double recursive_power(double a, double n) {
    if (n > 1)
        return a * recursive_power(a, n - 1);
}

Result power(double a, int n) {
    if (n < 0)
        return (Result) {0, '1'};
    else if (n == 0)
        return (Result) {1, '0'};
    else 
    {
        double final = recursive_power(a, n);
        return (Result) {final, '0'};
    }
}