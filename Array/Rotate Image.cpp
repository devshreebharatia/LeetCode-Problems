/*

You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Note:

You have to rotate the image in-place, which means you have to modify the input 
2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

Example 1:

Given input matrix = 
[
  [1,2,3],
  [4,5,6],
  [7,8,9]
],

rotate the input matrix in-place such that it becomes:
[
  [7,4,1],
  [8,5,2],
  [9,6,3]
]
Example 2:

Given input matrix =
[
  [ 5, 1, 9,11],
  [ 2, 4, 8,10],
  [13, 3, 6, 7],
  [15,14,12,16]
], 

rotate the input matrix in-place such that it becomes:
[
  [15,13, 2, 5],
  [14, 3, 4, 1],
  [12, 6, 8, 9],
  [16, 7,10,11]
]
 */

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {

        //Example
        /*
        [1,2,3],
        [4,5,6],
        [7,8,9]
         */
        
        //Solution involves first finding the transpose of the matrix
        /*
        [1,4,7],
        [2,5,8],
        [3,6,9]
         */
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<i;j++) {
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        
        //Flip the transpose to obtain the 90 degree rotated image
        /*
        [7,4,1],
        [8,5,2],
        [9,6,3]
         */
        for(int row=0 ;row<matrix.size(); row++){
            
            int start = 0;
            int end = matrix[0].size()-1;
            while(start<end){
                swap(matrix[row][start],matrix[row][end]);
                start++;
                end--;
            }
        }
    }
};