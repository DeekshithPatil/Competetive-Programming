#include <stdio.h>
#include <stdlib.h>

int removeElement(int* nums, int numsSize, int val);

int main()
{
    int nums[] = {3,2,2,3};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int val = 3;

    numsSize = removeElement(nums,numsSize,val);

    for(int i=0;i<numsSize;i++)
    {
        printf("%d ",nums[i]);
    }

    return 0;
}

int removeElement(int* nums, int numsSize, int val)
{
    int repeatedCounter = 0;

    for(int i=0;i<numsSize;i++)
    {
        /*****Check how many times continuously val has occured********/
        for(int j=i;j<numsSize;j++)
        {
            if(nums[j]!=val)
                break;
            repeatedCounter++;
        }
        /*****If val has occured atleast once, then start removing it*****/

        if(repeatedCounter>0)
        {
            for(int j=i+repeatedCounter;j<numsSize;j++)
            {
                nums[j-repeatedCounter] = nums[j]; //Shifting the values in array from J to (J-repeatedCounter)th position
            }
            numsSize-=repeatedCounter; //Reduce the length of array by repeated counter value
        }

        repeatedCounter = 0; //Reset repeated counter
    }
    return numsSize;

}
