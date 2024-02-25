#include <stdio.h>
#include "./lib/mymath.c"

int main() {
    printf("add(2, 3) = %f\n", add(2, 3).value);
    printf("subtract(5, 3) = %f\n", subtract(5, 3).value);
    printf("multiply(3, 7) = %f\n", multiply(3, 7).value);
    printf("divide(8, 4) = %f\n", divide(8, 4).value);
    printf("factorial(3) = %f\n", factorial(3).value);
    printf("power(3, 3)= %.8f\n", power(3, 3).value);
    return 0;
}