### STACK BASED programming
#### Ukazatel, Pole, struktura, sizeof, linked list

Ukazatel

```c
int value = 5;  // 4B
int *pValue = &value;  // 8B

int * pointer = NULL; // pointer can be null, dulezite pro LL

printf("%d\n", *pValue); // 5 - dereference
printf("%p\n", pValue);
printf("%p\n", &value); 
```

Pole

```c
const int arr[] = {1,2,3,4}; //staticka velikost, nelze menit
// arr[0] = 1; // bad practice, proto const

int arr[50]; // prazdne, staticka velikost, bad practice!
    
printf("%d\n", *arr);
printf("%d\n", *arr+1);
    
printf("Size of arr variable: %lu\n", sizeof(arr));
printf("Size of arr passed through function: %lu\n", arrsize(arr));

//pozor:
int arr2[] = {1,2,3,4};
int *arr3 = arr2;
arr3[0] = 55; // mutates arr2!!!!
//fix:
const int arr4[] = {1,2,3,4};
//int *arr5 = arr4; // error
```

print:

```c
void printArrLoop(int *arr, size_t size) {
    for(int i = 0; i < size; i++)
        printf("%d,", arr[i]);
}

// this prints array using loop and pointer arithmetic
void printArrLoopP(int *arr, size_t size) {
    TODO:
}

// this print array using recursion
void printArrRec(int *arr, size_t size) {
    TODO:
}
```


### Struktura, string literals

```c

typedef struct {
    char * name;
    int age;
} Person;


void printPerson(Person p) {
    printf("name: %s,", p.name);
    printf("age: %d", p.age);
}


int main()
{
    //readonly string literal
    
    char * sl = "totonejdezmenit";

    // sl[0] = 'A'; toto spadne

    char *sl2 = sl; // kopie, protoze readonly pamet se kopiruje
    
    Person p = {"adam", 5};

    printf("%ld", sizeof(p)); // ???
    
    Person p2 = p; // kopie, diky stacku!!!

   // demonstrace, ze to je kopie:

    p.name = "oto"; // bad practice! p by melo byt const
    
    printPerson(p);
    
    printPerson(p2);
    
    return 0;
}
```


### Linked list
```c
#include <stdio.h>


typedef struct Node {
    struct Node * next;
    double val;
} Node;


void printL(Node * n) {
    if(n == NULL) {
        printf("NULL\n");
        return;
    }
    printf("%lf->", n->val);
    printL(n->next);
}

int main()
{
    Node first = {NULL, 5};
    
    Node second = {&first, 6};
    
    printL(&second);
    
    Node third = {&second, 7};
    
    printL(&third);
    
    // zkracene:
    
    Node all = {&(Node){&(Node){NULL, 8}, 6}, 9};
    
    printL(&all);
    
    return 0;
}
```


### Koncová rekurze


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
