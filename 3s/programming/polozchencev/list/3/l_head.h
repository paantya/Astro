#include <stdio.h>
#include <stdlib.h>

struct ElemList * InputList (FILE *); /* Программа ввода списка из файла */

struct ElemList * PushStek (struct ElemList *, /* Программа вставки элемента */
                            int);              /* в стек */

int PopStek (struct ElemList *); /* Программа удалени элемента */
                                               /* из стека */

void PrintList (struct ElemList *); /* Программа вывода списка на экран */

void PrintRecur (struct ElemList *); /* Рекурсивная программа вывода списка
                                        на экран */

struct ElemList
  {
   int intKey;
   struct ElemList* next;
  };

