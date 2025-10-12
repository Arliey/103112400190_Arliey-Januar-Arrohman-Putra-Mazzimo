#include <iostream>
using namespace std;

struct mahasiswa{
    string nim;
    float nilai1;
    float nilai2;
};

void inputMhs(mahasiswa &m){
    cout << "Input NIM : ";
    cin >> m.nim;
    cout << "Input Nilai 1 : ";
    cin >> m.nilai1;
    cout << "Inpur Nilai 2 : ";
    cin >> m.nilai2;
};

float rata2(mahasiswa m){
    return (float)(m.nilai1 + m.nilai2)/2;
}

int main(){
    mahasiswa mhs;
    inputMhs(mhs);

    cout << "Rata-rata nilai adalah : " << rata2(mhs) << endl;
    return 0;
}