#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	main()
{
	pid_t child_pid = fork();
	int	stat;

	if (child_pid == 0)
	{
		printf("Child----\nCurrent PID: %d and Child PID: %d\n", getpid(), child_pid);		
		sleep(1);
	}
	else
	{
		printf("Parent---\nCurrent PID %d and Child PID: %d\n", getpid(), child_pid);
		waitpid(child_pid, &stat, 0);
	}
	return (0);
}
