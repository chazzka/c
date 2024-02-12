Lekce 1

```c
#include <stdio.h>

int main() {
    printf("%d", 5);
    return 0;
}
```

| format | desc | example |
|---|---|---|
| %c | character | printf("%c", 'a') |
| %d | decimal (integer) number | printf("%d", 15) |
| %f | floating-point number | printf("%.2f", 3.1415) |
| %s | a string of characters | printf("%s", "ahoj") |
## Problém s globálními/ nekonstantními proměnnými

Bad practice:

```c
#include <stdio.h>
#include <stdlib.h>

int g_mode; // global mutable variable

void doSomething()
{
    g_mode = 2; // set the global g_mode variable to 2
}

int main()
{
    g_mode = 1; // this sets the global g_mode variable to 1.  It does not declare a local g_mode variable!

    doSomething();

    // here, g_mode is not 1 but 2!!!

    if (g_mode == 1)
    {
        std::cout << "No threat detected.\n";
    }
    else
    {
        std::cout << "Launching nuclear missiles...\n";
    }

    return 0;
}

```

Řešení:

```c
#include <stdio.h>
#include <stdlib.h>

// doSomething -> addFive
int addFive(int a)
{
    return a + 5;
}

int main()
{
    const int g_mode = 1;

    // this does NOT change g_mode
    const int bigger_g_mode = addFive(g_mode);

    printf("%d\n", g_mode); // 1
    printf("%d", bigger_g_mode); // 6


    return 0;
}
```
