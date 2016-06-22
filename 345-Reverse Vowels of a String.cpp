class Solution {
private:
    bool isVowel(char c){
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
            return true;
        return false;
    }
public:
    string reverseVowels(string s) {
        vector<int> loc;
        for(int i = 0; i < s.size(); i++){
            if(isVowel(s[i])){
                loc.push_back(i);
            }
        }
        int time = loc.size()/2;
        for(int i = 0; i < time; i++){
            char tmp = s[loc[i]];
            s[loc[i]] = s[loc[loc.size()-i-1]];
            s[loc[loc.size()-i-1]] = tmp;
        }
        return s;
    }
};