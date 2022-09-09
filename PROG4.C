#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main()
{
  int pid=fork();
  if(pid>0)
  {
   sleep(20);
  }
else
   {
    printf("child process is running\n");
    exit(0);
   }
}
