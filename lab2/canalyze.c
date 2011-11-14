#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "namelist.h"

int sort(const void *a,const void *b){
    struct namestat *ia = (struct namestat *)a;
    struct namestat *ib = (struct namestat *)b;
    return strcmp(ia->name, ib->name);
 }

/*int check(char* word){
    switch(*word){
      case "auto": break;
      case "int": break;
      case "long": break;
      case "register": break;
      case "return": break;
      case "short": return 0;
      case "signed": return 0;
      case "sizeof": return 0;
      case "static": return 0;
      case "long": return 0;
      case "switch": return 0;
      case "typedef": return 0;
      case "union": return 0;
      case "unsigned": return 0;
      case "void": return 0;
      case "volatile": return 0;
      case "while": return 0;
      case "break":return 0;
      case "case":return 0;
      case "char":return 0;
      case "const":return 0;
      case "continue":return 0;
      case "default":return 0;
      case "do":return 0;
      case "double":return 0;
      case "else":return 0;
      case "enum":return 0;
      case "extern":return 0;
      case "float":return 0;
      case "for":return 0;
      case "goto":return 0;
      case "if":return 0;
      default:return 1;
}
}*/

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

    //  if (check(word)=1)
      add_name(nl, word);
      for(i=0;i<50;i++){
	  word[i]=0;
      }
     
    }
    else  
      c=fgetc(file);
   
  }  
  int j=0;

   qsort(&(nl->names[1]),nl->size,sizeof(nl->names[1]),sort);
   for (j=0; j<nl->size;++j){
      printf("%s\n",nl->names[j].name);      
    }
    
    
  fclose(file);
  return 0;
}
  
 

void main(int argc, char **argv)
{
  int num=0;
  num = canalyze(argv[1]);

}
