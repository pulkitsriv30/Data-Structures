class Solution {
public:
    // Brute
//     bool isSafe1(int row, int col, vector<string>& board, int n) {
//         // check upper diagonal
//         int duprow = row;
//         int dupcol = col;

//         while(row >= 0 && col >= 0) {
//             if(board[row][col] == 'Q') return false;
//             row--;
//             col--;
//         }

//         col = dupcol;
//         row = duprow;

//         while(col >= 0) {
//             if(board[row][col] == 'Q') return false;
//             col--;
//         }

//         row = duprow;
//         col = dupcol;

//         while(row < n && col >= 0) {
//             if(board[row][col] == 'Q') return false;
//             row++;
//             col--;
//         }

//         return true;
//     }

// public:
//     void solve(int col, vector<string> &board,
//                vector<vector<string>> &ans, int n) {

//         if(col == n) {
//             ans.push_back(board);
//             return;
//         }

//         for(int row = 0; row < n; row++) {
//             if(isSafe1(row, col, board, n)) {
//                 board[row][col] = 'Q';

//                 solve(col + 1, board, ans, n);

//                 board[row][col] = '.';
//             }
//         }
//     }

//     vector<vector<string>> solveNQueens(int n) {
//         vector<vector<string>> ans;
//         vector<string> board(n, string(n, '.'));

//         solve(0, board, ans, n);

//         return ans;
//     }
// Optimal
void solve(int col,vector<vector<string>>& ans,vector<string>& board,vector<int>& leftRow, vector<int>& upperDiag, vector<int>& lowerDiag,int n) {
    if(col==n) {
        ans.push_back(board);
        return;
    }
    for(int row=0;row<n;row++) {
        if(leftRow[row]==0 && upperDiag[row+col]==0 && lowerDiag[n-1+col-row]==0) {
            board[row][col]='Q';
            leftRow[row]=1;
            upperDiag[row+col]=1;
            lowerDiag[n-1+col-row]=1;
            solve(col+1,ans,board,leftRow,upperDiag,lowerDiag,n);
            board[row][col]='.';
            leftRow[row]=0;
            upperDiag[row+col]=0;
            lowerDiag[n-1+col-row]=0;
        }
    }
}
vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n,string(n,'.')); // at every index '....'
        vector<int> leftRow(n,0); 
        vector<int> upperDiag(2*n-1,0);
        vector<int> lowerDiag(2*n-1,0);
        solve(0,ans,board,leftRow,upperDiag,lowerDiag,n);
        return ans;
    }

};