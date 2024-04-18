https://en.wikipedia.org/wiki/Cycle_detection#Floyd's_tortoise_and_hare

```c
#include <stdio.h>
#include <math.h>

// 7.13
float f(float x) {
    return 2*x*x*x - 13*x*x - 2*x - 50;
}

float df(float x) {
    return 6*x*x - 26*x - 2;
}

float newton(float previous) {
    return previous - f(previous)/df(previous);
}

// pokud chceme specifikovat vlastni rovnost dle desetinnych mist
char Equality(float a, float b, float epsilon)
{
  return fabs(a - b) < epsilon;
}

float newton_run(float times, float prev) {
    if(times == 0) {
        return prev;
    }
    
    return newton(newton_run(times-1, prev));
}

float newton_run_zz(float times, float zelva, float zajic) {
    if(times == 0) {
        return 0;
    }
    
    if(zelva == zajic) {
        printf("%lf - %lf", times, zelva);
        printf("konec\n");
        return zelva;
    } else {
        return newton_run_zz(times-1, newton(zelva),newton(newton(zajic)));    
    }
}



int main()
{
    printf("%.30f", newton_run_zz(160,9, newton(9)));
    
    return 0;
}
```
