#define SIZE 20000

struct node{
    int value;
    struct node* next;
};

bool containsDuplicate(int* nums, int numsSize) {
    struct node* hash[SIZE]={NULL};

    for (int i=0; i<numsSize; i++){
        int index= nums[i] % SIZE;
        if (index<0){
            index= -index;
        }
        struct node* curr= hash[index];

        while (curr!=NULL){
            if (curr->value==nums[i]){
                return true;
            }
            curr=curr->next;
        }

        struct node* newnode;
        newnode=malloc(sizeof(struct node));

        newnode->value=nums[i];

        newnode->next=hash[index];
        hash[index]=newnode;
    }
    return false;
}