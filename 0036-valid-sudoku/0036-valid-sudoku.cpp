class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //TC = O(1), SC = O(1)
        const int num = 9;
        // Initialize boolean arrays to track digits in each row, column, and subgrid
        bool row[num][num] = {false};
        bool col[num][num] = {false};
        bool subGrid[num][num] = {false};

        // Iterate through each cell in the Sudoku board
        for(int r = 0; r < num; r++)    {
            for(int c = 0; c < num; c++)    {
                // Skip empty cells
                if(board[r][c] == '.')  {
                    continue;   // if not a number, proceed to the next cell
                }
                // Convert character digit to numerical index (from 0 to 8)
                int idx = board[r][c] - '0' - 1;
                // Determine the subgrid number based on the current cell's position
                int gridNum = (r/3) * 3 + (c/3);

                // Check if the number already exists in the corresponding row, column, or subgrid
                if(row[r][idx] || col[c][idx] || subGrid[gridNum][idx])  {
                    return false;
                }
                // Update the boolean arrays for the current row, column, and subgrid with the current digit
                row[r][idx] = true;
                col[c][idx] = true;
                subGrid[gridNum][idx] = true;
            }
        }
        return true;    // if no duplicates found, the Sudoku board is valid
    }
};