/*-----------------01.05.04 20:13-------------------
ðÒÏÇÒÁÍÍÁ ÕÐÁËÏ×ËÉ ÄÁÎÎÙÈ ÐÒÉ ÐÏÍÏÝÉ ÄÅÒÅ×Á ËÏÄÉÒÏ×ËÉ
ÓÏÚÄÁÎÎÏÇÏ ÐÏ ÍÅÔÏÄÕ èÁÆÆÍÁÎÁ
--------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* #include <io.h>  /* ÷ LINUXÅ ÎÅÔ ÔÁËÏÊ ÂÉÂÌÉÏÔÅËÉ */
#include <fcntl.h>
#include <math.h>
#include <sys/stat.h>
/* #include <unistd.h> */

/* ïÐÒÅÄÅÌÅÎÉÅ ÓÔÒÕËÔÕÒÙ ÄÌÑ ÜÌÅÍÅÎÔÏ× ÄÅÒÅ×Á */
struct TreeCode { char chSymb; /* óÉÍ×ÏÌ (ÌÉÓÔ Õ ÄÅÒÅ×Á) */
                      struct TreeCode *LeftNext; /* õËÁÚÁÔÅÌØ ÎÁ ÌÅ×ÏÅ ÐÏÄÄÅÒÅ×Ï */
                      struct TreeCode *RightNext; /* õËÁÚÁÔÅÌØ ÎÁ ÐÒÁ×ÏÅ ÐÏÄÄÅÒÅ×Ï */
                };

/* ïÐÒÅÄÅÌÅÎÉÅ ÓÔÒÕËÔÕÒÙ ÄÌÑ ÜÌÅÍÅÎÔÏ× ÓÐÉÓËÁ, ÐÏÌÕÞÅÎÎÏÇÏ ÉÚ ÆÁÊÌÁ */
struct List { char chSymb; /* óÉÍ×ÏÌ ÉÚ ÆÁÊÌÁ ËÏÄÉÒÏ×ËÉ */
              char *chIntCode; /* ëÌÀÞ ÄÌÑ ËÏÄÉÒÏ×ÁÎÉÑ */
              struct List *Next; /* õËÁÚÁÔÅÌØ ÎÁ ÓÌÅÄÕÀÝÉÊ ÜÌÅÍÅÎÔ ÓÐÉÓËÁ */
             };

/* ïÐÒÅÄÅÌÅÎÉÅ ÂÉÔÏ×ÏÊ ÓÔÒÕËÔÕÒÙ ÄÌÑ ÚÁÐÉÓÉ × ÆÁÊÌ ËÏÄÉÒÏ×ÁÎÎÏÊ ÉÎÆÏÒÍÁÃÉÉ */
  struct Bit32 { unsigned int i00 : 1;
                 unsigned int i01 : 1;
                 unsigned int i02 : 1;
                 unsigned int i03 : 1;
                 unsigned int i04 : 1;
                 unsigned int i05 : 1;
                 unsigned int i06 : 1;
                 unsigned int i07 : 1;
                 unsigned int i08 : 1;
                 unsigned int i09 : 1;
                 unsigned int i10 : 1;
                 unsigned int i11 : 1;
                 unsigned int i12 : 1;
                 unsigned int i13 : 1;
                 unsigned int i14 : 1;
                 unsigned int i15 : 1;
                 unsigned int i16 : 1;
                 unsigned int i17 : 1;
                 unsigned int i18 : 1;
                 unsigned int i19 : 1;
                 unsigned int i20 : 1;
                 unsigned int i21 : 1;
                 unsigned int i22 : 1;
                 unsigned int i23 : 1;
                 unsigned int i24 : 1;
                 unsigned int i25 : 1;
                 unsigned int i26 : 1;
                 unsigned int i27 : 1;
                 unsigned int i28 : 1;
                 unsigned int i29 : 1;
                 unsigned int i30 : 1;
                 unsigned int i31 : 1;
               };

/* æÕÎËÃÉÑ ÚÁÎÅÓÅÎÉÑ ÉÎÆÏÒÍÁÃÉÉ ÉÚ ÆÁÊÌÁ × ÓÐÉÓÏË */
struct List * ListFile (FILE *);

/* æÕÎËÃÉÑ ÓÏÚÄÁÎÉÑ ÄÅÒÅ×Á ÉÚ ÓÐÉÓËÁ */
struct TreeCode * CreatTree(struct List *);

/* òÅËÕÒÓÉ×ÎÁÑ ÆÕÎËÃÉÑ ×ËÌÀÞÅÎÉÑ ÎÏ×ÏÇÏ ËÏÎÃÅ×ÏÇÏ ÜÌÅÍÅÎÔÁ.*/
struct TreeCode * InputInfo (struct List *, struct TreeCode *);

/* æÕÎËÃÉÑ ÐÅÞÁÔÉ ÄÅÒÅ×Á */
void PrintTree (struct TreeCode *);

/* æÕÎËÃÉÑ ÓÏÚÄÁÎÉÑ ÔÁÂÌÉÃÙ ËÏÄÉÒÏ×ËÉ */
void CreatTabl(struct List *, char * []);

/* æÕÎËÃÉÑ ËÏÄÉÒÏ×ËÉ ÆÁÊÌÁ */
void FileToCode(int, int, char * []);

/* æÕÎËÃÉÑ ÐÏÌÕÞÅÎÉÑ ÏÞÅÒÅÄÎÏÇÏ ÓÉÍ×ÏÌÁ ÉÚ ËÏÄÉÒÕÅÍÏÇÏ ÆÁÊÌÁ */
int GetSymb(int);

/* æÕÎËÃÉÑ ÚÁÐÉÓÉ ÚÁËÏÄÉÒÕÅÍÏÇÏ ÓÉÍ×ÏÌÁ × ÆÁÊÌ */
void WriteCode(int, char * [], int);

/* æÕÎËÃÉÑ ÒÁÓËÏÄÉÒÏ×ËÉ ÆÁÊÌÁ */
void CodeToFile(int, int, struct TreeCode *);

/* æÕÎËÃÉÑ ÐÏÌÕÞÅÎÉÑ ÏÞÅÒÅÄÎÏÇÏ ÓÉÍ×ÏÌÁ ÐÏ ÄÅÒÅ×Õ */
char GetChTree(int, struct TreeCode *);

/* æÕÎËÃÉÑ ÐÏÌÕÞÅÎÉÑ ÏÞÅÒÅÄÎÏÇÏ ÓÉÍ×ÏÌÁ (0,1) ÉÚ ÒÁÓËÏÄÉÒÕÅÍÏÇÏ ÆÁÊÌÁ */
int GetCode(int);

void Help();

int SignEmpty=1; /* ðÅÒÅÍÅÎÎÁÑ ÄÌÑ ÐÒÉÓ×ÏÅÎÉÑ ÕÚÌÁÍ, ËÏÄÁ ÓÉÍ×ÏÌÁ, ÐÒÉÚÎÁË
                    ÎÅ ÌÉÓÔÁ */
int intPrint=0;

int main (int argc, char * argv[])
{
  int intIN;  /* ÷ÈÏÄÎÏÊ ÆÁÊÌ. ÷×ÏÄ ÎÁ ÎÉÖÎÅÍ ÕÒÏ×ÎÅ */
  int intOUT; /* ÷ÙÈÏÄÎÏÊ ÆÁÊÌ. ÷Ù×ÏÄ ÎÁ ÎÉÖÎÅÍ ÕÒÏ×ÎÅ */
  FILE * IN; /* ïÂÙÞÎÙÊ ××ÏÄ ÉÚ ÆÁÊÌÁ ÄÅÒÅ×Á */
  struct List * Top;
  char *Tabl[256]; /* ôÁÂÌÉÃÁ ËÏÄÉÒÏ×ËÉ */
  struct TreeCode *Root;
  int i;

  if (argc == 1)
   {
    Help();
    return 0;
   }

  if (argc == 5)
   intPrint = 1;    

  if ((IN = fopen("ModHaf.txt", "r")) == NULL)
   {
     printf ("Cannot open INPUT FILE: ModHaf.txt");
     return 1;
   }

  if ((intIN = open(argv[2], O_RDONLY)) == -1)
   {
     printf ("Cannot open INPUT FILE: %s", argv[2]);
     return 1;
   }

 for(i=0;i<256;i++)
  Tabl[i]=NULL;

 Top=ListFile (IN);
 if (strcmp(argv[1],"a")==0)
  {
   if ((intIN = open(argv[2], O_RDONLY)) == -1)
    {
      printf ("Cannot open INPUT FILE: %s", argv[2]);
      return 1;
    }

   if ((intOUT = open(argv[3], O_WRONLY|O_CREAT|O_TRUNC, S_IWRITE)) == -1)
    {
      printf ("Cannot open OUTPUT FILE: %s", argv[3]);
      return 1;
    }

    CreatTabl(Top, Tabl);
    FileToCode(intIN, intOUT, Tabl);
  }
 if (strcmp(argv[1],"e")==0)
  {
   if ((intIN = open(argv[2], O_RDONLY)) == -1)
    {
      printf ("Cannot open INPUT FILE: %s", argv[2]);
      return 1;
    }

   if ((intOUT = open(argv[3], O_WRONLY|O_CREAT|O_TRUNC, S_IWRITE)) == -1)
    {
      printf ("Cannot open OUTPUT FILE: %s", argv[3]);
      return 1;
    }

    if (intPrint) printf("\n÷ÙÚÙ×ÁÅÍ ÓÏÚÄÁÎÉÑ ÄÅÒÅ×Á");
    Root=CreatTree(Top);
    CodeToFile(intIN, intOUT, Root);
  }
}

/* æÕÎËÃÉÑ ÚÁÎÅÓÅÎÉÑ ÉÎÆÏÒÍÁÃÉÉ ÉÚ ÆÁÊÌÁ × ÓÐÉÓÏË */
struct List * ListFile (FILE * IN)
{
  int i1;
  char chSymb, shStr[256];
  int intSign=0;
  struct List *ListToFile, *Top, *Work;
  Top=NULL;
  while (!feof(IN))
   {
    ListToFile=(struct List *) malloc(sizeof(struct List));
    if (ListToFile==NULL)
     {
      printf ("\n îÅÈ×ÁÔÁÅÔ ÐÁÍÑÔÉ ÄÌÑ ÓÐÉÓËÁ");
      exit(1);
     }
/*    fscanf(IN, "%d %d %ld", &i,
           &(ListToFile->chSymb), &(ListToFile->intCode)); */
    if (intSign==0)
     {
      fscanf(IN, "%d %d", &i1, &chSymb);
      ListToFile->chIntCode=NULL;
      intSign=1;
     }
    else
     {
      fscanf(IN, "%d %d %s", &i1, &chSymb, shStr);
      ListToFile->chIntCode=(char *) malloc(strlen(shStr)+1);
      if (ListToFile==NULL)
       {
        printf ("\n îÅÈ×ÁÔÁÅÔ ÐÁÍÑÔÉ ÄÌÑ ÓÐÉÓËÁ");
        exit(1);
       }
      strcpy(ListToFile->chIntCode,shStr);
     }
    ListToFile->chSymb=chSymb;
/*    if (ListToFile->chSymb==SignEmpty)
      ListToFile->chSymb=0; */
    if (Top==NULL)
      Top=ListToFile;
    else
     Work->Next=ListToFile;
    Work=ListToFile;
   }
  ListToFile->Next=NULL;
  return Top;
}

/* æÕÎËÃÉÑ ÓÏÚÄÁÎÉÑ ÄÅÒÅ×Á ÉÚ ÓÐÉÓËÁ */
struct TreeCode * CreatTree(struct List * Top)
{
 struct TreeCode *Root=NULL;

 while (Top!=NULL)
  {
   if (intPrint) printf("\nInputInfo (Top, Root) Root->chSymb = %s", Root->chSymb);
   Root=InputInfo (Top, Root);
   Top=Top->Next;
  }
 if (intPrint) PrintTree(Root);
 return Root;
}

/* òÅËÕÒÓÉ×ÎÁÑ ÆÕÎËÃÉÑ ×ËÌÀÞÅÎÉÑ ÎÏ×ÏÇÏ ËÏÎÃÅ×ÏÇÏ ÜÌÅÍÅÎÔÁ.*/
struct TreeCode * InputInfo (struct List * Top, struct TreeCode *Root)
{
  static int i=-1;
  if (Root == NULL)
   {
     Root = (struct TreeCode *) malloc( sizeof(struct TreeCode));
     if (Root==NULL) 
      {
       printf ("\n îÅÈ×ÁÔÁÅÔ ÐÁÍÑÔÉ ÄÌÑ ÄÅÒÅ×Á");
       exit(1);
      }
     Root->chSymb = Top->chSymb;
     Root->LeftNext = NULL;
     Root->RightNext = NULL;
     i=-1;
   }
  else
   {
    i++;
    if (intPrint) printf("\nInputInfo: i = %d  Root->chSymb[i] = %s", i, Root->chSymb);
    if (Top->chIntCode[i]=='0')
      Root->LeftNext = InputInfo (Top, Root->LeftNext);
    else
      Root->RightNext = InputInfo (Top, Root->RightNext);
   }
  return Root;
}

/* æÕÎËÃÉÑ ÓÏÚÄÁÎÉÑ ÔÁÂÌÉÃÙ ËÏÄÉÒÏ×ËÉ */
void CreatTabl(struct List * Top, char *Tabl[])
{
 int i;
 while (Top!=NULL)
  {
   if (Top->chSymb!=SignEmpty)
    Tabl[Top->chSymb]=Top->chIntCode;
   Top=Top->Next;
  }
}

/* æÕÎËÃÉÑ ÐÅÞÁÔÉ ÄÅÒÅ×Á */
void PrintTree (struct TreeCode *Root)
{
  if (Root != NULL)
   {
     printf ("\nInfo = %c", Root->chSymb);
     PrintTree (Root->LeftNext);
     PrintTree (Root->RightNext);
   }
}

/* æÕÎËÃÉÑ ËÏÄÉÒÏ×ËÉ ÆÁÊÌÁ */
void FileToCode(int intIN, int intOUT, char * Tabl[])
{
  int intSymb=0;
  unsigned long lgSum=0;
  if (intPrint) printf("\nðÅÞÁÔÁÅÍ ÓÐÉÓÏË (æÁÊÌ)\n");
  while (intSymb != -1)
   {
     intSymb=GetSymb(intIN);
     if (intPrint) printf("%c",intSymb);
     WriteCode(intOUT, Tabl, intSymb);
     lgSum++; /* ËÏÌ-×Ï ÚÁÐÉÓÁÎÎÙÈ ÓÉÍ×ÏÌÏ× */
   }
  write(intOUT, &lgSum, sizeof(lgSum));
}

/* æÕÎËÃÉÑ ÐÏÌÕÞÅÎÉÑ ÏÞÅÒÅÄÎÏÇÏ ÓÉÍ×ÏÌÁ ÉÚ ËÏÄÉÒÕÅÍÏÇÏ ÆÁÊÌÁ */
int GetSymb(int intIN)
{
  char chSymbOne;
  int i;
  i=read(intIN, &chSymbOne, sizeof(char));
  if (i!=0)
    return chSymbOne;
  return -1;
}

/* æÕÎËÃÉÑ ÚÁÐÉÓÉ ÚÁËÏÄÉÒÕÅÍÏÇÏ ÓÉÍ×ÏÌÁ × ÆÁÊÌ */
void WriteCode(int intOUT, char * Tabl[], int intSymb)
{
 struct Bit32 static PackCode;
 int i;
 static int NumBit=0;
 char ch[10];
 if (intSymb<0)
  {
    if (NumBit!=0)
     {
      write(intOUT, &PackCode, sizeof(PackCode));
     }
  }
 else
  {
    for(i=0; i<strlen(Tabl[intSymb]); i++)
    {
     if (Tabl[intSymb][i] == '1')
       switch (NumBit)
         {
         case 0:
          PackCode.i00=1;
          break;
         case 1:
          PackCode.i01=1;
          break;
         case 2:
          PackCode.i02=1;
          break;
         case 3:
          PackCode.i03=1;
          break;
         case 4:
          PackCode.i04=1;
          break;
         case 5:
          PackCode.i05=1;
          break;
         case 6:
          PackCode.i06=1;
          break;
         case 7:
          PackCode.i07=1;
          break;
         case 8:
          PackCode.i08=1;
          break;
         case 9:
          PackCode.i09=1;
          break;
         case 10:
          PackCode.i10=1;
          break;
         case 11:
          PackCode.i11=1;
          break;
         case 12:
          PackCode.i12=1;
          break;
         case 13:
          PackCode.i13=1;
          break;
         case 14:
          PackCode.i14=1;
          break;
         case 15:
          PackCode.i15=1;
          break;
         case 16:
          PackCode.i16=1;
          break;
         case 17:
          PackCode.i17=1;
          break;
         case 18:
          PackCode.i18=1;
          break;
         case 19:
          PackCode.i19=1;
          break;
         case 20:
          PackCode.i20=1;
          break;
         case 21:
          PackCode.i21=1;
          break;
         case 22:
          PackCode.i22=1;
          break;
         case 23:
          PackCode.i23=1;
          break;
         case 24:
          PackCode.i24=1;
          break;
         case 25:
          PackCode.i25=1;
          break;
         case 26:
          PackCode.i16=1;
          break;
         case 27:
          PackCode.i27=1;
          break;
         case 28:
          PackCode.i28=1;
          break;
         case 29:
          PackCode.i29=1;
          break;
         case 30:
          PackCode.i30=1;
          break;
         case 31:
          PackCode.i31=1;
          break;
        }
       NumBit=NumBit+1;
       if (NumBit==32)
       {
         write(intOUT, &PackCode, sizeof(PackCode));
         NumBit=0;
         PackCode.i00=0;
         PackCode.i01=0;
         PackCode.i02=0;
         PackCode.i03=0;
         PackCode.i04=0;
         PackCode.i05=0;
         PackCode.i06=0;
         PackCode.i07=0;
         PackCode.i08=0;
         PackCode.i09=0;
         PackCode.i10=0;
         PackCode.i11=0;
         PackCode.i12=0;
         PackCode.i13=0;
         PackCode.i14=0;
         PackCode.i15=0;
         PackCode.i16=0;
         PackCode.i17=0;
         PackCode.i18=0;
         PackCode.i19=0;
         PackCode.i20=0;
         PackCode.i21=0;
         PackCode.i22=0;
         PackCode.i23=0;
         PackCode.i24=0;
         PackCode.i25=0;
         PackCode.i26=0;
         PackCode.i27=0;
         PackCode.i28=0;
         PackCode.i29=0;
         PackCode.i30=0;
         PackCode.i31=0;
     }
  }
 }
}

/* æÕÎËÃÉÑ ÒÁÓËÏÄÉÒÏ×ËÉ ÆÁÊÌÁ */
void CodeToFile(int intIN, int intOUT, struct TreeCode *Root)
{
 char chSymb=' ';
 unsigned long lgSum=0, lgSumW=0;

 lgSum=lseek(intIN, lgSum, SEEK_END);
 lgSum=lseek(intIN, lgSum-sizeof(lgSum), SEEK_SET);
 read(intIN, &lgSum, sizeof(lgSum)); /* óÞÉÔÙ×ÁÅÍ ÉÎÆÏÒÍÁÃÉÀ Ï ËÏÌ-×Å ÓÉÍ×ÏÌÏ× */
 lseek(intIN, lgSumW, lgSumW);

 while (lgSumW<lgSum-1)
  {
    lgSumW++;
    chSymb=GetChTree(intIN, Root);
    write(intOUT, &chSymb, sizeof(chSymb));
  }
}

/* æÕÎËÃÉÑ ÐÏÌÕÞÅÎÉÑ ÏÞÅÒÅÄÎÏÇÏ ÓÉÍ×ÏÌÁ (0,1) ÉÚ ÒÁÓËÏÄÉÒÕÅÍÏÇÏ ÆÁÊÌÁ */
int GetCode(int intIN)
{
 struct Bit32 static PackCode;
 static int NumBit=0;
 static int intRead=1;
 int intRet;
 if (NumBit==0)
  intRead=read(intIN, &PackCode, sizeof(PackCode));
  if (intRead==0)
   return -1;
 switch (NumBit)
   {
    case 0:
     intRet=PackCode.i00;
     break;
    case 1:
     intRet=PackCode.i01;
     break;
    case 2:
     intRet=PackCode.i02;
     break;
    case 3:
     intRet=PackCode.i03;
     break;
    case 4:
     intRet=PackCode.i04;
     break;
    case 5:
     intRet=PackCode.i05;
     break;
    case 6:
     intRet=PackCode.i06;
     break;
    case 7:
     intRet=PackCode.i07;
     break;
    case 8:
     intRet=PackCode.i08;
     break;
    case 9:
     intRet=PackCode.i09;
     break;
    case 10:
     intRet=PackCode.i10;
     break;
    case 11:
     intRet=PackCode.i11;
     break;
    case 12:
     intRet=PackCode.i12;
     break;
    case 13:
     intRet=PackCode.i13;
     break;
    case 14:
     intRet=PackCode.i14;
     break;
    case 15:
     intRet=PackCode.i15;
     break;
    case 16:
     intRet=PackCode.i16;
     break;
    case 17:
     intRet=PackCode.i17;
     break;
    case 18:
     intRet=PackCode.i18;
     break;
    case 19:
     intRet=PackCode.i19;
     break;
    case 20:
     intRet=PackCode.i20;
     break;
    case 21:
     intRet=PackCode.i21;
     break;
    case 22:
     intRet=PackCode.i22;
     break;
    case 23:
     intRet=PackCode.i23;
     break;
    case 24:
     intRet=PackCode.i24;
     break;
    case 25:
     intRet=PackCode.i25;
     break;
    case 26:
     intRet=PackCode.i26;
     break;
    case 27:
     intRet=PackCode.i27;
     break;
    case 28:
     intRet=PackCode.i28;
     break;
    case 29:
     intRet=PackCode.i29;
     break;
    case 30:
     intRet=PackCode.i30;
     break;
    case 31:
     intRet=PackCode.i31;
     break;
   }
   NumBit=NumBit+1;
   if (NumBit==32)
    NumBit=0;
 return intRet;
}

void Help(void)
{
 printf("\nðÒÏÇÒÁÍÍÁ ÕÐÁËÏ×ËÉ-ÒÁÓÐÁËÏ×ËÉ ÆÁÊÌÁ\n");
 printf("ðÒÏÇÒÁÍÍÅ ÎÅÏÂÈÏÄÉÍ ÆÁÊÌ MODHAF.TXT, ÐÏÌÕÞÅÎÎÙÊ\n");
 printf("× ÒÅÚÕÌØÔÁÔÅ ÒÁÂÏÔÙ ÐÒÏÇÒÁÍÍÙ haffman#.\n");
 printf("ôÁËÖÅ ÔÒÅÂÕÀÔÓÑ ÔÒÉ ×ÈÏÄÎÙÈ ÐÁÒÁÍÅÔÒÁ:\n");
 printf("1. 'a' (ÕÐÁËÏ×ËÁ) ÉÌÉ 'e' (ÒÁÓÐÁËÏ×ËÁ);\n");
 printf("2. éÍÑ ×ÈÏÄÎÏÇÏ ÆÁÊÌÁ, ËÏÔÏÒÙÊ ÕÐÁËÏ×Ù×ÁÅÔÓÑ (ÒÁÓÐÁËÏ×Ù×ÁÅÔÓÑ);\n");
 printf("3. éÍÑ ×ÙÈÏÄÎÏÇÏ ÆÁÊÌÁ, × ËÏÔÏÒÙÊ ÕÐÁËÏ×Ù×ÁÅÔÓÑ (ÒÁÓÐÁËÏ×Ù×ÁÅÔÓÑ);\n");
 printf("\nðÒÉÍÅÒ: pack# a input.txt outpack.txt\n");
}

/* æÕÎËÃÉÑ ÐÏÌÕÞÅÎÉÑ ÏÞÅÒÅÄÎÏÇÏ ÓÉÍ×ÏÌÁ ÐÏ ÄÅÒÅ×Õ */
char GetChTree(int intIN, struct TreeCode *Root)
/*
int intIN - ÎÏÍÅÒ ÆÁÊÌÁ, × ËÏÔÏÒÏÍ ÚÁËÏÄÉÒÏ×ÁÎÁ ÉÎÆÏÒÍÁÃÉÑ.
struct TreeCode *Root - ÕËÁÚÁÔÅÌØ ÎÁ ÄÅÒÅ×Ï ÒÁÓËÏÄÉÒÏ×ËÉ, ÐÏÓÔÒÏÅÎÎÏÅ 
ÉÚ ÍÏÄÅÌÉ ModHaf.txt.
*/

{
  char chSymb; /* óÉÍ×ÏÌ ×ÏÚ×ÒÁÝÁÅÍÙÊ ÉÚ ÆÕÎËÃÉÉ */
  int intPath=0; /* ðÅÒÅÍÅÎÎÁÑ × ËÏÔÏÒÕÀ ÚÁÎÏÓÉÔÓÑ ÎÁÐÒÁ×ÌÅÎÉÑ Ä×ÉÖÅÎÉÑ
                    ÐÏ ÄÅÒÅ×Õ */
  if (Root->chSymb!=SignEmpty) /* ëÏÎÅÃ ÒÅËÕÒÓÉÉ. SignEmpty (ÓÉÍ×ÏÌ Ó ËÏÄÏÍ
                                  1, ÎÁÈÏÄÉÔÓÑ × ÕÚÌÁÈ, ÎÏ ÎÅ × ÌÉÓÔÁÈ */
.............
    intPath=GetCode(intIN); /* intPath - 0, 1 ÉÌÉ -1.
                               0 - ÉÄÔÉ ÐÏ ÌÅ×ÏÍÕ ÐÏÄÄÅÒÅ×Õ
                               1 - ÉÄÔÉ ÐÏ ÐÒÁ×ÏÍÕ ÐÏÄÄÅÒÅ×Õ
                              -1 - ËÏÎÅÃ ÄÁÎÎÙÈ (ÆÁÊÌÁ) */
.............
 return chSymb;
}
