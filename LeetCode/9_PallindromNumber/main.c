#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isPalindrome(int x);

int main()
{
    bool  returnValue;
    returnValue = isPalindrome(121);
    printf("%d\n",returnValue);
    return 0;
}



bool isPalindrome(int x){
    int temp;
    temp =x;
    if(x<0)
        return false;
    else if(x == 0)
        return true;
    else
    {
       int reverseNumber = 0;

        while(x)
        {
            reverseNumber = reverseNumber * 10 + x%10;
            x = x/10;
        }
        x = temp;

        if(reverseNumber == x)
            return true;
        else
            return false;
    }

}
