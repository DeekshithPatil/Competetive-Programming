#include <stdio.h>
#include <stdlib.h>

int maxSubArray(int* nums, int numsSize);

int main()
{
    int arr[] = {5,4,-1,7,8};
    printf("%d\n", maxSubArray(arr,sizeof(arr)/sizeof(arr[0])));
    return 0;
}

int maxSubArray(int* nums, int numsSize){

    int max=nums[0];
    int tempmax = 0;

    if(numsSize == 1)
        return nums[0];

    for(int i=0;i<numsSize;i++)
    {
        for(int j=i;j<numsSize;j++)
        {
            tempmax+=nums[j];

            if(tempmax>max)
                max = tempmax;
        }
        tempmax = 0;
    }

    return max;

}
