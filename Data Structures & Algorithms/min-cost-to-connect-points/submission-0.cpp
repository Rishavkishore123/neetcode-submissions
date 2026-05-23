class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n=points.size();
        unordered_map<int, vector<pair<int,int>>>adj;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int dist=abs(points[i][0]- points[j][0])+abs(points[i][1]-points[j][1]);
                adj[i].push_back({j,dist});
                adj[j].push_back({i,dist});

            }
        }

        //min_heap, sum, isVisited

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        vector<bool>isVisited(n,false);

        pq.push({0,0});
        int sum=0;
        while(!pq.empty()){
            int wt=pq.top().first;
            int node=pq.top().second;
            pq.pop();

            if(isVisited[node]==true)
            continue;

            isVisited[node]=true;
            sum+=wt;

            for(auto& temp:adj[node]){
                int neighbour_wt=temp.second;
                int neighbour=temp.first;

                pq.push({neighbour_wt, neighbour});
            }
        }

        return sum;
    }
};
