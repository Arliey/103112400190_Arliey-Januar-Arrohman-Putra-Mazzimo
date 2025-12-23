#include "MLL.h"
#include <iostream>
using namespace std;

MultiLinkedList::MultiLinkedList() {
    firstParent = NULL;
    lastParent = NULL;
}

void MultiLinkedList::createListParent() {
    firstParent = NULL;
    lastParent = NULL;
}

void MultiLinkedList::createListChild() {
}

NodeParent* MultiLinkedList::alokasiNodeParent(string idGenre, string namaGenre) {
    NodeParent* P = new NodeParent;
    P->IDGenre = idGenre;
    P->namaGenre = namaGenre;
    P->next = NULL;
    P->prev = NULL;
    P->firstChild = NULL;
    P->lastChild = NULL;
    return P;
}

NodeChild* MultiLinkedList::alokasiNodeChild(string idFilm, string judul, int durasi, int tahun, float rating) {
    NodeChild* C = new NodeChild;
    C->IDFilm = idFilm;
    C->judulFilm = judul;
    C->durasiFilm = durasi;
    C->tahunTayang = tahun;
    C->ratingFilm = rating;
    C->next = NULL;
    C->prev = NULL;
    return C;
}

void MultiLinkedList::dealokasiNodeParent(NodeParent* P) {
    delete P;
}

void MultiLinkedList::dealokasiNodeChild(NodeChild* C) {
    delete C;
}

void MultiLinkedList::insertFirstParent(NodeParent* P) {
    if (firstParent == NULL) {
        firstParent = P;
        lastParent = P;
    } else {
        P->next = firstParent;
        firstParent->prev = P;
        firstParent = P;
    }
}

void MultiLinkedList::insertLastParent(NodeParent* P) {
    if (firstParent == NULL) {
        firstParent = P;
        lastParent = P;
    } else {
        lastParent->next = P;
        P->prev = lastParent;
        lastParent = P;
    }
}

void MultiLinkedList::insertAfterParent(NodeParent* Prec, NodeParent* P) {
    if (Prec != NULL) {
        P->next = Prec->next;
        P->prev = Prec;
        if (Prec->next != NULL) {
            Prec->next->prev = P;
        } else {
            lastParent = P;
        }
        Prec->next = P;
    }
}

void MultiLinkedList::insertFirstChild(NodeParent* P, NodeChild* C) {
    if (P->firstChild == NULL) {
        P->firstChild = C;
        P->lastChild = C;
    } else {
        C->next = P->firstChild;
        P->firstChild->prev = C;
        P->firstChild = C;
    }
}

void MultiLinkedList::insertLastChild(NodeParent* P, NodeChild* C) {
    if (P->firstChild == NULL) {
        P->firstChild = C;
        P->lastChild = C;
    } else {
        P->lastChild->next = C;
        C->prev = P->lastChild;
        P->lastChild = C;
    }
}

void MultiLinkedList::insertAfterChild(NodeParent* P, NodeChild* Prec, NodeChild* C) {
    if (Prec != NULL) {
        C->next = Prec->next;
        C->prev = Prec;
        if (Prec->next != NULL) {
            Prec->next->prev = C;
        } else {
            P->lastChild = C;
        }
        Prec->next = C;
    }
}

void MultiLinkedList::deleteFirstParent() {
    if (firstParent != NULL) {
        NodeParent* P = firstParent;
        if (firstParent == lastParent) {
            firstParent = NULL;
            lastParent = NULL;
        } else {
            firstParent = firstParent->next;
            firstParent->prev = NULL;
            P->next = NULL;
        }
        dealokasiNodeParent(P);
    }
}

void MultiLinkedList::deleteLastParent() {
    if (lastParent != NULL) {
        NodeParent* P = lastParent;
        if (firstParent == lastParent) {
            firstParent = NULL;
            lastParent = NULL;
        } else {
            lastParent = lastParent->prev;
            lastParent->next = NULL;
            P->prev = NULL;
        }
        dealokasiNodeParent(P);
    }
}

void MultiLinkedList::deleteAfterParent(NodeParent* Prec) {
    if (Prec != NULL && Prec->next != NULL) {
        NodeParent* P = Prec->next;
        Prec->next = P->next;
        if (P->next != NULL) {
            P->next->prev = Prec;
        } else {
            lastParent = Prec;
        }
        P->next = NULL;
        P->prev = NULL;
        dealokasiNodeParent(P);
    }
}

void MultiLinkedList::deleteFirstChild(NodeParent* P) {
    if (P->firstChild != NULL) {
        NodeChild* C = P->firstChild;
        if (P->firstChild == P->lastChild) {
            P->firstChild = NULL;
            P->lastChild = NULL;
        } else {
            P->firstChild = P->firstChild->next;
            P->firstChild->prev = NULL;
            C->next = NULL;
        }
        dealokasiNodeChild(C);
    }
}

void MultiLinkedList::deleteLastChild(NodeParent* P) {
    if (P->lastChild != NULL) {
        NodeChild* C = P->lastChild;
        if (P->firstChild == P->lastChild) {
            P->firstChild = NULL;
            P->lastChild = NULL;
        } else {
            P->lastChild = P->lastChild->prev;
            P->lastChild->next = NULL;
            C->prev = NULL;
        }
        dealokasiNodeChild(C);
    }
}

void MultiLinkedList::deleteAfterChild(NodeParent* P, NodeChild* Prec) {
    if (Prec != NULL && Prec->next != NULL) {
        NodeChild* C = Prec->next;
        Prec->next = C->next;
        if (C->next != NULL) {
            C->next->prev = Prec;
        } else {
            P->lastChild = Prec;
        }
        C->next = NULL;
        C->prev = NULL;
        dealokasiNodeChild(C);
    }
}

NodeParent* MultiLinkedList::findParent(string idGenre) {
    NodeParent* P = firstParent;
    while (P != NULL) {
        if (P->IDGenre == idGenre) {
            return P;
        }
        P = P->next;
    }
    return NULL;
}

NodeChild* MultiLinkedList::findChild(NodeParent* P, string idFilm) {
    if (P == NULL) return NULL;
    NodeChild* C = P->firstChild;
    while (C != NULL) {
        if (C->IDFilm == idFilm) {
            return C;
        }
        C = C->next;
    }
    return NULL;
}

void MultiLinkedList::printStrukturMLL() {
    NodeParent* P = firstParent;
    int parentNum = 1;
    
    while (P != NULL) {
        cout << "=== Parent " << parentNum << " ===" << endl;
        cout << "ID Genre : " << P->IDGenre << endl;
        cout << "Nama Genre : " << P->namaGenre << endl;
        
        NodeChild* C = P->firstChild;
        int childNum = 1;
        
        if (C == NULL) {
            cout << "  (Tidak ada film)" << endl;
        } else {
            while (C != NULL) {
                cout << "  - Child " << childNum << " :" << endl;
                cout << "    ID Film : " << C->IDFilm << endl;
                cout << "    Judul Film : " << C->judulFilm << endl;
                cout << "    Durasi Film : " << C->durasiFilm << " menit" << endl;
                cout << "    Tahun Tayang : " << C->tahunTayang << endl;
                cout << "    Rating Film : " << C->ratingFilm << endl;
                cout << "    -------------------" << endl;
                
                C = C->next;
                childNum++;
            }
        }
        
        P = P->next;
        parentNum++;
        cout << endl;
    }
}

void MultiLinkedList::searchFilmByRatingRange(float minRating, float maxRating) {
    cout << "Data Film dengan rating " << minRating << " - " << maxRating << endl;
    cout << "========================================" << endl;
    
    NodeParent* P = firstParent;
    bool found = false;
    
    while (P != NULL) {
        NodeChild* C = P->firstChild;
        int posisi = 1;
        
        while (C != NULL) {
            if (C->ratingFilm >= minRating && C->ratingFilm <= maxRating) {
                found = true;
                cout << "Data Film ditemukan pada list child dari node parent " 
                     << P->namaGenre << " pada posisi ke-" << posisi << endl;
                cout << "--- Data Film (Child) ---" << endl;
                cout << "ID Film : " << C->IDFilm << endl;
                cout << "Judul Film : " << C->judulFilm << endl;
                cout << "Durasi Film : " << C->durasiFilm << " menit" << endl;
                cout << "Tahun Tayang : " << C->tahunTayang << endl;
                cout << "Rating Film : " << C->ratingFilm << endl;
                cout << "=========================" << endl;
                cout << "--- Data Genre (Parent) ---" << endl;
                
                NodeParent* temp = firstParent;
                int parentPosisi = 1;
                while (temp != NULL) {
                    if (temp == P) break;
                    parentPosisi++;
                    temp = temp->next;
                }
                
                cout << "Posisi dalam list parent : posisi ke-" << parentPosisi << endl;
                cout << "Nama Genre : " << P->namaGenre << endl;
                cout << "=========================" << endl << endl;
            }
            C = C->next;
            posisi++;
        }
        P = P->next;
    }
    
    if (!found) {
        cout << "Tidak ada film dengan rating tersebut." << endl;
    }
}

void MultiLinkedList::deleteAfterParent(string idGenre) {
    NodeParent* P = findParent(idGenre);
    if (P != NULL && P->next != NULL) {
        NodeParent* toDelete = P->next;
        
        while (toDelete->firstChild != NULL) {
            deleteFirstChild(toDelete);
        }
        
        deleteAfterParent(P);
        cout << "Node parent setelah " << idGenre << " berhasil dihapus" << endl;
    } else {
        cout << "Node parent tidak ditemukan atau tidak ada node setelahnya" << endl;
    }
}

NodeParent* MultiLinkedList::getFirstParent() {
    return firstParent;
}

NodeParent* MultiLinkedList::getLastParent() {
    return lastParent;
}