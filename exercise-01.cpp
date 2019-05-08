/*
 alvina vania kirana
 140810180010
 strukdat-10
 menggunakan queue array
 */

#include <iostream>
using namespace std;

const int maxElemen=5;

struct queue {
    char isi[maxElemen];
    int head;
    int tail;
};


void createQueue (queue& q);
void insertQueue (queue& q, char elBaru);
void deleteQueue (queue& q, char& elHapus);
void print (queue q);

int main () {
    queue q;
    char el;
    int x, n, pilih;
    
    createQueue(q);
    
    cout << "1. Tambahkan data"<<endl;
    cout << "2. Hapus data pertama"<<endl;
    cout << "3. Cetak data"<<endl;
    cout << endl;
    cout << "Banyaknya huruf: "; cin >> n;
    cout << endl;
    
    for (int i=0; i<n; i++){
        cout << "Masukkan huruf : "; cin >> q.isi[q.tail];
        insertQueue(q,el);
    }
    
    print (q);
    
    cout << "Banyaknya memilih:"; cin>> x;
    for (int i=0; i<x; i++){
        cout << "Masukkan Pilihan   :";cin >> pilih;
        if (pilih==1){
            cout << "Masukkan huruf : "; cin >> q.isi[q.tail];
            insertQueue(q,el);
        }
        else if (pilih==2){
            deleteQueue (q,el);
        }
        else if (pilih==3){
            print(q);
        }
    }
    
    
    
}

void createQueue (queue& q){
    q.head=-1;
    q.tail=-1;
}

void insertQueue (queue& q, char elBaru){
    int posisiTemp;
    if (q.tail==-1){
        q.head=0;
        q.tail=0;
        q.isi[q.tail]=elBaru;
    }
    else {
        posisiTemp=q.tail;
        if (q.tail<maxElemen-1){
            q.tail=q.tail+1;
        }
        else {
            q.tail=0;
        }
        
        if (q.tail==q.head){
            cout << "Antrian Penuh" <<endl;
            q.tail=posisiTemp;
        }
        else {
            q.isi[q.tail]=elBaru;
        }
    }
}

void deleteQueue (queue& q, char& elHapus){
    if (q.head==-1){
        cout << "Antrian Kosong" <<endl;
    }
    else if (q.head==q.tail){
        elHapus=q.isi[q.head];
        q.isi[q.head]=' ';
        q.head=-1;
        q.tail=-1;
    }
    else {
        elHapus=q.isi[q.head];
        q.isi[q.head]=' ';
        if (q.head<maxElemen-1){
            q.head=q.head+1;
        }
        else {
            q.head=0;
        }
    }
}

void print (queue q){
    if(q.head==-1){
        cout<<"Antrian Kosong."<<endl;
    }else{
        int i=q.head;
        cout<<endl<<"Antrian = [";
        if(q.head>q.tail){
            while(i<maxElemen){
                cout<<q.isi[i];
                if(i!=q.tail){
                    cout<<", ";
                }
                i++;
            }
            i=0;
            while(i<=q.tail){
                cout<<q.isi[i];
                if(i!=q.tail){
                    cout<<", ";
                }
                i++;
            }
        }
        else{
            while(i<=q.tail){
                cout<<q.isi[i];
                if(i!=q.tail){
                    cout<<", ";
                }
                i++;
            }
        }
        cout<<"]"<<endl;
    }
}
