#include "l_head.h"

void PrintRecur (struct ElemList *Top)
/* ��������� ������ ������ �� ����� (����������) */
{
  if (Top != NULL) {
    PrintRecur(Top->next);
    printf ("%i\n", Top->intKey);
  }
}
