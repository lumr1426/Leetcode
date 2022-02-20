
class Solution {
public:
    int maximum69Number (int num) {
        vector<int> v;
        while(num)
        {
            v.push_back(num%10);
            num/=10;
        }
        reverse(v.begin(), v.end());
        for(int i=0;i<v.size();i++)
        {
            if(v[i]==6)
            {
                v[i]=9;
                break;
            }
        }
        int sum=0;
        int i=1;
        while(v.size()!=0)
        {
            sum+=v.back()*i;
            v.pop_back();
            i*=10;
        }
        return sum;
    }
};
