#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>

pid_t searchpid()
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