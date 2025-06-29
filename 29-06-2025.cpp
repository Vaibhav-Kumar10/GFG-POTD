class Solution {
  public:
    bool check(int mid, vector<int> &arr, int k) {
        int n = arr.size();
        int count = 0;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] > mid)
                return false;
            sum += arr[i];
            if (sum > mid) {
                count++;
                sum = arr[i];
            }
        }
        count++;
        if (count <= k)
            return true;
        return false;
    }
    int splitArray(vector<int> &arr, int k) {
        int n = arr.size();
        int max = *max_element(arr.begin(), arr.end());
        int start = max;
        int end = 0;
        for (int i = 0; i < n; i++) 
            end += arr[i];
        int ans = 0;
        while (start <= end) {
            int mid = (start + end) / 2;
            if (check(mid, arr, k)) {
                ans = mid;
                end = mid - 1;
            }
            else 
                start = mid + 1;
        }
        return ans;
    }
};
