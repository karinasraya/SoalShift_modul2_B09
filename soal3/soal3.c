#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

int main(){

pid_t child_id;
  int status;

  child_id = fork();

if(child_id == 0)
{
    child_id = fork();
    if (child_id == 0) {

    // Unzip campur2.zip
    char *argv[5] = {"unzip", "-n","campur2.zip", "*.txt", NULL};
    execv("/usr/bin/unzip", argv);
  } 
  else {
    while ((wait(&status)) > 0);

    int fd[2];
    pipe(fd);
    pid_t pid=fork();

    if(pid==0){

            close(fd[0]);
            dup2(fd[1], 1); 
            char *argv[3] = {"list", "campur2", NULL};
            execv("/bin/ls", argv);
        }
    
    else{

            close(fd[1]);       
            dup2(fd[0], 0);
            execlp("tee", "tee","daftar.txt", NULL);
                       
        }
    
  }
}
else
{
    wait(NULL);
    char *argv[4] = {"unzip", "-n","campur2.zip", NULL};
    execv("/usr/bin/unzip", argv);
}

    return 0;
}