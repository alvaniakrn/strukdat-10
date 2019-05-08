/*
alvina vania kirana
140810180010
strukdat-10
menggunakan queue linkedlist
*/

#include <iostream>
using namespace std;

struct elemenQueue {
    char huruf;
    elemenQueue* next;
};

typedef elemenQueue* pointer;

struct queue {
    pointer head;
    pointer tail;
};

void createQueue (queue& q);
void createElemen (pointer& pBaru);
void insertQueue (queue& q, pointer& pBaru);
void deleteQueue (queue& q, pointer& pHapus);
void traversal (queue q);

int main() {
    queue q;
    pointer p;
    int x, n, pilih;
    
    createQueue(q);
    
    cout << "1. Tambahkan data"<<endl;
    cout << "2. Hapus data pertama"<<endl;
    cout << "3. Cetak data"<<endl;
    cout << endl;
    cout << "Banyaknya huruf: "; cin >> n;
    cout << endl;
    
    for (int i=0; i<n; i++){
        createElemen(p);
        insertQueue (q,p);
    }
    
    traversal(q);
    
    cout << "Banyaknya memilih:"; cin>> x;
    for (int i=0; i<x; i++){
        cout << "Masukkan Pilihan   :";cin >> pilih;
        if (pilih==1){
            createElemen(p);
            insertQueue (q,p);
        }
        else if (pilih==2){
            deleteQueue (q,p);
        }
        else if (pilih==3){
            traversal (q);
        }
    }
    
    return 0;
}

//menggunakan queue LinkedList

void createQueue (queue& q){
    q.head=NULL;
    q.tail=NULL;
}

void createElemen (pointer& pBaru){
    pBaru=new elemenQueue;
    cout << "Masukkan huruf:"; cin >> pBaru->huruf;
    pBaru->next=NULL;
}

void insertQueue (queue& q, pointer& pBaru){
    if (q.head==NULL&& q.tail==NULL){
        q.head=pBaru;
        q.tail=pBaru;
    }
    else {
        q.tail->next=pBaru;
        q.tail=pBaru;
    }
}

void deleteQueue (queue& q, pointer& pHapus){
    if (q.head==NULL && q.tail==NULL){
        pHapus=NULL;
        cout << "List Tidak Ada"<<endl;
    }
    else if (q.head->next==NULL){
        pHapus=q.head;
        q.head=NULL;
        q.tail=NULL;
    }
    else{
        pHapus=q.head;
        q.head=q.head->next;
        pHapus->next=NULL;
    }
}

void traversal(queue q){
    pointer pBantu;
    
    if(q.head==NULL && q.tail==NULL){
        cout << "List Tidak Ada";
    }
    else{
        pBantu=q.head;
        do{
            cout << pBantu->huruf << " ";
            pBantu = pBantu->next;
        } while(pBantu != NULL);
    }
    cout << endl;
}
