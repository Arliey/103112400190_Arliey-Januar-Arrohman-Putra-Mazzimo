#include <iostream>
#include <string>

using namespace std;

typedef struct {
    string Nama;
    string NIM;
    float NilaiTugas;
    float NilaiUTS;
    float NilaiUAS;
} Mahasiswa;
const int MAX = 6;

typedef struct {
    Mahasiswa dataMahasiswa[MAX];
    int Top;
} StackMahasiswa;

bool isEmpty(StackMahasiswa& S);
bool isFull(StackMahasiswa& S);
void createStack(StackMahasiswa& S);
void Push(StackMahasiswa& S, Mahasiswa data_di_push);
void Pop(StackMahasiswa& S);
void View(StackMahasiswa& S);
void Update(StackMahasiswa& S, int posisi, Mahasiswa data_update);
float HitungNilaiAkhir(float tugas, float uts, float uas);
void SearchNilaiAkhir(StackMahasiswa& S, float NilaiAkhirMin, float NilaiAkhirMax);
void MaxNilaiAkhir(StackMahasiswa& S);