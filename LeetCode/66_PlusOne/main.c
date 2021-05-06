#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int* plusOne(int* digits, int digitsSize, int* returnSize);

int main()
{
    int arr[] = {1,0,9};
    int digitsSize = sizeof(arr) / sizeof(arr[0]);
    int resultLen;

    int *resultArray = plusOne(arr,digitsSize,&resultLen);


    for(int i=0;i<resultLen;i++)
        printf("%d \n",resultArray[i]);
    return 0;
}

int* plusOne(int* digits, int digitsSize, int* returnSize)
{
    int * arr = (int *) malloc ((digitsSize + 1) * sizeof(int)); //allocate size is 1 more than that of received array size
    bool additionComplete = false; //Flag to indicate whether addition of 1 was completed

    if(digits[digitsSize - 1] < 9) //If last digit in the received array is less than 9, than add 1 to it and return the array
    {
        digits[digitsSize - 1] +=1;
        *returnSize = digitsSize;
        return digits;
    }

    for(int i=digitsSize-1;i>=0;i--)
    {
        if( (digits[i]<9) && (!additionComplete) ) //Check if the digit at i th position is less than 9 and addition is not complete
        {
            arr[i+1] = digits[i]+1; //Add 1 to the element and store it at i+1 th position in result array
            additionComplete = true; //Set addition complete flag
        }

        else if( (digits[i] == 9) && (!additionComplete) )
        {
            arr[i+1] = 0; //If digit is equal to 9 and addition has not been complete, make the i+1 th element in the resulting array 0
        }

        else
        {
            arr[i+1] = digits[i]; //If none of the above condition has occurred, copy the i th digit into i+1 th position, as it is
        }

    }

    if(additionComplete) //If addition flag was set, it means 1 was added to the received array successfully.
    {
        *returnSize = digitsSize; //Set the result array length to be the length of array received
        return(&arr[1]); //Since in this case the arr[0] is not used, resulting array holds values only from arr[1]
    }

    else //It means addition was not completed because all the elements received were 9. E.g [9,9,9]. Therefore Result should be [1,0,0,0]
    {
        arr[0] = 1; //Set the first element in the resulting array as 1
        *returnSize = digitsSize+1; //Set the length of resulting array as length of received array + 1;
        return(&arr[0]); //return the address of 0th element in the array;
    }

}
