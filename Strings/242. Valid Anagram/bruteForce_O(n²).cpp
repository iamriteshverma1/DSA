class Solution {
public:
    bool isAnagram(string s, string t) {
      
        if(s.length() != t.length())
            return 0;

        for(int i = 0; i < s.length(); i++){
            bool check = true;

            for(int j = 0; j < t.length(); j++){
                
                if(s[i] == t[j]){
                    t[j] = '@';
                    check = false;
                    break;
                }
            }

            if(check)
                return false;
        }

        return true;
    }
};
