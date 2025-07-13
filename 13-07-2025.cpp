class Solution {
  public:
    int nonLisMaxSum(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(2));
        for (int i = 0; i < n; ++i) {
            dp[i][0] = arr[i];
            dp[i][1] = 1;
            for (int j = 0; j < i; ++j) {
                if (arr[i] > arr[j]) {
                    if (dp[j][1] + 1 == dp[i][1]) {
                        dp[i][0] = min(dp[i][0], dp[j][0] + arr[i]);
                    }
                    else if (dp[j][1] + 1 > dp[i][1]) {
                        dp[i][0] = dp[j][0] + arr[i];
                        dp[i][1] = dp[j][1] + 1;
                    }
                }
            }
        }
        int maxLen = 0;
        for (int i = 0; i < n; ++i) 
            maxLen = max(maxLen, dp[i][1]);
        int minSum = INT_MAX;
        for (int i = 0; i < n; ++i) 
            if (dp[i][1] == maxLen) 
                minSum = min(minSum, dp[i][0]);
        int total = accumulate(arr.begin(), arr.end(), 0);
        return total - minSum;
    }
};
