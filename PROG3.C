#include<stdio.h>
#include<unistd.h>
int main()
{
  int pid=fork();
  if(pid>0)
{
printf("parent process is runnning\n");
}
else{
  sleep(20);
  printf("child process is running\n");
}

}
