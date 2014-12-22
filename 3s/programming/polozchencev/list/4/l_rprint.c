#include "l_head.h"

void PrintRecur (struct ElemList *Top)
/* Программа вывода списка на экран (рекурсивно) */
{
  if (Top != NULL) {
    PrintRecur(Top->next);
    printf ("%i\n", Top->intKey);
  }
}
