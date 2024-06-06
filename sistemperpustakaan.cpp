#include <iostream>
using namespace std;

typedef struct node* address;
struct node {
    address prev;
    int data;
    address next;
};

address first, last = NULL;
address alokasi(int datanya) {
    address hasil = new node;
    hasil->data = datanya;
    hasil->next = hasil->prev = NULL;
    return hasil;
}

void insertFirst(address baru) {
    if (first == NULL) {
        first = last = baru;
    } else {
        baru->next = first;
        first->prev = baru;
        first = baru;
    }
}

void insertLast(address baru) {
    if (first == NULL) {
        first = last = baru;
    } else {
        last->next = baru;
        baru->prev = last;
        last = baru;
    }
}

void deleteFirst() {
    if (first == NULL) {
        cout << "Daftar buku kosong"<<endl;
        return;
    }
    if (first == last) {
        delete first;
        first = last = NULL;
    } else {
        first = first->next;
        delete first->prev;
        first->prev = NULL;
    }
}

void deleteLast() {
        if (first == NULL) {
            cout<< "daftar buku kosong" << endl;
            return;
        }
    if (first == last) {
        delete first;
        first = last = NULL;
    } else {
        last = last->prev;
        delete last->next;
        last->next = NULL;
    }
}
void cetak() {
    address p = first;
    while (p != NULL) {
        cout<<"ID buku :"<<p->data<<endl;
        p=p->next;
    }
}




bool isPrima(int n) {
   //
}
void printPrimeBookIDs() {
    //
}



address cariBuku(int id) {
    address p = first;
    while (p != NULL) {
        if (p->data == id) {
            return p;
        }
        p = p->next;
    }
    return NULL;
}

void hapusBuku(int id) {
    address p = cariBuku(id);
        if (p == NULL) {
            cout <<"buku dengan ID "<<id<<"tidak ditemukan"<< endl;
            return;
        }
    if (p == first) {
        deleteFirst();
    } else if (p == last) {
        deleteLast();
    } else {
        p->prev->next = p->next;
        p->next->prev = p->prev;
        delete p;
    }
    cout<<"buku dengan ID"<<id<<"telah dihapus"<<endl;
}

int main() {
        insertLast(alokasi(10));
        insertFirst(alokasi(30));
        insertLast(alokasi(50));
        insertLast(alokasi(19));
        insertFirst(alokasi(90));
        insertLast(alokasi(27));
        insertLast(alokasi(11));

    cout << "Daftar buku awal:" << endl;
    cetak();

    hapusBuku(20);
    hapusBuku(10);

    cout << "\nDaftar buku setelah penghapusan:" << endl;
    cetak();
    return 0;
}
