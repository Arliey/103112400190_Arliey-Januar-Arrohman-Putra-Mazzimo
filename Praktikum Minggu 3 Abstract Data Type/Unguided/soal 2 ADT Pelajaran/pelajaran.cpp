#include <iostream>
#include "pelajaran.h"
using namespace std;

pelajaran createPelajaran(string nama, string kode) {
    pelajaran P;
    P.namaPelajaran = nama;
    P.kodePelajaran = kode;
    return P;
}

void showPelajaran(pelajaran P) {
    cout << "Nama Pelajaran : " << P.namaPelajaran << endl;
    cout << "Kode Pelajaran : " << P.kodePelajaran << endl;
}