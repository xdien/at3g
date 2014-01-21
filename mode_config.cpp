#include "mode_config.h"

mode_config::mode_config()
{
    int fd; // file descriptor
    int flags; // communication flags
    int rsl_len; // result size
    char message; // message to send
    char result; // result to read
    int open_p()
    {
        flags = O_RDWR | O_NOCTTY;
        if ( (fd = open("/dev/ttyUSB1", flags)) >= 0 ){
          printf("Error while opening\n");
    }
}
