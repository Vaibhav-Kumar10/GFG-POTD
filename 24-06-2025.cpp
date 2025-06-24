class Solution {
  public:
    string maxSubseq(string& s, int k) {
        int n = s.length(), toRemove = k; 
        string res = "";
        for (int i = 0; i < n; i++) {
            while (!res.empty() && toRemove > 0 && res.back() < s[i]) {
                res.pop_back();
                toRemove--;
            }
            res.push_back(s[i]);
        }
        res.resize(n - k);
        return res;
    }
};
