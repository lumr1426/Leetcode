class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int,vector<int>> graph;
        for(auto e:edges)
        {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        vector<bool> isvisited(n,false);
        queue<int> q;
        q.push(source);
        while(!q.empty())
        {
            int nodeval=q.front();
            isvisited[nodeval]=true;
            q.pop();
            if(isvisited[destination]) return true;
            for(auto connect:graph[nodeval])
            {
                if(!isvisited[connect]) q.push(connect);
            }
        }
        return false;
    }
};
