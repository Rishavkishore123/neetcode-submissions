class Solution {
public:

/*
Time complexity- 0(v+e);
space complexity - o(V + e)


but this question can be solved by using dfs as well go through it;
*/
    bool courseScheduletopo(int n, unordered_map<int, vector<int>>&adj, vector<int>&indegree){
        queue<int> q;
        int count=0;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                count++;
                q.push(i);
            }
        }

        while(!q.empty()){
            int m=q.front();
            q.pop();

            for(int &v:adj[m]){
                indegree[v]--;
                if(indegree[v]==0){
                    q.push(v);
                    count++;
                }
            }

        }

        if(count==n) return true;

        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>>adj;
        vector<int>indegree(numCourses, 0);

        for(auto &vec:prerequisites){
            int a=vec[0];
            int b=vec[1];

            adj[b].push_back(a);
            indegree[a]++;
        }

        return courseScheduletopo(numCourses, adj, indegree);
    }
};
