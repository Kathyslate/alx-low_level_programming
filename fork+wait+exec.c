#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

execute(char *cmd, char *argv[]) {
int main() {
  // this loop creates 5 processes
  for (int i = 0; i < 5; i++) {
    if (fork() == 0) {
	    execve("ls -l /tmp" + cmd, args NULL);
	    printf("Child %d, PID %d\n", i, getpid());
      sleep(i);
      exit(0);
    }
  }
  // now, all subprocesses were started

  // wait for the same number of child processes to end
  for (int i = 0; i < 5; i++) {
    wait(NULL);
  }
}
}
