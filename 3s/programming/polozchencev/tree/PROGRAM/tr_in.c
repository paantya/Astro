#include "tr_head.h"

/* ---------------------------------------------------------------
   InclElem - рекурсивная функция включения нового элемента.
   NewInfo - информация (целое число), включаемая в дерево.
   Root - указатель на корень дерева (на втором и
   последующих уровнях рекурсии на корни поддеревьев).*/

struct Tree * InclElem (int NewInfo, struct Tree *Root)
{
  if (Root == NULL)                      /* см. комментарий 1 в пункте 4.3 */
   {
     Root = (struct Tree *) malloc( sizeof(struct Tree));        /* шаг 1а */
     Root->Info = NewInfo;                                       /* шаг 1б */
     Root->LeftNext = NULL;                                      /* шаг 1в */
     Root->RightNext = NULL;                                     /* шаг 1в */
   }
  else                                         /* см. комментарий 2 там же */
   if (NewInfo < Root->Info)
     Root->LeftNext = InclElem (NewInfo, Root->LeftNext);        /* шаг 2а */
   else
     Root->RightNext = InclElem (NewInfo, Root->RightNext);      /* шаг 2б */

  return Root;                                        /* см. комментарий 3 */
}

