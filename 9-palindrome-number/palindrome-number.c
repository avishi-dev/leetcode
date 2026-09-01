bool isPalindrome(int x) {
    if (x<0){
        return false;
    }else{
        int original=x;
        long reversed=0;
        while (x!=0){
            reversed = (10*reversed) +(x%10);
            x=x/10;
        }
        return reversed==original;
    }
}