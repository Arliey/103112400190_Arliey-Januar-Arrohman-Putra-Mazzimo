#include <iostream>
#include "QueuePengiriman.h"

using namespace std;

int main() {
    QueueEkspedisi queue;
    createQueue(queue);

    Paket p1 = {"123456", "Hutao", 14, "Sumeru"};
    Paket p2 = {"234567", "Ayaka", 10, "Fontaine"};
    Paket p3 = {"345678", "Bennet", 7, "Natlan"};
    Paket p4 = {"456789", "Furina", 16, "Liyue"};
    Paket p5 = {"567890", "Nefer", 6, "Inazuma"};

    int choice;
    do {
        cout << "Menu : \n";
        cout << "1 input data paket\n";
        cout << "2 hapus data paket\n";
        cout << "3 tampilkan queue paket\n";
        cout << "4 hitung total biaya pengiriman\n";
        cin >> choice;

        switch (choice) {
            case 1:
                enqueue(queue, p1);
                enqueue(queue, p2);
                enqueue(queue, p3);
                enqueue(queue, p4);
                enqueue(queue, p5);
                break;

            case 2:
                dequeue(queue);
                break;

            case 3:
                viewQueue(queue);
                break;

            case 4:
                cout << "Total Biaya Pengiriman: Rp " << totalBiayaPengiriman(queue) << endl;
                break;

            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while (choice != 0);

    return 0;
}