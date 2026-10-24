struct node{
    int value;
    int times;
    struct node* next;
};

int singleNumber(int* nums, int numsSize) {
    struct node* hash[numsSize];
    for (int i=0; i<numsSize; i++){
        hash[i]=NULL;
    }
    for (int i=0; i<numsSize; i++){
        int index= ((nums[i]%numsSize)+numsSize)%numsSize;
        struct node* curr=hash[index];
        bool found=false;
        while (curr!=NULL){
            if (curr->value==nums[i]){
                found=true;
                curr->times++;
                break;
            }
            curr=curr->next;
        }
        if (!found){
            struct node*newnode =malloc(sizeof(struct node));
            newnode->value=nums[i];
            newnode->times=1;
            newnode->next=hash[index];
            hash[index]=newnode;
        }
    }

    for (int i=0; i<numsSize; i++){
        int index= ((nums[i]%numsSize)+numsSize)%numsSize;
        struct node* curr=hash[index];
        while (curr!=NULL){
            if (curr->times==1){
                return curr->value;
            }
            curr=curr->next;
        }
    }
    return -1;
}