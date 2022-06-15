###5. Longest Palindromic Substring
###Difficulty: Medium
###Given a string s, return the longest palindromic substring in s.

###Failed for the first try

###Optimal Solution

class Solution {
public:
    string longestPalindrome(string s) {
        int longest_l=0;
        int maxlength=1;
        int l,r;
        for(int i=0;i<s.length();i++)
        {
            l=i;
            r=i;
            while(r<s.length()&&s[r]==s[i])
            {
                r+=1;
            }
            l-=1;
            while(l>=0&&r<s.length()&&s[l]==s[r])
            {
                l-=1;
                r+=1;
            }
            if(maxlength<r-l-1)
            {
                maxlength=r-l-1;
                longest_l=l+1;
            }
        }
        return s.substr(longest_l,maxlength);
    }
};

#Time Complexity: O(n^2)
#Space Complexity: O(1)

##Runtime: 23ms(Beats 88.88%)
##Memory Usage: 7.2MB(Beats  81.72%)

#My Comments
#1. iterate through the string with i (i will be the base unit for the palindrome)
#2. find the next element that is same as s[i], move the right pointer until s[r] is different with s[i]
#3. repeat l-=1, r+=1 and compare s[r], s[i], if they are same, it is a palindrome
#4. keep updating maxlength and return the substring after loop

###Python3

class Solution:
    def longestPalindrome(self, s: str) -> str:
        n=len(s)
        max_l,maxlength=0,1
        for i in range(n):
            r=i
            while r<n and s[r]==s[i]:
                r+=1
            l=i-1
            while l>=0 and r<n and s[l]==s[r]:
                l-=1
                r+=1
            if maxlength<r-l-1:
                maxlength=r-l-1
                max_l=l+1
        return s[max_l:max_l+maxlength]

#Runtime: 713ms(beats 90.94%)
#Memory usage: 14.1MB(beats 29.26%)
