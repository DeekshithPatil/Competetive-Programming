#include <stdio.h>
#include <stdlib.h>

int searchInsert(int* nums, int numsSize, int target);

int main()
{
    int arr[] = {0,1,2,3,4,5,6,7};

    printf("%d\n",searchInsert(arr,sizeof(arr)/sizeof(arr[0]),5));
    return 0;
}


int searchInsert(int* nums, int numsSize, int target)
{

    for(int i=0;i<numsSize;i++)
    {
        if(nums[i] >= target) //If target is less than or equal to the element at ith index in array, return i
            return i;
    }

    return numsSize; //If target was not able to be inserted in between the array, it needs to appended

}
