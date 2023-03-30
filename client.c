#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include "./libft/libft.h"

int main(int argc, char *argv[])
{
    int num = 0;
    if(argc < 3)
        write(0, "you need 2 parameters: pid, message\n", 36);
    sleep(2);
    int i = 32;
    while(--i >= 0)
    {
        printf("%lu", (2147483647 >> i) & 0x01);
        if(ft_strlen(ft_atoi(argv[2]) >> i) & 0x01)
            kill(ft_atoi(argv[1]), SIGUSR2);
        else
            kill(ft_atoi(argv[1]), SIGUSR1);
    }
    
    printf("\n\nanswer%d", num);
    // printf("%zu", ft_strlen(argv[2]));
    // while(1)
    // {
        
    // }
    // printf("%ld", (ft_strlen(argv[2]) >> 2) & 0x01);
}