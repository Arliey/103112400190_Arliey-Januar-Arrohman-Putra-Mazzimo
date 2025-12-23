#include <iostream>
#include "MLL.h"
using namespace std;

int main() {
    MultiLinkedList bioskop;

    cout << " SISTEM BIOSKOP - MULTI LINKED LIST" << endl;
    
    cout << "\n1) createListParent()" << endl;
    bioskop.createListParent();
    cout << "List Parent berhasil dibuat" << endl;
    cout << "\n2) Alokasi dan Insert Node Parent & Child" << endl;
    
    NodeParent* P1 = bioskop.alokasiNodeParent("G001", "Action");
    NodeParent* P2 = bioskop.alokasiNodeParent("G002", "Comedy");
    NodeParent* P3 = bioskop.alokasiNodeParent("G003", "Horror");
    NodeParent* P4 = bioskop.alokasiNodeParent("G004", "Romance");
    
    bioskop.insertLastParent(P1);
    bioskop.insertLastParent(P2);
    bioskop.insertLastParent(P3);
    bioskop.insertLastParent(P4);
    
    NodeChild* C1 = bioskop.alokasiNodeChild("FA001", "The Raid", 101, 2011, 7.6);
    bioskop.insertLastChild(P1, C1);
    
    NodeChild* C2 = bioskop.alokasiNodeChild("FC001", "Agak Laen", 119, 2024, 8.0);
    bioskop.insertLastChild(P2, C2);
    
    NodeChild* C3 = bioskop.alokasiNodeChild("FC002", "My Stupid Boss", 108, 2016, 6.8);
    bioskop.insertLastChild(P2, C3);
    
    NodeChild* C4 = bioskop.alokasiNodeChild("FH001", "Pengabdi Setan", 107, 2017, 8.4);
    bioskop.insertLastChild(P3, C4);
    
    NodeChild* C5 = bioskop.alokasiNodeChild("FR001", "Habibie & Ainun", 118, 2012, 7.6);
    bioskop.insertLastChild(P4, C5);
    
    NodeChild* C6 = bioskop.alokasiNodeChild("FR002", "Dilan 1990", 110, 2018, 6.6);
    bioskop.insertLastChild(P4, C6);
    
    cout << "Semua data berhasil dimasukkan" << endl;
    
    cout << "\n3) printStrukturMLL()" << endl;
    bioskop.printStrukturMLL();
    
    cout << "\n4) searchFilmByRatingRange(8.0, 8.5)" << endl;
    bioskop.searchFilmByRatingRange(8.0, 8.5);
    
    cout << "\n5) deleteAfterParent(G002)" << endl;
    bioskop.deleteAfterParent("G002");
    
    cout << "\n6) printStrukturMLL() setelah delete" << endl;
    bioskop.printStrukturMLL();

    cout << "PROGRAM SELESAI" << endl;
    
    return 0;
}