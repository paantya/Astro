#include "tr_head.h"

/* ---------------------------------------------------------------
   PassTree - рекурсивная процедура обхода дерева.
   Root - указатель на корень дерева (на втором и
   последующих уровнях рекурсии на корни поддеревьев).*/

void PassTree (struct Tree *Root)
{
  if (Root != NULL)
   {
     printf ("Info = %i\n", Root->Info);
     PassTree (Root->LeftNext);
     PassTree (Root->RightNext);
   }
}
