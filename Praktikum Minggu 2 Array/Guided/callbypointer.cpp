#include <iostream>
using namespace std;

void ubahNilai(int *ptr){
    *ptr = 20;
}

int main(){
    int x = 10;
    cout << "Nilai Sebelum Diubah: " << x << endl;
    ubahNilai(&x); 
    cout << "Nilai Sesudah Diubah: " << x << endl;

    return 0;
}