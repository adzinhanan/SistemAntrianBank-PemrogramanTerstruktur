#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <fstream>
#include <cctype>
#include <iomanip> 
#include <windows.h> 

using namespace std;


const int MAX_TELLERS = 3;
const int MAX_ANTRIAN_PER_TELLER = 5;

struct Nasabah {
    int id;
    string nama;
};

class Teller {
private:
    string kodeTeller;
    int kapasitas;
    bool istirahat;
    vector<Nasabah> antrian;

public:
    void clrscr() {
        system("cls"); 
    }
    
    void PenghitungWaktu(int milliseconds) {
        Sleep(milliseconds);
    }

    void keluarDariProgram(string pesan) {
        for (int i = 1; i >= 0; i--) {
            this->clrscr();
            cout << endl << " " << pesan << endl;
            this->PenghitungWaktu(1000);
            
            if (i == 0) {
                exit(0);
            }
        }
    }
    
    Teller(string kode, int maxAntrian) : kodeTeller(kode), kapasitas(maxAntrian), istirahat(false) {}

    string getKode() const {
        return kodeTeller;
    }

    bool sedangIstirahat() const {
        return istirahat;
    }

    void setIstirahat(bool status) {
        istirahat = status;
    }

    bool bisaMenampung() const {
        return antrian.size() < kapasitas && !istirahat;
    }

    bool tambahNasabah(const string& nama, int id) {
        if (bisaMenampung()) {
            antrian.push_back({id, nama});
            return true;
        }
        return false;
    }

    void tampilkanAntrian() const {
        if (antrian.empty()) {
            cout << "  Status: kosong" << endl;
        } else {
            for (size_t i = 0; i < antrian.size(); ++i) {
                cout << "  " << i + 1 << ". " << antrian[i].nama << " - No Antrian: " << kodeTeller << "-00" << antrian[i].id << endl;
            }
        }
    }

    void hapusAntrian() {
        antrian.clear();
    }
};

bool validasiLogin(const string& username, const string& password) {
    ifstream file("akun.txt");
    string user, pass;
    while (file >> user >> pass) {
        if (user == username && pass == password) {
            return true;
        }
    }
    return false;
}

class kelompok3 {
public:
    void clrscr() {
        system("cls"); 
    }

    void PenghitungWaktu(int milliseconds) {
        Sleep(milliseconds);
    }

    void keluarDariProgram(string pesan) {
        for (int i = 1; i >= 0; i--) {
            this->clrscr();
            cout << endl << " " << pesan << endl;
            this->PenghitungWaktu(1000);

            if (i == 0) {
                exit(0);
            }
        }
    }

    void MenampilkanLoading() {
        char a = 177;
        char b = 219;

        clrscr();
        cout << endl << endl << endl << endl << endl << endl << endl << endl << endl;
        cout << endl << endl;
        cout << "            >> Membuka Program Antrian Bank <<            " << endl << endl;

        for (int i = 0; i < 40; i++) {
            cout << a;
        }
        cout << "\r";
        cout << "                                         ";
        cout << "\r";

        for (int i = 0; i < 40; i++) {
            cout << b;
            PenghitungWaktu(50);
        }
        clrscr();
    }

    void tampilkantanggal() {
        time_t now = time(0);
        tm* ltm = localtime(&now);
        string nama_bulan;
        int tanggal = ltm->tm_mday;
        int tahun = 1900 + ltm->tm_year;
        int bulan = 1 + ltm->tm_mon;

        if (bulan == 1) nama_bulan = "Januari";
        else if (bulan == 2) nama_bulan = "Februari";
        else if (bulan == 3) nama_bulan = "Maret";
        else if (bulan == 4) nama_bulan = "April";
        else if (bulan == 5) nama_bulan = "Mei";
        else if (bulan == 6) nama_bulan = "Juni";
        else if (bulan == 7) nama_bulan = "Juli";
        else if (bulan == 8) nama_bulan = "Agustus";
        else if (bulan == 9) nama_bulan = "September";
        else if (bulan == 10) nama_bulan = "Oktober";
        else if (bulan == 11) nama_bulan = "November";
        else if (bulan == 12) nama_bulan = "Desember";
        else nama_bulan = "00";

        cout << tanggal << " " << nama_bulan << " " << tahun;
    }

    void tampilkanMenuUtama(int pengunjung) {
        clrscr();
        cout << endl;
        cout << "  +-----------------------------------------------------------------------+" << endl;
        cout << "  |                          SISTEM ANTRIAN BANK                          |" << endl;
        cout << "  |-----------------------------------------------------------------------|" << endl;
        cout << "  |                  KELOMPOK WALID NAK DEWI BOLEE?                       |" << endl;
        cout << "  +-----------------------------------------------------------------------+" << endl;
        cout << endl;

        cout << "  +------------------------------------+----------------------------------+" << endl;
        cout << "  |          MENU UTAMA BANK           |          INFORMASI ANTRIAN         |" << endl;
        cout << "  +------------------------------------+----------------------------------+" << endl;
        cout << "  | 1. Ambil Nomor Antrian             | Total Nasabah Bank:              |" << endl;
        cout << "  |                                    | " << setw(33) << left << "        (" + to_string(pengunjung) + " Orang)" << "|" << endl;
        cout << "  | 2. Tampilkan Antrian Bank          |                                  |" << endl;
        cout << "  | 3. Masuk Sebagai Teller            | Tanggal:                         |" << endl;
        cout << "  | 4. Rincian Program                 | "; tampilkantanggal(); cout << "             |" << endl;
        cout << "  | 5. Keluar Dari Program             |                                  |" << endl;
        cout << "  +------------------------------------+----------------------------------+" << endl;
        cout << endl;
    }
};

int main() {
    kelompok3 programBank;
    programBank.MenampilkanLoading();


    vector<Teller> daftarTeller;
    daftarTeller.emplace_back("A", MAX_ANTRIAN_PER_TELLER);
    daftarTeller.emplace_back("B", MAX_ANTRIAN_PER_TELLER);
    daftarTeller.emplace_back("C", MAX_ANTRIAN_PER_TELLER);

    int idNasabah = 1;
    string pilihan;
    string namaInput;
    int nextTellerIndex = 0; 

    while (true) {
        programBank.tampilkanMenuUtama(idNasabah - 1);
        cin >> pilihan;

        if (pilihan == "1") {
            cout << "Masukkan nama anda: ";
            cin >> namaInput;

            bool berhasil = false;
           
            for (int i = 0; i < daftarTeller.size(); ++i) {
                int currentTellerIndex = (nextTellerIndex + i) % daftarTeller.size();
                Teller& teller = daftarTeller[currentTellerIndex];

                if (teller.bisaMenampung()) {
                    if (teller.tambahNasabah(namaInput, idNasabah)) {
                        cout << "\nAnda dilayani oleh Teller " << teller.getKode() << " dengan nomor antrian: " << teller.getKode() << "-00" << idNasabah << endl;
                        idNasabah++;
                        berhasil = true;
                        nextTellerIndex = (currentTellerIndex + 1) % daftarTeller.size(); 
                        break;
                    }
                }
            }

            if (!berhasil) {
                cout << "\nSemua teller sedang penuh atau istirahat. Silakan tunggu." << endl;
            }

            cout << "\nTekan Enter untuk kembali ke menu utama...";
            cin.ignore();
            cin.get();

        } else if (pilihan == "2") {
            cout << "\n=== DAFTAR ANTRIAN NASABAH ===\n";
            for (const auto& teller : daftarTeller) {
                cout << "\nTELLER " << teller.getKode() << ":\n";
                teller.tampilkanAntrian();
            }
            cout << "\nTekan Enter untuk kembali ke menu utama...";
            cin.ignore();
            cin.get();

        } else if (pilihan == "3") {
            string user, pass;
            cout << "\nLogin Admin" << endl;
            cout << "Username: "; cin >> user;
            cout << "Password: "; cin >> pass;

            if (validasiLogin(user, pass)) {
                string adminPil;
                do {
                    programBank.clrscr(); 
                    cout << "\n=== MENU ADMIN ===\n";
                    cout << "1. Hapus Semua Antrian\n";
                    cout << "2. Aktifkan/Nonaktifkan Teller\n";
                    cout << "3. Keluar Admin\n";
                    cout << "Pilih: "; cin >> adminPil;

                    if (adminPil == "1") {
                        for (auto& teller : daftarTeller) teller.hapusAntrian();
                        cout << "\nSemua antrian berhasil dihapus.\n";
                        programBank.PenghitungWaktu(1500);
                    } else if (adminPil == "2") {
                        cout << "\nTeller yang ingin diatur (A/B/C): ";
                        char kode; cin >> kode;
                        bool foundTeller = false;
                        for (auto& teller : daftarTeller) {
                            if (teller.getKode()[0] == toupper(kode)) {
                                bool status = teller.sedangIstirahat();
                                teller.setIstirahat(!status);
                                cout << "Status teller " << kode << " sekarang: " << (teller.sedangIstirahat() ? "Istirahat" : "Aktif") << endl;
                                foundTeller = true;
                                break;
                            }
                        }
                        if (!foundTeller) {
                            cout << "Teller tidak ditemukan." << endl;
                        }
                        programBank.PenghitungWaktu(1500);
                    }
                } while (adminPil != "3");

            } else {
                cout << "\nLogin gagal. Username atau password salah.\n";
                programBank.PenghitungWaktu(1500);
            }

        } else if (pilihan == "4") {

            programBank.clrscr();
            cout << "\n=== RINCIAN PROGRAM ===\n";
            cout << "Aplikasi Sistem Antrian Bank ini dikembangkan oleh Kelompok Walid nak dewi bolee?\n";
            cout << "Tujuan: Mempermudah pengelolaan antrian nasabah di bank.\n";
            cout << "Fitur: Ambil nomor antrian, tampilkan antrian, dan manajemen teller oleh admin.\n";
            cout << "\nTekan Enter untuk kembali ke menu utama...";
            cin.ignore();
            cin.get();
        } else if (pilihan == "5") {
             programBank.keluarDariProgram("Anda telah keluar dari program.");
        } else {
            cout << "Pilihan tidak tersedia. Coba lagi.\n";
            programBank.PenghitungWaktu(1500);
        }
    }
    return 0;
}
