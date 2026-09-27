#include <string>
#include <vector>
#include <unordered_map>

class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> map;
        for (const auto& pair : knowledge) {
            map[pair[0]] = pair[1];
        }

        string result = "";
        int n = s.length();
        
        for (int i = 0; i < n; ) {
            if (s[i] == '(') 
            {
                int j = i + 1;
                string key = "";
                while (j < n && s[j] != ')')
                {
                    key += s[j];
                    j++;
                }
                if (map.find(key) != map.end()) 
                {
                    result += map[key];
                } else 
                {
                    result += "?";
                }
                i = j + 1;
            } 
            
            else 
            {
                result += s[i];
                i++;
            }
        }

        return result;
    }
};