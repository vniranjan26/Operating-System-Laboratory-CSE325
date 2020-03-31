/*
Question1: Write a program using System calls to display the no of bytes of
data read and print the message if read is successful.


*/

#include<unistd.h>
#include<stdio.h>
int main()
{
	int n=1;
	char buff[100];
        write(1,"Enter the string : ",19);
	n=read(0,buff,100);
        if(n!=1)
        {
           printf("I read %d byte of data.\n",n);
        }
        else
        {
           printf("I dosen't read data.");
        }
}
.
