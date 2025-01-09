class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int dx[8] = {0,0,-1,1,-1,-1,1,1};
        int dy[8] = {1,-1,0,0,1,-1,1,-1};
        int m = board.size(), n = board[0].size(), ct = 0;

        for(int i = 0; i < m; i++)  {
            for(int j = 0; j < n; j++)  {
                for(int k = 0; k < 8; k++)  {
                    int nx = dx[k] + i;
                    int ny = dy[k] + j;
                    if(nx >= 0 && nx < m && ny >= 0 && ny < n)  {
                        if(board[nx][ny] == 1 || board[nx][ny] == -1)   {
                            ct++;
                        }
                    }
                }
                if(board[i][j] == 1 && (ct < 2 || ct > 3))  {
                    board[i][j] = -1;
                }
                if(board[i][j] == 0 && ct == 3) {
                    board[i][j] = 2;
                }
                ct = 0; //reset counter
            }
        }
        for(int i = 0; i < m; i++)  {
            for(int j = 0; j < n; j++)  {
                if(board[i][j] == -1)
                    board[i][j] = 0;
                else if(board[i][j] == 2)
                    board[i][j] = 1;
            }
        }
    }
};