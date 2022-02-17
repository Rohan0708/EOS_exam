/* Message queue program
   */
#include <stdio.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#define SIZE 20







int main()
{
    /* code */
    char string[SIZE];
    int c;
    int shmd;
    shmd = shm_open("/cdacshm", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);// it is of path name , flags ,mode(we used as user call f'n)
    ftruncate(shmd,sizeof(char)); //file named by path & sizeof length
    string[SIZE] = (char *)mmap(NULL,sizeof(char),PROT_READ | PROT_WRITE,MAP_SHARED,shmd,0);//virtual address space of the calling process IT HASaddress.length,prot,flags,fd,offset.
    
    
            c=strlen(string);
            printf("length: %d\n",c);
            
   //printf("string is: %d\n",string);
    
    return 0;
}
