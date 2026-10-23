/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    for (int i=0; i<numsSize; i++){
        int first= nums[i];
        for (int j=i+1; j<numsSize; j++){
            int second=nums[j];
            int sum= first+second;
            if (sum==target){
                int* result = malloc(2 * sizeof(int));
                result[0] = i;
                result[1] = j;

                *returnSize = 2;
                return result;
            }
        }
    }
    return NULL;
}