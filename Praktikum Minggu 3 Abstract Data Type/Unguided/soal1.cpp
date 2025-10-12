#include <iostream>
using namespace std;

float hitungNilaiAkhir(float uts, float uas, float tugas) {
    return 0.3f * uts + 0.4f * uas + 0.3f * tugas;
}

int main() {
    const int MAX_MHS = 10;
    string nama[MAX_MHS], nim[MAX_MHS];
    float uts[MAX_MHS], uas[MAX_MHS], tugas[MAX_MHS];
    int n;

    do {
        cout << "Jumlah Mahasiswa (MAKS 10!): ";
        cin >> n;
        if (n > MAX_MHS || n <= 0) {
            cout << "Jumlah Mahasiswa Melebihi Batas!\n";
        }
    } while (n > MAX_MHS || n <= 0);


    for (int i = 0; i < n; i++) {
        cout << "\nNama: "; 
        cin >> nama[i];

        cout << "NIM : "; 
        cin >> nim[i];

        cout << "UTS : "; 
        cin >> uts[i];

        cout << "UAS : "; 
        cin >> uas[i];

        cout << "Tugas: "; 
        cin >> tugas[i];

        cout << "Nilai Akhir: " << hitungNilaiAkhir(uts[i], uas[i], tugas[i]) << endl;
    }

    return 0;
}