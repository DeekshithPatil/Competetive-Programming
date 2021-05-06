#include <stdio.h>
#include <stdlib.h>

int lengthOfLastWord(char * s);

int main()
{
    char str[] = "a ";
    printf("%d\n",lengthOfLastWord(str));
    return 0;
}

int lengthOfLastWord(char * s){

    int count = 0; //Used to hold the count of letters in word

    while(*s != '\0')
    {
        if(*s == ' ')
        {

            s++;
            if(*s != '\0' && *s!= ' ') //If a space has occured and the next element is neither a space nor a null character
                count = 0; //reset count
            continue;

        }

       /*The occured character is not a space. Thus increment the count and the pointer */
       count++;

       s++;
    }

    return count;

}
