class Solution {
public:
    /*
        30 minutes 13:10
     How will you measure the K stops I need to think on this
        
     we have to apply the dijikstra's algorithm
     but how we apply here we have to find the shortest dist with atmost k stops

     first remember how to apply the djikstra's algo
     => apply the min_heap
     => push in the queue with weight and src
     =>traverse the queue until the queu is not empy
     =>now queue carry 2 value one is weight, node=> src actually
     => now we traverse on the node find the neighnour who have the short
     path to dest
     => if we found that puth the neighour_node and neighbour_weight in the queue

     that's how we apply the dijikstra's algo and one more take the ans variable in
     above initalize as 0;
     add the weight into ans when we traverse in the queue


    
    */
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int, vector<pair<int,int>>>adj;
        for(auto& vec:flights){
            int a=vec[0]; // src
            int b=vec[1]; // dest
            int c=vec[2]; // cost

            adj[a].push_back({b,c});
        }

        vector<int>dist(n, INT_MAX);
        queue<pair<int,int>>q;
        int steps=0;

        q.push({0,src});
        dist[src]=0;

        while(!q.empty() && steps<=k){
            int m=q.size();

            while(m--){
                int d=q.front().first;
                int node=q.front().second;
                q.pop();

                for(auto& neighbour:adj[node]){
                    int cost=neighbour.second;
                    int nbr=neighbour.first;

                    if(dist[nbr]>d+cost){
                        dist[nbr]=d+cost;
                         q.push({d + cost, nbr});
                    }
                }
            }

            steps++;        
        }
        if(dist[dst]==INT_MAX)
        return -1;

        return dist[dst];
    }
};
