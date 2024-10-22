#include<stdio.h>
#include<conio.h>
#include<string.h>
#define MAXSIDE 100

struct HashNode
{
  char Data[100];
  HashNode *Next;
};

 HashNode *bucket[MAXSIDE];
 
 int HashFunction(char a[])
 {
  int tong = 0;
  for(int i = 0; i < strlen(a); i++)
  {
    tong = (tong * 31) + a[i];
  }
  return tong % MAXSIDE;
 }

 // Khoi tao bang bam
  void EmptyTable()
  {
    for(int i = 0; i < MAXSIDE; i++)
    {
      bucket[i] = NULL;
    }
  }
 
 HashNode *CreateNode(char x[])
 {
  HashNode *p = new HashNode;
  strcpy(p->Data, x);
  p->Next = NULL;
  return p;
 }

 void ThemDauBucket(int b, HashNode *p)
 {
  if(bucket[b] == NULL)
   bucket[b] = p;
  else
  {
   p->Next = bucket[b];
   bucket[b] = p;
  }  
 }

 void InsertTable(char key[], HashNode *p)
 {
  int b = HashFunction(key);
  ThemDauBucket(b, p);
 }

 void TraverseBucket(int k)
 {
    HashNode * p = bucket[k];
    while (p != NULL)
    {
      printf(" %s", p->Data);
      p = p->Next;
    }
 }

 void Traverse()
 {
  for(int i = 0; i < MAXSIDE; i++)
  {
   printf("\nBucket[%d] : ", i);
   if(bucket[i] == NULL)
    printf("Khong co gi !!!");
   else
   {
    HashNode * p = bucket[i];
    while (p != NULL)
    {
      printf(" %s", p->Data);
      p = p->Next;
    }
   } 
  }
 }
 
 void Search(char x[])
 {
  int b = HashFunction(x);
  HashNode *p = bucket[b];
  if(p == NULL)
   printf("\nKhong tim thay trong tu dien");
  else
  {
    printf("\nNghia la : %s", p->Data);
  } 
 }

 int main()
 {
  EmptyTable();
  char a[17];
  InsertTable("Yeu", CreateNode((char*)"Tinh cam giua ng khac gioi hay cam thay de chiu voi mot su vat"));
  InsertTable("Ghet", CreateNode((char*)"Danh tu la chat ban, Dong tu la ko thik, ko ua"));
  InsertTable("Vui", CreateNode((char*)"Thich thu, vua long voi nhung dieu minh mong muon"));
  InsertTable("Me", CreateNode((char*)"Nguoi sinh ra minh"));
  InsertTable("Hoc", CreateNode((char*)"Tiep nhan kien thuc hay van hoa nao do"));
  //Traverse();
  printf("\nNhap vao tim kiem (Viet hoa chu cai dau): ");
   gets(a);
  Search(a); 
  getch();
  return 1;
 }