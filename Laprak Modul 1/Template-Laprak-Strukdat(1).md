# <h1 align="center">Laporan Praktikum Modul 1 - Codeblocks IDE & Pengenalan Bahas C++ (Bagian Pertama)</h1>
<p align="center">Arliey Januar Arrohman Putra Mazzimo - 103112400190</p>

## Dasar Teori
Bahasa C++ adalah bahasa pemrograman yang mendukung paradigma pemrograman prosedural dan berorientasi objek. C++ banyak digunakan dalam pembuatan aplikasi karena memiliki performa tinggi dan kontrol penuh terhadap sistem [1]. Struktur dasar program C++ terdiri dari fungsi main() sebagai titik awal eksekusi, pernyataan input/output dengan cin dan cout, serta dapat memanfaatkan pustaka standar seperti <iostream> dan <string> [2].

### A. Operator Aritmatika <br/>
Operator aritmatika adalah operator dasar untuk melakukan operasi matematika seperti penjumlahan, pengurangan, perkalian, dan pembagian. Dalam C++, operator ini digunakan untuk memproses data numerik.

### B. Percabangan dan Perulangan <br/>
Percabangan (if, else) digunakan untuk pengambilan keputusan, sedangkan perulangan (for, while) digunakan untuk mengulang eksekusi blok kode berdasarkan kondisi tertentu.

## Guided 

### 1. ...

```C++
source code guided 1
```
penjelasan singkat guided 1

### 2. ...

```C++
source code guided 2
```
penjelasan singkat guided 2

### 3. ...

```C++
source code guided 3
```
penjelasan singkat guided 3

## Unguided 

### 1. Program Kalkulator Sederhana

#include <iostream>
using namespace std;


int main() {
float bil1,bil2;


cout << "Kalkulator" << endl;
cout << "Masukan Bilangan Pertama : ";
cin >> bil1;
cout << "Masukan Bilangan Kedua : ";
cin >> bil2;


cout << "Hasil operasi " << endl;
cout << "Penjumlahan : " << bil1 << " + " << bil2 << " = " << (bil1 + bil2) << endl;
cout << "Pengurangan : " << bil1 << " - " << bil2 << " = " << (bil1 - bil2) << endl;
cout << "Perkalian : " << bil1 << " * " << bil2 << " = " << (bil1 * bil2) << endl;


if (bil2 != 0) {
cout << "Pembagian : " << bil1 << " / " << bil2 << " = " << (bil1 / bil2) << endl;
} else {
cout << "Pembagian Tidak Bisa Dilakukan!" << endl;
}
return 0;
}
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/Arliey/103112400190_Arliey-Januar-Arrohman-Putra-Mazzimo/blob/5f37cadf5f794a653f822c28eae35c1a5ed8c587/Output-Unguided1-Modul1.png)


Program ini menerima dua input bilangan, lalu melakukan operasi aritmatika dasar

### 2. Program Konversi Angka ke Kata (0–100)

#include <iostream>
#include <string>
using namespace std;

string DigitToString (int digit) {

    string satuan [] = {"Nol", "Satu", "Dua", "Tiga", "Empat", "Lima", "Enam", "Tujuh", "Delapan", "Sembilan", 
                        "Sepuluh", "Sebelas", "Dua Belas", "Tiga Belas", "Empat Belas", "Lima Belas", "Enam Belas",
                         "Tujuh belas", "Delapan Belas", "Sembilan Belas"};

    string puluhan [] = {"", "", "Dua Puluh", "Tiga Puluh", "Empat Puluh", "Lima Puluh", "Enam Puluh", "Tujuh Puluh", "Delapan Puluh", "Sembilan Puluh"};

 if (digit == 0) {
    return "nol";
    }

    else if (digit < 20) {
    return satuan[digit];
    }

    else if (digit < 100) {
    int puluhan_digit = digit / 10;
    int satuan_digit = digit % 10;
    if (satuan_digit == 0) {
        return puluhan[puluhan_digit];
    } else {
        return puluhan[puluhan_digit] + " " + satuan[satuan_digit];
    }
    }

 else if (digit == 100) {
        return "Seratus";
        
    }
    return "Angka Jauh Diluar Jangkauan!";
}

int main (){
    int digit;
    cout << "Masukkan Angka (0-100): ";
    cin >> digit;
    cout << "Angka Dalam Kata : " << DigitToString(digit) << endl;
    return 0;
}

### Output Unguided 2 :

##### Output 1
![Screenshot Output Unguided 2_1](https://github.com/Arliey/103112400190_Arliey-Januar-Arrohman-Putra-Mazzimo/blob/5f37cadf5f794a653f822c28eae35c1a5ed8c587/Output-Unguided2-Modul1.png)

Program ini mengubah input angka dari 0 sampai 100 ke dalam bentuk kata dalam bahasa Indonesia.

### 3. Program Pola Angka dengan Bintang

#include <iostream>
using namespace std;


int main() {
int n;
cout << "Masukan angka : ";
cin >> n;


cout << "Hasil : " << endl;
for (int i = n; i >= 1; i--) {
for (int space = 0; space < n - i; space++) {
cout << " ";
}
for (int j = i; j >= 1; j--) {
cout << j;
}
cout << "*";
for (int k = 1; k <= i; k++) {
cout << k;
}
cout << endl;
}
for (int space = 0; space < n; space++) {
cout << " ";
}
cout << "*" << endl;
return 0;
}
### Output Unguided 3 :

##### Output 1
![Screenshot Output Unguided 3_1](https://github.com/Arliey/103112400190_Arliey-Januar-Arrohman-Putra-Mazzimo/blob/5f37cadf5f794a653f822c28eae35c1a5ed8c587/Output-Unguided3-Modul1.png)

Program ini menghasilkan pola angka menurun dengan bintang di tengah. Pola ini memanfaatkan perulangan for bertingkat untuk mencetak spasi, angka menurun, tanda *, lalu angka menaik.

## Kesimpulan
Dari tiga percobaan program, diperoleh pemahaman mengenai:

1. Penggunaan operator aritmatika dasar dalam kalkulator sederhana.

2. Implementasi fungsi dan array string untuk mengonversi angka menjadi kata.

3. Pemanfaatan perulangan bertingkat untuk mencetak pola.

Praktikum ini membantu memahami konsep dasar input-output, percabangan, fungsi, serta perulangan dalam bahasa C++.

## Referensi
[1] Triase. (2020). Diktat Edisi Revisi : STRUKTUR DATA. Medan: UNIVERSTAS ISLAM NEGERI SUMATERA UTARA MEDAN. 
<br>[2] Indahyati, Uce., Rahmawati Yunianita. (2020). "BUKU AJAR ALGORITMA DAN PEMROGRAMAN DALAM BAHASA C++". Sidoarjo: Umsida Press. Diakses pada 10 Maret 2024 melalui https://doi.org/10.21070/2020/978-623-6833-67-4.
<br>...
