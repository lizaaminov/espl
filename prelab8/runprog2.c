#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>


void main(int argc, char **argv)
{
  char inbuf[100];
  int i;
  int status =-1;
  int p[2], j;
  int flag=1;
  int line=1;

   /* open pipe */

   if(pipe(p) == -1)
   {    perror("pipe call error");
        exit(1);
   }
   

  for (i=2; i<argc; i++)
  {
    printf("%s ",argv[i]);
  }
  printf("\n");
  
  
  if (fork()!=0) //if parent
  {
    close(p[1]); //close the write
    while(read(p[0],inbuf,1)>0){
      if(flag==1){
	printf("%d : ", line);
	flag=0;
      }
        printf("%s",inbuf);
	if(inbuf[0]=='\n'){
	  flag=1;
	  line++;
	}
    }
    wait(&status);
    printf("system exit:%d\n",WEXITSTATUS(status));
  }
  
  
  else //if child 
  {
    close(p[0]); //close the read
    dup2(p[1],1);
    close(p[1]);
    execvp(argv[2], argv+2);

  }
}