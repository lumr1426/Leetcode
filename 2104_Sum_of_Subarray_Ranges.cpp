#2104 Sum of subarray ranges
#difficulty: Medium
#You are given an integer array nums. The range of a subarray of nums is the difference between the largest and smallest element in the subarray.

#Return the sum of all subarray ranges of nums.

#A subarray is a contiguous non-empty sequence of elements within an array.

##First Try failed
##First solution
class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
       int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            int ma=nums[i];
            int mi=nums[i];
            for(int j=i;j<nums.size();j++)
            {
                ma=max(ma, nums[j]);
                mi=min(mi,nums[j]);
                sum+=ma-mi;
            }
        }
        return sum;
    }
};

#TC: O(n^2)
#SC: O(1)

#My Comments:
#1. Basic solution, i is start of a subarray and j is end of subarray
#2. when i is fixed, keep increasing j and using max and min func to save the max and min info of the smaller array with same i
#3. repeat and return the answer

###
