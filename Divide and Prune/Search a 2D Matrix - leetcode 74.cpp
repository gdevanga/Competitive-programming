// Problem Description at https://leetcode.com/problems/search-a-2d-matrix/

// C++ Solution : 9th feb 2020
class Solution {
public:
    bool searchMatrix1(vector<vector<int>>& matrix, int search)
    {
        int ROW = matrix.size();
        int COL = matrix[0].size();
        for (int i = 0; i < ROW; ++i)
        {
            for (int j = 0; j < COL; ++j)
            {
                if (matrix[i][j] ==  search)
                    return true;
            }
        }
        return false;
    }

    bool searchMatrix2(vector<vector<int>>& matrix, int search)
    {
        int ROW = matrix.size();
        int COL = matrix[0].size();
        for (int i = 0; i < ROW; ++i)
        {
            if (matrix[i][COL-1] >= search)
            {
                // search in that row
                for (int j = 0; j < COL; ++j)
                    if (matrix[i][j] == search)
                        return true;
            }
        }
        return false;
    }

    bool auxmatrixSearch3(vector<int> matrix, int search)
    {
        int COL = matrix.size();
        int low = 0; int high = COL;
        while (low < high)
        {
            int mid = low + (high-low)/2;
            if (matrix[mid] == search)
                return true;
            else if (matrix[mid] > search)
                high = mid-1;
            else
                low = mid+1;
        }
        if (matrix[low] == search)
            return true;
        else
            return false;
    }

    bool searchMatrix3(vector<vector<int>>& matrix, int search)
    {
        int ROW = matrix.size();
        int COL = matrix[0].size();
        // find ceil row by binary search
        int low = 0, high = ROW;
        while (low < high-1)
        {
            int mid = low + (high-low)/2;
            if (matrix[mid][COL-1] == search)
                return true;
            else if (matrix[mid][COL-1] > search)
                high = mid;
            else
                low = mid;
        }
        if (matrix[low][COL-1] < search)
            return auxmatrixSearch3 (matrix[high], search);
        else
            return auxmatrixSearch3 (matrix[low], search);
    }

    bool searchMatrix(vector<vector<int>>& matrix, int search)
    {
        int ROW = matrix.size();
        if (ROW < 1) return false; 
        int COL = matrix[0].size();
        if (COL < 1) return false; 
        int low = 0;
        int high = ROW*COL -1;

        while (low < high)
        {
            int mid = low + (high-low)/2;
            if (matrix[mid/COL][mid%COL] == search)
                return true;
            else if (matrix[mid/COL][mid%COL] > search)
                high = mid-1;
            else
                low = mid+1;
            }
            if (matrix[low/COL][low%COL] == search)
                return true;
            else
                return false;
        }
    };


