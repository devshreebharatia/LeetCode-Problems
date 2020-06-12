
/*
Given a m x n matrix, if an element is 0, set its entire row and column to 0. 
Do it in-place.

Example 1:

Input: 
[
  [1,1,1],
  [1,0,1],
  [1,1,1]
]
Output: 
[
  [1,0,1],
  [0,0,0],
  [1,0,1]
]
Example 2:

Input: 
[
  [0,1,2,0],
  [3,4,5,2],
  [1,3,1,5]
]
Output: 
[
  [0,0,0,0],
  [0,4,5,0],
  [0,3,1,0]
]
Follow up:

A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?
 */


class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        
        //Solution 1: Space Complexity O(m+n)
        if(matrix.size() == 0) return;
        
        vector<int> zeroRows;
        vector<int> zeroColumns;
        
        //Obtain the row and column numbers that contain zeros
        for(int i=0;i<matrix.size();i++) {
            for(int j=0;j<matrix[0].size();j++) {
                
                if(matrix[i][j] == 0) {
                    zeroRows.push_back(i);
                    zeroColumns.push_back(j);
                }
            }
        }
        
        //For those column row numbers set all the columns as zero
        for(int i=0;i<zeroRows.size();i++) {
            int row = zeroRows[i];
            for(int j=0;j<matrix[0].size();j++) {
                matrix[row][j] = 0;
            }
        }
        
        //For those row numbers set all the rows as zero
        for(int j=0;j<zeroColumns.size();j++) {
            int col = zeroColumns[j];
            for(int i=0;i<matrix.size();i++) {
                matrix[i][col] = 0;
            }
        }
        
        //Solution 2: Space Complexity: O(1)

        //First check the first rows and columns. If they have any zeros, set 
        //flags for latter modification
        bool firstRow = false, firstCol = false;
        for(int r=0;r<matrix.size();r++) {
            if(matrix[r][0] == 0) {
                firstCol =  true;
            }
        }
        for(int c=0;c<matrix[0].size();c++) {
            if(matrix[0][c] == 0) {
                firstRow = true;
            }
        }
        //Now traverse through the entire matrix(other than first row and column)
        //and for every zero element set its corresponding first row element and 
        //first column element zero
        for(int r=1;r<matrix.size();r++) {
            for(int c=1;c<matrix[0].size();c++) {
                if(matrix[r][c] == 0) {
                    
                    matrix[0][c] = 0;
                    matrix[r][0] = 0;
                    
                }
            }
        }
        //For row 0 and all columns check which column is 0
        //For that column, all the rows should be made 0
        for(int c=1;c<matrix[0].size();c++) {
            if(matrix[0][c] == 0) {
                
                for(int r=1;r<matrix.size();r++) {
                    
                    matrix[r][c] = 0;
                }
                
            }
        }
        //For column 0 and all rows check which row is 0
        //For that row, all the columns should be made 0
        for(int r=1;r<matrix.size();r++) {
            if(matrix[r][0] == 0) {
                
                for(int c=1;c<matrix[0].size();c++) {
                    
                    matrix[r][c] = 0;
                }
                
            }
        }
        //Now consider the firstRow and firstColumn flags
        if(firstRow) {
            for(int c=0;c<matrix[0].size();c++) {
                matrix[0][c] = 0;
            }
        }
            
        if(firstCol) {
            for(int r=0;r<matrix.size();r++) {
                matrix[r][0] = 0;
            }
        }
    }
};