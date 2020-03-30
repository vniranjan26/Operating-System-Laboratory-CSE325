/*
Question 3: create two threads where thread 1 is calculating factorial of 5 and thread 2 is calculating the average of first 10 natural
number .but make sure the execution of  thread 1 is successful up-to factorial but when going to print the output it is  replaced by
“LS” shell command.


*/

#include<pthread.h> 
#include<stdio.h>
#include<unistd.h>
void *th1()
{
   int fact=1;
   for(int i=1;i<=5;i++)
   {
      fact=fact*i;
   }
   execl("/bin/ls","ls",NULL);
   printf("Factorial of 5 is :%d\n",fact);
}
void *th2()
{
    int sum;
    float avg=0;
    for(int i = 1 ; i <= 10 ; i++)
    {
       sum = sum + i;
    }
       avg = sum / 10;
    printf("\nAverage of first %d numbers is : %.2f", 10, avg);
}
int main()
{
   pthread_t t1,t2;
   pthread_create(&t1,NULL,&th1,NULL);
   pthread_create(&t2,NULL,&th2,NULL);
   pthread_join(t1,NULL);
   pthread_join(t2,NULL);
   printf("main process is working\n");
}
