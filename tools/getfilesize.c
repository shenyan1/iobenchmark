
uint64_t getFilesize(char *str){
FILE *fp=fopen(str,"r");
fseek(fp,0L,SEEK_END);
uint64_t size=ftell(fp);
fclose(fp);
return size;
}
