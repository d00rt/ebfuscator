#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int
check_input(void)
{
    char input[101] = { 0 };
    char passwd[11] = "password123";
    printf("Enter a value: ");
    fgets(input, 50, stdin);

    if (strncmp(input, passwd, strnlen(passwd, 11)) == 0)
    {
        return 1;
    }
    return 0;
}

int
main(int argc, char *argv[])
{
    if (check_input() == 1)
    {
        char * valid_pass = "Well done!";
        printf("%s\n", valid_pass);
    } else
    {
        char * invalid_pass = "Try again!";
        printf("%s\n", invalid_pass);
    }

    return 0;
}
