#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

 struct Node
 {
   int Data;
   Node *Right;
   Node *Left;
 };

 struct Tree
 {
  Node *Root;
 };

 int EmptyTree(Tree &sl)
 {
    sl.Root = NULL;
    return 1;
 }

 Node *CreateNode(int x) 
 {
  Node *p = new Node;
  if(p == NULL)
  {
    printf("\nKhong du bo nho");
    getch();
    return NULL;
  }
  p->Data = x;
  p->Left = NULL;
  p->Right = NULL;
  return p;
 }

  int CreateTree(Node *&root, Node *p)
 {
   if(p == NULL)
    return 0;
   if(root == NULL)
    {
     root = p;
     return 1;
    }
    
   if(p->Data == root->Data)
    return 0;
   if(p->Data < root->Data)
    CreateTree(root->Left, p);
   else
    CreateTree(root->Right, p);   
  return 1;
 }

 void PrintTree(Node *root)  //LNR
 {
   if(root == NULL)
    return;
   PrintTree(root->Left);
   printf("%4d", root->Data);
   PrintTree(root->Right); 
 }

 void NLR(Node *root)
 {
  if(root == NULL)
   return;
   printf("%3d", root->Data);
   NLR(root->Left);
   NLR(root->Right);
 }
 
 Node *FindNode(Node *root, int x)
 {
  if(root == NULL)
   return NULL;
  if(root->Data == x)
   return root;
  else if(x < root->Data)
   return FindNode(root->Left, x);
  else
   return FindNode(root->Right, x);
 }
 
 Node *NodeReplace(Node *&p)
 {
  Node *q = p->Right;
  Node *f = p;
  while (q->Left != NULL)
  {
    f = q;
    q = q->Left;
  }
   p->Data = q->Data;
   if(f == p)
    {
      f->Right = q->Right;
    }
   else
   {
    f->Left = q->Right;
   }
   return q;
 }

 int DeleteNode(Node *&root, int x)
 {
    if(root == NULL)
   return 0;
  if(x < root->Data)
   DeleteNode(root->Left, x);
  else if(x > root->Data)
   DeleteNode(root->Right, x);
  else
  {
    Node *p = root;
    if(root->Right == NULL)
     {
       root = root->Left;
       delete p;
     }
    else if(root->Left == NULL)
    {
     root = root->Right;
     delete p;
    }
    else 
    {
      Node *q = NodeReplace(p);
      delete q;
    }
  }
  return 1;
 }

 void ReadFromFile(int &n, Tree &ROOT)
 {
   FILE *f = fopen("Songuyen.txt", "r");
    fscanf(f, "%d\n\n", &n);
   for(int i = 0; i < n; i++)
   {
    int x = 0;
    fscanf(f, "%d\n", &x);
    CreateTree(ROOT.Root, CreateNode(x));
   }
   fclose(f);
 }
 
 void ReadFromArray(Tree &ROOT, char a[], int n)
 {
   for(int i = 0; i < n; i++)
   {
    CreateTree(ROOT.Root, CreateNode(a[i]));
   }
 }

 int main()
 {
  Tree ROOT;
  int n = 0;
  EmptyTree(ROOT);
  //DeleteNode(ROOT.Root, 15);
  //printf("\n\n");
  ReadFromFile(n, ROOT);
  NLR(ROOT.Root);
  getch();
  return 1;
 }