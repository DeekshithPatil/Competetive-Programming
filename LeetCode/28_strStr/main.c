#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int strStr(char * haystack, char * needle);

int main()
{
    char haystack []= "";
    char needle [] = "";

    int returnValue = strStr(haystack,needle);

    printf("%d\n",returnValue);
    return 0;
}


int strStr(char * haystack, char * needle)
{
    int startIndex = 0;
    bool notFound = false;
    char *haystackStart;
    char *needleStart;

    /*****************if needle is empty string, then return 0************************/
    if(*needle == '\0')
        return 0;

    /*****************Check the occurence of needle in haystack character by character******/
    while(*haystack != '\0')
    {

        if(*needle == *haystack)
        {
            haystackStart = haystack; //Make a copy of current value of haystack
            needleStart = needle; //Make a copy of current valye of needle

            while((*needleStart!='\0'))
            {

                if(*haystackStart != *needleStart) //if values are not same, then break by setting notFound flag
                {
                    notFound = true;
                    break;
                }
                haystackStart++;
                needleStart++;
            }

            if(!notFound) //If match has occurred, that is if the above loop is completed successfully without breaking out
            {
                return startIndex; //return the index at which it has occured
            }
        }

        notFound = false;  //Reset flag
        startIndex++;
        haystack++;
    }
    /*******************Return -1 if match has not occurred***************************/
    return -1; //If control has reached till here, it means that the comparisons are complete and no match was found. Thus return -1;

}
