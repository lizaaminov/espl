#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>


int atod(const char* number) {
int num=0;
int temp = 1;
int i=0;
  for(i = (int)strlen(number)-1; i>=0; i--)
  {
    num = num+((number[i]-'0')*temp);
    temp = temp*10;
  }
  return num;

}


/*int atod (char *number)
{
    int i=0;
    int j;
    for (j=0;number[j]!='\0' ;j++) {
      i=i*10;
      i=i+(number[j]-'0');
    }
    
    return i;
}*/
