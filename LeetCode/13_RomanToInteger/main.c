#include <stdio.h>
#include <stdlib.h>



int romanToInt(char * s);

int main()
{
    char str[] = "MCMXCIV";
    int ret;
    ret = romanToInt(str);
    printf("\nInteger value = %d",ret);
    return 0;
}




int romanToInt(char * s){

    int value = 0;
    char *temp;

    while(*s !='\0')
    {
        if(*s == 'I')
        {
            temp =s;
            temp++;
            if(*(temp) == 'V') //i.e IV has occured
            {
                value += 4;
                //temp =s;
                s++;
            }
            else if(*(temp) == 'X') //IX has occured
            {
                value += 9;
                //temp = s;
                s++;
            }
            else //only I has occured
            {
                value += 1;
            }
        }
        else if(*s == 'V')
        {
            value += 5;
        }
        else if(*s == 'X')
        {
            temp = s;
            temp++;
            if(*(temp) == 'L') //XL
            {
                value += 40;
                //temp =s;
                s++;
            }
            else if(*(temp) == 'C') //XC
            {
                value += 90;
                //temp =s;
                s++;
            }
            else//X
            {
                value += 10;
            }
        }
        else if(*s == 'L')
        {
            value +=50;
        }
        else if(*s == 'C')
        {
            temp = s;
            temp++;
            if(*(temp) == 'D') //CD
            {
                value += 400;
                //temp = s;
                s++;
            }
            else if(*(temp) == 'M') //CM
            {
                value += 900;
                //temp = s;
                s++;
            }
            else //C
            {
                value +=100;
            }
        }
        else if(*s == 'D')
        {
            value +=500;
        }
        else if(*s == 'M')
        {
            value += 1000;
        }

        s++; //Point to the next element
    }


    return value;

}
