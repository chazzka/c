#include "tap.c"
#include "../mathlib/math.h"

int main () {
    ok(add(5,6) == 11, "add test");
    ok(mul(5,6) == 30, "mul test");
    done_testing();
}