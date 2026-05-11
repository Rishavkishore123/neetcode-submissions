class Solution {
public:

    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size()!=n-1)
        return false;

        vector<vector<int>>adj(n);

        for(auto& vec:edges){
            int u=vec[0];
            int v=vec[1];

            adj[u].push_back(v);
            adj[v].push_back(u);

        }

        vector<bool>visited(n,false);
        queue<pair<int, int>>q;

        q.push({0,-1});
        visited[0]=true;

        while(!q.empty()){
            //int node=q.front().first;
            //int parent=q.front().second;
            
            auto [node,parent]=q.front();
            q.pop();
            for(auto& neighbour:adj[node]){
                if(!visited[neighbour]){
                    visited[neighbour]=true;
                    q.push({neighbour,node});
                }

                else if(neighbour!=parent)
                    return false;
            }
        }

        for(int i=0;i<n;i++){
            if(!visited[i])
            return false;
        }
        
        return true;
    }
};
