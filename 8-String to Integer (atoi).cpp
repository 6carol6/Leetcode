class Solution {
public:
    int myAtoi(string str) {
        int i = 0;
        int symbol = 0;
        int start = 0, end = 0;
        long long int_max = 2147483647;
        long long int_min = -2147483648;
        long long ans = 0;
        while(str[i] != '\0'){
            if(str[i]-'0'>=0 && str[i]-'0'<10){
                if(start){
                    ans = ans*10+(str[i]-'0');
                    if(ans > int_max){
                        if(symbol == 2) return int_min;
                        else return int_max;
                    }
                }else{
                    if(symbol == 0){
                        start = 1;
                        ans = str[i]-'0';
                    }else{
                        return 0;
                    }
                }
                end = 1;
            }
            else if(!start && (str[i]=='+' || str[i]=='-')){
                start = 1;
                if(str[i]=='-') symbol = 2;
                else symbol = 1;
            }
            else{
                if(end){
                    if(symbol==2) ans = -ans;
                }
                if(str[i] == ' ' && !start){
					i++; continue;
				}
                return ans;
            }
            i++;
        }
        if(!start) return 0;
        if(symbol==2) ans = -ans;
        return ans;
    }
};