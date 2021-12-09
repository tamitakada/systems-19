#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

#include <sys/types.h>
#include <sys/stat.h>

void plumbing(int fd_in, int fd_out) {
  printf("Input something: ");
  char line[100];
  fgets(line, 100, stdin);

  write(fd_in, line, sizeof(line));
  
  char output[100];
  read(fd_out, output, sizeof(output));
  printf("%s\n", output);
    
  plumbing(fd_in, fd_out);
}

int main() {
  mkfifo("pipe_input", 0644);
  mkfifo("pipe_output", 0644);
    
  int fd_in = open("pipe_input", O_WRONLY);
  int fd_out = open("pipe_output", O_RDONLY);
    
  plumbing(fd_in, fd_out);
}
