#include "StackMahasiswa.h"

Mahasiswa createMahasiswa(string nama, string nim, float tugas, float uts, float uas) {
    Mahasiswa mhs;
    mhs.Nama = nama;
    mhs.NIM = nim;
    mhs.NilaiTugas = tugas;
    mhs.NilaiUTS = uts;
    mhs.NilaiUAS = uas;
    return mhs;
}

int main() {
    StackMahasiswa S;
    Mahasiswa mhs;
    createStack(S);

    mhs = createMahasiswa("Venti", "11111", 75.7, 82.1, 65.5);
    Push(S, mhs);

    mhs = createMahasiswa("Xiao", "22222", 87.4, 88.9, 81.9);
    Push(S, mhs);

    mhs = createMahasiswa("Kazuha", "33333", 92.3, 88.8, 82.4);
    Push(S, mhs);

    mhs = createMahasiswa("Wanderer", "44444", 95.5, 85.5, 90.5);
    Push(S, mhs);

    mhs = createMahasiswa("Lynette", "55555", 77.7, 65.4, 79.9);

    Push(S, mhs);
    mhs = createMahasiswa("Chasca", "66666", 99.9, 93.6, 87.3);
    Push(S, mhs);

    View(S);
    Pop(S);
    View(S);

    Mahasiswa data_update;
    data_update.Nama = "Heizou";
    data_update.NIM = "77777";
    data_update.NilaiTugas = 99.9;
    data_update.NilaiUTS = 88.8;
    data_update.NilaiUAS = 77.7;
    
    Update(S, 3, data_update); 
    View(S);
    SearchNilaiAkhir(S, 85.5, 95.5);
    MaxNilaiAkhir(S);
    return 0;
}