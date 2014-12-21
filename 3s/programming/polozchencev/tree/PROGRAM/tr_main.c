#include "tr_head.h"

/* Начало основной программы */
main ()
{
  struct Tree *Root;
  int NewInfo;

  Root = NULL;
  NewInfo = 0;
  printf("\n Ввод информации для создание дерева (конец ввода 9999)\n");
  while (NewInfo != 9999)
   {
     printf("Введите целое число: ");
     scanf("%i", &NewInfo);
     if (NewInfo != 9999)
      {
       Root = InclElem (NewInfo, Root);
      }
   }
  PassTree (Root);

  printf("\n Введите элемент, для который будет произведен поиск в дереве = ");
  scanf("%i", &NewInfo);
  if (FindElem(NewInfo, Root))
   printf("\nЭлемент найден\n");
  else
   printf("\nЭлемент не найден\n");
}
