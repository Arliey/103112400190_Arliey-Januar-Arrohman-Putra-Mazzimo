#ifndef PELAJARAN_H
#define PELAJARAN_H
#include <iostream>
using namespace std;

typedef struct {
    string namaPelajaran;
    string kodePelajaran;
} pelajaran;

pelajaran createPelajaran(string nama, string kode);

void showPelajaran(pelajaran p);

#endif