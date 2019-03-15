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
        
Maka, file dengan format "[namafile]_grey.png" nya akan berada di direktori /home/[user]/modul2/gambar dan file .png di direktori sebelumnya akan terhapus.

![Gambar Soal 1](/Image/1a.PNG)
![Gambar Soal 1](/Image/1b.PNG)

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

![Gambar Soal 1](/Image/2.PNG)

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

Jawaban
1. lakukan fork();
2. Pada Parent dari proses fork pertama lakukan execv("/usr/bin/unzip", argv); dengan argv berisi ("unzip","-n", "campur2.zip", NUL); setelah proses pada child selesai; -n memiliki arti ketika menemukan file yang sama jangan lakukan overwrite.
3. Pada child, lakukan fork lagi.
4. Pada child dari fork kedua, laukan fork lagi.
5. child dari fork ketiga diberi instruksi untuk melakukan execv("usr/bin/unzip", argv) dengan argv berisi ("unzip", "campur2.zip", "*.txt"); *.txt memiliki makna extract yang berekstensi *.txt saja.
6. lakukan pipe pada child dan parent hasil fork kedua. pada child tutup file descriptor read [0] dan pada parent tutup file descriptor write [1]'
7. lakukan execlp pada child dengan parameter "ls" "ls" "campur2". command ls bertujuan untuk mendaftar item item yang ada di direktori yang diinginkan. output dari child akan dikirim melalui pipe.
8. lakukan execlp pada parent dengan parameter "tee" "tee" "daftar.txt". command tee bertujuan untuk memasukkan input ke file yang diinginkan. input parent didapat dari pipe.

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

Jawab:
0. buat sebuah proccess daemon dengan isi while(1) sebagai berikut.
1. buat suatu variabel dengan tipe data stat untuk mencatat stat dari file dan variabe untuk menghitung jumlah log.
2. masukkan stat dari file makan_enak.txt kedalam variael bertipe data stat tadi dengan menggunakan fungsi stat();
3. buat sebuah kondisi jika difftime (beda waktu) dari atime (access time) dari variabel stat dengan waktu sekarang lebih kecil dari 30 maka:
	3.1 buatlah variabel string hastag yang menampung nilai urutan log.
	3.2 buatlah variabel string namafile berisi "makan_sehat"
	3.3 buatlah variabel string exten berisi ".txt"
	3.4 gabungkan semuanya dengan strcat;
	3.5 gunakan perintah fopen dengan parameter w (buat file jika file belum ada) dengan nama file hasil strcat tadi;
	3.6 tutup file dan increment variabel cont++

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

Jawab:
0. buat sebuah proccess daemon dasar.
1. sebelum while masukkan syntax berikut

	  time_t start_t;
	  time( &start_t );
	  int coutn=1;

	  time_t rawtime;
	  struct tm *info;
	  char buffer[80];
	  char menit[8];
	  char def[]="/home/bintang/log/";
	  char folder[80];
	  time_t end_t;
	  double diff_t;

	  coutn=1;
	  time( &rawtime );
	  info = localtime( &rawtime );
	  strftime(buffer,80,"%d:%m:%Y-%H:%M", info);
	    //strftime(menit,4,"%M", info);
	  strcpy(folder,buffer);
	  strcat(def,folder);
	  mkdir("/home/bintang/log", S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
	  sleep(1);
	  mkdir(def, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);	
	  
penjelasan : start_t merupakan variabel penanda program dimulai. Coutn merupakan variabel penghitung untuk log.
Line 215 - 217 bertujuan untuk mendapatkan string dari tanggal dengan format dd:mm:yyyy-HH-MM. Variabel folder berisi string dari tanggal dengan format yang dikehendaki. strcat(def,folder) berguna untuk memberitahu path dari folder yang akan dibuat. mkdir bertujuan untuk membuat folder dengan hak akses rwx untuk semua jenis user.

2. pada while(1) masukkan syntax berikut
	time(&end_t);
	    if((difftime(end_t,start_t)) >= 1800 && (difftime(end_t,start_t)) <= 1802)
	    {
	    strcpy(def,"/home/bintang/log/");
	    time(&start_t);
	    coutn=1;
	    time( &rawtime );
	    info = localtime( &rawtime );
	    strftime(buffer,80,"%d:%m:%Y-%H:%M", info);
	    //strftime(menit,4,"%M", info);
	    strcpy(folder,buffer);
	    strcat(def,folder);
	    mkdir("/home/bintang/log", S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
	    sleep(1);
	    mkdir(def, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
	    //printf("Final destination string : |%s|",menit);
	    //printf("Formatted date & time : |%s|\n", folder );
	    }

	    char target_file[80];
	    strcpy(target_file,def);
	    strcat(target_file,"/log");
	    sprintf(menit, "%d", coutn); 
	    strcat(target_file,menit);
	    strcat(target_file,".log");

	    char ch, source_file[]="/var/log/syslog";
	    FILE *source, *target;
	    source = fopen(source_file, "r");
	    if (source == NULL)
	    {
		printf("Source gak ada...\n");
		exit(EXIT_FAILURE);
	    }

	    target = fopen(target_file, "w");

	    if (target == NULL)
	    {
		fclose(source);
		printf("target gak ada...\n");
		exit(EXIT_FAILURE);
	    }

	    while ((ch = fgetc(source)) != EOF)
		fputc(ch, target);

	    printf("File copied successfully.\n");

	    fclose(source);
	    fclose(target);
	    sleep(60);
	    coutn++;

	  }
  penjelasan : syntax di dalam if sama dengan syntax di atas while dan syntax itu dijalankan ketika selisih dari detik mulai dan detik saat ini 1800 (30 menit). Di dalam if, waktu mulai dan penanda log akan direstart kembali menjadi 0.
Line 248 - line 253 bertujuan untuk mendefinisikan nama file log yang akan dibuat. syntax sisa dibawahnya bertujuan untuk mencopy file dari /var/log/syslog ke file log yang dikehendaki di direktori yang dikehendaki. Setelah mencopy, penanda log akan diincrement.

untuk mematikan proses 5a gunakan syntax berikut

id_t searchpid()
{
    char calpid[7]={0};
    FILE *pidpath = popen("pidof /home/bintang/prak/soal5/soala5", "r");
    fgets(calpid, 7, pidpath);
    pid_t pidprog = strtoul(calpid, NULL, 10);
    pclose(pidpath);

    return pidprog;
}

int main(){
    
    pid_t soal5 = searchpid();
    kill(soal5, SIGKILL);

    return(0);
}
 penjelasan : fungsi searchpid berguna untuk mengembalikan pid dari proses yang diinginkan. pidpath akan mendapatkan calon pid dari fungsi pidof dimana pidof mencari pid dari soal5a. variabel calpid akan menyimpan data yang dibawa oleh pidpath. kemudian dengna menggunakan fungsi stroul dengan basis 10 didapatkan pid dari proccess yang diinginkan.
untuk membunuh proses, gunakan fungsi kill(pid,signal) (dalam konteks ini kill(soal5,sigkill))


