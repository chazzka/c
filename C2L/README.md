## Iterativní vs Rekurzivní funkce

[Programming Loops vs Recursion - Computerphile](https://youtu.be/HXNhEYqFo0o?si=ORGNZPw1LE_N7M7W)


### Factorial

5! = 120

#### Normal recursion

```c
int fact(int num) {
    if(num == 1) {
        return num;
    }
    
    return num * fact(num -1);
}
```


### Fibonacci

![Fibbo](https://upload.wikimedia.org/wikipedia/commons/thumb/1/15/Fibonacci_Squares.svg/1920px-Fibonacci_Squares.svg.png)

#### Normal recursion

```c
int fibo(int index) {
    if(index <= 1) {
        return index;
    }
    
    return fibo(index - 1) + fibo(index - 2);
}
```






