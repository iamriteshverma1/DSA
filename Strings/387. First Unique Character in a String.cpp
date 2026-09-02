//Approach -1
class Solution {
public:
    int firstUniqChar(string s) {
        int n = s.length();
        for(int i = 0; i < n; i++){
            bool flag = true;
            for(int j = 0; j < n; j++){
                if(i == j){
                    continue;
                }
                else if(s[i] == s[j]){
                    flag = false;
                    break;
                }
            }
            if(flag == true)
                return i;
        }
        return -1;
    }
};


//Approach - 2
class Solution {
public:
    int firstUniqChar(string s) {
        int freq[26]={0};
        for(int i=0;i<s.size();i++){
            freq[s[i]-'a']++;
        }
        for(int i=0;i<s.size();i++){
            if(freq[s[i]-'a']==1){
                return i;
            }
        }
        return -1;
    }
};
