// UTS Praktikum Paket A: Parkir Kampus.
// Lengkapi TODO 1 sampai TODO 6 sesuai lembar soal. Bagian yang sudah ada jangan diubah kecuali diminta.
// Bangun dengan baseline kelas; program harus bebas warning. Uji dengan: ./parkir < contoh_masukan.txt
#include <cctype>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

int main() {
    const int TARIF_AWAL_MOTOR = 2000;
    const int TARIF_LANJUT_MOTOR = 1000;
    const int MAKS_MOTOR = 10000;
    const int TARIF_AWAL_MOBIL = 5000;
    const int TARIF_LANJUT_MOBIL = 3000;
    const int MAKS_MOBIL = 30000;

    int jumlah = 0;
    cout << "=== Parkir Kampus ===\n";
    cout << "Jumlah kendaraan: ";
    cin >> jumlah;
    while (cin.fail() || jumlah < 1) {           // contoh pembacaan aman; pakai pola ini untuk durasi
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Harus bilangan bulat paling sedikit 1. Jumlah kendaraan: ";
        cin >> jumlah;
    }
    cin.ignore(1000, '\n');

    cout << fixed << setprecision(2);

    int total = 0;
    int banyak_motor = 0;
    int banyak_mobil = 0;
    // TODO 5a: deklarasikan penampung biaya tertinggi (mulai -1) dan plat pemiliknya.

    for (int i = 1; i <= jumlah; i++) {
        string plat;
        char jenis = ' ';
        int durasi = 0;

        cout << "\n--- Kendaraan ke-" << i << " dari " << jumlah << " ---\n";

        // TODO 1: baca plat dengan getline sampai sah (tidak kosong dan bukan hanya spasi),
        //         lalu ubah semua hurufnya menjadi huruf besar. Pesan penolakan: "Plat tidak boleh kosong."
        cout << "Plat nomor : ";
        getline(cin, plat);

        // TODO 2: baca jenis (char), jadikan huruf besar, ulangi selama bukan 'M' atau 'R'.
        //         Pesan penolakan: "Hanya M (motor) atau R (roda empat). Jenis (M/R): "
        cout << "Jenis (M/R): ";
        cin >> jenis;

        // TODO 3: baca durasi dengan aman (bilangan bulat 1 sampai 24), pola seperti jumlah di atas.
        //         Pesan penolakan: "Harus bilangan bulat 1 sampai 24. Durasi (jam): "
        cout << "Durasi (jam, 1-24): ";
        cin >> durasi;
        cin.ignore(1000, '\n');

        // TODO 4: hitung biaya dan tentukan nama_jenis ("Motor" atau "Mobil"):
        //         biaya = tarif awal + (durasi - 1) * tarif lanjut, lalu dibatasi tarif maksimum jenisnya.
        //         Tambah banyak_motor atau banyak_mobil.
        int biaya = 0;
        string nama_jenis;

        cout << "  " << left << setw(12) << plat << setw(8) << nama_jenis
             << right << setw(4) << durasi << " jam" << setw(9) << biaya << "\n";

        total += biaya;
        // TODO 5b: perbarui biaya tertinggi dan plat pemiliknya bila biaya ini lebih tinggi.
    }

    cout << "\n=== Rekap Hari Ini ===\n";
    cout << "Jumlah kendaraan : " << jumlah << "\n";
    cout << "Motor            : " << banyak_motor << "\n";
    cout << "Mobil            : " << banyak_mobil << "\n";
    cout << "Total pendapatan : " << total << "\n";
    cout << "Rata-rata biaya  : " << static_cast<double>(total) / jumlah << "\n";
    // TODO 5c: cetak "Tertinggi        : " diikuti plat dan biaya tertinggi dalam kurung.

    cout << "\nSebaran jenis:\n";
    // TODO 6: dua baris batang, satu untuk Motor dan satu untuk Mobil, memakai perulangan bersarang:
    //         perulangan luar memilih label dan jumlahnya, perulangan dalam mencetak tanda # sebanyak itu.
    //         Format tiap baris: label rata kiri selebar 6, lalu "| ", batang, spasi, jumlah. Contoh: "Motor | ## 2"

    return 0;
}
