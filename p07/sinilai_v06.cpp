// SiNilai v0.6: v0.5 yang tangguh terhadap masukan salah. Dibangun di atas v0.5 (laporan kelas).
// Yang baru: angka dibaca dengan aman (cin.fail, clear, ignore), nama divalidasi dan dirapikan
// huruf per huruf. Pola pembacaan aman sengaja ditulis berulang untuk empat komponen nilai;
// di Pertemuan 9 pola ini akan dibungkus fungsi.
#include <cctype>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

int main() {
    const double BOBOT_KEHADIRAN = 0.10;
    const double BOBOT_MINGGUAN = 0.45;
    const double BOBOT_UTS = 0.25;
    const double BOBOT_UAS = 0.20;

    // ---- Jumlah mahasiswa: dibaca aman, harus bilangan bulat >= 1 ----
    int jumlah_mahasiswa = 0;
    cout << "=== SiNilai v0.6 ===\n";
    cout << "Jumlah mahasiswa (paling sedikit 1): ";
    cin >> jumlah_mahasiswa;
    while (cin.fail() || jumlah_mahasiswa < 1) {
        if (cin.eof()) {
            cout << "\nMasukan berakhir sebelum jumlah mahasiswa terbaca.\n";
            return 1;
        }
        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Itu bukan angka. ";
        } else {
            cin.ignore(1000, '\n');
            cout << "Paling sedikit 1 mahasiswa. ";
        }
        cout << "Coba lagi: ";
        cin >> jumlah_mahasiswa;
    }
    cin.ignore(1000, '\n');   // buang Enter yang tersisa setelah angka, supaya getline nama tidak memungutnya

    cout << fixed << setprecision(2);

    double total_nilai_kelas = 0;
    int jumlah_lulus = 0;
    int jumlah_mutu_a = 0;
    int jumlah_mutu_b = 0;
    int jumlah_mutu_c = 0;
    int jumlah_mutu_d = 0;
    int jumlah_mutu_e = 0;
    double nilai_tertinggi = -1;
    string nama_tertinggi;

    for (int urutan = 1; urutan <= jumlah_mahasiswa; urutan++) {
        string nama;
        string npm;
        double kehadiran = 0;
        double mingguan = 0;
        double uts = 0;
        double uas = 0;

        cout << "\n--- Mahasiswa ke-" << urutan << " dari " << jumlah_mahasiswa << " ---\n";

        // ---- Nama: ulangi sampai tidak kosong, bukan hanya spasi, dan tanpa angka ----
        bool nama_sah = false;
        do {
            cout << "Nama      : ";
            getline(cin, nama);
            if (cin.eof() && nama.empty()) {
                cout << "\nMasukan berakhir sebelum nama terbaca.\n";
                return 1;
            }

            int panjang_nama = nama.length();
            bool ada_huruf = false;
            bool ada_angka = false;
            for (int posisi = 0; posisi < panjang_nama; posisi++) {
                if (nama[posisi] != ' ') {
                    ada_huruf = true;
                }
                if (isdigit(static_cast<unsigned char>(nama[posisi]))) {
                    ada_angka = true;
                }
            }

            if (!ada_huruf) {
                cout << "Nama tidak boleh kosong.\n";
            } else if (ada_angka) {
                cout << "Nama tidak boleh mengandung angka.\n";
            } else {
                nama_sah = true;
            }
        } while (!nama_sah);

        // ---- Rapikan nama: huruf pertama tiap kata besar, sisanya kecil ----
        int panjang_nama = nama.length();
        bool awal_kata = true;
        for (int posisi = 0; posisi < panjang_nama; posisi++) {
            if (nama[posisi] == ' ') {
                awal_kata = true;
            } else if (awal_kata) {
                nama[posisi] = toupper(static_cast<unsigned char>(nama[posisi]));
                awal_kata = false;
            } else {
                nama[posisi] = tolower(static_cast<unsigned char>(nama[posisi]));
            }
        }

        cout << "NPM       : ";
        getline(cin, npm);

        // ---- Empat nilai: masing-masing dibaca aman, harus 0 sampai 100 ----
        cout << "Kehadiran : ";
        cin >> kehadiran;
        while (cin.fail() || kehadiran < 0 || kehadiran > 100) {
            if (cin.eof()) {
                cout << "\nMasukan berakhir sebelum kehadiran terbaca.\n";
                return 1;
            }
            if (cin.fail()) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Itu bukan angka. ";
            } else {
                cin.ignore(1000, '\n');
                cout << "Harus 0 sampai 100. ";
            }
            cout << "Kehadiran : ";
            cin >> kehadiran;
        }

        cout << "Mingguan  : ";
        cin >> mingguan;
        while (cin.fail() || mingguan < 0 || mingguan > 100) {
            if (cin.eof()) {
                cout << "\nMasukan berakhir sebelum nilai mingguan terbaca.\n";
                return 1;
            }
            if (cin.fail()) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Itu bukan angka. ";
            } else {
                cin.ignore(1000, '\n');
                cout << "Harus 0 sampai 100. ";
            }
            cout << "Mingguan  : ";
            cin >> mingguan;
        }

        cout << "UTS       : ";
        cin >> uts;
        while (cin.fail() || uts < 0 || uts > 100) {
            if (cin.eof()) {
                cout << "\nMasukan berakhir sebelum nilai UTS terbaca.\n";
                return 1;
            }
            if (cin.fail()) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Itu bukan angka. ";
            } else {
                cin.ignore(1000, '\n');
                cout << "Harus 0 sampai 100. ";
            }
            cout << "UTS       : ";
            cin >> uts;
        }

        cout << "UAS       : ";
        cin >> uas;
        while (cin.fail() || uas < 0 || uas > 100) {
            if (cin.eof()) {
                cout << "\nMasukan berakhir sebelum nilai UAS terbaca.\n";
                return 1;
            }
            if (cin.fail()) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Itu bukan angka. ";
            } else {
                cin.ignore(1000, '\n');
                cout << "Harus 0 sampai 100. ";
            }
            cout << "UAS       : ";
            cin >> uas;
        }
        cin.ignore(1000, '\n');   // buang Enter setelah uas, supaya getline nama mahasiswa berikutnya bersih

        double nilai_akhir = kehadiran * BOBOT_KEHADIRAN + mingguan * BOBOT_MINGGUAN
                           + uts * BOBOT_UTS + uas * BOBOT_UAS;

        string huruf_mutu;
        if (nilai_akhir >= 80) {
            huruf_mutu = "A";
        } else if (nilai_akhir >= 75) {
            huruf_mutu = "B+";
        } else if (nilai_akhir >= 70) {
            huruf_mutu = "B";
        } else if (nilai_akhir >= 65) {
            huruf_mutu = "C+";
        } else if (nilai_akhir >= 60) {
            huruf_mutu = "C";
        } else if (nilai_akhir >= 40) {
            huruf_mutu = "D";
        } else {
            huruf_mutu = "E";
        }

        bool lulus = nilai_akhir >= 60;

        cout << "  " << left << setw(20) << nama << right << setw(7) << nilai_akhir
             << "  " << left << setw(3) << huruf_mutu;
        if (lulus) {
            cout << "Lulus\n";
        } else {
            cout << "Belum lulus\n";
        }

        total_nilai_kelas += nilai_akhir;
        if (lulus) {
            jumlah_lulus++;
        }

        switch (huruf_mutu[0]) {
            case 'A':
                jumlah_mutu_a++;
                break;
            case 'B':
                jumlah_mutu_b++;
                break;
            case 'C':
                jumlah_mutu_c++;
                break;
            case 'D':
                jumlah_mutu_d++;
                break;
            default:
                jumlah_mutu_e++;
        }

        if (nilai_akhir > nilai_tertinggi) {
            nilai_tertinggi = nilai_akhir;
            nama_tertinggi = nama;
        }
    }

    cout << "\n=== Laporan Kelas ===\n";
    cout << "Jumlah mahasiswa : " << jumlah_mahasiswa << "\n";
    cout << "Lulus            : " << jumlah_lulus << "\n";
    cout << "Belum lulus      : " << jumlah_mahasiswa - jumlah_lulus << "\n";
    cout << "Rata-rata kelas  : " << total_nilai_kelas / jumlah_mahasiswa << "\n";
    cout << "Tertinggi        : " << nama_tertinggi << " (" << nilai_tertinggi << ")\n";

    cout << "\nSebaran huruf mutu:\n";
    for (char huruf = 'A'; huruf <= 'E'; huruf++) {
        int banyak = 0;
        if (huruf == 'A') {
            banyak = jumlah_mutu_a;
        } else if (huruf == 'B') {
            banyak = jumlah_mutu_b;
        } else if (huruf == 'C') {
            banyak = jumlah_mutu_c;
        } else if (huruf == 'D') {
            banyak = jumlah_mutu_d;
        } else {
            banyak = jumlah_mutu_e;
        }

        cout << huruf << " | ";
        for (int batang = 1; batang <= banyak; batang++) {
            cout << "#";
        }
        cout << " " << banyak << "\n";
    }
    return 0;
}
