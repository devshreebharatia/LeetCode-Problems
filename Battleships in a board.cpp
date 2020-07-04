/*
Given an 2D board, count how many battleships are in it. The battleships are 
represented with 'X's, empty slots are represented with '.'s. You may assume the 
following rules:
You receive a valid board, made of only battleships or empty slots.
Battleships can only be placed horizontally or vertically. In other words, they 
can only be made of the shape 1xN (1 row, N columns) or Nx1 (N rows, 1 column), 
where N can be of any size.
At least one horizontal or vertical cell separates between two battleships - 
there are no adjacent battleships.

Example:
X..X
...X
...X
In the above board there are 2 battleships.

Invalid Example:
...X
XXXX
...X
This is an invalid board that you will not receive - as battleships will always 
have a cell separating between them.
Follow up:
Could you do it in one-pass, using only O(1) extra memory and without modifying 
the value of the board?

*/

class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        
        /* Solution 1: Using depth first search for recursively travelling through
        *  all the left,right,bottom,up positions and returning only once for one
        *  such continuous island. Sinking the co-ordinates in the process to avoid
        *  revisiting them.
        */
        if(board.size() == 0) {
            return 0;
        }
        int numberOfBoardships = 0;
        for(int i=0;i<board.size();i++) {
            for(int j=0;j<board[i].size();j++) {
                if(board[i][j] == 'X') {
                    //recursiveCounting funstion defined at the bottom
                    numberOfBoardships = numberOfBoardships + recursiveCounting(&board,i,j);
                }
            }
        }
        return numberOfBoardships;



        /* Solution 2: As we know that the left or upper co-ordinates will be already
        *  visited/checked, we must check if the co-ordinates to the right or down
        *  are 'X' or not. If yes, then sink the current co-ordinate and continue 
        *  to avoid counting the current co-ordinate. If the current co-ordinate is
        * '.', again continue.
        */
        if(board.size() == 0) {
            return 0;
        }
        
        int numberOfBoardships = 0;
        for(int i=0;i<board.size();i++) {
            for(int j=0;j<board[i].size();j++) {
                if(board[i][j] == '.') {
                    continue;
                }
                if(i<board.size()-1 && board[i+1][j] == 'X') {
                   board[i][j] = '.';
                   continue;
                }
                if(j<board[i].size()-1 && board[i][j+1] == 'X') {
                    board[i][j] = '.';
                    continue;
                }
                numberOfBoardships++;
            }
        }
        return numberOfBoardships;

        /* Solution 3: As we know that the left or upper co-ordinates will be already
        *  visited/checked. So in this case, if a left or upper co-ordinate is 'X'
        *  it signifies that we have already counted that board. Hence we simply
        *  continue. If the current co-ordinate is '.', again continue.
        */
        if(board.size() == 0) {
            return 0;
        }
        
        int numberOfBoardships = 0;
        for(int i=0;i<board.size();i++) {
            for(int j=0;j<board[i].size();j++) {
                if(board[i][j] == '.') {
                    continue;
                }
                if(i>0 && board[i-1][j] == 'X') {
                    continue;
                }
                if(j>0 && board[i][j-1] == 'X') {
                    continue;
                }
                numberOfBoardships++;
            }
        }
        return numberOfBoardships;


        /*
        Difference between the solutions 2 and 3

        In solution 2, we are sinking the current 'X' if it is surrounded by any 'X'
        at the right or bottom, so that the counting will be done at the end, when the
        continuous board terminates.

        In solution 3, we are counting the island first, and then avoiding counting,
        if left or upper co-ordinate has 'X'

        */
    }
    
    int recursiveCounting(vector<vector<char>> *board_ptr, int i, int j) {
        
        auto& board = *board_ptr;
        //In a recursion first specify the terminating condition
        if(i<0 || i>=board.size() || j<0 || j>=board[i].size() || board[i][j] == '.') {
            return 0;
        }
        
        //Sink the current co-ordinate
        board[i][j] = '.';
        
        //Traverse through all other directions
        recursiveCounting(board_ptr,i-1,j);
        recursiveCounting(board_ptr,i+1,j);
        recursiveCounting(board_ptr,i,j-1);
        recursiveCounting(board_ptr,i,j+1);
        return 1;
    }

};
