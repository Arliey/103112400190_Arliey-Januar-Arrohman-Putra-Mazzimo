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