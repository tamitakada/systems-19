#include <stdio.h>
#include <unistd.h>
#include <ctype.h>
#include <fcntl.h>

#include <sys/types.h>
#include <sys/stat.h>

int plumbing() {
  mkfifo("pipe_input", 0644);
  mkfifo("pipe_output", 0644);

  int fd_in = open("pipe_input", O_WRONLY);
  int fd_out = open();
  
  printf("Input something: ");
  char line[100];
  fgets(line, 100, stdin);

  write(fd, line, sizeof(line));

    int status;
    wait(&status);

    read(pipe_output[0], line, sizeof(line)
  } else {
    close(pipe_input[1]);
    close(pipe_output[0]);
    
    char input[100];
    read(pipe_input[0], input, sizeof(input));

    int i = 0;
    while (input[i]) {
      input[i] = toupper(input[i]);
      i++;
    }

    write(pipe_output[1], input, sizeof(input));
  }
}

int main() {
  plumbing();
}
