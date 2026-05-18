class Solution {
public:
    /* 45 minute     
     */
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // make the min_heap
        // make the adj list
        unordered_map<int, vector<pair<int,int>>>adj;
        for(auto& vec:times){
            int a=vec[0];
            int b=vec[1];
            int c=vec[2];
            adj[a].push_back({b,c});
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int, int>>>pq;

        vector<int>result(n+1, INT_MAX);

        result[k]=0;
        pq.push({0,k});

        while(!pq.empty()){
            int d=pq.top().first;
            int node=pq.top().second;
            pq.pop();

            for(auto& neighbour:adj[node]){
                int adjNode=neighbour.first;
                int wt=neighbour.second;

                if(d+wt<result[adjNode]){
                    result[adjNode]=d+wt;
                    pq.push({d+wt, adjNode});
                }
            }
        }
            int ans=0;
        // I have the result array which have a less value
        for(int i=1;i<=n;i++){
            if(result[i]==INT_MAX)
            return -1;

           ans=max(ans,result[i]);
        }

        return ans;
    }
};
