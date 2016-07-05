//recursive
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

//non-recursive
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0)     return false;
		if (matrix[0][0] > target)  return false;
        int left = 0, right = matrix.size();
        if(right == 0) return false;
        while(left < right-1){
            int mid = (left+right)/2;
            if(matrix[mid][0] == target) {return true;}
            else if(matrix[mid][0] > target) right = mid;
            else left = mid; 
        }
        if(left == -1 || left == matrix.size()) return false;
  
        int row = left; left = 0, right = matrix[0].size();
        while(left < right){
            int mid = (left+right)/2;
            if(matrix[row][mid] == target) return true;
            else if(matrix[row][mid] > target) right = mid;
            else left = mid+1;
        }
        return false;
    }
};