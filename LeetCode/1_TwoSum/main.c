#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize);

int main()
{
    int arr[] = {3,2,4};
    int target = 6;
    int returnSize;
    int arrayLength = sizeof(arr) / sizeof(arr[0]);

    int *returnedArray;
    returnedArray = twoSum(arr,arrayLength,target,&returnSize);
    for(int i=0;i<returnSize;i++)
    {
        printf("%d ",returnedArray[i]);
    }
    free(returnedArray);
    return 0;
}


int* twoSum(int* nums, int numsSize, int target, int* returnSize){

    int *returnArray;
    returnArray = (int *) malloc((2) * (sizeof(int)));
    int breakFlag = 0;

    *returnSize = 2;

    for(int i=0; i<numsSize; i++)
    {
        for(int j=i+1;j<numsSize;j++)
        {
            if(nums[i] + nums[j] == target)
            {
                returnArray[0] = i;
                returnArray[1] = j;
                breakFlag = 1;
                break;
            }
        }
        if(breakFlag)
        {
            break;
        }
    }

    return (returnArray);

}
