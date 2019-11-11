#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
int numgen(){
  int result;
  int toenter[1];
  int rando=open("/dev/random",O_RDONLY);
  if (rando<0) printf("Error opening random");
  result=read(rando,toenter,4);
  if (result<0) printf("Error with random number generator");
//  printf("%d\n",*toenter);
  //printf("%d\n",result);
  close(rando);
  return *toenter;
}

int main(){
int toberead[10];
int starter[10];
int fd;
int fd2;
int i;
int result;
printf("Populating the array:\n");
for (i=0;i<10;i++){
  starter[i]=numgen();
  printf("Number %d: %d\n",i+1,starter[i]);
}

printf("Writing the array to a new file.\n");
fd =open("randnum",O_WRONLY | O_CREAT | O_EXCL ,0744);
  if (fd<0) printf("Error opening new file.\n");
result=write(fd,starter,10*sizeof(int));
  if (result<0) printf("Error writing to the file.\n");
result=close(fd);

printf("Reading the file back.\n");
fd2 =open("randnum",O_RDONLY,0644);
  if (fd<0) printf("Error reopening file.\n");
result=read(fd2,toberead,10*sizeof(int));
  if (result<0) printf("Error reading the file.\n");
result=close(fd2);

printf("Checking that the numbers are identical:\n");
for (i=0;i<10;i++){
  printf("Number %d:%d\n",i+1,toberead[i]);
}
printf("Done\n");
return 1;
}
