/*
Given a 2d grid map of '1's (land) and '0's (water), count the number of islands
.An island is surrounded by water and is formed by connecting adjacent lands 
horizontally or vertically. You may assume all four edges of the grid are all 
surrounded by water.

Example 1:

Input:
11110
11010
11000
00000

Output: 1
Example 2:

Input:
11000
11000
00100
00011

Output: 3

*/

/* Logic EXplanation: We are traversing through the entire matrix, and wherever 
* we find an island i.e a "1", we check its neighbours. If the neighbours are all
* 0s, in that case we return 1 and continue traversing through the matrix.
* If any of the neighbour is 1 as well, then due to recursive calls, we will end
* checking its neightbours as well. This process will continue until we reach the limit
* of the matrix or we get a "0". In this way even a large piece of island can be 
* considered only once and we will return 1 only once we have completely traversed
* through this entire continous piece of island.
* We are also marking each of these islands visited, to avoid counting the same island twice
*/

//Time Complexity: O(m*n)
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        
        if(grid.size() == 0) {
            return 0;
        }
        
        //Traversing through the matrix
        int numberOfIslands = 0;
        for(int i=0; i<grid.size(); i++) {
            for(int j=0; j<grid[i].size(); j++) {
                
                //If we find an island
                if(grid[i][j] == '1') {
                    
                    numberOfIslands = numberOfIslands + dfs(&grid,i,j);
                }
            }
        }
        return numberOfIslands;
    }
    
    int dfs(vector<vector<char>>* grid_ptr, int i,int j) {
        
        auto& grid = *grid_ptr;
        
        //If the current co-ordinate is beyond the matrix or if it is already sunken, return
        if(i<0 || j<0 || i>=grid.size() || j>=grid[i].size() || grid[i][j] == '0') {
            return 0;
        }
        
        //Sinking the current co-ordinate(its similar to marking it as visited)
        grid[i][j] = '0';
        
        //Recursive calls
        dfs(grid_ptr,i+1,j);
        dfs(grid_ptr,i-1,j);
        dfs(grid_ptr,i,j+1);
        dfs(grid_ptr,i,j-1);

        //So once a island is found, return
        return 1;
        
    }
};