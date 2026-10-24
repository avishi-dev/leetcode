bool canConstruct(char* ransomNote, char* magazine) {
    int hash[26]={0};
    int r= strlen(ransomNote);
    int m= strlen(magazine);
    if (r>m){return false;}
    for (int i=0; i<m; i++){
        int index = magazine[i]-'a';
        hash[index]++;
    }
    for (int i=0; i<r; i++){
        int index = ransomNote[i]-'a';
        if (!hash[index]){
            return false;
        }
        hash[index]--;
    }
    return true;
}