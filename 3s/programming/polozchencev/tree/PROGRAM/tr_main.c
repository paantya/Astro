#include "tr_head.h"

/* ������ �������� ��������� */
main ()
{
  struct Tree *Root;
  int NewInfo;

  Root = NULL;
  NewInfo = 0;
  printf("\n ���� ���������� ��� �������� ������ (����� ����� 9999)\n");
  while (NewInfo != 9999)
   {
     printf("������� ����� �����: ");
     scanf("%i", &NewInfo);
     if (NewInfo != 9999)
      {
       Root = InclElem (NewInfo, Root);
      }
   }
  PassTree (Root);

  printf("\n ������� �������, ��� ������� ����� ���������� ����� � ������ = ");
  scanf("%i", &NewInfo);
  if (FindElem(NewInfo, Root))
   printf("\n������� ������\n");
  else
   printf("\n������� �� ������\n");
}
