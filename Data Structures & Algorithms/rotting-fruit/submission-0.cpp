class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;
        int fresh = 0;

        // push all rotten oranges
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2)
                    q.push({i,j});
                else if(grid[i][j]==1)
                    fresh++;
            }
        }

        int time = 0;
        int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};

        while(!q.empty() && fresh>0){
            int size = q.size();
            time++;

            while(size--){
                auto [i,j] = q.front();
                q.pop();

                for(auto d:dir){
                    int ni=i+d[0], nj=j+d[1];

                    if(ni>=0 && ni<n && nj>=0 && nj<m && grid[ni][nj]==1){
                        grid[ni][nj]=2;
                        fresh--;
                        q.push({ni,nj});
                    }
                }
            }
        }

        return fresh==0 ? time : -1;
    }
};