#include "l_head.h"

struct ElemList * PushStek (struct ElemList *Top, int intNewKey)
{
 struct ElemList *Elem_Work;  /* Указатель, рабочая переменная */

 /* Создаем новый элемент стека и указатель на него заносим в переменную
   Elem_Work, т.е. выделяем память достаточную для размещения элемента 
   стека при помощи функции malloc {(type *) malloc(sizeof(type))}.*/
 Elem_Work = (struct ElemList *) malloc(sizeof(struct ElemList));

/*
Необходимо сделать:
1. Занести в соответствующее поле нового элемента новый ключ.
2. Занести в соответствующее поле нового элемента указатель на предыдущий.
3. Изменить указатель на верхний элемент списка.
4. Вернуть в главную программу указатель на верхний элемент списка.
*/
  Elem_Work->intKey = intNewKey;
  Elem_Work->next = Top;
  Top = Elem_Work;
  return Top;
}
