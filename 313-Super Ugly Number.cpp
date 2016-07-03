class Solution {
private:
    int min(vector<vector<int>>& vec){
        int m = 1000001;
        for(int i = 0; i < vec.size(); i++){
            if(vec[i][0] < m) m = vec[i][0];
        }
        for(int i = 0; i < vec.size(); i++){
            if(m == vec[i][0]) vec[i].erase(vec[i].begin());
        }
        return m;
    }
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<vector<int>> list;
        for(int i = 0; i < primes.size(); i++){
            vector<int> tmp;
            tmp.push_back(1);
            list.push_back(tmp);
        }
        int ans = 1;
        while(n--){
            int ans = min(list);
            for(int i = 0; i < primes.size(); i++){
                list[i].push_back(ans*primes[i]);
            }
        }
        return ans;
    }
};