#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"

/**
 *infinite_while - An endless loop function that pauses for
 *one second in each iteration.
 *Return: Always returns 0.
 */
int infinite_while(void)
{
	while (1)
	{
		sleep(1);
	}
	return (0);
}

/**
 *main - The entry point of the program.
 *This function creates five zombie processes.
 *
 *Return: Always returns 0.
 */
int main(void)
{
	int children = 0;
	pid_t pid;

	while (children < 5)
	{
		pid = fork();
		if (!pid)
			break;
		printf("Zombie process created, PID: %i\n", (int)pid);
		children++;
	}
	if (pid != 0)
	{
		infinite_while();
	}
	return (0);
}
