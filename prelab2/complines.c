#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int complines(char* frame1, char* frame2)
{
  FILE *f1, *f2;
  char line1[80]={0}, line2[80]={0};
  char c1, c2;
  int ind1=0;
  int ind2=0;
  int i=0;
  int line = 0;

  f1=fopen(frame1, "r"); 
  f2=fopen(frame2, "r");
  
  if(!f1)
  {
    printf("Error opening file %s\n", frame1);
    fclose(f1);
    return -1;
  }
    
  if(!f2)
  {
    printf("Error opening file %s\n", frame2);
    fclose(f2);
    return -1;
  }
    
    c1=getc(f1);
    c2=getc(f2);
    
  while(c1!=EOF || c2!=EOF){
      while(c1!='\n'){
	if( c1!=EOF){
	  line1[ind1++]=c1;
	  c1=getc(f1);
	  }
	  else break;
      }
	line1[ind1]='\0';
	ind1=0;
      while(c2!='\n'){
	if( c2!=EOF){
	  line2[ind2++]=c2;
	  c2=getc(f2);
	}
	else break;
      }
	 line2[ind2]='\0';
	  ind2=0;
      line++;
      if(strcmp(line1, line2)!=0){
	printf(" %d\n",line);
	printf("%s\n",line1);
	printf("%s\n",line2);
      }
     
	  for(i=0;i<80;i++)
		  line1[i]=0;

	  for(i=0;i<80;i++)
		  line2[i]=0;
	  
	  c1=getc(f1);
	  c2=getc(f2);
  }
    
    fclose(f1);
    fclose(f2);
    
    return 0;
  }

void main(int argc, char **argv)
{
	complines(argv[1],argv[2]);

}