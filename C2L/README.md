## Iterativní vs Rekurzivní funkce

[Programming Loops vs Recursion - Computerphile](https://youtu.be/HXNhEYqFo0o?si=ORGNZPw1LE_N7M7W)

[Tail recursion - Computerphile](https://youtu.be/_JtPhF8MshA?si=SQxuLJ5lCt8WNb1M)


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

#### Tail recursion

4 * (4 - 1) -> 12 * (3 - 1) -> 24 * (2 - 1) = 24

3 * (3 - 1) -> 6 * (2-1) = 6

2 * (2 - 1) -> 2 -> go

```c
int go(int num, int iterator) {
    return num * (iterator - 1);
}
```

fac 3 \
= go 3 2\
= go 6 1

```c
int fac(int what, int res) {
    if(what <= 1) {
        return res;
    }
    
    return fac(what - 1, go(res, what));
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

#### Tail recursion

One fibonacci step: 0 1 -> 1 2 (swap and add -> iterate)

```c
typedef struct FiboTuple {
    int first;
    int second;
} FiboTuple;


FiboTuple iterate(FiboTuple old) {
    return (FiboTuple) {old.second, old.first + old.second};
}

int fibotupletail(int index, FiboTuple tup) {
    if(index < 1) {
        return tup.first;
    }
    
    return fibotupletail(index - 1, iterate(tup));
}

for(int i = 0; i < 5; i++) {
    printf("%d,", fibotupletail(i, (FiboTuple){0,1}));    
}
```



