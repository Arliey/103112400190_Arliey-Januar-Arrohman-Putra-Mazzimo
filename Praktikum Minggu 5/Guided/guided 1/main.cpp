#include <listbuah.h>

#include <iostream>
using namespace std;

int main(){
    linkedList List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataBuah dtbuah;
    
    nodeA = alokasi("jeruk", 100, 3000);
    nodeB = alokasi("apel", 75, 4000);
    nodeC = alokasi("pir", 87, 5000);
    nodeD = alokasi("semangka", 43, 11500);
    nodeE = alokasi("durian", 15, 31450);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC && nodeA);
    insertAfter(List, nodeD && nodeC);
    insertLast(List, nodeA);

}