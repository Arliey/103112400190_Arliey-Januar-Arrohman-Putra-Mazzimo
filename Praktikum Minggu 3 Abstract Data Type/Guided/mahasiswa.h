#ifndef MAHASISWA_H
#define MAHASISWA_H

//Definisi tipe(Struct)
struct mahasiswa {
    char nim[10];
    int nilai1, nilai2;
};

//Deklarasi Primitid(fungsi)
void inputMhs(mahasiswa &m);
float rata2(mahasiswa m);

#endif