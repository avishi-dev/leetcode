/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct node{
    int value;
    int arr_index;
    struct node* next;
};

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    struct node* hash[numsSize];
    for (int i = 0; i < numsSize; i++) {
        hash[i] = NULL;
    }
    for (int i=0; i<numsSize; i++){
        int need= target - nums[i];
        int index = ((need % numsSize) + numsSize) % numsSize;

        struct node* curr=hash[index];
        while (curr!=NULL){
            if (curr->value==need){
                int* result= malloc(2*sizeof(int));
                result[0]=i;
                result[1]= curr->arr_index;
                *returnSize=2;
                return result;
            }
            curr=curr->next;
        }

        int insert_index = ((nums[i] % numsSize)+numsSize)%numsSize;
        struct node* newnode;
        newnode=malloc(sizeof(struct node));

        newnode->value=nums[i];
        newnode->arr_index= i;
        newnode->next=hash[insert_index];
        hash[insert_index]=newnode;
    }
    return NULL;
}