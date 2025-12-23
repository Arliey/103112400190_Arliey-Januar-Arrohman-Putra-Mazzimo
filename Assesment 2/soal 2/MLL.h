#ifndef MLL_H
#define MLL_H

#include <string>
using namespace std;

struct NodeChild {
    string IDFilm;
    string judulFilm;
    int durasiFilm;
    int tahunTayang;
    float ratingFilm;
    NodeChild* next;
    NodeChild* prev;
};

struct NodeParent {
    string IDGenre;
    string namaGenre;
    NodeParent* next;
    NodeParent* prev;
    NodeChild* firstChild;
    NodeChild* lastChild;
};

class MultiLinkedList {
private:
    NodeParent* firstParent;
    NodeParent* lastParent;
    
public:
    MultiLinkedList();
    void createListParent();
    void createListChild();
    NodeParent* alokasiNodeParent(string idGenre, string namaGenre);
    NodeChild* alokasiNodeChild(string idFilm, string judul, int durasi, int tahun, float rating);
    void dealokasiNodeParent(NodeParent* P);
    void dealokasiNodeChild(NodeChild* C);
    void insertFirstParent(NodeParent* P);
    void insertLastParent(NodeParent* P);
    void insertAfterParent(NodeParent* Prec, NodeParent* P);
    void insertFirstChild(NodeParent* P, NodeChild* C);
    void insertLastChild(NodeParent* P, NodeChild* C);
    void insertAfterChild(NodeParent* P, NodeChild* Prec, NodeChild* C);
    void deleteFirstParent();
    void deleteLastParent();
    void deleteAfterParent(NodeParent* Prec);
    void deleteFirstChild(NodeParent* P);
    void deleteLastChild(NodeParent* P);
    void deleteAfterChild(NodeParent* P, NodeChild* Prec);
    NodeParent* findParent(string idGenre);
    NodeChild* findChild(NodeParent* P, string idFilm);
    void printStrukturMLL();
    void searchFilmByRatingRange(float minRating, float maxRating);
    void deleteAfterParent(string idGenre);
    
    NodeParent* getFirstParent();
    NodeParent* getLastParent();
};

#endif