#include <stdio.h>
#include <stdlib.h>

struct ElemList * InputList (FILE *); /* ��������� ����� ������ �� ����� */

struct ElemList * PushStek (struct ElemList *, /* ��������� ������� �������� */
                            int);              /* � ���� */

int PopStek (struct ElemList *); /* ��������� ������� �������� */
                                               /* �� ����� */

void PrintList (struct ElemList *); /* ��������� ������ ������ �� ����� */

void PrintRecur (struct ElemList *); /* ����������� ��������� ������ ������
                                        �� ����� */

struct ElemList
  {
   int intKey;
   struct ElemList* next;
  };

