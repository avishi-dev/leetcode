int findMaxConsecutiveOnes(int* nums, int numsSize) {
    int* zero= malloc(numsSize*sizeof(int));
    int j=0;
    for (int i=0;i<numsSize;i++){
        if (nums[i]==0){
            zero[j]=i;
            j++;
        }
    }
    if (j==0){
        return numsSize;
    }
    int max=zero[0];
    for (int i=0; i<j-1; i++){
        if (max < (zero[i+1]- zero[i]- 1)){
            max = zero[i+1]-zero[i]- 1;
        }
    }
    if ((max < (numsSize-zero[j-1]-1))){
        max= numsSize-zero[j-1]-1;
    }
    return max;
}