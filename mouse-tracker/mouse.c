#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <linux/input.h>
#include <sys/time.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s <event-file-path>\n", argv[0]);
        exit(0);
    }
    char *devicepath = argv[1];
    printf("Mouse %s movements are intercepted here .... \n", devicepath);
    int fd = open(devicepath, O_RDONLY);
    printf("File Descriptor: %d\n", fd);

    struct input_event input_event;
    read(fd, &input_event, sizeof(input_event));
    struct timeval time = input_event.time;
    printf("Event at=%lds %ldus\n", time.tv_sec, time.tv_usec);
}
