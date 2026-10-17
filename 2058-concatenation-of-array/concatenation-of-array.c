/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getConcatenation(int* nums, int numsSize, int* returnSize) {
    int* ans= malloc(numsSize*2*sizeof(int));
    for (int i=0; i< numsSize*2; i++){
        ans[i]=nums[i%numsSize];
    }
    *returnSize= numsSize*2;
    return ans;
}