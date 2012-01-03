
int puts(char *s) {
  return write(1,s,length(s));
}
