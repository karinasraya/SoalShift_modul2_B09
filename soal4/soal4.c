#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>
#include <time.h>

int main() {
  pid_t pid, sid;

  pid = fork();

  if (pid < 0) {
    exit(EXIT_FAILURE);
  }

  if (pid > 0) {
    exit(EXIT_SUCCESS);
  }

  umask(0);

  sid = setsid();

  if (sid < 0) {
    exit(EXIT_FAILURE);
  }

  if ((chdir("/home/Documents/")) < 0) {
    exit(EXIT_FAILURE);
  }

  close(STDIN_FILENO);
  close(STDOUT_FILENO);
  close(STDERR_FILENO);

    int cont=1;
  while(1) {
    struct stat addr;
    char hastag[50];
    char namafile[] = "makan_sehat";
    char exten[] = ".txt";
    double diff;
    

    stat("/home/bintang/Documents/makan_enak.txt", &addr);
    
    diff = difftime(time(NULL), addr.st_atime);

    if(diff <=30)
    {
        sprintf(hastag,"%d", cont);
        strcat(namafile,hastag);
        strcat(namafile,exten);

        FILE* neu = fopen(namafile, "w");
        fclose(neu);
        strcpy(namafile, "makan_sehat");
        cont++;
    }
  }
  
  exit(EXIT_SUCCESS);
}