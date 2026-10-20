// SiNilai v0.4: memproses banyak mahasiswa sekaligus dan mencetak rekap kelas.
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
    const double BOBOT_KEHADIRAN = 0.10;
    const double BOBOT_MINGGUAN = 0.45;
    const double BOBOT_UTS = 0.25;
    const double BOBOT_UAS = 0.20;

    int jumlah_mahasiswa = 0;
    cout << "=== SiNilai v0.4 ===\n";

    do {
        cout << "Jumlah mahasiswa (paling sedikit 1): ";
        if (!(cin >> jumlah_mahasiswa)) {
            cerr << "Input jumlah mahasiswa harus berupa angka.\n";
            return 1;
        }
        if (jumlah_mahasiswa < 1) {
            cout << "Jumlah mahasiswa harus paling sedikit 1.\n";
        }
    } while (jumlah_mahasiswa < 1);

    // Dua akumulator untuk rekap kelas.
    double total_nilai = 0.0;
    int jumlah_lulus = 0;

    for (int i = 1; i <= jumlah_mahasiswa; i++) {
        string nama;
        string npm;
        double kehadiran = 0.0;
        double mingguan = 0.0;
        double uts = 0.0;
        double uas = 0.0;

        cout << "\n--- Mahasiswa ke-" << i << " dari "
             << jumlah_mahasiswa << " ---\n";
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

        const double nilai_akhir =
            kehadiran * BOBOT_KEHADIRAN +
            mingguan * BOBOT_MINGGUAN +
            uts * BOBOT_UTS +
            uas * BOBOT_UAS;

        string huruf_mutu;
        if (nilai_akhir >= 80.0) {
            huruf_mutu = "A";
        } else if (nilai_akhir >= 75.0) {
            huruf_mutu = "B+";
        } else if (nilai_akhir >= 70.0) {
            huruf_mutu = "B";
        } else if (nilai_akhir >= 65.0) {
            huruf_mutu = "C+";
        } else if (nilai_akhir >= 60.0) {
            huruf_mutu = "C";
        } else if (nilai_akhir >= 40.0) {
            huruf_mutu = "D";
        } else {
            huruf_mutu = "E";
        }

        const bool lulus = nilai_akhir >= 60.0;

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
                break;
        }

        cout << fixed << setprecision(3);
        cout << "\n--- Kartu Nilai Mahasiswa ---\n";
        cout << "Nama        : " << nama << "\n";
        cout << "NPM         : " << npm << "\n";
        cout << "Nilai akhir : " << nilai_akhir << "\n";
        cout << "Huruf mutu  : " << huruf_mutu << "\n";
        cout << "Keterangan  : " << keterangan << "\n";
        cout << "Status      : " << (lulus ? "Lulus" : "Belum lulus") << "\n";

        // Akumulator untuk menghitung rata-rata dan jumlah mahasiswa lulus.
        total_nilai += nilai_akhir;
        if (lulus) {
            jumlah_lulus++;
        }
    }

    cout << "\n=== Rekap Kelas ===\n";
    cout << "Jumlah mahasiswa : " << jumlah_mahasiswa << "\n";
    cout << "Lulus            : " << jumlah_lulus << "\n";
    cout << "Belum lulus      : " << jumlah_mahasiswa - jumlah_lulus << "\n";
    cout << fixed << setprecision(3);
    cout << "Rata-rata kelas  : "
         << total_nilai / jumlah_mahasiswa << "\n";

    return 0;
}
