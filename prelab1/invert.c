 #include <stdio.h>

 int main(int argc, char **argv) {
   int i;

   for(i=argc-1; i>=1; --i) {

      printf("%s", argv[i]);
      printf("%s", " ");

   }
   printf("'.\n");

   return 0;
 }
