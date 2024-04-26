## Samostatná práce - faktorizace

### naivní algoritmus faktorizace (trial  and error):

```c
long trial(long n, long start) {
    if(n % start == 0) {
        return start;
    }
    return trial(n, start-1);
}

int main()
{    
    printf("%ld", trial(1024, sqrt(1024)));
    return 0;
}
```

### Samostatný úkol: Polardova metoda rhó pro faktorizaci:
- využití největšího společného dělitele, rekurze a algoritmu želvy a zajíce
- https://www.math.umd.edu/~immortal/ClassNotes/
