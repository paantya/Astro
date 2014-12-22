/* ======================================= */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define NN 30

#define N 22

void PrHash(void);
int keyfunc(char []);
unsigned long ElfHash ( const unsigned char *);


struct record {
struct record *next;
char key_fio[80];  /* for simplicity */
char val_tel[11]; };

static struct record *hash[NN];

int i;
int j;
struct record *pointer;
struct record *mpointer;

int main()
 {
  for (i=0;i<NN;i++)
   hash[i] = NULL; // �������������� ���
  for (i=0;i<N;i++)
   {
     pointer= (record*) malloc(sizeof(struct record )); // �������� ������� ������ ��� ������ ���� record
/* ������� ���������� � ��������������� ���� ������ */
     (*pointer).next = NULL;
     scanf ("%s %s", &((*pointer).key_fio), &((*pointer).val_tel));
/* ************** */
     j = keyfunc((*pointer).key_fio); // �������� �������� ���-������� (���-����)

/* ������� ��������� ������� � ��� (���-�������) */
     if (hash[j] == NULL) 
      // �������� � ���-���� ������ j ��� 
      hash[j] = pointer; // ������� � hash[j] ��������� (����� ������) �� ��������� ������
     else
      // �������� � ���-���� ������ j ����������, ����� ���������� ������
      { mpointer = hash[j];
	while ((*mpointer).next != NULL) {mpointer = (*mpointer).next;}
	(*mpointer).next = pointer; }
      }
   PrHash(); // �������� ������ ������
 }


void PrHash(void)
{
 int i;
 for (i=0;i<NN;i++)
  if (hash[i] != NULL) {
   printf (" hash[%i] <> NULL \n", i);
   mpointer = hash[i];
   while (mpointer != NULL) {
    printf ("  %s %s\n", (*mpointer).key_fio, (*mpointer).val_tel);
    mpointer=(*mpointer).next;
   }
  }
  else
    printf (" hash[%i] = NULL \n", i);

 return;
}

int keyfunc(char s[])
{
 unsigned long int j;
 int key_hash;
   j = ElfHash((unsigned char *) s);
   key_hash = fmod (j, NN);
 return key_hash;
}

/*--- ElfHash --------------------------------------------------- *
  �������������� �������� ���� �������������� � ������� ELF ���
  ��������� ������ UNIX. ��������� ��������� �� ������ ������,
  �������� �� � ���������� unsigned long.
-----------------------------------------------------------------*/
unsigned long ElfHash(const unsigned char *str_in)
{
   unsigned long int x = 0, g;
   while (*str_in)
   {
      x = (x << 4) + *str_in++;
      if (g = x & 0xF0000000)
         x ^= g >> 24;
      x &= ~g;
   }

   return x;
}

char* ChoiceHash(char fio[]) {
  j = keyfunc(fio);
  mpointer = hash[j];
  while (mpointer->key_fio != fio && mpointer != NULL) mpointer = mpointer->next;
  if (mpointer == NULL) 
    return NULL;
  else
    return mpointer->val_tel;
}

int DelElem(char fio[]) {
  j = keyfunc(fio);
  mpointer = hash[j];
  while (mpointer->key_fio != fio && mpointer != NULL) mpointer = mpointer->next;
  if (mpointer == NULL) 
    return 0;
  else {
    pointer = mpointer;
    mpointer = mpointer->next;
    free(pointer);
    return 1;
  }
}


