#1710 Maximum units on a truck
#DIfficulty: easy
# You are assigned to put some amount of boxes onto one truck. You are given a 2D array boxTypes, where boxTypes[i] = [numberOfBoxesi, numberOfUnitsPerBoxi]:

#numberOfBoxesi is the number of boxes of type i.
#numberOfUnitsPerBoxi is the number of units in each box of the type i.
#You are also given an integer truckSize, which is the maximum number of boxes that can be put on the truck. You can choose any boxes to put on the truck as long as the number of boxes does not exceed truckSize.

#Return the maximum total number of units that can be put on the truck.

#First try
class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [](vector<int> a, vector<int> b) {return a[1]>b[1];});
        int total_units=0;
        int i=0;
        while(truckSize>0&&i<boxTypes.size())
        {
            int num_boxes=boxTypes[i][0];
            int unit_box=boxTypes[i][1];
            while(num_boxes!=0&&truckSize!=0)
            {
                total_units+=unit_box;
                num_boxes--;
                truckSize--;
            }
            i++;
        }
        return total_units;
    }
};

#TC: O(nlogn) : based on sorting
#SC: O(n)

#Runtime: 391 ms, faster than 7.11%
#Memory usage: 49.5 MB, less than 13.86%

#My comments
#1. sorted based on vector[1] in the big vector

#Optimal Solution
class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        // -1 means there are no boxes
        vector<int> boxes(1001,-1);
        // Use counting sort
        // index is the type of unit, the contents are num of boxes
        for(auto vec: boxTypes)
        {
            if(boxes[vec[1]]==-1)
                boxes[vec[1]]=vec[0];
            else
                boxes[vec[1]]+=vec[0];
        }
        // until here is O(n)
        // starting from the back, add up possible boxes
        int tot_unit=0;
        for(int i=1000;i>=0;i--)
        {
            if(truckSize<=0) break;
            int num_box=boxes[i];
            if(num_box==-1)
                continue;
            else
            {
                while(num_box>0&&truckSize>0)
                {
                    tot_unit+=i;
                    num_box--;
                    truckSize--;
                }
            }
        }
        return tot_unit;
    }
};

#TC: O(n)
#SC: O(1001)

#Runtime: 66 ms, faster than 56.73%
#MEmory usage: 17.7 MB, less than 30.37% 

#Mycomments:
#1. Used counting sort, since there was a constraint of '1 <= boxTypes.length <= 1000'
#2. num_box, num_unit both had positive integer numbers -> can think of counting sort with O(n)
#3. but only usable when there is a constraint, if not can't use this

