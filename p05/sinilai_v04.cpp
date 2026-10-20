
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    const double BOBOT_KEHADIRAN = 0.10;
    const double BOBOT_MINGGUAN = 0.45;
    const double BOBOT_UTS = 0.25;
    const double BOBOT_UAS = 0.20;

    int jumlah_mahasiswa;

    cout << "=== SiNilai v0.4 ===\n";

    do {
        cout << "Masukkan jumlah mahasiswa: ";
        cin >> jumlah_mahasiswa;

        if (jumlah_mahasiswa < 1) {
            cout << "Jumlah mahasiswa minimal 1!\n";
        }
    } while (jumlah_mahasiswa < 1);

    double total_nilai = 0;
    int jumlah_lulus = 0;

    for (int i = 1; i <= jumlah_mahasiswa; i++) {
        string nama, npm;
        double kehadiran, mingguan, uts, uas;

        cout << "\nMahasiswa ke-" << i << "\n";

        cout << "Nama      : ";
        getline(cin >> ws, nama);

        cout << "NPM       : ";
        cin >> npm;

        cout << "Kehadiran : ";
        cin >> kehadiran;

        cout << "Mingguan  : ";
        cin >> mingguan;

        cout << "UTS       : ";
        cin >> uts;

        cout << "UAS       : ";
        cin >> uas;

        double nilai_akhir =
            kehadiran * BOBOT_KEHADIRAN +
            mingguan * BOBOT_MINGGUAN +
            uts * BOBOT_UTS +
            uas * BOBOT_UAS;

        string huruf_mutu;

        if (nilai_akhir >= 80)
            huruf_mutu = "A";
        else if (nilai_akhir >= 75)
            huruf_mutu = "B+";
        else if (nilai_akhir >= 70)
            huruf_mutu = "B";
        else if (nilai_akhir >= 65)
            huruf_mutu = "C+";
        else if (nilai_akhir >= 60)
            huruf_mutu = "C";
        else if (nilai_akhir >= 40)
            huruf_mutu = "D";
        else
            huruf_mutu = "E";

        bool lulus = nilai_akhir >= 60;
        string keterangan;

        switch (huruf_mutu[0]) {
            case 'A':
                keterangan = "Sangat baik";
                break;
            case 'B':
                keterangan = "Baik";
                break;
            case 'C':
                keterangan = "Cukup";
                break;
            case 'D':
                keterangan = "Kurang";
                break;
            default:
                keterangan = "Sangat kurang";
        }

        cout << fixed << setprecision(2);
        cout << "\n=== Kartu Nilai ===\n";
        cout << "Nama        : " << nama << "\n";
        cout << "NPM         : " << npm << "\n";
        cout << "Nilai akhir : " << nilai_akhir << "\n";
        cout << "Huruf mutu  : " << huruf_mutu << "\n";
        cout << "Keterangan  : " << keterangan << "\n";

        if (lulus) {
            cout << "Status      : Lulus\n";
            jumlah_lulus++;
        } else {
            cout << "Status      : Belum lulus\n";
        }

        total_nilai += nilai_akhir;
    }

    double rata_rata = total_nilai / jumlah_mahasiswa;

    cout << "\n=== Rekap Kelas ===\n";
    cout << "Jumlah mahasiswa : " << jumlah_mahasiswa << "\n";
    cout << "Lulus            : " << jumlah_lulus << "\n";
    cout << "Belum lulus      : "
         << jumlah_mahasiswa - jumlah_lulus << "\n";
    cout << "Rata-rata kelas  : " << rata_rata << "\n";

    return 0;
}