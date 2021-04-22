#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b, c;
    fflush(stdout);//Clears the stdout buffer
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
    fflush(stdout);//Clears the stdout buffer
    scanf("%d %d %d", &a, &b, &c);
    printf("Values entered: %d %d %d\n", a, b, c);
    return EXIT_SUCCESS;
}
