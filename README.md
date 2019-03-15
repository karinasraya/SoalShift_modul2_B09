# SoalShift_modul2_B09

<b> No. 1 </b>

Elen mempunyai pekerjaan pada studio sebagai fotografer. Suatu hari ada seorang klien yang bernama Kusuma yang meminta untuk mengubah nama file yang memiliki ekstensi .png menjadi “[namafile]_grey.png”. Karena jumlah file yang diberikan Kusuma tidak manusiawi, maka Elen meminta bantuan kalian untuk membuat suatu program C yang dapat mengubah nama secara otomatis dan diletakkan pada direktori /home/[user]/modul2/gambar.
Catatan : Tidak boleh menggunakan crontab.

Jawaban :
1. Buat folder "modul2"
 
        mkdir modul2
    
2. Di dalam folder "modul2" buat folder "gambar"

        mkdir gambar

3. Buat file bernama soal1.c

        nano soal1.c

4. Setelah itu isikan soal1.c dengan script sebagai berikut : [Script Soal 1](/soal1/soal1.c)

Keterangan :

* Menyimpan direktori yang sedang dicek

       DIR *gbr
       
* Menyimpan file yang dicek dalam bentuk struct

       struct dirent *dir
       
* Membuka direktori file

       gbr = opendir(".")
       
* Mengecek semua file yang ada pada direktori

       while ((dir = readdir(gbr)) != NULL)
       
* Mencari semua file yang memiliki ekstensi .png lalu di concat dengan string yang mengandung direktori tujuan

       if(name[pjg-4] == '.' && name[pjg-3] == 'p' && name[pjg-2] == 'n' && name[pjg-1] == 'g'){
            	strcpy(file, "/home/karinasraya/modul2/gambar/");
		           strcat(file, name);
       
* Ambil nama file dan satukan dengan "_grey.png"

        char n[20]="_grey.png";
        pjg = strlen(file);
		      file[pjg-4] = '\0';
		      strcat(file,n);

* Hasilnya di copy ke direktori tujuan

        char *new[]={"cp", name, file, NULL};
		      execv("/bin/cp", new);
        
* Jika semua file .png sudah di ubah namanya dan disimpan di direktori tujuan, maka tutup direktori dan hapus file .png di direktori sebelumnya

        closedir(gbr);
       	remove("/home/karinasraya/Modul2/soal1/*.png");

5. Jalankan programnya

        gcc -o soal1 soal1.c
        
Maka, file dengan format "[namafile]_grey.png" nya akan berada di direktori /home/[user]/modul2/gambar.

#

<b> No. 2 </b>

Pada suatu hari Kusuma dicampakkan oleh Elen karena Elen dimenangkan oleh orang lain. Semua kenangan tentang Elen berada pada file bernama “elen.ku” pada direktori “hatiku”. Karena sedih berkepanjangan, tugas kalian sebagai teman Kusuma adalah membantunya untuk menghapus semua kenangan tentang Elen dengan membuat program C yang bisa mendeteksi owner dan group dan menghapus file “elen.ku” setiap 3 detik dengan syarat ketika owner dan grupnya menjadi “www-data”. Ternyata kamu memiliki kendala karena permission pada file “elen.ku”. Jadi, ubahlah permissionnya menjadi 777. Setelah kenangan tentang Elen terhapus, maka Kusuma bisa move on.
Catatan: Tidak boleh menggunakan crontab

Jawaban :
1. Buat folder "hatiku"
 
        mkdir hatiku
    
2. Di dalam folder "hatiku" buat file "elen.ku"

        touch elen.ku

3. Buat file bernama soal2.c

        nano soal2.c

4. Setelah itu isikan soal2.c dengan script sebagai berikut : [Script Soal 2](/soal2/soal2.c)

Keterangan :

* Mendapatkan owner dan grup :
        
       struct stat hh;
       char ff[50]="/home/karinasraya/Modul2/soal2/hatiku/elen.ku";
       stat(ff, &hh);
       struct passwd *pw = getpwuid(hh.st_uid);
       struct group  *gr = getgrgid(hh.st_gid);
       
* Mengecek apakah owner dan grupnya www-data

      ((strcmp(pw->pw_name,"www-data"))==0) && ((strcmp(gr->gr_name,"www-data"))==0)
      
* Menghapus kenangan

       remove(ff)
       
* Menghapus file setiap 3 detik

       sleep(3)

5. Ubah permission file "elen.ku" menjadi 777

        chmod 777 elen.ku
        
6. Ubah owner dan grup pada file "elen.ku" menjadi "www-data"

        sudo chown www-data:www-data elen.ku

7. Jalankan programnya

        gcc -o soal2 soal2.c
        
Maka, kenangannya akan terhapus.

#

<b> No. 3 </b>

Diberikan file campur2.zip. Di dalam file tersebut terdapat folder “campur2”. 
Buatlah program C yang dapat :
i)  mengekstrak file zip tersebut.
ii) menyimpan daftar file dari folder “campur2” yang memiliki ekstensi .txt ke dalam file daftar.txt. 
Catatan:  
Gunakan fork dan exec.
Gunakan minimal 3 proses yang diakhiri dengan exec.
Gunakan pipe
Pastikan file daftar.txt dapat diakses dari text editor

#

<b> No. 4 </b>

Dalam direktori /home/[user]/Documents/makanan terdapat file makan_enak.txt yang berisikan daftar makanan terkenal di Surabaya. Elen sedang melakukan diet dan seringkali tergiur untuk membaca isi makan_enak.txt karena ngidam makanan enak. Sebagai teman yang baik, Anda membantu Elen dengan membuat program C yang berjalan setiap 5 detik untuk memeriksa apakah file makan_enak.txt pernah dibuka setidaknya 30 detik yang lalu (rentang 0 - 30 detik).
Jika file itu pernah dibuka, program Anda akan membuat 1 file makan_sehat#.txt di direktori /home/[user]/Documents/makanan dengan '#' berisi bilangan bulat dari 1 sampai tak hingga untuk mengingatkan Elen agar berdiet.

Contoh:
File makan_enak.txt terakhir dibuka pada detik ke-1
Pada detik ke-10 terdapat file makan_sehat1.txt dan makan_sehat2.txt

Catatan: 
dilarang menggunakan crontab
Contoh nama file : makan_sehat1.txt, makan_sehat2.txt, dst

#

<b> No. 5 </b>

Kerjakan poin a dan b di bawah:
Buatlah program c untuk mencatat log setiap menit dari file log pada syslog ke /home/[user]/log/[dd:MM:yyyy-hh:mm]/log#.log
Ket:
Per 30 menit membuat folder /[dd:MM:yyyy-hh:mm]
Per menit memasukkan log#.log ke dalam folder tersebut
‘#’ : increment per menit. Mulai dari 1
Buatlah program c untuk menghentikan program di atas.
NB: Dilarang menggunakan crontab dan tidak memakai argumen ketika menjalankan program.
