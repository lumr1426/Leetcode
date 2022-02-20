class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> answer;
        vector<int> compare;
        int targetind=0;
        
        for(int i=0;i<n;i++)
        {
            compare.push_back(i+1);
            answer.push_back("Push");
            if(compare.back()!=target[targetind])
            {
                compare.pop_back();
                answer.push_back("Pop");
            }
            else
            {
                targetind++;
            }
            if(targetind==size(target))
            {
                break;
            }
        }
        return answer;
    }
};
