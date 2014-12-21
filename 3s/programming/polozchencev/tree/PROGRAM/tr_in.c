#include "tr_head.h"

/* ---------------------------------------------------------------
   InclElem - ����������� ������� ��������� ������ ��������.
   NewInfo - ���������� (����� �����), ���������� � ������.
   Root - ��������� �� ������ ������ (�� ������ �
   ����������� ������� �������� �� ����� �����������).*/

struct Tree * InclElem (int NewInfo, struct Tree *Root)
{
  if (Root == NULL)                      /* ��. ����������� 1 � ������ 4.3 */
   {
     Root = (struct Tree *) malloc( sizeof(struct Tree));        /* ��� 1� */
     Root->Info = NewInfo;                                       /* ��� 1� */
     Root->LeftNext = NULL;                                      /* ��� 1� */
     Root->RightNext = NULL;                                     /* ��� 1� */
   }
  else                                         /* ��. ����������� 2 ��� �� */
   if (NewInfo < Root->Info)
     Root->LeftNext = InclElem (NewInfo, Root->LeftNext);        /* ��� 2� */
   else
     Root->RightNext = InclElem (NewInfo, Root->RightNext);      /* ��� 2� */

  return Root;                                        /* ��. ����������� 3 */
}

