class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j, int& area){
        
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j]==0 )
        return;

        area++;
        grid[i][j]=0;
        // call dfs for every direction
        dfs(grid, i-1,j, area);
        dfs(grid, i+1,j, area);
        dfs(grid, i,j-1, area);
        dfs(grid, i,j+1, area);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int maxi=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    int area=0;
                    dfs(grid, i, j, area);
                    maxi=max(maxi,area);
                }
            }
        }

        return maxi;
    }
};
