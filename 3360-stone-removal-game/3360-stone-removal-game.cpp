class Solution {
public:
    bool canAliceWin(int n) {
        int count = 0;
        int start = 10;
        while(start <= n) {
            count++;
            n -= start;
            start--;
        }
        if(count % 2 == 0)
            return false;
        return true;

    }
};