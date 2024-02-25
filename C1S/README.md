### Knihovna MyMath

- knihovna pro základní matematické funkce
- knihovna nevyužívá žádné externí knihovny, je vhodná do minimalistických prostředí
- knihovna je otestována pomoci libtap

##### soubor lib/mymath.h + testy (1 bod)
obsahuje funkce
- sčítání dvou čišel
- odčítání
- násobení
- dělení (viz dále)
- faktoriál jednoho čísla
- mocnina číslo na n

každá funkce je otestována v souboru tests/test.c

##### struktura Result, ošetření chyb  (1b)
Některé funkce (například dělení) přirozeně mohou vykazovat chyby při určitých vstupech. Místo vyhazování výjimek existuje v lib/mymath.h struktura Result, kterou vrací všechny funkce.

- struktura obsahuje výsledek (double)
- obsahuje informaci o chybovém stavu (char 1/0)

- testy reflektují tuto skutečnost a ověřují správnost navrácené struktury Result


