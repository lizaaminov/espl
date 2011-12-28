
int bcmp(int argc, char **argv){
  
char *nl = "\n";

char buf2[1];
char buf1[1];

char *file1 = argv[1];
unsigned int fh1 = fopen(file1);
char *file2 = argv[2];
unsigned int fh2 = fopen(file2);

int diff, eof1, eof2;
char f1=0;
char f2=0;
int byteNum;

int diffletter;
char temp1 = '1';
char temp2 = 1;
diffletter = temp1-temp2;

byteNum = 1;
diff = 0;
eof1 = 1;
eof2 = 1;


while ((eof1 == 1) & (eof2 == 1)){
  eof1 = readchar(fh1, buf1);
  eof2 = readchar(fh2, buf2);

  if ((eof1 == 0) | (eof2 == 0)){
    break;
  }

  if ((char)*buf1 != (char)*buf2){
    char* msg = "byte ";
    puts(msg);

    msg = " -";
    puts(msg);
    puts(buf1);
    msg = " +";
    puts(msg);
    puts(buf2);
    puts(nl);
    diff = 1;
  }
  
  byteNum ++;
}

 // fclose(fh1);
 // fclose(fh2);

return 0;
}
