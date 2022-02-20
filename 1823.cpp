class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> queue;
        for(int i=0;i<n;i++)
        {
            queue.push_back(i);
        }
        int cur=0;
        while(queue.size()>1)
        {
            cur=(k-1+cur)%queue.size();
            queue.erase(queue.begin()+cur);
        }
        return queue[0]+1;
    }
};
