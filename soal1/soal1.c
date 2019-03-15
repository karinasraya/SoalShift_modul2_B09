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
	    char file[200];
	    char n[20]="_grey.png";
	    int pjg = strlen(dir->d_name);
	    char *name = dir->d_name;
	    
	if(name[pjg-4] == '.' && name[pjg-3] == 'p' && name[pjg-2] == 'n' && name[pjg-1] == 'g'){
            	strcpy(file, "/home/karinasraya/modul2/gambar/");
		strcat(file, name);
		pjg = strlen(file);
		file[pjg-4] = '\0';
		strcat(file,n);
	if(fork()==0)
	{
		char *new[]={"cp", name, file, NULL};
		execv("/bin/cp", new);
	}
	    }
        }
        closedir(gbr);
	remove("/home/karinasraya/Modul2/soal1/*.png");
    }
  }
  
  exit(EXIT_SUCCESS);
}
