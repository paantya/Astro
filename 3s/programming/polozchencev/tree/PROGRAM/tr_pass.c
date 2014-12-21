#include "tr_head.h"

/* ---------------------------------------------------------------
   PassTree - ����������� ��������� ������ ������.
   Root - ��������� �� ������ ������ (�� ������ �
   ����������� ������� �������� �� ����� �����������).*/

void PassTree (struct Tree *Root)
{
  if (Root != NULL)
   {
     printf ("Info = %i\n", Root->Info);
     PassTree (Root->LeftNext);
     PassTree (Root->RightNext);
   }
}
