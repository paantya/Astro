#include "l_head.h"

void PrintList (struct ElemList *Top)
/* Программа вывода списка на экран */
{
  printf ("\n Печать списка\n");
  while (Top!=NULL)
   {
    printf ("%i\n", Top->intKey);
    Top=Top->next;
   }
}
