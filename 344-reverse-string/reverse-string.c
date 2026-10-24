void swap(char *x, char *y){
    char temp;
    temp=*x;
    *x=*y;
    *y=temp;
}
void reverseString(char* s, int sSize) {
    for (int i=0; i<sSize/2; i++){
        swap(&s[i],&s[sSize-i-1]);
    }
}