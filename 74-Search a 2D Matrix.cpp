class Solution {
private:
    int binarySearchRow(vector<vector<int>>& matrix, int target, int left, int right){
        if(left == right) return left;
        int mid = (left+right)/2;
        if(matrix[mid][0] > target) return binarySearchRow(matrix, target, left, mid-1);
        else if(matrix[mid][0] < target) return binarySearchRow(matrix, target, mid+1, right);
        else return mid;
    }
    bool binarySearchColumn(vector<int>& vec, int target, int left, int right){
        if(left > right) return false;
        int mid = (left+right)/2;
        if(vec[mid] == target) return true;
        else if(vec[mid] > target) return binarySearchColumn(vec, target, left, mid-1);
        else return binarySearchColumn(vec, target, mid+1, right);
    }
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = binarySearchRow(matrix, target, 0, matrix.size()-1);
        cout << row<<endl;
        return binarySearchColumn(matrix[row], target, 0, matrix[row].size()-1);
    }
};