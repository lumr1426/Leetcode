class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<pair<int,int>> pair;
        int n=nums.size();
        vector<int> result(n);
        for(int i=0;i<n;i++)
        {
            pair.push_back(make_pair(i,(i+k)%n));
        }
        for(int i=0;i<n;i++)
        {
            result[pair[i].second]=nums[pair[i].first];
        }
        nums=result;
    }
};
