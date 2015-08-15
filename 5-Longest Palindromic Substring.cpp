class Solution {
private:
    string subPalindrome(string s, int l, int r){
        int len = s.length();
        while(l>=0 && r <= len && s[l] == s[r]){
            l--; r++;
        }
		l++;r--;
        return s.substr(l,r-l+1);
    }
public:
    string longestPalindrome(string s) {
        int len = s.length();
        if(len == 0) return "";
        string longestPal = s.substr(0, 1);
        for(int i = 0; i < len; i++){
            string tmp = subPalindrome(s, i, i);
            if(tmp.length() > longestPal.length()){
				longestPal = tmp;
			}
            if(s[i] == s[i+1]){
                tmp = subPalindrome(s, i, i+1);
                if(tmp.length() > longestPal.length()){
					longestPal = tmp;
				}
            }
        }
        return longestPal;
    }
};