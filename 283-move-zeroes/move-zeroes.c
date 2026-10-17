void swap (int *x, int *y){
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}

void moveZeroes(int* nums, int numsSize) {
    for (int i=0; i<numsSize; i++){
        if (nums[i]==0){
            int j=i+1;
            while (j<numsSize && nums[j]==0){
                j++;
            }
            if (j<numsSize){
                swap (&nums[i], &nums[j]);
            }
        }

    }
}