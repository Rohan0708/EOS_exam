/* Message queue program
   */
#include <stdio.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>



int *count,i;
char str[1000];

int main()
{
    /* code */
    int shmd;
    shmd = shm_open("/dictionary.txt", O_RDWR , S_IRUSR | S_IWUSR);// it is of path name , flags ,mode(we used as user call f'n)
    ftruncate(shmd,sizeof(int)); //file named by path & sizeof length
    count = (int *)mmap(NULL,sizeof(int),PROT_READ | PROT_WRITE,MAP_SHARED,shmd,0);//virtual address space of the calling process IT HASaddress.length,prot,flags,fd,offset.
    
    
       while (1)
       {
          
        
    
      
    printf("Length of Str is %s", str);
     sleep(1);
        printf("Count: %d\n", *count); //In this receive was takes place when the sender will pass the o/p.
        sleep(2);
        
     
       }
    
    return 0;
}