#include <stdio.h>
#include <stdlib.h>

/* ����������� ��������� ���� ������ */
struct Tree { int Info;               /* �������������� ���� (�����) */
              struct Tree *LeftNext;  /* ��������� �� ����� ��������� */
              struct Tree *RightNext; /* ��������� �� ������ ��������� */
            };

/* ����������� ������� InclElem, PassTree � FindElem */
struct Tree *InclElem (int, struct Tree *);

void PassTree (struct Tree *);

int FindElem (int, struct Tree *);

