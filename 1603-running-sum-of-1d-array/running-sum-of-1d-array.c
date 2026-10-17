/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* runningSum(int* nums, int numsSize, int* returnSize) {
    int* ans=malloc(numsSize*sizeof(int));
    ans[0]=nums[0];
    for (int i=1;i<numsSize;i++){
        ans[i]=nums[i]+ans[i-1];
    }
    *returnSize=numsSize;
    return ans;
}