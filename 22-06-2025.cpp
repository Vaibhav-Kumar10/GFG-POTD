class Solution {
  public:
    vector<int> largestSubset(vector<int>& arr) {
      	int n  = arr.size();
        sort(arr.rbegin(), arr.rend());
        vector<int> dp(n, 1);
        vector<int> parent(n, -1);
        int maxSize = 1, lastIndex = 0;
    
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (arr[j] % arr[i] == 0 && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    parent[i] = j;
                }
            }
            if (dp[i] > maxSize) {
                maxSize = dp[i];
                lastIndex = i;
            }
        }

        vector<int> res;
        for (int i = lastIndex; i >= 0; i = parent[i]) {
            res.push_back(arr[i]);
            if (parent[i] == -1)
                break;
        }
        return res;
    }
};
