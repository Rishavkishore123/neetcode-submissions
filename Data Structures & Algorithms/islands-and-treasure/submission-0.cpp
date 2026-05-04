class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j, int dist){
        if(i<0 || i>=grid.size() || j<0|| j>=grid[0].size()|| grid[i][j]< dist)
        return;

       grid[i][j]=dist;

        // call the dfs for up, down , right, left
        dfs(grid,i-1,j,dist+1);
        dfs(grid,i+1,j,dist+1);
        dfs(grid,i,j-1,dist+1);
        dfs(grid,i,j+1,dist+1);
    }
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int count=0;
                if(grid[i][j]==0){
                    dfs(grid, i, j, 0);
                }
            }
        }
    }
};
