#2178 Maximum Split of Positive Even Integers
#Difficulty: Medium
#You are given an integer finalSum. Split it into a sum of a maximum number of unique positive even integers.

#For example, given finalSum = 12, the following splits are valid (unique positive even integers summing up to finalSum): (12), (2 + 10), (2 + 4 + 6), and (4 + 8). Among them, (2 + 4 + 6) contains the maximum number of integers. Note that finalSum cannot be split into (2 + 2 + 4 + 4) as all the numbers should be unique.
#Return a list of integers that represent a valid split containing a maximum number of integers. If no valid split exists for finalSum, return an empty list. You may return the integers in any order.

##First try
class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        vector<long long> output;
        // return empty list if finalSum is odd or negative integer including 0
        if(finalSum%2==1||finalSum<=0)
            return output;
        // if finalSum is 4, answer is 4 -> unique case
        if(finalSum==4) { output.push_back(finalSum); return output;}
        long long i=1;
        long long sum=0;
        while(true)
        {
            sum+=2*i;
            output.push_back(2*i);
            if(sum>finalSum)
            {
                while(output[output.size()-1]>=finalSum-sum)
                {
                    sum-=output[output.size()-1];
                    output.erase(output.end()-1);
                }
                output.push_back(finalSum-sum);
                break;
            }
            else if(sum==finalSum)
            {
                break;
            }
            i++;
        }
        return output;
    }
};

#Time Complexity: O(n^(1/2))
#Space Complexity: O(n^(1/2))

#Runtime: 308 ms, faster than 17.74%
#Memory Usage: 40.6 MB, less than 46.66%

#My Comments:
#1. add up even numbers starting from 2, 4, 6, ... 
#2. once it exceeds the finalsum, starting erasing from end of the vector.
#3. keep erasing when condition is 'output[output.size()-1]>=finalSum-sum'
#4. when escaping the loop, include the last difference with the finalsum

###Optimal Solution

class Solution {
public:
    vector<long long> maximumEvenSplit(long long n) {
        if(n%2) // odd
            return {};

		vector<long long> ans;
        long long i = 2;
        long long crSum=0;
		
        while((crSum+i)<= n)
        {
            ans.push_back(i);
            crSum+=i;
            i+=2;
        }
		
		// add remaining difference to the last value in answer list
		int sz = ans.size();
        ans[sz-1] += (n-crSum);
        return ans;
    }
};

#My Comments
#1. Difference with my code was I kept erasing last element while this solution just added the remaining difference to the last element
#2. Also, I used multiplication which takes up more time, this solution used addition(i+=2) to minimize calcuating cost.
#3. Multiplication -> addition => runtime reduced to half!!!

##Python3
class Solution:
    def maximumEvenSplit(self, finalSum: int) -> List[int]:
        output=[]
        if finalSum%2==1:
            return []
        i=2
        sum=0
        while sum+i<=finalSum:
            output.append(i)
            sum+=i
            i+=2
        output[-1]+=finalSum-sum
        return output
