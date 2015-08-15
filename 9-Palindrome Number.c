bool isPalindrome(int x) {
        if(x < 0) return false;
        if(x == 0) return true;
        
        int base = 1;
        while(x/base >= 10){
            base *= 10;
        }
        while(x){
            if(x/base != x%10) return false;
            x -= base * (x/base);
            x /= 10;
            base /= 100;
        }
        return true;
}