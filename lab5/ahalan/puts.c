void puts(char *s){
  int len=length(s);
  write(1, s,len);
}