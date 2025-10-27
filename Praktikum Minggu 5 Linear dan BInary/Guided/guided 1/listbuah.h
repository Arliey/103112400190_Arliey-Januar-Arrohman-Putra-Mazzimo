//header guard digunakan untuk mencegah file header yang sama
#ifndef LISTBUAH_H
#define LISTBUAH_H
#define Nil NULL 

#include <iostream>
using namespace std;

struct buah {
    string nama;
    int jumlah;
    float harga;
};

typedef buah dataBuah; // memberikan nama alias dataBuah untuk struct buah
typedef struct node *address; // memberikan nama alias alamatelmt untuk pointer ke struct elemen

struct node { // node untuk isi dari linked list, isi setiap node adalah data & point
    dataBuah isidata; 
    address next; 
};

struct linkedList { // ini linked listnya
    address first; 
};

//semua function & prosedur yang akan dipakai
//materi modul 4
bool isEmpty(linkedList List);
void createList(linkedList &List);
address alokasi(string nama, int jumlah, float harga);
void  delokasi(address &node);
bool isEmpty(linkedList List);
void createList(linkedList &List);
address alokasi(string nama, int jumlah, float harga);
void  delokasi(address &node);
void printList(linkedList List);
void insertFirst(linkedList &List, address nodebaru);
void insertAfter(address &list, address nodebaru, address Prev);
void insertLast(linkedList &List, address nodebaru);
void deleteFirst(linkedList &List);
void deleteAfter(address &list, address &nodehapus, address Prev);
int nblist(linkedList List);
void deleteLast(linkedList &List);

//materi modul 5 (part 1 - update)
void updateFirst(linkedList list);
void updatelast(linkedList list);
void updateafter(linkedList, address Prev);

#endif