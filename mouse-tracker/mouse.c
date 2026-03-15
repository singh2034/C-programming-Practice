#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main (int argc, char* argv[]) 
{
    if (argc != 2)
    {
        printf("Usage: %s <event-file-path>\n", argv[0]);
        exit(0);
    }
    char* devicepath = argv[1];
    printf("Mouse %s movements are intercepted here .... \n", devicepath);
    int fd = open(devicepath, 0, O_RDONLY);
    printf("File Descriptor: %d\n", fd);
}
