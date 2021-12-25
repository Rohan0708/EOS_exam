/* Shared memory program
   */
#include <stdio.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>




int main()
{
    /* code */
    FILE* fd;
    //int *count;
    char buff[100] = {'/0'};
    char *s1;

    fd = fopen("/home/rohan/Desktop/EOS_EXAM_0010/dictionary.txt","r");

    if(fd == NULL)
    {
      printf("Error loading file!");
    }

    int shmd;
    shmd = shm_open("/cdacshm", O_RDWR | O_CREAT , S_IRUSR | S_IWUSR);// it is of path name , flags ,mode(we used as user call f'n)
    ftruncate(shmd,100); //file named by path & sizeof length
    s1 = (char *)mmap(NULL,100,PROT_READ | PROT_WRITE,MAP_SHARED,shmd,0);//virtual address space of the calling process IT HASaddress.length,prot,flags,fd,offset.
    

      while (fgets(buff,100,fd)!= NULL)
      {
        /* code */
        if(buff[0] == 'm')
        {
          while (1)
          {
            
            /* code */
            printf("%s",buff);
         
          }

          
          
        }
      }     
    
     /* printf("Enter the string starting letter: ");
      scanf("%s",str);
     str[1000] = *count;  */
       
      fclose(fd);
    return 0;
}