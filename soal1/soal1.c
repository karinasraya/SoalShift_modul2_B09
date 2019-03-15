#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <syslog.h>
#include <string.h>
#include <dirent.h>

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

  if ((chdir("/home/karinasraya/Modul2/soal1/")) < 0) {
    exit(EXIT_FAILURE);
  }

  close(STDIN_FILENO);
  close(STDOUT_FILENO);
  close(STDERR_FILENO);

  while(1) {
    DIR *gbr;
    struct dirent *dir;
    gbr = opendir(".");

    if (gbr)
    {
        while ((dir = readdir(gbr)) != NULL)
        {
	    char file[500];
	    int pjg = (int) strlen(dir->d_name);
	    char *name = dir->d_name;
	    
	  if(name[pjg-4] == '.' && name[pjg-3] == 'p' && name[pjg-2] == 'n' && name[pjg-1] == 'g'){
            	strcpy(file, "/home/karinasraya/modul2/gambar/");
		          strcat(file, name);
		          pjg = (int)strlen(file);
		          file[pjg-4] = '\0';
		          strcat(file, "_grey.png");
	
	  if(fork()==0){
		  char *argv[] = {"cp", name, file, NULL};
		  execv("/bin/cp", argv);
		}
		  printf("%s\n", file);
	    }
        }
        closedir(gbr);
    }
 	sleep(5);
  }
  
  exit(EXIT_SUCCESS);
}
