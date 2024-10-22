#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>

struct MonHoc   // Môn học
{
    char MaMonHoc[12];
    char TenMonHoc[30];
    char LoaiMonHoc[20];
    int TinChi;
    char HeDaoTao[5];
};

struct Node
{
    MonHoc Data;
    Node *Left;
    Node *Right;
};

struct QueueNode
{
  Node *node;
  QueueNode *Next;
};

struct Queue
{
   QueueNode *Head;
   QueueNode *Tail;
};

struct Tree
{
    Node *Root;
};

 Node *CreateNode(MonHoc x)  // Tạo Node
{
    Node *p = new Node;
    if(p == NULL)
     {
      printf("\n\nKhong du bo nho !!\n\n");
       return NULL;
     }
     p->Data = x;
     p->Left = NULL;
     p->Right = NULL;
     return p;
}

 void EmptyTree(Tree &root)
 {
    root.Root = NULL;
 }
 
 void EmptyQueue(Queue &sl)
 {
   sl.Head = NULL;
   sl.Tail = NULL;
 }
  
 void ThemNodeQueue(Queue &q, Node *Node)
 {
   QueueNode *p = new QueueNode;
   if(p == NULL)
    {
      printf("\nKhong du bo nho !");
      return ;
    }
    p->node = Node;
    p->Next = NULL;
    if(q.Head == NULL)
    {
      q.Head = p;
      q.Tail = p;
      return ;
    }
    q.Tail->Next = p;
    q.Tail = p;
 }

 Node *XoaNodeQueue(Queue &q)
 {
   if(q.Head == NULL)
    return NULL;
   QueueNode *p = q.Head;
    q.Head = q.Head->Next;
    if(q.Head == NULL)
     q.Tail = NULL;
   Node *tam = p->node;
    delete p;
    return tam;
 }
 
 void DuyetCayRong(Node *root)
 {
   if(root == NULL)
    return;
   Queue q;
   EmptyQueue(q);
   ThemNodeQueue(q, root);
   while(q.Head != NULL)
   {
    Node *Nho = XoaNodeQueue(q);
      printf("\n|| %s-%s-%s-%d-%s ||", Nho->Data.MaMonHoc, Nho->Data.TenMonHoc, Nho->Data.LoaiMonHoc, Nho->Data.TinChi, Nho->Data.HeDaoTao);
      printf("\n--------------------------------------------------");
    if(Nho->Left != NULL)
      ThemNodeQueue(q, Nho->Left);
    if(Nho->Right != NULL)
      ThemNodeQueue(q, Nho->Right); 
   }
 }

 int CreateTree(Node *&root, Node *p)  //Tạo cây (thêm Node)
 {
    if(p == NULL)
     return 0;
    if(root == NULL)
     {
       root = p;
       return 1;
     }     
    if(strcmp(root->Data.TenMonHoc, p->Data.TenMonHoc) == 0)  // Trùng Ten Môn học
     return 0;
    if(strcmp(p->Data.TenMonHoc, root->Data.TenMonHoc) < 0)
     CreateTree(root->Left, p);
    else
     CreateTree(root->Right, p);
    return 1;    
 }

 void PrintMonHocLNR(Node *root)  // Xuất ra màn hình LNR
 {
    if(root == NULL)
     return;
    PrintMonHocLNR(root->Left);
    printf("\n|| %s-%s-%s-%d-%s ||", root->Data.MaMonHoc, root->Data.TenMonHoc, root->Data.LoaiMonHoc, root->Data.TinChi, root->Data.HeDaoTao);
    printf("\n--------------------------------------------------");
    PrintMonHocLNR(root->Right);
 }

 void PrintMonHocLRN(Node *root)  // Xuất ra màn hình LRN
 {
    if(root == NULL)
     return;
    PrintMonHocLRN(root->Left);
    PrintMonHocLRN(root->Right);
    printf("\n|| %s-%s-%s-%d-%s ||", root->Data.MaMonHoc, root->Data.TenMonHoc, root->Data.LoaiMonHoc, root->Data.TinChi, root->Data.HeDaoTao);
    printf("\n-------------------------------------------------------------");
 }

 void PrintMonHocNLR(Node *root)  // Xuất ra màn hình NLR
 {
    if(root == NULL)
     return;
    printf("\n|| %s-%s-%s-%d-%s ||", root->Data.MaMonHoc, root->Data.TenMonHoc, root->Data.LoaiMonHoc, root->Data.TinChi, root->Data.HeDaoTao);
    printf("\n-------------------------------------------------------------");
    PrintMonHocNLR(root->Left);
    PrintMonHocNLR(root->Right);
 }

 void PrintMonHocNRL(Node *root)  // Xuất ra màn hình NRL
 {
    if(root == NULL)
     return;
    printf("\n|| %s-%s-%s-%d-%s ||", root->Data.MaMonHoc, root->Data.TenMonHoc, root->Data.LoaiMonHoc, root->Data.TinChi, root->Data.HeDaoTao);
    printf("\n-------------------------------------------------------------");
    PrintMonHocNRL(root->Right);
    PrintMonHocNRL(root->Left);
 }

 void PrintMonHocRNL(Node *root)  // Xuất ra màn hình RNL
 {
    if(root == NULL)
     return;
    PrintMonHocRNL(root->Right);
    printf("\n|| %s-%s-%s-%d-%s ||", root->Data.MaMonHoc, root->Data.TenMonHoc, root->Data.LoaiMonHoc, root->Data.TinChi, root->Data.HeDaoTao);
    printf("\n-------------------------------------------------------------");
    PrintMonHocRNL(root->Left);
 }

 void PrintMonHocRLN(Node *root)  // Xuất ra màn hình RLN
 {
    if(root == NULL)
     return;
    PrintMonHocRLN(root->Right);
    PrintMonHocRLN(root->Left);
    printf("\n|| %s-%s-%s-%d-%s ||", root->Data.MaMonHoc, root->Data.TenMonHoc, root->Data.LoaiMonHoc, root->Data.TinChi, root->Data.HeDaoTao);
    printf("\n-------------------------------------------------------------");
 }
 
 Node* minValueNode(Node* node) 
 {
    Node* current = node;

    while (current && current->Left != NULL) {
        current = current->Left;
    }

    return current;
 }

 Node* SearchNode(Node* node, char* subjectName) 
 {
    if (node == NULL || strcmp(node->Data.TenMonHoc, subjectName) == 0) {
        return node;
    }

    if (strcmp(subjectName, node->Data.TenMonHoc) < 0) {
        return SearchNode(node->Left, subjectName);
    } else {
        return SearchNode(node->Right, subjectName);
    }
 }

 Node* DeleteNode(Node* root, char TenMonHoc[30]) 
 {
    if (root == NULL) {
        return root;
    }

    // tim nut can xoa 
    if (strcmp(TenMonHoc, root->Data.TenMonHoc) < 0) {
        root->Left = DeleteNode(root->Left, TenMonHoc);
    } else if (strcmp(TenMonHoc, root->Data.TenMonHoc) > 0) {
        root->Right = DeleteNode(root->Right, TenMonHoc);
    } else {
        // Node co 1 node hoac ko co node
        if (root->Left == NULL) 
        {
            Node* temp = root->Right;
            free(root);
            return temp;
        } 
        else if (root->Right == NULL) 
        {
            Node* temp = root->Left;
            free(root);
            return temp;
        }
        else 
        {
          // nut co 2 con
          // Tim gia tri nho nhat cua cay con phai
        Node* temp = minValueNode(root->Right);

        // Copy nut co gia tri nho nhat 
        strcpy(root->Data.TenMonHoc, temp->Data.TenMonHoc);

        // xoa nut co gia tri nho nhat cay ben phai 
        root->Right = DeleteNode(root->Right, temp->Data.TenMonHoc);
        }
    }
    return root;
 }

 void DemSTC(Node *root, int NhapSTC, int &count) 
 {
  if (root == NULL) {
    return;
  }
  DemSTC(root->Left, NhapSTC, count);
  if (root->Data.TinChi == NhapSTC) {
    count++;
  }
  DemSTC(root->Right, NhapSTC, count);
}

 void TinhTongSTC(Node* root, int &tongSTC) 
 {
    if (root == NULL) {
        return; // Base case: empty subtree
    }

    // them so vao nut hien tai 
    tongSTC += root->Data.TinChi;

    // tinh de quy cac nut trai phai 
    TinhTongSTC(root->Left, tongSTC);
    TinhTongSTC(root->Right, tongSTC);
 }

 void NhapTuFile(Tree &Root, char a[])
 {
   int n;
   FILE *f = fopen(a, "r");
   if(f == NULL)
    {
      printf("\nKhong ton tai file !!!");
      return;
    }

   else
   {
    fscanf(f, "%d\n\n", &n);
    for(int i = 0; i < n; i++)
    {
      MonHoc x;
      fscanf(f, "%[^#]#%[^#]#%[^#]#%[^#]#%d\n", &x.MaMonHoc, &x.TenMonHoc, &x.LoaiMonHoc, &x.HeDaoTao, &x.TinChi);
      CreateTree(Root.Root, CreateNode(x));
    }
   printf("\nDa doc xong !");
   fclose(f);
   }
 }
 
 void NhapThongTin(MonHoc &x)
 {
    rewind(stdin);
    printf("\nNhap vao ma mon hoc : ");
     gets(x.MaMonHoc);
    printf("\nNhap vao ten mon hoc : ");
     gets(x.TenMonHoc);
    printf("\nNhap vao loai mon hoc : ");
     gets(x.LoaiMonHoc);
    printf("\nNhap vao so tin chi : ");
     scanf("%d", &x.TinChi);
    rewind(stdin);
    printf("\nNhap vao he dao tao : ");
     gets(x.HeDaoTao);
     rewind(stdin);
 }

 void DemSoLuongTheoLoai(Node* root, char loaiMonHoc[], int &count)
 {
  if(root == NULL)
    return;
  if(strcmp(root->Data.LoaiMonHoc, loaiMonHoc) == 0)
  {
   count++;
   printf("\n|| %s-%s-%s-%d-%s ||", root->Data.MaMonHoc, root->Data.TenMonHoc, root->Data.LoaiMonHoc, root->Data.TinChi, root->Data.HeDaoTao);
   printf("\n-------------------------------------------------------------");
  }
  DemSoLuongTheoLoai(root->Left, loaiMonHoc, count);
  DemSoLuongTheoLoai(root->Right, loaiMonHoc, count);
 }

 void ThongKeMonHoc(Node *root, int x)
 {
   if(root == NULL)
     return;
   if(root->Data.TinChi == x)
   {
    printf("\n|| %s-%s-%s-%d-%s ||", root->Data.MaMonHoc, root->Data.TenMonHoc, root->Data.LoaiMonHoc, root->Data.TinChi, root->Data.HeDaoTao);
    printf("\n-------------------------------------------------------------");
   }
    ThongKeMonHoc(root->Left, x);
    ThongKeMonHoc(root->Right, x);
 }
 
 void MENU()
 {
   printf("\n*************************************************************");
   printf("\n||   1) Them mon hoc tu ban phim                           ||");
   printf("\n||   2) Them mon hoc tu File txt                           ||");
   printf("\n||   3) Xuat ra man hinh 6 cach duyet cay                  ||");
   printf("\n||   4) Xuat ra man hinh duyet cay chieu sau va chieu rong ||");
   printf("\n||   5) Xoa mot mon hoc ra khoi cay                        ||");
   printf("\n||   6) Tim mot mon hoc x trong cay                        ||");
   printf("\n||   7) Thong ke mon hoc theo so tin chi                   ||");
   printf("\n||   8) Dem so luong mon hoc theo tung loai                ||");
   printf("\n||   9) Tinh tong so tin chi cac mon hoc                   ||");
   printf("\n||   0) Thoat chuong trinh                                 ||");
   printf("\n*************************************************************");
 }
 
 void ChonSo()
 {  
   Tree ROOT;
   EmptyTree(ROOT);
   int chon, NhapSTC, count;
   int dem = 1;
   MonHoc X;
   while(dem != 0)
   {
    MENU();
    rewind(stdin);
    printf("\nNhap vao lua chon : ");
    scanf("%d", &chon);
    switch (chon)
    {

      case 1 :
      {
       NhapThongTin(X);
       CreateTree(ROOT.Root, CreateNode(X));
       rewind(stdin);
      }
         break;

      case 2 :
      {
         char a[30];
         rewind(stdin);
         printf("\nNhap vao ten file : ");
          gets(a);
         NhapTuFile(ROOT, a);
         rewind(stdin);
      }   
       break;
           
      case 3 :
      {
        printf("\nCach 1 LNR");
        PrintMonHocLNR(ROOT.Root);
        printf("\nCach 2 LRN");
        PrintMonHocLRN(ROOT.Root);
        printf("\nCach 3 NLR");
        PrintMonHocNLR(ROOT.Root);
        printf("\nCach 4 NRL");
        PrintMonHocNRL(ROOT.Root);
        printf("\nCach 5 RNL");
        PrintMonHocRNL(ROOT.Root);
        printf("\nCach 6 RLN");
        PrintMonHocRLN(ROOT.Root);
      }   
       break;
      
      case 4 :
      {
       printf("\nDuyet cay theo chieu sau (DFS)");
        PrintMonHocNLR(ROOT.Root);
       printf("\n\nDuyet cay theo chieu rong (BFS)");
        DuyetCayRong(ROOT.Root);      
      }   
       break;

      case 5: 
      {
        printf("\nNhap ten mon hoc can xoa: ");
	      scanf("%s", X.TenMonHoc);
	      // tim nut can xoa 
	      Node* nodeToDelete = SearchNode(ROOT.Root, X.TenMonHoc);
	      if (nodeToDelete == NULL) 
	       printf("\nKhong tim thay mon hoc %s!\n", X.TenMonHoc);

        else 
        {
	       // xoa nut khoi BST
	       ROOT.Root = DeleteNode(ROOT.Root, X.TenMonHoc);
	       printf("\nXoa thanh cong mon hoc %s!\n", X.TenMonHoc);
    	  }
    	  PrintMonHocNLR(ROOT.Root);
      }
       break;
       
      case 6 :
      {
       printf("\nNhap ten mon hoc can tim: ");
        scanf("%s", X.TenMonHoc);
       Node* result = SearchNode(ROOT.Root, X.TenMonHoc);
       if (result != NULL) 
       { 
        printf("\nTim thay mon hoc %s:\n", X.TenMonHoc);
        printf("Ma Mon Hoc: %s\n", result->Data.MaMonHoc);
        printf("Ten Mon Hoc: %s\n", result->Data.TenMonHoc);
        printf("Loai Mon Hoc: %s\n", result->Data.LoaiMonHoc);
        printf("So Tin Chi: %d\n", result->Data.TinChi);
        printf("He Dao Tao: %s\n", result->Data.HeDaoTao);
       }

       else 
       {   
        printf("\nKhong tim thay mon hoc %s!\n", X.TenMonHoc);
       }
      }   
       break;
       
      case 7:
      {
       printf("\nNhap so tin chi can tim: ");
       scanf("%d", &NhapSTC);
       count = 0;
       DemSTC(ROOT.Root, NhapSTC, count);
       printf("\nSo mon hoc co %d tin chi: %d\n", NhapSTC, count);
       if(count != 0)
        {
          ThongKeMonHoc(ROOT.Root, NhapSTC);
        }
      }
       break;
       
      case 8 :
      {
       int count = 0;
       DemSoLuongTheoLoai(ROOT.Root, "BatBuoc", count);
       printf("\nSo luong mon hoc loai Bat Buoc la : %d\n\n", count);
       count = 0;
       DemSoLuongTheoLoai(ROOT.Root, "TuChon", count);
       printf("\nSo luong mon hoc loai Tu Chon la : %d", count);
      }
       break;

      case 9:
      {
       int tongSTC = 0;
       TinhTongSTC(ROOT.Root, tongSTC);
       printf("\nTong so tin chi cua cac mon hoc: %d\n", tongSTC);
      }
       break; 
      
      case 0 : 
      {
        dem = 0;
        printf("\nTHOAT CHUONG TRINH !!!");
      }
        break;

      default:printf("\nVUI LONG NHAP DUNG MENU !!!");
        break;
    } 
   }
 }

 int main()
 {
   ChonSo();
   getch();
   return 1;
 }