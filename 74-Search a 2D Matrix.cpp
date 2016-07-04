class Solution {
private:
    int binarySearchRow(vector<vector<int>>& matrix, int target, int left, int right){
        if(left >= right-1) return right-1;
        int mid = (left+right)/2;
        if(matrix[mid][0] > target) return binarySearchRow(matrix, target, left, mid);
        else if(matrix[mid][0] < target) return binarySearchRow(matrix, target, mid, right);
        else return mid;
    }
    bool binarySearchColumn(vector<int>& vec, int target, int left, int right){
        if(left > right-1) return false;
        int mid = (left+right)/2;
        if(vec[mid] == target) return true;
        else if(vec[mid] > target) return binarySearchColumn(vec, target, left, mid);
        else return binarySearchColumn(vec, target, mid+1, right);
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = binarySearchRow(matrix, target, 0, matrix.size());
        if(row == -1 || row == matrix.size()) return false;
        return binarySearchColumn(matrix[row], target, 0, matrix[row].size());
    }
};