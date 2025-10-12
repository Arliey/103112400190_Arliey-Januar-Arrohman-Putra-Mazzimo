#include <iostream>
using namespace std;

void tampilkanhasil(int arr[2][2]){
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}


// Penjumlahan Matriks 2x2
int main(){
    int arrA [2][2] ={
        {1, 2},
        {3, 4}
    };
    
    int arrB[2][2] ={
        {2, 3},
        {4, 5}
    };

    int arrC[2][2] ={0};
    int arrD[2][2] ={0};

    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            arrC[i][j] = arrA[i][j] = arrB[i][j];
        }
    }

    cout << "Hasil Penjumlahan : " << endl;
    tampilkanhasil(arrC);

    cout << endl;

    // Perkalian Matriks 2x2
    for (int i = 0; i < 2; i++){            // Perlangan Baris
        for (int j = 0; j < 2; i++){        // Perulangan Kolom
            for (int k = 0; k < 2; k++){    // Perulangan Perkalian
                arrD[i][j] += arrA[i][j] * arrB[i][j];
            }
        }
    }

    cout << "Hasil Perkalian : " << endl;
    tampilkanhasil(arrD);
    return 0;
}