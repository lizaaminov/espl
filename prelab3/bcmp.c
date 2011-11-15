#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int bcm(char* frame1, char* frame2)
{
  FILE *f1, *f2;
  char *buffer1;
  char *buffer2;
  unsigned long fileLen1, fileLen2;
  int n1, n2;
  
  
  f1=fopen(frame1, "rb"); 
  f2=fopen(frame2, "rb");
  
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
  
  fseek(f1, 0, SEEK_END);
  fileLen1=ftell(f1);
  fseek(f1, 0, SEEK_SET);
  
  fseek(f2, 0, SEEK_END);
  fileLen2=ftell(f2);
  fseek(f2, 0, SEEK_SET);
  
  buffer1=(char *)malloc(fileLen1+1);
        if (!buffer1)
        {
                fprintf(stderr, "Memory error!");
                                fclose(f1);
                return -1;
        }
        
  buffer2=(char *)malloc(fileLen2+1);
        if (!buffer2)
        {
                fprintf(stderr, "Memory error!");
                                fclose(f2);
                return -1;
        }
  

 fread(buffer1, fileLen1, 1, f1);
 fread(buffer2, fileLen2, 1, f2);
 
  int i;
  for(i = 0;i < fileLen1+1;i++){
    n1 = (int)buffer1[i];
    n2 = (int)buffer2[i];

    if(n1!=n2){
    printf("%d\n",i);
    printf("%d %d\n",n1, n2);
    
    }
  }
  
  
  
  
  fclose(f1);
  free(buffer1);
  fclose(f2);
  free(buffer2);
  
 
  
  return 0;
}
    
 //   c1=getc(f1);
  //  c2=getc(f2);
    
void main(int argc, char **argv)
{
        bcm(argv[1],argv[2]);

}