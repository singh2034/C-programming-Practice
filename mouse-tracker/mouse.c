#include <stdio.h>

int main (int argc, char* argv[]) 
{
    if (argc != 2)
    {
        printf("Usage: %s <event-file-path> \n" argv[0]);
        exit(0);
    }
    printf("Mouse movements are intercepted here .... \n");

}
