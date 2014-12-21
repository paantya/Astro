#include <stdio.h>
#include <stdlib.h>

/* Определения структуры узла дерева */
struct Tree { int Info;               /* Информационное поле (целое) */
              struct Tree *LeftNext;  /* Указатель на левое поддерево */
              struct Tree *RightNext; /* Указатель на правое поддерево */
            };

/* Определения функций InclElem, PassTree и FindElem */
struct Tree *InclElem (int, struct Tree *);

void PassTree (struct Tree *);

int FindElem (int, struct Tree *);

