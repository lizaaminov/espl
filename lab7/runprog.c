#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>


void main(int argc, char **argv)
{
  int i;
  int status =-1;
  for (i=1; i<argc; i++)
  {
    printf("%s ",argv[i]);
  }
  printf("\n");
  if (fork()==0) {
    execvp(argv[1], argv+1);
  }
  else {
    wait(&status);
    printf("system exit:%d\n",WEXITSTATUS(status));
  }
}