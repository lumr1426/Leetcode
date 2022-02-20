class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> seen;
        vector<int> result;
        for(int i=0;i<nums.size();i++)
        {
            if(seen.count(target-nums[i])==1)
            {
                result.push_back(i);
                result.push_back(seen[target-nums[i]]);
                return result;
            }
            seen[nums[i]]=i;
        }
        return result;
    }
};
