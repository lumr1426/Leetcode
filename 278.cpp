// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left,pivot=1, right=n;
        while(left<=right)
        {
            pivot=left+(right-left)/2;
            if(isBadVersion(pivot)==false&&isBadVersion(pivot+1)==true)
                return pivot+1;
            else if(isBadVersion(pivot)&&isBadVersion(pivot+1))
                right=pivot-1;
            else left=pivot+1;
        }
        return 1;
    }
};
