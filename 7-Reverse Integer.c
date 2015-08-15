int reverse(int x) {
    if(x == -2147483648) return 0;
	long long INTMAX = 2147483647;
    long long ans = 0;
    int symbol = 1;
    if(x < 0){
        symbol = -1; x = -x;
    }
    while(x){
        ans = ans*10+x%10;
		if(ans > INTMAX) return 0;
        x = x/10;
    }
    ans *= symbol;
    return ans;
}
