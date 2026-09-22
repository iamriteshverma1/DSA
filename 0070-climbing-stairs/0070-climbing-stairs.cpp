class Solution {
public:
    int climbStairs(int n) {
        if(n  == 1)
            return 1;
        else if(n == 2)
            return 2;
        //1, 2, 3, 5, 8, 13, 21, 34, 55, 89 ... .. ..
        int a = 1;
        int b = 2;
        int i = 2;
        int ans = 0;
        while(i != n){
            ans = a + b;
            a = b;
            b = ans;
            i++;
        }

        return ans;
        
    }
};