bool canConstruct(char* ransomNote, char* magazine) {
    int hash[26]={0};
    int r= strlen(ransomNote);
    int m= strlen(magazine);
    for (int i=0; i<m; i++){
        int index = magazine[i]-'a';
        hash[index]++;
    }
    for (int i=0; i<r; i++){
        int index = ransomNote[i]-97;
        if (!hash[index]){
            return false;
        }else{
            hash[index]--;
        }
    }
    return true;
}