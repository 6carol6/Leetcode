//罗马数字前一个数比后一个大就加上，比后一个小减去
#include <iostream>
#include <string.h>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int sum = 0, i = 0;
		for(i = 0; s[i+1] != '\0'; i++){
			int c = letterToInt(s[i]);
			if(c >= letterToInt(s[i+1]))
				sum += c;
			else
				sum -= c;
		}
		sum += letterToInt(s[i]);
		return sum;
    }
private:
	int letterToInt(char c){
		switch(c){
			case 'I': return 1;
			case 'V': return 5;
			case 'X': return 10;
			case 'L': return 50;
			case 'C': return 100;
			case 'D': return 500;
			case 'M': return 1000;
		}
	}
};

int main(){
	Solution* a = new Solution;
	cout << a->romanToInt("CCXIV") << endl;
	return 0;	
}