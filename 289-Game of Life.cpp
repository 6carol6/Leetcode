class Solution {
private:
    int n, m;
    bool judge(int i, int j){
        if(i >= n || i < 0 || j >= m || j < 0) return false;
        return true;
    }
    void is_alive(vector<vector<int>>& board, int x, int y){
        int alive_neighbour = 0, dead_neighbour = 0;
        for(int i = x-1; i <= x+1; i++){
            for(int j = y-1; j <= y+1; j++){
                if(judge(i, j) && !(i == x && j == y)){
                    if(board[i][j] & 0x01 == 1)
                        alive_neighbour++;
                    else
                        dead_neighbour++;
                }
            }
        }
        if(board[x][y] == 1){
            if(alive_neighbour == 2 || alive_neighbour == 3){
                board[x][y] = 3;
            }
        }
        else if(alive_neighbour == 3){
            board[x][y] = 2;
        }
    }
public:
    void gameOfLife(vector<vector<int>>& board) {
        n = board.size();
        for(int i = 0; i < n; i++){
            m = board[0].size();
            for(int j = 0; j < m; j++){
                is_alive(board, i, j);
            }
        }
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(board[i][j]>>1 == 1){
                    board[i][j] = 1;
                }else{
                    board[i][j] = 0;
                }
            }
        }
    }
};