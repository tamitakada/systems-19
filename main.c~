#include <stdio.h>
#include <unistd.h>
#include <ctype.h>

#include <sys/types.h>
#include <sys/wait.h>

int plumbing() {
  int pipe_input[2];
  int pipe_output[2];
  
  pipe(pipe_input);
  pipe(pipe_output);
  
  int pid = fork();
  if (pid) {
    close(pipe_input[0]);
    close(pipe_output[1]);
    
    printf("Input something: ");
    char line[100];
    fgets(line, 100, stdin);

    write(pipe_input[1], line, sizeof(line));

    int status;
    wait(&status);

    read(pipe_output[0], line, sizeof(line));
    printf("%s", line);
    
    plumbing();
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
