#include "l_head.h"

void PrintList (struct ElemList *Top)
/* ��������� ������ ������ �� ����� */
{
  printf ("\n ������ ������\n");
  while (Top!=NULL)
   {
    printf ("%i\n", Top->intKey);
    Top=Top->next;
   }
}
