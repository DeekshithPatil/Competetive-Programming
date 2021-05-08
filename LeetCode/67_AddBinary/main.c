#include <stdio.h>
#include <stdlib.h>

char * addBinary(char * a, char * b);

int main()
{
    char a[] = "11";
    char b[] = "1";

    char *res = addBinary(a,b);

    printf("%s\n",res);

    free(res);
    return 0;
}



char * addBinary(char * a, char * b)
{
    int lena=0,lenb=0;
    char *s1 = a;
    char *s2 = b;
    char *res;
    int lenres;
    int carry =0,temp=0;

    /************************Find length of string 'a'************************/
    while(*a != '\0')
    {
        a++;
        lena++;
    }
    //len becomes equal to 2;
    /*************************************************************************/

    /************************Find length of string 'b'************************/
    while(*b != '\0')
    {
        b++;
        lenb++;
    }
    //len b, becomes equal to 1
    /*************************************************************************/

    /***********Allocate memory in heap for result, with length 1 greater than that of longest string**********************/
    a = s1; //reset a to base address
    b = s2; //reset b to base address

    //2 extra bytes need to be allocated than the longest string. 1 is for null character. The other is used if there is an overflow
    //Length of result becomes, 1 more than the length of longest string
    if(lena > lenb)
    {
        res = (char *)malloc((lena +1 +1) * sizeof(char));
        lenres = lena + 1;
    }

    else
    {
        res = (char *)malloc((lenb +1 +1) * sizeof(char));
        lenres = lenb + 1;
    }

    res[lenres] = '\0'; //In this case, lenres = 3 (as 2 is the longest length). Therefore 4 bytes are allocated
    //The indices reange from 0 to 3. Therefore set 3rd index index in string to NULL character
    lenres --; //Decrement the length to 2. As indices will now range from 0 to 2 (i.e 0,1,2)
    /*********************************************************************************************/

    /**************************Perform Binary Addition********************************************/
    //Loop as longs ass len res is greater than 0. i.e perform addition and insert values from 2,1
    //NOTE: addition value is inserted only at index 2 and 1. Because length of longest string is 2
    while(lenres>0)
    {
        temp = lena >0 ? a[lena-1] - '0':0; //If len a is greater than 0, temp = integer value of a(if is 1, temp is 1). Else it is 0.
        temp += lenb >0 ? b[lenb-1] - '0':0; //Same as above. But add it to temp
        temp += carry; //Add carry to temp

        if(temp == 0) //If temp is 0, it means, a, b and carry were 0. Therefore result is 0 and no carry
        {
            res[lenres] = '0';
            carry =0;
        }
        else if(temp == 1) //Only one of a,b and carry were 1. Therefore result is 1 and no carry
        {
            res[lenres] = '1';
            carry = 0;
        }
        else if(temp == 2) //Two 1s were present. This generates a carry and sum =0
        {
            res[lenres] = '0';
            carry = 1;
        }
        else if(temp == 3) //All three were 1. This generates a carry and sum = 1
        {
            res[lenres] = '1';
            carry = 1;
        }
        lenres--;
        lena--;
        lenb--;
    }
    /******************************************************************************************************************/

    /***************************Return appropriate value*********************************************/
    if(carry == 1) //If carry is still present, then overflow has occured. Result[0] is 1
    {
        res[0] = '1';
        return res;
    }

    return res + 1; //else the result[0] has no signifcance. Therefore return the address of result[1]
    /************************************************************************************************/
}
