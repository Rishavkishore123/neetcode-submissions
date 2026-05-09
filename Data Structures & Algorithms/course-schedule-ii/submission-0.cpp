class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>>adj;
       // unordered_map<int, vector<int>>adj;
        vector<int>indegree(numCourses,0);
        vector<int>ans;

        for(auto &vec:prerequisites){
            int a=vec[0];
            int b=vec[1];

            adj[b].push_back(a);
            indegree[a]++;
        }

        queue<int>q;

        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
                ans.push_back(i);
            }
        }

        while(!q.empty()){
            auto z=q.front();
            q.pop();

            for(int v:adj[z]){
                indegree[v]--;
                if(indegree[v]==0){
                    ans.push_back(v);
                    q.push(v);
                }
            }
        }

        if(ans.size()==numCourses)
        return ans;


        return {};
    }
};
