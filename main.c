#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
int main(){
int toenter[10];
int towrite[10];
int result;
int rando=open("/dev/random",O_RDONLY);
if (rando<0) printf("Error opening random");
result=read(rando,toenter,4);
printf("%d\n",*toenter);
//int fd = open ("rand.txt",O_WRONLY | O_CREAT, 0644);
//if (fd<0) printf("Error opening new file");
printf("Done");
return 1;
}
