### Heap-based programming

malloc, free, memcpy, dynamické pole

https://cs.wikipedia.org/wiki/Dynamick%C3%A1_alokace_pam%C4%9Bti

Dynamická alokace 2*4 = 8 bitů paměti

```c
int main()
{
    int length = 2;
    int * oldarr = (int*)malloc(length*sizeof(int));
    oldarr[0] = 5;
    oldarr[1] = 7;
    free(oldarr);
}
```

Využití funkce malloc pro přenesení paměti z funkce (toto by bez mallocu nešlo, paměť by se ztratila - viz stack based programming cviko):

```c
int * insert(int*oldarr, int length, int item) {
    int * newarr = (int*)malloc(length*sizeof(int));
    memcpy(newarr, oldarr, length);
    newarr[0] = 88;
    return newarr;
}
```

Dynamický vektor:

Poznámka autora: bylo by lepší, kdyby funkce vracely nový list, nemutovaly původní, ale pro podobnost s jazykem c# ukazuji tuto možnost i za cenu špatné testovatelnosti.

1. alokujeme strukturu, aby drzela velikost
```c
typedef struct {
    int * arr;
    int length;
}Vector;
```

2. metoda insert - funcke realloc pro dynamickou realokaci - **zachová data**
```c
void mutableinsert(Vector * oldvec, int item) {
    if(oldvec->length == 0) {
        oldvec->arr = (int*)malloc(sizeof(int));
        oldvec->arr[0] = item;
        oldvec->length = 1;
    } else {
        int newlength = oldvec->length + 1;
        oldvec->arr = realloc(oldvec->arr, newlength * sizeof(int));
        oldvec->arr[newlength-1] = item;
        oldvec->length = newlength;
    }
}
```

3. main, důležitá funkce free()

```c
int main() {
    Vector v = {NULL, 0};
    mutableinsert(&v, 5);
    mutableinsert(&v, 7);
    printArr(v.arr, v.length);
    free(v.arr);
    return 0;
}
```
