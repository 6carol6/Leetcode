#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
private:
    bool symbol[10000];
    bool is_symbol(char c){
        if(c == '+' || c == '-' || c == '*') return true;
        return false;
    }
    vector<int> work(int begin, int end, const vector<int>& input){
        vector<int> ans;
        if(begin == end-1){
            ans.push_back(input[begin]);
        }
        for(int i = begin; i < end; i++){
            if(symbol[i]){
                vector<int> left = work(begin, i, input);
                vector<int> right = work(i+1, end, input);
                for(int j = 0; j < left.size(); j++){
                    for(int k = 0; k < right.size(); k++){
                        if(input[i] == '+'){
                            ans.push_back(left[j] + right[k]);
                        }
                        else if(input[i] == '-'){
                            ans.push_back(left[j] - right[k]);
                        }
                        else if(input[i] == '*'){
                            ans.push_back(left[j] * right[k]);
                        }
                    }
                }
            }
        }
        return ans;
    }
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> in;
        int num = 0;
        for(int i = 0; i < input.size(); i++){
            if(is_symbol(input[i])){
                in.push_back(num);
                num = 0;
                symbol[in.size()] = true; 
                in.push_back(input[i]);

            }else{
                num = num*10+(input[i]-'0');
            }
        }
        in.push_back(num);
        return work(0, in.size(), in);
    }
};

int main(){
    Solution* s = new Solution();
    vector<int> ans = s->diffWaysToCompute("2-1-1");
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}