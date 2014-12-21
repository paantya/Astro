/*-----------------03.05.05 -----------------------
ðÒÏÇÒÁÍÍÁ ÓÏÚÄÁÎÉÑ ÄÅÒÅ×Á ËÏÄÉÒÏ×ËÉ ÐÏ ÍÅÔÏÄÕ èÁÆÆÍÁÎÁ
--------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* #include <io.h> ÷ LINUXÅ ÎÅÔ ÔÁËÏÊ ÂÉÂÌÉÏÔÅËÉ */
#include <fcntl.h>
#include <math.h>

/*-----------------01.05.04 18:39-------------------
ïÐÒÅÄÅÌÅÎÉÅ ÓÔÒÕËÔÕÒÙ ÄÌÑ ÜÌÅÍÅÎÔÏ× ÄÅÒÅ×Á É ËÕÞÉ
--------------------------------------------------*/
struct ElemHeapTree { char chSymb; /* óÉÍ×ÏÌ (ÐÏÌÅ ÏÐÒÅÄÅÌÅÎÏ ÔÏÌØËÏ
                                      Õ ÌÉÓÔØÅ× ÄÅÒÅ×Á) */
                      long longSumSymb; /* þÁÓÔÏÔÁ ÐÏÑ×ÌÅÎÉÑ ÓÉÍ×ÏÌÁ (chSymb)
                                         × ÔÅËÓÔÅ */
          struct ElemHeapTree *Left; /* õËÁÚÁÔÅÌØ ÎÁ ÌÅ×ÏÅ ÐÏÄÄÅÒÅ×Ï */
          struct ElemHeapTree *Right; /* õËÁÚÁÔÅÌØ ÎÁ ÐÒÁ×ÏÅ ÐÏÄÄÅÒÅ×Ï */
                     };
void ExclEmpty(struct ElemHeapTree *); /* æÕÎËÃÉÑ ÉÓËÌÀÞÅÎÉÑ ÓÉÍ×ÏÌÏ×
                                          (ÜÌÅÍÅÎÔÏ× ÍÁÓÓÉ×Á), ËÏÔÏÒÙÈ
                                           ÎÅÔ × ÔÅËÓÔÅ */

void PrintHeap(struct ElemHeapTree *intSumChar); /* æÕÎËÃÉÑ ÐÅÞÁÔÉ ËÕÞÉ */

void PrintTree (struct ElemHeapTree *); /* æÕÎËÃÉÑ ÐÅÞÁÔÉ ÄÅÒÅ×Á */

void SaveTree (FILE *, struct ElemHeapTree *, char *, int); /* æÕÎËÃÉÑ ÚÁÐÉÓÉ ÄÅÒÅ×Á × ÆÁÊÌ */

int Parent(int); /* æÕÎËÃÉÑ ÐÏÌÕÞÅÎÉÑ ÒÏÄÉÔÅÌÑ × ËÕÞÅ */

int Left(int); /* æÕÎËÃÉÑ ÐÏÌÕÞÅÎÉÑ ÌÅ×ÏÇÏ ÐÏÔÏÍËÁ × ËÕÞÅ */

int Right(int); /* æÕÎËÃÉÑ ÐÏÌÕÞÅÎÉÑ ÐÒÁ×ÏÇÏ ÐÏÔÏÍËÁ × ËÕÞÅ */

void Heapify(struct ElemHeapTree *, int); /* æÕÎËÃÉÑ ÉÓÐÒÁ×ÌÅÎÉÑ ËÕÞÉ.
                                            ô.Å. ÐÏÓÔÏÎÏ×ËÁ ÚÁÄÁÎÎÏÇÏ
                                            ÜÌÅÍÅÎÔÁ ÍÁÓÓÉ×Á (×ÔÏÒÏÊ ÁÒÇÕÍÅÎÔ)
                                            ÎÁ Ó×ÏÅ ÍÅÓÔÏ */

void BuildHeap(struct ElemHeapTree *); /* æÕÎËÃÉÑ ÐÏÓÔÒÏÅÎÉÑ ËÕÞÉ */

void Help(void);

struct ElemHeapTree HeapMinExtract(struct ElemHeapTree *);  /* æÕÎËÃÉÑ
                                  ÉÚ×ÌÅÞÅÎÉÑ ÍÉÎÉÍÁÌØÎÏÇÏ ÜÌÅÍÅÎÔÁ ÉÚ ËÕÞÉ */

void HeapInsert(struct ElemHeapTree *, struct ElemHeapTree);  /* æÕÎËÃÉÑ
                                                   ×ÓÔÁ×ËÉ ÜÌÅÍÅÎÔÁ × ËÕÞÕ */

struct ElemHeapTree * Haffman(struct ElemHeapTree *);  /* æÕÎËÃÉÑ ÐÏÓÔÒÏÅÎÉÑ
                                                        ÄÅÒÅ×Á ÐÏ èÁÆÆÍÁÎÕ */

int HeapSize=256; /* íÁËÓÉÍÁÌØÎÙÊ ÒÁÚÍÅÒ ËÕÞÉ ÐÏ ËÏÌ-×Õ ÓÉÍ×ÏÌÏ× (1-ÂÁÊÔ) */

int SignEmpty=1; /* ðÅÒÅÍÅÎÎÁÑ ÄÌÑ ÐÒÉÓ×ÏÅÎÉÑ ÕÚÌÁÍ, ËÏÄÁ ÓÉÍ×ÏÌÁ, ÐÒÉÚÎÁË
                    ÎÅ ÌÉÓÔÁ */

int intPrint=0; 

int main (int argc,char * argv[])
{
  char chSymbOne; /* ðÅÒÅÍÅÎÎÁÑ ÄÌÑ ÓÉÍ×ÏÌÏ× ÉÚ ÆÁÊÌÁ */
  int IN; /* ÷ÈÏÄÎÏÊ ÆÁÊÌ. ÷×ÏÄ ÎÁ ÎÉÖÎÅÍ ÕÒÏ×ÎÅ */
  FILE *OUT; /* ïÂÙÞÎÙÊ ×Ù×ÏÄ */
  struct ElemHeapTree *intSumChar; /* íÁÓÓÉ× ÄÌÑ ËÕÞÉ */
  struct ElemHeapTree * RootTree; /* õËÁÚÁÔÅÌØ ÎÁ ËÏÒÅÎØ ÄÅÒÅ×Á */
  int i; /* òÁÂÏÞÁÑ ÐÅÒÅÍÅÎÎÁÑ */
  char *chCodeSym; /* ðÅÒÅÍÅÎÎÁÑ, ÄÌÑ ÆÏÒÍÉÒÏ×ÁÎÉÑ ËÏÄÁ ÓÉÍ×ÏÌÁ */

  intSumChar=(struct ElemHeapTree *) malloc(sizeof(struct ElemHeapTree)*HeapSize);
  if (intSumChar==NULL)
   {
    printf ("îå è÷áôáåô ðáíñôé!!!\n");
    exit(1);
   }

  chCodeSym=(char *) malloc(sizeof(char)*HeapSize);

  if (argc == 1)
   {
    Help();
    return 0;
   }

  if (argc == 3) intPrint=1;

/*  if ((IN = open(argv[1], O_RDONLY)) == 0) */
  if ((IN = open(argv[1], O_RDONLY)) == -1) 
   {
     printf ("Cannot open INPUT FILE: IN");
     return 1;
   }
  if ((OUT = fopen("ModHaf.txt", "w")) == NULL)
   {
     printf ("Cannot open OUTPUT FILE: OUT");
     return 1;
   }
  for (i=0; i<HeapSize; i++) /* ãÉËÌ ÉÎÉÃÉÁÌÉÚÁÃÉÉ ËÕÞÉ */
   {
    intSumChar[i].longSumSymb=0;
    intSumChar[i].chSymb=i;
    intSumChar[i].Left=NULL;
    intSumChar[i].Right=NULL;
   }
  while (i!=0) /* þÔÅÎÉÑ ÉÎÆÏÒÍÁÃÉÉ ÉÚ ÔÅËÓÔÏ×ÏÇÏ ÆÁÊÌÁ */
   {
     i=read(IN, &chSymbOne, sizeof(chSymbOne));
     if (i!=0)
      intSumChar[chSymbOne].longSumSymb++; /* úÁÎÅÓÅÎÉÅ ÓÉÍ×ÏÌÁ × ÍÁÓÓÉ× (ËÕÞÕ) */
   }

  ExclEmpty(intSumChar); /* éÓËÌÀÞÅÎÉÅ ÉÚ ÍÁÓÓÉ×Á ÓÉÍ×ÏÌÏ×,
                            ËÏÔÏÒÙÈ ÎÅÔ × ÔÅËÓÔÅ  */

/*   PrintHeap(intSumChar);  */

  BuildHeap(intSumChar); /* ðÏÓÔÒÏÅÎÉÅ ËÕÞÉ */
  if (intPrint) PrintHeap(intSumChar);
  RootTree=Haffman(intSumChar); /* ðÏÓÔÒÏÅÎÉÅ ÄÅÒÅ×Á ÐÏ èÁÆÆÍÁÎÕ */
  if (intPrint) PrintTree(RootTree);
  i=0;
/*  PrintTree(RootTree); */
  SaveTree(OUT, RootTree, chCodeSym, i); /* óÏÈÒÁÎÅÎÉÑ ÄÅÒÅ×Á × ÆÁÊÌ */
}

/* æÕÎËÃÉÑ ÉÓËÌÀÞÅÎÉÑ ÓÉÍ×ÏÌÏ×, ËÏÔÏÒÙÈ ÎÅ × ÔÅËÓÔÅ */
void  ExclEmpty(struct ElemHeapTree *intSumChar)
{
  int j;
  int i=0;
  for (j=0; j<HeapSize; j++)
   if (intSumChar[j].longSumSymb!=0) /* ðÒÏ×ÅÒËÁ ÐÏÑ×ÌÑÌÓÑ ÌÉ ÓÉÍ×ÏÌ Ó ËÏÄÏÍ j
                                       × ÔÅËÓÔÅ */
    {
/*      printf("\n ÓÉÍ×ÏÌ = %c ËÏÄ ÓÉÍ×ÏÌÁ = %X ËÏÌ-×Ï ÓÉÍ×ÏÌÏ× = %ld",
             j, j, intSumChar[j].longSumSymb); */
     intSumChar[i]=intSumChar[j];
     i++;
    }
  HeapSize=i;
}

/* æÕÎËÃÉÑ ÐÅÞÁÔÉ ËÕÞÉ */
void PrintHeap(struct ElemHeapTree *intSumChar)
{
  int j;
  printf ("\nðÅÞÁÔØ ËÕÞÉ\n");
  for (j=0; j<HeapSize; j++)
    printf("\n ÓÉÍ×ÏÌ = %c ËÏÄ ÓÉÍ×ÏÌÁ = %X ËÏÌ-×Ï ÓÉÍ×ÏÌÏ× = %d",
           intSumChar[j].chSymb, intSumChar[j].chSymb,
           intSumChar[j].longSumSymb);
}

/* æÕÎËÃÉÉ Ä×ÉÖÅÎÉÅ ÐÏ ËÕÞÉ */
int Parent(int i) /* æÕÎËÃÉÑ ÐÏÌÕÞÅÎÉÑ ÒÏÄÉÔÅÌÑ ÄÌÑ i-ÇÏ ÜÌÅÍÅÎÔÁ ÍÁÓÓÉ×Á */
{ return (i+1)/2-1; }

int Left(int i)   /* æÕÎËÃÉÑ ÐÏÌÕÞÅÎÉÑ ÌÅ×ÏÇÏ ÐÏÔÏÍËÁ ÄÌÑ i-ÇÏ ÜÌÅÍÅÎÔÁ ÍÁÓÓÉ×Á */
{ return 2*i+1; } /* åÓÌÉ ÉÎÄÅËÓ ÏÔ 1, ÔÏ 2*i */

int Right(int i)  /* æÕÎËÃÉÑ ÐÏÌÕÞÅÎÉÑ ÐÒÁ×ÏÇÏ ÐÏÔÏÍËÁ ÄÌÑ i-ÇÏ ÜÌÅÍÅÎÔÁ ÍÁÓÓÉ×Á */
{ return 2*i+2; } /* åÓÌÉ ÉÎÄÅËÓ ÏÔ 1, ÔÏ 2*i+1 */

/* æÕÎËÃÉÑ ÐÏÄÄÅÒÖÁÎÉÑ Ó×ÏÊÓÔ×Á ËÕÞÉ */
void Heapify(struct ElemHeapTree *intSumChar, int intIndex)
{
 int intLeft, intRight; /* éÎÄÅËÓÙ × ÍÁÓÓÉ×Å ÌÅ×ÏÇÏ É ÐÒÁ×ÏÇÏ ÐÏÔÏÍËÁ */
 int intSmallest; /* éÎÄÅËÓ ÍÁÓÓÉ×Á Ó ÍÉÎÉÍÁÌØÎÏÊ ÞÁÓÔÏÔÏÊ ÐÏÑ×ÌÅÎÉÑ
                     ÓÉÍ×ÏÌÁ (ÒÁÓÓÍÁÔÒÉ×ÁÅÔÓÑ ÒÏÄÉÔÅÌØ É Ä×Á ÐÏÔÏÍËÁ) */
 struct ElemHeapTree WorkSave; /* ðÅÒÅÍÅÎÎÁÑ ÄÌÑ ÏÂÍÅÎÁ ÜÌÅÍÅÎÔÏ× ÍÁÓÓÉ×Á */
 intLeft=Left(intIndex); /* ðÏÌÕÞÅÎÉÑ ÌÅ×ÏÇÏ ÐÏÔÏÍËÁ ÄÌÑ intIndex-ÇÏ ÜÌÅÍÅÎÔÁ ÍÁÓÓÉ×Á */
 intRight=Right(intIndex); /* ðÏÌÕÞÅÎÉÑ ÌÅ×ÏÇÏ ÐÏÔÏÍËÁ ÄÌÑ intIndex-ÇÏ ÜÌÅÍÅÎÔÁ ÍÁÓÓÉ×Á */
/* âÌÏË ÏÐÒÅÌÅÎÉÑ ÉÎÄÅËÓÁ ÍÁÓÓÉ×Á Ó ÍÉÎÉÍÁÌØÎÏÊ ÞÁÓÔÏÔÏÊ
   ÓÉÍ×ÏÌÁ ÉÚ ÒÏÄÉÔÅÌÑ É Ä×ÕÈ ÐÏÔÏÍËÏ× ÐÏÑ×ÌÅÎÉÑ*/
 if (intLeft<HeapSize &&
     intSumChar[intLeft].longSumSymb<=intSumChar[intIndex].longSumSymb)
  intSmallest=intLeft;
 else
  intSmallest=intIndex;
 if ((intRight<HeapSize &&
     intSumChar[intRight].longSumSymb<intSumChar[intSmallest].longSumSymb) ||
    (intRight<HeapSize && intSmallest==intLeft &&
     intSumChar[intRight].longSumSymb==intSumChar[intSmallest].longSumSymb &&
     intSumChar[intRight].chSymb!=SignEmpty))
  intSmallest=intRight;
/* ëÏÎÅÃ ÂÌÏËÁ ÏÐÒÅÄÅÎÉÑ ÉÎÄÅËÓÁ */
 if (intSmallest!=intIndex) /* åÓÌÉ ÞÁÓÔÏÔÁ ÐÏ×ÌÅÎÉÑ ÓÉÍ×ÏÌÁ Õ ÒÏÄÉÔÅÌÑ
                               ÂÏÌØÛÅ, ÞÅÍ Õ ÏÄÎÏÇÏ ÉÚ ÐÏÔÏÍËÏ×, ÔÏ ÍÅÎÑÅÔ
                               ÜÌÅÍÅÎÔÙ ÍÁÓÓÉ×Á ÍÅÓÔÁÍÉ */
   {
      WorkSave=intSumChar[intIndex];
      intSumChar[intIndex]=intSumChar[intSmallest];
      intSumChar[intSmallest]=WorkSave;
      Heapify(intSumChar, intSmallest); /* òÁÓÓÍÁÒÉ×ÁÅÍ ÓÌÅÄÕÀÝÕÀ ÔÒÏÊËÕ:
                                           ÒÏÄÉÔÅÌØ É Ä×ÕÈ ÐÏÔÏÍËÏ× */
   }
}

/* æÕÎËÃÉÑ ÐÏÓÔÒÏÅÎÉÑ ËÕÞÉ */
void BuildHeap(struct ElemHeapTree *intSumChar)
{
  int i;
  for (i=HeapSize-1; i>-1; i--)
   Heapify(intSumChar, i); /* éÓÐÒÁ×ÌÑÅÍ ËÕÞÕ ÄÌÑ i-ÇÏ ÜÌÅÍÅÎÔÁ */
}

/* õÄÁÌÅÎÉÅ ÍÉÎÉÍÁÌØÎÏÇÏ ÜÌÅÍÅÎÔÁ (ÐÅÒ×ÏÇÏ × ÍÁÓÓÉ×Å, ÓÏÇÌÁÓÎÏ ÐÏÓÔÒÏÅÎÉÀ ËÕÞÉ */
struct ElemHeapTree HeapMinExtract(struct ElemHeapTree *intSumChar)
{
 struct ElemHeapTree Min;
 if (HeapSize==0)
   {
     printf("\n ïÛÉÂËÁ: ÏÞÅÒÅÄØ ÐÕÓÔÁ\n");
     exit;
   }
  Min=intSumChar[0]; /* óÏÈÒÁÎÑÅÍ ÍÉÎÉÍÁÌØÎÙÊ ÜÌÅÍÅÎÔ */
  intSumChar[0]=intSumChar[HeapSize-1]; /* ðÏÓÌÅÄÎÉÊ ÜÌÅÍÅÎÔ ËÕÞÉ ÄÅÌÁÅÍ
                                           ÐÅÒ×ÙÍ */
  HeapSize--; /* õÍÅÎØÛÁÅÍ ËÏÌ-×Ï ÜÌÅÍÅÎÔÏ× × ËÕÞÅ ÎÁ ÅÄÉÎÉÃÕ */
  Heapify(intSumChar, 0); /* éÓÐÒÁ×ÌÑÅÍ ËÕÞÕ, ÄÌÑ ÐÅÒ×ÏÇÏ (0-ÇÏ) ÜÌÅÍÅÎÔÁ
                             ÍÁÓÓÉ×Á */
  return Min;
}

/* ÷ÓÔÁ×ËÁ ÎÏ×ÏÇÏ ÜÌÅÍÅÎÔÁ × ËÕÞÕ */
void HeapInsert(struct ElemHeapTree *intSumChar, struct ElemHeapTree InputElem)
{
  int i;
  i=HeapSize;
  HeapSize++;
  while (i>0 && intSumChar[Parent(i)].longSumSymb>InputElem.longSumSymb)
/* ðÏËÁ Õ ×ÓÔÁ×ÌÑÅÍÏÇÏ ÜÌÅÍÅÎÔÁ ÞÁÓÔÏÔÁ ÐÏÑ×ÌÅÎÉÑ ÓÉÍ×ÏÌÁ ÍÅÎØÛÅ ÞÅÍ Õ
   ÒÏÄÉÔÅÌÑ ÏÐÕÓËÁÅÍ ÒÏÄÉÔÅÌÑ ÎÁ ÏÄÉÎ ÕÒÏ×ÅÎØ ×ÎÉÚ */
   {
    intSumChar[i]=intSumChar[Parent(i)];
    i=Parent(i);
   }
 intSumChar[i]=InputElem; /* ÷ÓÔÁ×ÌÑÅÍ ÎÏ×ÙÊ ÜÌÅÍÅÎÔ ÎÁ ÎÁÊÄÅÎÎÏÅ ÍÅÓÔÏ */
}

/* æÕÎËÃÉÑ ÓÏÚÄÁÎÉÑ ÄÅÒÅ×Á ÐÏ ÍÅÔÏÄÕ èÁÆÆÍÁÎÁ */
struct ElemHeapTree * Haffman(struct ElemHeapTree *intSumChar)
{
  int i, intSave; /* òÁÂÏÞÉÅ ÐÅÒÅÍÅÎÎÙÅ */
  struct ElemHeapTree NewCreat;
  struct ElemHeapTree *Root;
  intSave=HeapSize; /* óÏÈÒÁÎÑÅÍ ÒÁÚÍÅÒ ËÕÞÉ, Ô.Ë. HeapSize ÍÅÎÑÅÔÓÑ × ÃÉËÌÅ */
  for (i=0; i<intSave-1; i++)
   {
/* óÏÚÄÁÅÍ Ä×Á ÎÏ×ÙÈ ÜÌÅÍÅÎÔÁ ÄÅÒÅ×Á (ÐÒÁ×ÏÅ É ÌÅ×ÏÅ) É ÚÁÎÏÓÉÍ Ï ÎÉÈ
   ÉÎÆÏÒÍÁÃÉÀ × ×ÅÒÈÎÉÊ ÕÚÅÌ */
     NewCreat.Left=(struct ElemHeapTree *) malloc(sizeof(struct ElemHeapTree));
     NewCreat.Right=(struct ElemHeapTree *) malloc(sizeof(struct ElemHeapTree));
/* ÷ ÎÏ×ÙÅ ÜÌÅÍÅÎÔÙ ÚÁÎÏÓÉÍ ÉÎÆÏÒÍÁÃÀ ÉÚ ÍÉÎÉÍÁÌØÎÙÈ ÜÌÅÍÅÎÔÏ× ËÕÞÉ */
     *(NewCreat.Left)=HeapMinExtract(intSumChar);
     *(NewCreat.Right)=HeapMinExtract(intSumChar);
/* úÁÎÏÓÉÍ × ×ÅÒÈÎÉÊ ÕÚÅÌ × ËÁÞÅÓÔ×Å ÓÉÍ×ÏÌÁ 1 ÐÕÓÔÏÔÕ */
     NewCreat.chSymb=SignEmpty; /* '' */
/* úÁÎÏÓÉÍ × ×ÅÒÈÎÉÊ ÕÚÅÌ × ËÁÞÅÓÔ×Å ÞÁÓÔÏÔÙ ÐÏÑ×ÌÅÎÉÑ ÓÕÍÍÕ ÞÁÓÔÏÔÙ ÐÏÑ×ÌÅÎÉÑ
   ÐÏÔÏÍËÏ× */
     NewCreat.longSumSymb=NewCreat.Left->longSumSymb+NewCreat.Right->longSumSymb;
/* ÷ÓÔÁ×ÌÑÅÍ ×ÅÒÈÎÉÊ ÕÚÅÌ × ËÕÞÕ. (ÔÁËÉÍ ÏÂÒÁÚÏÍ, ÚÁ ÏÄÉÎ ÐÒÏÈÏÄ ÄÁÎÎÏÇÏ
   ÃÉËÌÁ for ËÏÌ-×Ï ÜÌÅÍÅÎÔÏ× ÕÍÅÎØÛÉÔÓÑ ÎÁ 1 */
     HeapInsert(intSumChar, NewCreat);
   }
/* óÏÚÄÁÅÍ ËÏÒÅÎØ ÄÅÒÅ×Á */
  Root=(struct ElemHeapTree *) malloc(sizeof(struct ElemHeapTree));
  *Root=HeapMinExtract(intSumChar);
  return Root;
}

/* æÕÎËÃÉÑ ÐÅÞÁÔÉ ÄÅÒÅ×Á */
void PrintTree (struct ElemHeapTree *Root)
{
  if (Root != NULL)
   {
     printf ("\nInfo = %li", Root->longSumSymb);
     PrintTree (Root->Left);
     PrintTree (Root->Right);
   }
}

/* æÕÎËÃÉÑ ÓÏÈÒÁÎÅÎÉÑ ÄÅÒÅ×Á × ÆÁÊÌ */
void SaveTree (FILE * OUT, struct ElemHeapTree *Root, char* chCodeSym, int i)
{
  if (Root != NULL)
   {
     chCodeSym[i]='\0';
     fprintf (OUT,"%6ld %3d %s\n", Root->longSumSymb,
              Root->chSymb, chCodeSym);
     chCodeSym[i]='0';
     SaveTree (OUT, Root->Left,chCodeSym,i+1);
     chCodeSym[i]='1';
     SaveTree (OUT, Root->Right,chCodeSym,i+1);
   }
}

void Help(void)
{
 printf("\nðÒÏÇÒÁÍÍÁ ÓÏÚÄÁÎÉÑ ÄÅÒÅ×Á ÓÖÁÔÉÑ\n");
 printf("\nðÒÏÇÒÁÍÍÁ ÓÔÒÏÉÔ ÄÅÒÅ×Ï ÐÏ ÍÅÔÏÄÕ èÁÆÆÍÁÎÁ.\n");
 printf("ôÒÅÂÕÅÔÓÑ ×ÈÏÄÎÏÊ ÐÁÒÁÍÅÔÒ - ÆÁÊÌ, ËÏÔÏÒÏÊ ÐÒÅÄÐÏÌÁÇÁÅÔÓ ËÏÄÉÒÏ×ÁÔØ.\n");
 printf("÷ ÒÅÚÕÌØÔÁÔÅ ÓÏÚÄÁÅÔÓÑ ÆÁÊÌ - datetree.txt\n");
 printf("\nðÒÉÍÅÒ: haffman# input.txt\n");
}
