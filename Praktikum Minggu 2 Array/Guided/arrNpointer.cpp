#include <iostream>
using namespace std;

int main(){
    int arr[] = {10, 20, 30, 40, 50};
    int * ptr = arr;

    // Mengakses Elemen Array Menggunakan Pointer
    for (int i = 0; i < 5; ++i){
        cout << "Elemen ke- " << i + 1 << " Menggunakan Pointer " << *(ptr + i) << endl;
    }

    // Mengakses Elemen Array Menggunakan Index
    for (int i = 0; i <5; ++i){
        cout << "Elemen ke- " << i + 1 << " Menggunakan Index " << arr[i] << endl;
    }

    return 0;
}