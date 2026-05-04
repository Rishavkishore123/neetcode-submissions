class Solution {
public:
    // solve by using BFS
    // we are using the queue
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int ir[4]={0,0,-1,1};
        int ic[4]={-1,1,0,0};

        queue<pair<int,int>>q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0)
                q.push({i,j});
            }
        }

        while(!q.empty()){
            int t=q.size();

            while(t--){
                auto z=q.front();
                q.pop();

                int ii=z.first;
                int jj=z.second;

                for(int k=0;k<4;k++){
                    int new_ii=ii+ir[k];
                    int new_jj=jj+ic[k];

                 // handle the corner cases
                 if(new_ii>=0 && new_ii<n && new_jj>=0 && new_jj<m && grid[new_ii][new_jj]==2147483647){

                    grid[new_ii][new_jj]= grid[ii][jj]+1;
                    q.push({new_ii,new_jj});
                 }


                }
            }
        }

    }
};
