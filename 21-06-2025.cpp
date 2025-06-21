class Solution {
  public:
    int catchThieves(vector<char> &arr, int k) {
        int n = arr.size(), p = 0, t = 0, count = 0;
        while (p < n && t < n) {
            while (p < n && arr[p] != 'P') p++;
            while (t < n && arr[t] != 'T') t++;
            if (p < n && t < n && abs(p - t) <= k) {
                count++; 
                p++;
                t++; 
            }
            else if (t < n && t < p) 
                t++;
            else if (p < n && p < t) 
                p++;
        }
        return count;
    }
}; 
