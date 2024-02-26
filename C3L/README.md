### Struktury + koncová rekurze


#### Struct

```c
typedef struct Result {
 int value;
 char error;
}

Result ireturnit(Result res) {
  return (Result) {res.value + 2, res.error};
}

int main() {
  const Result res = {1,2};
  // bad
  Result res;
  res.value = 5;

}
```



[Tail recursion - Computerphile](https://youtu.be/_JtPhF8MshA?si=SQxuLJ5lCt8WNb1M)

#### Factorial

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

#### Fibonacci

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
