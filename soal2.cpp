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