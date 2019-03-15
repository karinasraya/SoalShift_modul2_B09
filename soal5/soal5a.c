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
#include<limits.h>

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

  if ((chdir("/")) < 0) {
    exit(EXIT_FAILURE);
  }

  close(STDIN_FILENO);
  close(STDOUT_FILENO);
  close(STDERR_FILENO);


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
  while(1) {
    
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
  
  exit(EXIT_SUCCESS);
}