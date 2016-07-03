class Solution {
private:
    
    int min(vector<int>& ans, vector<int>& idx, vector<int>& primes){
        int m = 1100000000;
        //int index = 0;
        for(int i = 0; i < idx.size(); i++){
            if(m > (ans[idx[i]]*primes[i])){
                m = ans[idx[i]]*primes[i];
          //      index = i;
            }
        }
        for(int i = 0; i < idx.size(); i++){
            if(m == ans[idx[i]]*primes[i]) idx[i]++;
        }
        //idx[index]++;
        return m;
    }
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> ans;
        vector<int> idx(primes.size(), 0);
        ans.push_back(1);
        
        for(int i = 1; i < n; i++){
            ans.push_back(min(ans, idx, primes));
        }
        return ans[n-1];
    }
};