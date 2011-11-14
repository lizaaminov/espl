#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "namelist.h"

int sort(const void *a,const void *b){
    struct namestat *ia = (struct namestat *)a;
    struct namestat *ib = (struct namestat *)b;
    return strcmp(ia->name, ib->name);
 }
 
static char *keywords[]={"auto","break","case","char","const","continue","default","do","double",
  "else","enum","extern","float","for","goto","if","long","register","return","short","signed","sizeof",
  "static","long","switch","typedef","union","unsigned","void","volatile","while", NULL};

int iskeyword(char *name) {
    char **keyword = keywords;
    while(*keyword) {
        if(!strcmp(*keyword, name))
            return 1;
        ++keyword;
    }
    return 0;
}


int canalyze(char* frame)
{
  FILE *file;
  char c;
  char word[50];
  namelist nl = make_namelist();

  file=fopen(frame, "r"); 
  
  if(!file)
  {
    printf("Error opening file %s\n", frame);
    fclose(file);
    return -1;
  }
  int i=0;
  c=fgetc(file);
  while(c!=EOF){
    int ind=0;
    if(isalpha(c)!=0){
      while(isalpha(c)!=0){
	    word[ind++]=c;
	    c=getc(file);
      }

      if (iskeyword(word)==0){
	add_name(nl, word);
      }
      for(i=0;i<50;i++){
	  word[i]=0;
      } 
    }
    else  
      c=fgetc(file);   
  }  
  
  int j=0;

   qsort(&(nl->names[1]),nl->size,sizeof(nl->names[1]),sort);
   for (j=0; j<= nl->size;++j){
     if(j!=1){ 
       printf("%s %d\n",nl->names[j].name, nl->names[j].count);      
     }
   }
    
  fclose(file);
  return 0;
}
  
 

void main(int argc, char **argv)
{
  int num=0;
  num = canalyze(argv[1]);

}
