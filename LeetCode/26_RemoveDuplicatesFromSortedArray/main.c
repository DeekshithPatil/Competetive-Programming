#include <stdio.h>
#include <stdlib.h>

int removeDuplicates(int* nums, int numsSize);


int main()
{
    int numbers[] = {1,1};

    int len = sizeof(numbers)/sizeof(numbers[0]);

    len = removeDuplicates(numbers,len);

    for(int i=0;i<len;i++)
        printf("%d ",numbers[i]);


    return 0;
}

int removeDuplicates(int* nums, int numsSize)
{

    int repeatedCounter = 0;

    for(int i=0;i<numsSize;i++)
    {

        /*****Loop and check how many times ith element has occured in the array**************/
        for(int j=i+1;j<numsSize;j++)
        {
            if(nums[j]!=nums[i])
                break;
            repeatedCounter++;
        }

        /*****Remove the repeated elements based on the number of times it has occured*************/
        if(repeatedCounter>0)
        {
            /*************Place (j + repeatedCOunter)th element in ith position in array*****************/
            for(int j=i+repeatedCounter;j<numsSize;j++)
            {

                nums[j-repeatedCounter] = nums[j];
            }
            numsSize-=repeatedCounter; //Reduce the lenght of the array accordingly
        }

        repeatedCounter = 0; //Reset repeatedCounter
    }

    return numsSize;

}
