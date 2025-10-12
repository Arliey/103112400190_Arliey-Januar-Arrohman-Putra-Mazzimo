#include <iostream>
#include "pelajaran.h"
using namespace std;

int main() {
    string namaPelajaran, kodePelajaran;

    cout << "Masukkan Nama Pelajaran : ";
    getline(cin, namaPelajaran);
    cout << "Masukkan Kode Pelajaran : ";
    cin >> kodePelajaran;

    pelajaran P = createPelajaran (namaPelajaran, kodePelajaran);

    showPelajaran(P);

    return 0;
}