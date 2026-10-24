/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
struct node{
    int value;
    struct node* next;
};

int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int n= fmax(nums1Size, nums2Size);
    struct node* hash[n];
    for (int i=0; i<n; i++){
        hash[i]=0;
    }

    for (int i=0; i<nums1Size; i++){
        int index= ((nums1[i]%n)+n)%n;
        struct node* curr=hash[index];
        bool found=false;
        while(curr!=NULL){
            if (curr->value==nums1[i]){
                found =true;
                break;
            }
            curr=curr->next;
        }
        if (!found){
            struct node* newnode;
            newnode= malloc(sizeof(struct node));
            newnode->value=nums1[i];
            newnode->next=hash[index];
            hash[index]=newnode;
        }
    }

    int* result = malloc(nums2Size*sizeof(int));
    int j=0;
    for (int i=0; i<nums2Size; i++){
        int index= ((nums2[i]%n)+n)%n;
        struct node* curr=hash[index];
        struct node* prev=NULL;
        while (curr!=NULL){
            if (curr->value==nums2[i]){
                result[j++]=nums2[i];
                if (prev==NULL){
                    hash[index]=curr->next;
                }else{
                    prev->next=curr->next;
                }
                free(curr);
                break;
            }
            prev=curr;
            curr=curr->next;
        }
    }
    *returnSize=j;
    return result;

}