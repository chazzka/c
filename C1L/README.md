Lekce 1
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

