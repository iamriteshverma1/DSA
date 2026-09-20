class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int totalL = 0;
        int total_ = 0;
        int totalR = 0;
        
        for(char& ch : moves) {
            if(ch == 'R')
                totalR += 1;
            else if(ch == 'L')
                totalL += 1;
            else 
                total_ += 1;
        }
        if(totalL > totalR)
            return totalL - totalR + total_;
        
        return totalR - totalL + total_;

    }
};