#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

Node* head = nullptr;
Node* tail = nullptr;

void insertLast(int value) {
    Node* newNode = new Node{value, nullptr, nullptr};
    if (head == nullptr) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

void deleteLast() {
    if (tail == nullptr) {
        return;
    }
    Node* temp = tail;
    if (head == tail) {
        head = tail = nullptr;
    } else {
        tail = tail->prev;
        tail->next = nullptr;
    }
    delete temp;
}

void viewForward() {
    Node* temp = head;
    if (!temp) {
        return;
    }
    while (temp) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void reverseList() {
    Node* curr = head;
    Node* temp = nullptr;

    while (curr != nullptr) {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;

        curr = curr->prev;
    }

    if (temp != nullptr) {
        head = temp->prev;
    }
}

void reverseAndView() {
    reverseList();
    viewForward();
}

int main() {
    int choice, value;

    do {
        cout << "\nMenu: ";
        cout << "1 insert, ";
        cout << "2 delete, ";
        cout << "3 view, ";
        cout << "4 reverse & view depan, ";
        cout << "0 exit ";
        cout << " \n";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "masukkan nilainya : ";
                cin >> value;
                insertLast(value);
                break;

            case 2:
                deleteLast();
                break;

            case 3:
                viewForward();
                break;

            case 4:
                reverseAndView();
                break;

            case 0:
                cout << "";
                break;

            default:
                cout << "pilihan tidak valid \n";
        }
    } while (choice != 0);

    return 0;
}
