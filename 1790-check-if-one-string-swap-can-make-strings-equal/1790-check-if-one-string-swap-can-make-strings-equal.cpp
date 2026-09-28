class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1.length() != s2.length())
            return false;
        
        int first = -1;
        int second = -1;
        int diff = 0;

        for(int i = 0; i < s1.length(); i++) {
            if(s1[i] != s2[i])  {
                diff++;
                
                if(diff == 1)
                    first = i;
                else if(diff == 2)
                    second = i;
                else
                    return false;
            }
        }

        if(diff == 0)
            return true;
        if(diff != 2)
            return false;
        return s1[first] == s2[second] && s2[first] == s1[second] ;
    }
};