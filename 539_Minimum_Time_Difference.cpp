#539 Minimum Time Difference
#Difficulty: Medium
#Given a list of 24-hour clock time points in "HH:MM" format, return the minimum minutes difference between any two time-points in the list.

#Example 1:

#Input: timePoints = ["23:59","00:00"]
#Output: 1
  
#Example 2:

#Input: timePoints = ["00:00","23:59","00:00"]
#Output: 0  

###First Try

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> min_time;
        for(int i=0;i<timePoints.size();i++)
        {
            string hour=timePoints[i].substr(0,2);
            string min=timePoints[i].substr(3,2);
            int total_min=stoi(hour)*60+stoi(min);
            min_time.push_back(total_min);
            cout<<min_time[i]<<"\n";
        }
        //sort the elements in ascending order
        sort(min_time.begin(),min_time.end());
        int mindiff;
        for(int i=0;i<min_time.size();i++)
        {
            if(i==0)
                mindiff=min_time[0]+(24*60-min_time[min_time.size()-1]);
            else
            {
                if(mindiff>min_time[i]-min_time[i-1])
                    mindiff=min_time[i]-min_time[i-1];
            }
        }
        return mindiff;
    }
};

#Time Complexity: O(nlogn) -> it is depended by which sorting algorithm you use, in this case quicksort
#Space Complexity: O(n)

#Runtime: 15 ms, faster than 79.25%
#Memory Usage: 13.7 MB, less than 45.04%

#My Comments
#1. First change the string to int representing time by minutes
#2. Sort times in ascending order
#3. Compare the elements next to each other(you should also compare first and the last element)
#4. return the mindiff

