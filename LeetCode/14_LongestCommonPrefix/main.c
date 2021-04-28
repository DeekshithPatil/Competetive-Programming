#include <stdio.h>
#include <stdlib.h>

#define stringSize          3

//char returnString[200] = "";


char * longestCommonPrefix(char ** strs, int strsSize);


int main()
{
    //int stringSize = 3;
    char *pointer[stringSize] = {"dog","racecar","car"};
    char *returnedPointer;

    returnedPointer = longestCommonPrefix(pointer,stringSize);

    printf("\n%s",returnedPointer);

    free(returnedPointer);

    return 0;
}

char * longestCommonPrefix(char ** strs, int strsSize)
{
    char returnStringCounter = 0;
    char temp,temp2;
    char *p[strsSize];
    char stopFlag = 0;
    //char *returnPointer;
    char *returnString = (char *) malloc(200 * sizeof(char));

    for(int i=0;i<strsSize;i++)
    {
        p[i] = *strs;
        strs++;
    }

    while(!stopFlag)
    {
        temp = *(p[0]);

        for(int i=1;i<strsSize;i++)
        {
            temp2 = *(p[i]);
            if((temp!= temp2) || (temp2 == '\0'))
            {
                stopFlag = 1;
                break;
            }
        }
        if(stopFlag == 1)
        {
            break;
        }
        else
        {
            returnString[returnStringCounter] = *(p[0]);
            returnStringCounter++;
            for(int i=0;i<strsSize;i++)
            {
                p[i]++;
            }
        }
    }

    returnString[returnStringCounter] = '\0';

    return (returnString);
}
