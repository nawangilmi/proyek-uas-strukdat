/* 
Kelompok 3 :

 Aulia Rahmanita 140810200004
 Nawang Ilmi Adzani 140810200014
 Pujo Prayogo 1408102000038
*/

#include <iostream>
#include <stdlib.h>

struct masuk{
    int uangmasuk;
    char tanggal[30];
    masuk* nextMasuk;
};

struct keluar{
    int uangkeluar;
    char tanggal[30];
    keluar* nextKeluar;
};


typedef masuk* pMasuk;
typedef pMasuk listMasuk;
typedef keluar* pKeluar;
typedef pKeluar listKeluar;

void createElementmasuk(pMasuk& pBaru){
    pBaru = new masuk;
    std::cout<<"Masukkan jumlah uang yang masuk : " ; std::cin>>pBaru->uangmasuk;
    std::cout<<"Masukkan tanggal (DD/MM/YYYY) : " ; std::cin>>pBaru->tanggal;
    pBaru->nextMasuk= nullptr;
}

void insertFirstMasuk(listMasuk& First,pMasuk pBaru){
if (First== nullptr) {
		First=pBaru; 
        } else { 
		pBaru-> nextMasuk=First;
		First=pBaru;
	}
}

void createElementKeluar(pKeluar& pBaru){
    pBaru = new keluar;
    std::cout<<"Masukkan jumlah uang yang keluar : " ; std::cin>>pBaru->uangkeluar;
    std::cout<<"Masukkan tanggal (DD/MM/YYYY) : " ; std::cin>>pBaru->tanggal;
    pBaru-> nextKeluar= nullptr;
}

void insertFirstKeluar(listKeluar& First,pKeluar pBaru){
if (First== nullptr) {
		First=pBaru; 
        } else { 
		pBaru-> nextKeluar=First;
		First=pBaru;
	}
}


void TampilkanPemasukan(listMasuk& First){
 if(First == nullptr){
     std::cout << "Data tidak tersedia!\n";
    } else {
        masuk* pBantu;
        pBantu = First;
        std::cout << "----------------------------\n";
        std::cout << "    TRANSAKSI UANG MASUK    \n";
        std::cout << "----------------------------\n";
        while (pBantu != nullptr){
            std::cout << "Tanggal : " << pBantu->tanggal << std::endl;
            std::cout << pBantu->uangmasuk << std::endl;
        }
    }
}

void TampilkanPengeluaran(listKeluar& First){
 if(First == nullptr){
     std::cout << "Data tidak tersedia!\n";
    } else {
        keluar* pBantu;
        pBantu = First;
        std::cout << "----------------------------\n";
        std::cout << "    TRANSAKSI UANG MASUK   \n";
        std::cout << "----------------------------\n";
        while (pBantu != nullptr){
            std::cout << "Tanggal : " << pBantu->tanggal << std::endl;
            std::cout << pBantu->uangkeluar << std::endl;
        }
    }
}

void Total (){

}
void RatarataPemasukan(listMasuk& First){
    int count = 0;
    int sum = 0;
    float mean;
    pMasuk curr;
    First = curr;

     if (First == NULL){
        std::cout << -1;} 
    while (curr != NULL){
        count++; 
        sum += curr->uangmasuk; 
        curr = curr->nextMasuk;
    }
    mean = (double)sum / count; //menghitung rata-rata
  
    std::cout << "Rata - Rata : "<< mean; //mengoutputkan nilai ratarata
}

void RatarataPengeluaran(listKeluar& First){
    int count = 0;
    int sum = 0;
    float mean;
    pKeluar curr;
    curr = First; //

     if (First == NULL){
        std::cout << -1;} 
    while (curr != NULL){
        count++; 
        sum += curr->uangkeluar; 
        curr = curr->nextKeluar;
    }
    mean = (double)sum/count; //menghitung rata-rata
  
    std::cout << "Rata - Rata : "<< mean; //mengoutputkan nilai ratarata
}

void MaxMasuk(listMasuk& First){
    int max = 0;
    pMasuk pBaru ;
    pBaru = First;
        while (pBaru != NULL) {
        if (pBaru->uangmasuk > max) 
            max = pBaru->uangmasuk; 
    }  pBaru = pBaru->nextMasuk;
    std::cout << "Pemasukkan Terbesar : " << max;     
    }

void MaxKeluar(listKeluar& First){
    int max = 0;
    pKeluar pBaru ;
    pBaru = First;
        while (pBaru != NULL) {
        if (pBaru->uangkeluar > max) 
            max = pBaru->uangkeluar; 
    }  pBaru = pBaru->nextKeluar;
    std::cout << "Pengeluaran Terbesar : " << max;    
}

void DataKeuangan(){
    listMasuk FirstMasuk;
    listKeluar FirstKeluar;
    pMasuk masuk;
    pKeluar keluar;
    int pilih;
    system("cls");
    std::cout << "==================================\n";
    std::cout << "        Data-data Keuangan        \n";
    std::cout << "==================================\n";
    std::cout << "1. Rata-rata Pemasukkan\n";
    std::cout << "2. Rata-rata Pengeluaran\n";
    std::cout << "3. Pemasukkan Terbesar\n";
    std::cout << "4. Pengeluaran Terbesar\n";
    std::cout << "5. Back \n"; 
    std::cout << "Masukkan Pilihan : ";
    std::cin >> pilih;

    switch(pilih){
        case 1 :
            RatarataPemasukan(FirstMasuk);
            break;
        case 2 :
            RatarataPengeluaran(FirstKeluar);
            break;
        case 3 :
            MaxMasuk(FirstMasuk);
            break;
        case 4 :
            MaxKeluar(FirstKeluar);
            break;
        case 5:
            break;
        default : 
            std::cout << "Pilihan tidak tersedia!\n";
            break; 
        
    }

}

int main(){
    int *max = 0;
    int count = 0;
    int sum = 0;
    float mean;
    int pilih;
    char pilih1;
    pMasuk masuk;
    pKeluar keluar;
    listMasuk firstmasuk;
    listKeluar firstkeluar;
    std::string data;

    do{
    system("cls");
    std::cout << "==================================\n";
    std::cout << "           BUDGETIN AJA           \n";
    std::cout << "==================================\n";
    std::cout << "1. Isi Pemasukkan                 \n";
    std::cout << "2. Isi Pengeluaran                \n";
    std::cout << "3. Tampilkan Pemasukan            \n";
    std::cout << "4. Tampilkan Pengeluaran          \n";
    std::cout << "5. Total Uang                     \n";
    std::cout << "6. Data - data Keuangan           \n";
    std::cout << "Masukkan Pilihan : ";
    std::cin >> pilih;

    switch (pilih)
    {
    case 1:
        createElementmasuk(firstmasuk);
        insertFirstMasuk(firstmasuk,masuk);
        break;
    case 2:
        createElementKeluar(firstkeluar);
        insertFirstKeluar(firstkeluar,keluar);
        break;
    case 3:
        system("cls");
        TampilkanPemasukan(firstmasuk);
        break;
    case 4:
        system("cls");
        TampilkanPengeluaran(firstkeluar);
        break;
    case 6:
        ;
        break;
     case 7:
        DataKeuangan();
        break;
    default : 
        std::cout << "Pilihan tidak tersedia!\n";
        break;  
    }
    std::cout <<"Kembali ke menu awal (y/n)?";
    std::cin >> pilih1;
		system("pause");
    } while (pilih1=='Y' || pilih1=='y');
    return 0;
}