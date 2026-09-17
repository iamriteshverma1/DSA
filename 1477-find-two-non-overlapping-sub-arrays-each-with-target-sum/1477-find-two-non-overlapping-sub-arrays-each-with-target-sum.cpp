/*
class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<pair<int, int>> sub;

        for (int i = 0; i < n; i++) {
            int sum = 0;

            for (int j = i; j < n; j++) {
                sum += arr[j];

                if (sum == target) {
                    sub.push_back({i, j});
                    break;
                }

                if (sum > target)
                    break;
            }
        }

        int ans = INT_MAX;

        for (int i = 0; i < sub.size(); i++) {
            for (int j = i + 1; j < sub.size(); j++) {

                int l1 = sub[i].first;
                int r1 = sub[i].second;

                int l2 = sub[j].first;
                int r2 = sub[j].second;

                if (r1 < l2 || r2 < l1) {
                    int len1 = r1 - l1 + 1;
                    int len2 = r2 - l2 + 1;

                    ans = min(ans, len1 + len2);
                }
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};

*/

/*
class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> best(n, INT_MAX);

        int left = 0;
        int sum = 0;
        int ans = INT_MAX;
        int minLen = INT_MAX;

        for (int right = 0; right < n; right++) {
            sum += arr[right];

            while (sum > target) {
                sum -= arr[left++];
            }

            if (sum == target) {
                int len = right - left + 1;

                if (left > 0 && minLen != INT_MAX) {
                    ans = min(ans, len + minLen);
                }

                minLen = min(minLen, len);
            }

            if (right > 0)
                best[right] = minLen;
        }

        return ans == INT_MAX ? -1 : ans;
    }
};
*/

class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        int ans = n + 1;
        int s = 0;
        vector<int> dp(n + 1, n);
        for (int l = 0, r = 0; r < n; r++) {
            s += arr[r];
            while (s > target) {
                s -= arr[l++];
            }
            dp[r + 1] = dp[r];
            if (s == target) {
                ans = min(ans, r - l + 1 + dp[l]);
                dp[r + 1] = min(dp[r], r - l + 1);
            }
        }
        return ans == n + 1 ? -1 : ans;
    }
};