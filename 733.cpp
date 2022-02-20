class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(image.size()==0) return image;
        queue<pair<int,int>> q;
        vector<vector<bool>> isvisited(image.size(), vector<bool>(image[0].size()));
        for(int i=0;i<image.size();i++)
        {
            for(int j=0;j<image[0].size();j++)
            {
                isvisited[i].push_back(false);
            }
        }
        q.push(make_pair(sr,sc));
        int startnum=image[sr][sc];
        while(!q.empty())
        {
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            if(isvisited[row][col])
                continue;
            isvisited[row][col]=true;
            if(image[row][col]==startnum)
                image[row][col]=newColor;
            else continue;
            if(row!=0)
                q.push(make_pair(row-1,col));
            if(row!=image.size()-1)
                q.push(make_pair(row+1,col));
            if(col!=0)
                q.push(make_pair(row,col-1));
            if(col!=image[0].size())
                q.push(make_pair(row,col+1));
        }
        return image;
    }
};
