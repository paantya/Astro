#include "l_head.h"

main()
{
 struct ElemList *Top; /* ��������� �� ������� ����� */
 int intWork;
 FILE *FileInt; /* �������� ���������, ��� ������ � ������ ���������� ������
                   ������ */

 if ((FileInt=fopen("key.txt","r"))==NULL) /* ��������� ���� */
   {
     printf("������ �������� �����"); return 1;
   }

 Top=InputList (FileInt); /* ����� ������� ����������� ����� */

 PrintList (Top);

 printf("\n������� ������� ����������� � ������ = ");
 scanf("%i", &intWork);
 Top=PushStek(Top, intWork);

 PrintList(Top);
 printf("\n");
 PrintRecur(Top);

 intWork=PopStek(Top);
 printf("\n�������� ���������� �������� �� ����� = %i\n", intWork);
}
