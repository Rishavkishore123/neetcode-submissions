class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);

        for(auto edge:edges){
            int a=edge[0];
            int b=edge[1];

            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        vector<bool>visited(n,false);

        queue<pair<int,int>>q;

        q.push({0,-1});
        visited[0]=true;

        while(!q.empty()){
            int node=q.front().first;
            int parent=q.front().second;

            q.pop();

            for(auto neighbour:adj[node]){
                if(!visited[neighbour]){
                    visited[neighbour]=true;
                    q.push({neighbour,node});
                }

                else if(neighbour!=parent){
                    return false;
                }
            }
        }
        // now we are getting the whole visited array
        for(int i=0;i<n;i++){
            if(!visited[i])
            return false;
        }

        return true;
    }
};
