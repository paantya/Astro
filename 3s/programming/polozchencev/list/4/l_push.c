#include "l_head.h"

struct ElemList * PushStek (struct ElemList *Top, int intNewKey)
{
 struct ElemList *Elem_Work;  /* ���������, ������� ���������� */

 /* ������� ����� ������� ����� � ��������� �� ���� ������� � ����������
   Elem_Work, �.�. �������� ������ ����������� ��� ���������� �������� 
   ����� ��� ������ ������� malloc {(type *) malloc(sizeof(type))}.*/
 Elem_Work = (struct ElemList *) malloc(sizeof(struct ElemList));

/*
���������� �������:
1. ������� � ��������������� ���� ������ �������� ����� ����.
2. ������� � ��������������� ���� ������ �������� ��������� �� ����������.
3. �������� ��������� �� ������� ������� ������.
4. ������� � ������� ��������� ��������� �� ������� ������� ������.
*/
  Elem_Work->intKey = intNewKey;
  Elem_Work->next = Top;
  Top = Elem_Work;
  return Top;
}
