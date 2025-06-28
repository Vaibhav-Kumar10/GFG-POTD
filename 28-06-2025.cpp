class Solution {
  public:
    vector<int> countLessEq(vector<int>& a, vector<int>& b) {
        vector<int> freq(100001, 0);
        for(int el : b)
            freq[el]++;
        
        for(int i = 1; i < freq.size(); i++)
            freq[i] += freq[i-1];
        
        vector<int> ans;
        for(int el : a)
            ans.push_back(freq[el]);
        
        return ans;
    }
};
