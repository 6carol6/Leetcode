#include <memory.h>
#include <deque>

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        int mmap[10000];
        memset(mmap, 0, sizeof(mmap));
        for(int i = 0; i < prerequisites.size(); i++){
            mmap[prerequisites[i].first]++;
        }
        deque<int> q;
        for(int i = 0; i < numCourses; i++){
            if(!mmap[i]) q.push_back(i);
        }
        int cnt = q.size();
        while(!q.empty()){
            int k = q.front();
            q.pop_front();
            for(int i = 0; i < prerequisites.size(); i++){
                if(k == prerequisites[i].second){
                    mmap[prerequisites[i].first]--;
                    if(!mmap[prerequisites[i].first]){
                        q.push_back(prerequisites[i].first);
                        cnt++;
                    }
                }
            }
        }
        //cout << cnt << endl;
        return cnt == numCourses;
    }
};