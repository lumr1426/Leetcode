#3.Longest Substring Without Repeating Characters
#Difficulty: Medium
#Acceptance: 33.4%
###Given a string s, find the length of the longest substring without repeating characters.
###Note that it is NOT a subsequence!!!

###First Try

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length()==0)
            return 0;
        int maxlength=1;
        for(int i=0;i<s.length();i++)
        {
            int count=0;
            unordered_map<char, bool> hash;
            for(int j=i;j<s.length();j++)
            {
                if(hash.count(s[j])==1)
                {
                    // update maxlength if current count is max
                    if(maxlength<count)
                    {
                        maxlength=count;
                        break;
                    }
                    break;
                }
                else
                {
                    hash.insert(make_pair(s[j], 1));
                    count++;
                }
                if(maxlength<count)
                    maxlength=count;
            }
        }
        return maxlength;
    }
};

##Result
#Runtime: 966ms (beats 6.09%)
#Memory Usage: 244.1MB (beats 5.11%)

#Time Complexity: O(n^2)
#Space Complexity: O(n^2)

##My Comments
#1. Go through s from 0 to s.length() using i
#2. from i to s.length(), push hash elements when encountering first found character
#3. update maxlength everytime loop ends
#4. return maxlength
#5. used hashmap


### Optimal Solution

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> seen;
        int l=0;
        int output=0;
        for(int r=0;r<s.length();r++)
        {
            // If char is first seen
            if(seen.count(s[r])!=1)
            {
                // We use max because there might be a sequence
                // that is longer than current one found before
                output=max(output, r-l+1);
            }
            else
            {
                if(seen[s[r]]<l)
                {
                    output=max(output, r-l+1);
                }
                else
                {
                    l=seen[s[r]]+1;
                }
            }
            seen[s[r]]=r;
        }
        return output;
    }
};

##Result
#Runtime: 16ms (beats 70.66%)
#Memory Usage: 8.3MB (beats 74.07%)

#Time Complexity: O(n)
#Space Complexity: O(n)

##My Comments
#1. Used sliding window technique
#2. Use l(left pointer of window) and r(right pointer of window)
#3. increase r if found character is not in seen (output=max(output, r-l+1))
#4. Two case of character is in seen
  #1) The character is in the window
  #2) The character is outside of window
  #Case 1): move the l pointer to seen[s[r]]+1
  #Case 2): just increase the window
#5. Goes through loop only once -> TC: O(n)
#6. Store only characters in s -> SC: O(n)

###Python3
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        seen={}
        l=0
        output=0
        for r in range(len(s)):
            if s[r] not in seen:
                output=max(output, r-l+1)
            else:
                if seen[s[r]]<l:
                    output=max(output, r-l+1)
                else:
                    l=seen[s[r]]+1
            seen[s[r]]=r
        return output
