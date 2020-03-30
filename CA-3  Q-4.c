/*
Question4:   Write a Program to create  this hierarchy Also verify the parent & child relationship.
                 P
                /\
              /    \
            /        \
          C1       C2
         /\
       /    \
     /        \
   C3       C4

*/

#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/wait.h>
int main()
{
    for(int i=1;i<=2;i++)
    {
       if(fork()==0)
          {
             printf("Child [C%d] ID is :%d Parent ID is :%d\n",i,getpid(),getppid());
	     if(i==1)
		{
		for(int j=3;j<=4;j++)
    		{
       		   if(fork()==0)
         	   {
             		printf("Child [C%d] ID is :%d Parent ID is :%d\n",j,getpid(),getppid());		 
           		  exit(0);
          	   }
    		}
		for(int j=3;j<=4;j++)
	       {
		  wait(NULL);
	       }
		break;
              }
            }
      }
    for(int i=1;i<=2;i++)
    {
        wait(NULL);
    }
}
