#include "StackMahasiswa.h"
#include <iomanip>

bool isEmpty(StackMahasiswa& S) {
    return S.Top == -1;
}

bool isFull(StackMahasiswa& S) {
    return S.Top == MAX - 1;
}

void createStack(StackMahasiswa& S) {
    S.Top = -1;
    cout << "Stack kosong berhasil dibuat dengan Top = -1." << endl;
}

void Push(StackMahasiswa& S, Mahasiswa data_di_push) {
    if (isFull(S)) {
        cout << "Gagal Push: Stack sudah penuh (MAX = " << MAX << ")." << endl;
    } else {
        S.Top++;
        S.dataMahasiswa[S.Top] = data_di_push;
        cout << "Berhasil Push data Mahasiswa " << data_di_push.Nama << " ke posisi Top (" << S.Top << ")." << endl;
    }
}

void Pop(StackMahasiswa& S) {
    if (isEmpty(S)) {
        cout << "Gagal Pop: Stack kosong." << endl;
    } else {
        cout << "Berhasil Pop data Mahasiswa: " << S.dataMahasiswa[S.Top].Nama << " (NIM: " << S.dataMahasiswa[S.Top].NIM << ") dari posisi Top (" << S.Top << ")." << endl;
        S.Top--;
    }
}

float HitungNilaiAkhir(float tugas, float uts, float uas) {
    return (0.20 * tugas) + (0.40 * uts) + (0.40 * uas);
}

void View(StackMahasiswa& S) {
    cout << "\nTampilan Isi Stack (Top: " << S.Top << ", MAX: " << MAX << ")" << endl;
    if (isEmpty(S)) {
        cout << "Stack kosong." << endl;
    } else {
        cout << fixed << setprecision(1);

        for (int i = S.Top; i >= 0; i--) {
            float nilai_akhir = HitungNilaiAkhir(
                S.dataMahasiswa[i].NilaiTugas,
                S.dataMahasiswa[i].NilaiUTS,
                S.dataMahasiswa[i].NilaiUAS
            );
            cout << i + 1 << ") Nama : " << S.dataMahasiswa[i].Nama << endl;
            cout << "   NIM : " << S.dataMahasiswa[i].NIM << endl;
            cout << "   NilaiTugas : " << S.dataMahasiswa[i].NilaiTugas << endl;
            cout << "   NilaiUTS : " << S.dataMahasiswa[i].NilaiUTS << endl;
            cout << "   NilaiUAS : " << S.dataMahasiswa[i].NilaiUAS << endl;
            cout << "   NilaiAkhir : " << nilai_akhir << endl;
        }
    }
}

void Update(StackMahasiswa& S, int posisi, Mahasiswa data_update) {
    int index = posisi - 1;

    if (posisi < 1 || posisi > S.Top + 1) {
        cout << "Gagal Update: Posisi " << posisi << " tidak valid. Posisi harus antara 1 sampai " << S.Top + 1 << "." << endl;
    } else {
        S.dataMahasiswa[index] = data_update;
        cout << "Berhasil Update data Mahasiswa pada posisi " << posisi << " (Index Array: " << index << "). Nama baru: " << data_update.Nama << endl;
    }
}

void SearchNilaiAkhir(StackMahasiswa& S, float NilaiAkhirMin, float NilaiAkhirMax) {
    cout << "\nHasil Pencarian Mahasiswa (Nilai Akhir antara " << NilaiAkhirMin << " - " << NilaiAkhirMax << ")" << endl;
    if (isEmpty(S)) {
        cout << "Stack kosong, tidak ada data untuk dicari." << endl;
        return;
    }

    bool ditemukan = false;
    cout << fixed << setprecision(1);

    for (int i = 0; i <= S.Top; i++) {
        float nilai_akhir = HitungNilaiAkhir(
            S.dataMahasiswa[i].NilaiTugas,
            S.dataMahasiswa[i].NilaiUTS,
            S.dataMahasiswa[i].NilaiUAS
        );

        if (nilai_akhir >= NilaiAkhirMin && nilai_akhir <= NilaiAkhirMax) {
            cout << "Ditemukan pada Posisi Stack: " << i + 1 << " (Index Array: " << i << ")" << endl;
            cout << "  Nama: " << S.dataMahasiswa[i].Nama << endl;
            cout << "  NIM: " << S.dataMahasiswa[i].NIM << endl;
            cout << "  Nilai Akhir: " << nilai_akhir << endl;
            ditemukan = true;
        }
    }

    if (!ditemukan) {
        cout << "Tidak ada Mahasiswa yang memiliki Nilai Akhir dalam rentang tersebut." << endl;
    }
}

void MaxNilaiAkhir(StackMahasiswa& S) {
    if (isEmpty(S)) {
        cout << "Stack kosong." << endl;
        return;
    }

    float max_nilai = -1.0;
    int posisi_max = -1;
    int index_max = -1;

    for (int i = 0; i <= S.Top; i++) {
        float current_nilai = HitungNilaiAkhir(
            S.dataMahasiswa[i].NilaiTugas,
            S.dataMahasiswa[i].NilaiUTS,
            S.dataMahasiswa[i].NilaiUAS
        );

        if (current_nilai > max_nilai) {
            max_nilai = current_nilai;
            index_max = i;
            posisi_max = i + 1;
        }
    }

    cout << fixed << setprecision(1);
    cout << "Nilai Akhir Terbesar: " << max_nilai << endl;
    cout << "Ditemukan pada Posisi Stack: " << posisi_max << " (Index Array: " << index_max << ")" << endl;
    cout << "Detail Mahasiswa:" << endl;
    cout << "  Nama: " << S.dataMahasiswa[index_max].Nama << endl;
    cout << "  NIM: " << S.dataMahasiswa[index_max].NIM << endl;
    cout << "  NilaiTugas: " << S.dataMahasiswa[index_max].NilaiTugas << endl;
    cout << "  NilaiUTS: " << S.dataMahasiswa[index_max].NilaiUTS << endl;
    cout << "  NilaiUAS: " << S.dataMahasiswa[index_max].NilaiUAS << endl;
}