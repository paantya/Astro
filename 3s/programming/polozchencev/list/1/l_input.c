#include "l_head.h"

struct ElemList * InputList (FILE *FileInt)
/* ��������� ����� ������ �� ����� */
{
 int intKeyNew;
 struct ElemList *Top; /* ��������� �� ������� ����� */
 Top=NULL;
 while(!feof(FileInt)) /* ���� ����������� ����� */
  {
   fscanf (FileInt,"%i", &intKeyNew);
   Top=PushStek(Top, intKeyNew);
  }
 return Top;
}
