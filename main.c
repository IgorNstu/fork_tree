#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(void)
{
    pid_t pid,ppid;
    int status;
    printf("(1)-(2)-(3)\n     \\\n     (4)-(5)\n      \\\n      (6)\n");
    pid=fork();
    if(pid==0) {
       pid=getpid();
       ppid=getppid();
       printf("(2)Я: %d, Мой родитель: %d \n",pid,ppid);
       pid=fork();
       if(pid==0){
          pid=getpid();
          ppid=getppid();
          printf("(3)Я: %d, Мой родитель: %d \n",pid,ppid);
          exit(1);
       }
          else {
          wait(&status);
       }

    }
    else
        {
        pid=getpid();
        printf("(1)Я: %d\n",pid);
        wait(&status);
        pid=fork();
        if(pid==0){
           pid=getpid();
           ppid=getppid();
           printf("(4)Я: %d, Мой родитель: %d \n",pid,ppid);
           pid=fork();
           if(pid==0){
              pid=getpid();
              ppid=getppid();
              printf("(5)Я: %d, Мой родитель: %d \n",pid,ppid);
           }
            else {
               wait(&status);
               pid=fork();
               if(pid==0){
               pid=getpid();
               ppid=getppid();
               printf("(6)Я: %d, Мой родитель: %d \n ",pid,ppid);
               }
               else {
                   wait(&status);
               }
           }

           }
        else{
            wait(&status);
        }
    }

return 0;
}


