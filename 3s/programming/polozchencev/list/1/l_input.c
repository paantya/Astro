#include "l_head.h"

struct ElemList * InputList (FILE *FileInt)
/* Программа ввода списка из файла */
{
 int intKeyNew;
 struct ElemList *Top; /* Указатель на вершину стека */
 Top=NULL;
 while(!feof(FileInt)) /* Цикл организации стека */
  {
   fscanf (FileInt,"%i", &intKeyNew);
   Top=PushStek(Top, intKeyNew);
  }
 return Top;
}
