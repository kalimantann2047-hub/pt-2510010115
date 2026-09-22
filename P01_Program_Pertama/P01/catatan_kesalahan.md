# Catatan Kesalahan Praktikum 5

## Tabel Praktikum 5

| No | Berkas | Jenis Kesalahan | Pesan/Error | Penyebab | Solusi |
|---|---|---|---|---|---|
| 1 | `k1_sintaks.cpp` | Kesalahan Sintaks | `uexpected ‘,’ or ‘;’ before ‘std’`, `unused variable ‘nilai’`| Variabel sudah dideklarasikan tetapi belum digunakan dan kurang `;` pada variabel `nilai = 80` | Gunakan variabel dalam perhitungan atau hapus variabel yang tidak diperlukan dan tambahkan `;` setelah variabel `int nilai = 80` |
| 2 | `k2_nama.cpp` | Kesalahan Nama Variabel | `Nilai’ was not declared in this scope; did you mean ‘nilai’`,  `‘bonus’ was not declared in this scope`| kesalahan pada nama variabel, harusnya `nilai` bukan `Nilai` dan variabel `bonus` tidak di deklarasikan | perbaiki nilai typo `Nilai` jadi `nilai` dan deklarasikan variabel `bonus` |
| 3 | `k3_runtime.cpp` | Kesalahan Logika | Program melakukan pembagian dengan 0 ketika jumlah mahasiswa yang dimasukkan adalah 0 | Memeriksa jumlah_mahasiswa == 0 sebelum melakukan pembagian. |
| 4 | `k4_logika.cpp` | Kesalahan Logika | Program emmbulatkan jadi `81` harusnya hasilnya `81.67` karena dia dibagi `3` | dibagi 3 | harusnya dibagi `3.0` |

## Kesimpulan

Menurut saya, kesalahan logika merupakan jenis kesalahan yang paling berbahaya, karena program dapat terlihat berjalan dengan normal tanpa menampilkan pesan error, padahal hasil yang diberikan salah. Oleh karena itu, selain memastikan program berhasil dikompilasi dan dijalankan, hasil perhitungan dan logika program juga harus diperiksa dan diuji dengan teliti.