void swap (int *x, int *y){
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}

void moveZeroes(int* nums, int numsSize) {
    int *p1 = nums;
    int *p2 = nums;
    while (p1< nums+numsSize && p2< nums+numsSize ){
        while (p1<nums+numsSize && *p1!=0){
            p1++;
        }

        if (p1 == nums + numsSize) {
            break;
        }

        p2=p1+1;

        while (p2<nums+numsSize && *p2==0){
            p2++;
        }

        if (p2 == nums + numsSize) {
            break;
        }

        swap(p1,p2);
        p1++;
    }
}