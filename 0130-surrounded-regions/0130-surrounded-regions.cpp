class Solution {
public:

     //We will use boundary DFS to solve this problem
        
      // Let's analyze when an 'O' cannot be flipped,
      // if it has atleast one 'O' in it's adjacent, AND ultimately this chain of adjacent 'O's is connected to some 'O' which lies on boundary of board
        
      //consider these two cases for clarity :
      /*
        O's won't be flipped          O's will be flipped
        [X O X X X]                   [X X X X X]     
        [X O O O X]                   [X O O O X]
        [X O X X X]                   [X O X X X] 
        [X X X X X]                   [X X X X X]
      
      So we can conclude if a chain of adjacent O's is connected some O on boundary then they cannot be flipped
      
      */
        
      //Steps to Solve :
      //1. Move over the boundary of board, and find O's 
      //2. Every time we find an O, perform DFS from it's position
      //3. In DFS convert all 'O' to 'T'      (why?? so that we can differentiate which 'O' can be flipped and which cannot be)   
      //4. After all DFSs have been performed, board contains three elements,T,O and X
      //5. 'O' are left over elements which are not connected to any boundary O, so flip them to 'X'
      //6. 'T' are elements which cannot be flipped to 'X', so flip them back to 'O'
    

    int n = 0, m = 0;
    vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    void mat(vector<vector<char>>& board, int i, int j) {
        if (i < 0 || j < 0 || i >= n || j >= m || board[i][j] != 'O') return;
        board[i][j] = 'T'; 
        for (auto it : dir) {
            int i_ = it[0];
            int j_ = it[1];
            mat(board, i + i_, j + j_);
        }
    }

    void solve(vector<vector<char>>& board) {
        n = board.size();
        m = board[0].size();
        
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if ((i == 0 || j == 0 || i == n-1 || j == m-1) && board[i][j] == 'O') {
                    mat(board, i, j);
                }
            }
        }

         
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } else if (board[i][j] == 'T') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};
