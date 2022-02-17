/* Shared memory program
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <string.h>
#define SIZE 20
int i = 0;

int shmd;
//char *data;

int main()
{
     char string[SIZE];

    shmd = shm_open("/cdacshm", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR);                     // it is of path name , flags ,mode(we used as user call f'n)
    ftruncate(shmd, sizeof(char));                                                                  // file named by path & sizeof length
    string[SIZE] = (char *)mmap(NULL, sizeof(char), PROT_READ | PROT_WRITE, MAP_SHARED, shmd, 0); // virtual address space of the calling process IT HASaddress.length,prot,flags,fd,offset.



   
    FILE *fp=fopen("dictionary.txt", "r");

    if (fp==NULL)
    {
        printf("File opening Error!!");
    }
    while(fgets(string,SIZE,fp)!=NULL)
         if(string[0]=='m'||string[0]=='M')
         {
             i++;
             printf("%s %d",string,i);
         }
    
    
    printf("\nsucessfull");
    fclose(fp);
    return 0;
}
