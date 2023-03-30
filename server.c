#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handler1(int signum){

}

void handler2(int signum){

}

int main (void)
{
    struct sigaction	sa1;
	struct sigaction	sa2;
	int					i;
	int					num;
	char				c;
	
    sa1.sa_handler = handler1;
	sa2.sa_handler = handler2;
	num = 0;

	printf("pid: %d\n", (int) getpid());
	pause();
	i = 32;
    while(--i >= 0)
	{
		if(sigaction(SIGUSR2, &sa2, NULL) == -1)
            perror("SIGACTION");
		else
			// num |= 1UL << i;
			printf("1");
		if(sigaction(SIGUSR1, &sa1, NULL) == -1)
            perror("SIGACTION");
		else
			printf("0");
		printf("inside\n");
	}

	printf("%d", num);
  
    // while (1)
    // {
    //     if(sigaction(SIGUSR2, &sa2, NULL) == -1)
    //         perror("SIGACTION");
    // }
}