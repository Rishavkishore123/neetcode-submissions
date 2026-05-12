class Solution {
public:
    void dfs(vector<int>&visited, vector<vector<int>>& edges, int node){
      visited[node]=1;
      for(int i=0;i<edges.size();i++){
        if(edges[i][0]==node && !visited[edges[i][1]]){
          dfs(visited,edges,edges[i][1]);
        }

        else if(edges[i][1]==node && !visited[edges[i][0]]){
          dfs(visited,edges, edges[i][0]);
        }
      }

    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int>visited(n,0);
        int component=0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
              component++;
              dfs(visited, edges, i);
            }
        }

        return component;
    }


};
