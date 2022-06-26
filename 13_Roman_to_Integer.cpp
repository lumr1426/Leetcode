# 13 Roman to Integer
# DIfficulty: easy
#Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

#Symbol       Value
#I             1
#V             5
#X             10
#L             50
#C             100
#D             500
#M             1000
#For example, 2 is written as II in Roman numeral, just two ones added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.

#Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:

#I can be placed before V (5) and X (10) to make 4 and 9. 
#X can be placed before L (50) and C (100) to make 40 and 90. 
#C can be placed before D (500) and M (1000) to make 400 and 900.
#Given a roman numeral, convert it to an integer.

#FIrst try
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, pair<char,char>> instance;
        unordered_map<char, int> rtoi;
        instance.insert(make_pair('I',make_pair('V','X')));
        instance.insert(make_pair('X',make_pair('L','C')));
        instance.insert(make_pair('C',make_pair('D','M')));
        rtoi.insert(make_pair('I',1));
        rtoi.insert(make_pair('V',5));
        rtoi.insert(make_pair('X',10));
        rtoi.insert(make_pair('L',50));
        rtoi.insert(make_pair('C',100));
        rtoi.insert(make_pair('D',500));
        rtoi.insert(make_pair('M',1000));
        int sum=0;
        for(int i=0;i<s.length()-1;i++)
        {
            if(instance[s[i]].first==s[i+1]||instance[s[i]].second==s[i+1])
            {
                sum-=rtoi[s[i]];
            }
            else
                sum+=rtoi[s[i]];
        }
        sum+=rtoi[s[s.length()-1]];
        return sum;
    }
};

#TC:O(n)
#SC:O(n+alpha)

#Runtime: 56ms
#Memory usage:  9.8MB

#Optimal Solution
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> rtoi=
        {
            {'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D',500},
            {'M',1000}
        };
        int sum=rtoi[s[s.length()-1]];
        for(int i=0;i<s.length()-1;i++)
        {
            if(rtoi[s[i]]<rtoi[s[i+1]])
            {
                sum-=rtoi[s[i]];
            }
            else
                sum+=rtoi[s[i]];
        }
        return sum;
    }
};

#Tc, SC is almost same

#Runtime 31ms
#Memory Usage 7.7MB

#My Comments
#1. You can intialize unordered map when you need to don't forget that
#2. Roman is made Larger to somaller which means opposite situation means the special instances.
