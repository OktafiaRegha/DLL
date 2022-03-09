#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <conio.h> 
using namespace std;
struct node 
{
  string data;
  node *next;
  node *prev; 
}; 


  node *head = NULL;
  node *tail = NULL;
  int option = 0; 

void tambah_awal_list()
{
  node *baru;
  baru = new node;
  cout << "Masukkan Data  : ";
  cin >> baru->data;
  baru->next = NULL;
  baru->prev = NULL;
  if(head == NULL)
  {
    head=baru;
    tail=baru;
  }
  else
  {
    baru->next = head;
    head->prev = baru;
    head = baru;
  }
} 

void menambah_node_di_akhir()
  {
  node *baru;   // Temporary pointers 
  // menciptakan node baru 
  baru = new node; 
  cout << "Masukkan Data     : ";
  cin >>   baru->data;
  baru->next = NULL; 

// Set up link pada node
  if (head == NULL )
  {
    head = baru;
    tail = head;
  }
  else
  {
   	tail->next = baru;
    baru->prev = tail;
    tail = baru;
  }
} 

void display_list()
{
  node *temp;
  temp = head;
  cout << endl;
cout << "DATA [";  
  if (temp == NULL)
    cout << "List kosong!" << endl;
  else
  {
    while (temp != NULL)
    {  // Menampilkan detail data
     
     cout << "" << temp->data << ",";
     
     if (temp == tail)
        cout << "     <<<< tail node";
//     cout << endl;
     temp = temp->next; 
    }
    cout << "] ";  
    cout << "Akhir list!" << endl;
  }
  
} 

void hapus_awal_node()
{
  node *temp;
  
  if(head==NULL)
  	{
  		cout<<"Kosong"<<endl;
	  }
	  
  else if(head->next==NULL){
  temp = head;
  head = temp->next;
  head->prev = NULL;
  delete temp;
  	
  }
 
  
  else
  {
  	temp = head;
  	head = temp->next;
  	head->prev = NULL;
  	delete temp;
  }
} 

void hapus_akhir_node()
{
  node *temp;
  if (head == NULL)
    cout << "List kosong!" << endl;
    
  else if(head->next==NULL)
  {
	temp = head;
	head = NULL;
	tail = NULL;
	delete temp;  
  }
  
  else
  {
  	temp = tail;
  	tail = temp->prev;
  	tail->next = NULL;
  	delete temp;
  }
   
} 

void tambah_tengah_list()
{
  node *baru, *bantu, *bantu2;
  int posisi_sisip;
  if(head != NULL)
  {
  
   
    cout<<"Akan disisip setelah Data Ke ? : ";
    cin>>posisi_sisip;
    baru =new node;
   bantu=head;
     
    for(int i=1;i<posisi_sisip-1;i++) {
      if(bantu->next != NULL)
        bantu=bantu->next;
      else
        break; 
    }
  cout << "Masukkan Data     : ";
  cin >> baru->data;
  	 bantu2=bantu->next;
     bantu->next=baru;
     baru->prev=bantu;
     baru->next=bantu2;
     bantu2->prev=baru;
  }
  else
  {
    cout<<"Belum ada data !! silahkan isi data dulu....";
    getch();
  } 
} 
void Hapus_tengah_list()
{
  int banyakdata,posisi_hapus,poshapus;
  node *hapus, *bantu, *bantu2;
  if(head != NULL)
  {
    cout<<" Akan dihapus pada data ke : ";
    cin>>posisi_hapus;
    banyakdata=1;
    bantu=head;
    while(bantu->next != NULL)
    {
      bantu=bantu->next;
      banyakdata++;
    }
    if((posisi_hapus<1)||(posisi_hapus>banyakdata))
    {
      cout<<"Belum ada data !! masukkan Data dula aja...\n";
    }
    else
    {
      bantu=head;
      poshapus=1;
      while(poshapus<(posisi_hapus-1))
      {
        bantu=bantu->next;
        poshapus++;
      }
       hapus=bantu->next;
	   bantu2=hapus->next;
	   bantu->next=hapus->next;
	   bantu2->prev=bantu;
	   delete hapus;
    }
 }
 else {
 	cout<<"Data Masih kosong, tidak bisa hapus data dari tengah! ";
 }
    
 getch();
}

main()
{
 int option;
  do
  {
//    clrscr();
 	system("cls");
    display_list();
    cout<<endl;
    cout<<"    DOUBLE LINKED LIST   "<<endl;
    cout<<"========================="<<endl;
    cout<<"|     MENU PILIHAN :    |"<<endl;
    cout<<"========================="<<endl;
    cout<<"| 0. Keluar program     |"<<endl;
    cout<<"| 1. Tambah awal list   |"<<endl;
    cout<<"| 2. Tambah akhir list  |"<<endl;
    cout<<"| 3. Tambah tengah list |"<<endl;
    cout<<"| 4. Hapus awal list    |"<<endl;
    cout<<"| 5. Hapus akhir list   |"<<endl;
    cout<<"| 6. Hapus tengah list  |"<<endl;
    cout<<endl<<" Pilihan : ";
    cin>>option; 

switch (option)
  {
  case 1 :  system("cls");
  			tambah_awal_list(); 
    break;
  case 2 :  system("cls");
  			menambah_node_di_akhir();
    break;
  case 3 :  system("cls");
  			tambah_tengah_list();
    break;
  case 4 :  system("cls");
  			hapus_awal_node();
    break;
  case 5 :  system("cls");
  			hapus_akhir_node();
    break;
  case 6 :  system("cls");
  			Hapus_tengah_list();
    break;

  }
 }  
while (option != 0); 

}
