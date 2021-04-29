#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isValid(char * s);

int main()
{
    char str[] = "]";
    bool result;

    result = isValid(str);

    //printf("%d\n",sizeof(bool));
    printf("%d\n",result);
    return 0;
}


bool isValid(char * s)
{
    char *si = s;


    long int sum = 0;

    bool unordered = false;

    char arr[10000] = "";
    int counter = 0;
    char negateValue = 0;
    char temp = 0;

    /**************************************Check whether correct type and equal number of opening brackets have occured ****************/

    while(*s!='\0')
    {
        if(*s == '(')
        {
            temp = 1;
        }
        else if(*s == '[')
        {
            temp = 2;
        }
        else if(*s == '{')
        {
            temp = 3;
        }
        else if(*s == ')')
        {
            temp = -1;
        }
        else if(*s == ']')
        {
            temp = -2;
        }
        else if(*s == '}')
        {
            temp = -3;
        }

        sum = sum + temp;

        s++;

    }

    /*******************************************************************************************************************************************/

    /*************************************************If the string is Imbalanced, exit*********************************************************/
    if(sum!=0)
    {
        return false;
    }
    /********************************************************************************************************************************************/

    /******************************Check if the balanced number of opening and closing brackets have occured in correct order********************/

    s = si; // Reinitialise pointer to start of string

    while(*s !='\0')
    {
        /* If opening brackets has occured, append its corresponding weight value into the string */
        if(*s == '(')
        {
            arr[counter] = 1;
            counter++;
            s++;
            continue;
        }
        else if(*s == '[')
        {
            arr[counter] = 2;
            counter++;
            s++;
            continue;
        }
        else if(*s == '{')
        {
            arr[counter] = 3;
            counter++;
            s++;
            continue;
        }

        /*If closing bracket has occured, check if the correct closing bracket has occured */

        if(*s == ')')
            negateValue = -1;
        else if(*s == ']')
            negateValue = -2;
        else if(*s == '}')
            negateValue = -3;

        if(counter - 1 < 0) // In case index becomes 0 it means that a closing bracket has occured before its opening bracket has occured e.g "}{"
        {
            unordered = true;
            break;
        }
        temp = arr[counter-1];
        if(temp + negateValue !=0) // the sum of opening value and closing value should be 0. Else a wrong closing bracket has occured
        {
            unordered = true;
            break;
        }

        else //correct closing bracket has occured. Check next
        {
            counter--;
            s++;
        }

    }

    /************************************************************************************************************************************************/

    /********************************************Check if Unordered flag is set*********************************************************************/

    if(unordered)
        return false;
    else
        return true;

    /************************************************************************************************************************************************/
}
