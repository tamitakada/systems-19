#include <stdio.h>
#include <unistd.h>
#include <ctype.h>
#include <fcntl.h>

#include <sys/types.h>
#include <sys/stat.h>

void plumbing(int fd_in, int fd_out) {
    char input[100];
    read(fd_in, input, sizeof(input));

    int i = 0;
    while (input[i]) {
      input[i] = toupper(input[i]);
      i++;
    }

    write(fd_out, input, sizeof(input));
    
    plumbing(fd_in, fd_out);
}

int main() {
    int fd_in = open("pipe_input", O_RDONLY);
    int fd_out = open("pipe_output", O_WRONLY);
    
    plumbing(fd_in, fd_out);
}
