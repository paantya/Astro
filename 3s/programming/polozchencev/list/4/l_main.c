#include "l_head.h"

main()
{
 struct ElemList *Top; /* Указатель на вершину стека */
 int intWork;
 FILE *FileInt; /* Файловая переменая, для работы с файлом содержащим данные
                   списка */

 if ((FileInt=fopen("key.txt","r"))==NULL) /* Открываем файл */
   {
     printf("Ошибка открытия файла"); return 1;
   }

 Top=InputList (FileInt); /* Вызов функции организации стека */

 PrintList (Top);

 printf("\nВведите элемент добавляемый в список = ");
 scanf("%i", &intWork);
 Top=PushStek(Top, intWork);

 PrintList(Top);
 printf("\n");
 PrintRecur(Top);

 intWork=PopStek(Top);
 printf("\nЗначение удаленного элемента из стека = %i\n", intWork);
}
