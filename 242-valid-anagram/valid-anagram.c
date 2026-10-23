struct node {
    char value;
    struct node* next;
};

bool isAnagram(char* s, char* t) {
    if (strlen(s) == strlen(t)) {
        if (strlen (s)== 0) { return true; }
        else {
            struct node* hash[strlen(s)];
            for (int i = 0; i < strlen(s); i++) {
                hash[i] = NULL;
            }
            for (int i = 0; i < strlen(s); i++) {
                int index = ((s[i] % strlen(s)) + strlen(s)) % strlen(s);
                struct node* newnode;
                newnode = malloc(sizeof(struct node));
                newnode->value = s[i];
                newnode->next = hash[index];
                hash[index] = newnode;
            }
            for (int j = 0; j < strlen(t); j++) {
                int index = ((t[j] % strlen(s)) + strlen(s)) % strlen(s);
                struct node* curr = hash[index];
                struct node* prev=NULL;
                bool found=false;
                while (curr != NULL) {
                    if (curr->value == t[j]){
                        found = true;
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
                if (!found){
                    return false;
                }
            }
            return true;
        }
    }
    return false;
}