#include <stdio.h>
#include <signal.h>
#include <unistd.h>

static int character[2];

void handler1(int signum){
	if(signum == SIGUSR1)
	if(character[1] == 0)
	{
		character[1] = 31;
		write(0, &character[0], 1);
		character[0] = 0;
	}
	else
		character[1]--;
}

void handler2(int signum){
		character[0] |= 1UL << character[1];
	if(character[1] == 0)
	{
		character[1] = 31;
		write(0, &character[0], 1);
		 	character[0] = 0;

	}	
	else
		character[1]--;
}

int main (int argc, char *argv[])
{
	character[0] = 0;
	character[1] = 31;
    struct sigaction	sa1;
	struct sigaction	sa2;
	int					i;
	int					num;
	char				c;
	void				*ptr;
	
    sa1.sa_handler = handler1;
	sa2.sa_handler = handler2;
	num = 0;

	printf("pid: %d\n", (int) getpid());
	
  	if(sigaction(SIGUSR2, &sa2, NULL) == -1)
        perror("SIGACTION");
	else
	if(sigaction(SIGUSR1, &sa1, NULL) == -1)
        perror("SIGACTION");
    while (1)
    {
		// if(character[1] == 7)
		// 	write(0, &character[0], 1);
		// printf("%d", character[0]);
		// if(character[2] == -2147483647)
		// 	kill(argv[2], SIGUSR2);
    }
}