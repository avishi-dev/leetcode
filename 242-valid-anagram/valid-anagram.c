bool isAnagram(char* s, char* t) {
    int hash[26]={0};
    int n= strlen(s);
    int m= strlen(t);
    if (n!=m){
        return false;
    }
    for (int i=0; i< n; i++){
        int index = s[i] - 'a';
        hash[index]++;
    }
    for (int i=0; i<m; i++){
        int index= t[i]-'a';
        bool state=false;
        if (hash[index]){
            state=true;
            hash[index]--;
        }
        if (!state){
            return false;
        }
    }
    return true;
}