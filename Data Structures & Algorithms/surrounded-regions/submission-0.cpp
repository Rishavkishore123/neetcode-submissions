class Solution {
public:
    void solve(vector<vector<char>>& board) {

        int n = board.size();
        int m = board[0].size();

        queue<pair<int,int>> q;

        // push boundary O's
        for(int i=0;i<n;i++){

            if(board[i][0]=='O'){
                q.push({i,0});
                board[i][0]='#';
            }

            if(board[i][m-1]=='O'){
                q.push({i,m-1});
                board[i][m-1]='#';
            }
        }

        for(int j=0;j<m;j++){

            if(board[0][j]=='O'){
                q.push({0,j});
                board[0][j]='#';
            }

            if(board[n-1][j]=='O'){
                q.push({n-1,j});
                board[n-1][j]='#';
            }
        }

        int ir[4]={0,0,-1,1};
        int ic[4]={-1,1,0,0};

        // BFS
        while(!q.empty()){

            auto z=q.front();
            q.pop();

            int ii=z.first;
            int jj=z.second;

            for(int k=0;k<4;k++){

                int new_ii=ii+ir[k];
                int new_jj=jj+ic[k];

                if(new_ii>=0 && new_ii<n &&
                   new_jj>=0 && new_jj<m &&
                   board[new_ii][new_jj]=='O'){

                    board[new_ii][new_jj]='#';
                    q.push({new_ii,new_jj});
                }
            }
        }

        // final conversion
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                if(board[i][j]=='O')
                    board[i][j]='X';

                else if(board[i][j]=='#')
                    board[i][j]='O';
            }
        }
    }
};