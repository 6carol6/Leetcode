#include <memory.h>

class Solution {
private:
    int map[100][100];
    bool isBorder(int x, int y, int m, int n){
        if(x < 0 || x >= m) return true;
        if(y < 0 || y >= n) return true;
        if(x == m-1 && y == n-1) return true;
        return false;
    }
public:
    int uniquePaths(int m, int n) {
        memset(map, 0, sizeof(map));
        map[0][0] = 1;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(!isBorder(i-1, j, m, n)){
                    map[i][j] += map[i-1][j];
                }
                if(!isBorder(i+1, j, m, n)){
                    map[i][j] += map[i+1][j];
                }
                if(!isBorder(i, j-1, m, n)){
                    map[i][j] += map[i][j-1];
                }
                if(!isBorder(i, j+1, m, n)){
                    map[i][j] += map[i][j+1];
                }
            }
        }
        return map[m-1][n-1];
    }
};