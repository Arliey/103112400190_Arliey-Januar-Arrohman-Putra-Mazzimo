#include <iostream>
#include <string>
using namespace std;

struct Node {
    string nama;
    Node* next;
};

Node* head = nullptr;

void insertAkhir(string nama) {
    Node* baru = new Node{nama, nullptr};

    if (head == nullptr) {
        head = baru;
    } else {
        Node* p = head;
        while (p->next != nullptr) {
            p = p->next;
        }
        p->next = baru;
    }
}

void deleteNama(string nama) {
    if (head == nullptr) {
        return;
    }

    if (head->nama == nama) {
        Node* hapus = head;
        head = head->next;
        delete hapus;
        return;
    }

    Node* p = head;
    while (p->next != nullptr && p->next->nama != nama) {
        p = p->next;
    }

    if (p->next == nullptr) {
        cout << "Nama Tidak Ditemukan.\n";
    } else {
        Node* hapus = p->next;
        p->next = p->next->next;
        delete hapus;
    }
}

void viewList() {
    if (head == nullptr) {
        return;
    }

    Node* p = head;
    while (p != nullptr) {
        cout << p->nama << " ";
        p = p->next;
    }
}

void hitungGenap() {
    if (head == nullptr) {
        return;
    }

    Node* p = head;
    cout << "jumlah nama dengan huruf genap: ";

    while (p != nullptr) {
        if (p->nama.length() % 2 == 0) {
            cout << p->nama << endl;
        }
        p = p->next;
    }
}

int main() {
    int menu;
    string nama;

    do {
        cout << "\nMenu: ";
        cout << "1 insert, ";
        cout << "2 delete, ";
        cout << "3 view, ";
        cout << "4 hitung genap, ";
        cout << "0 exit";
        cout << " \n";
        cin >> menu;

        switch (menu) {
            case 1:
                cout << "masukkan nama: ";
                cin >> nama;
                insertAkhir(nama);
                break;
            case 2:
                cout << "masukkan nama untuk delete: ";
                cin >> nama;
                deleteNama(nama);
                break;
            case 3:
                viewList();
                break;
            case 4:
                hitungGenap();
                break;
        }
    } while (menu != 0);

    return 0;
}
