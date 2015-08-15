class Solution {
    string rom[34] = {"","I","II","III","IV","V","VI","VII","VIII","IX", "","X","XX","XXX","XL","L","LX","LXX","LXXX","XC","","C","CC","CCC","CD","D","DC","DCC","DCCC","CM","","M","MM","MMM"};
public:
    string intToRoman(int num) {
        string ans = "";
        int flag = 0;
	
        while(num){
            ans = rom[num%10+flag]+ans;
            num /= 10;
            flag+=10;
        }
        return ans;
    }
};