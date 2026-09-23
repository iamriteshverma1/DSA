//Try to sove wiht HAsh Map 
class Solution {
private: 
    int NextNum(int n) {
        int totalSum = 0;
        while(n) {
            int digit= n % 10;
            n /= 10;
            totalSum += digit * digit; 
        }
        return totalSum;
    }
public:
    bool isHappy(int n) {
        unordered_set<int> visited;
        while(n != 1 && visited.find(n) == visited.end()) { // checdk it does numer is not came before than the number is not in  loop or in cycle iterate next.
            visited.insert(n);
            n = NextNum(n);
        }

        return n == 1;
    }
};