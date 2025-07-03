class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        vector<int> freq(26, 0);
        int i = 0, unique = 0, ans = -1;
        for(int j = 0; j < s.size(); j++){
            freq[s[j] - 'a']++;
            if(freq[s[j] - 'a'] == 1)
                unique++;
            while(unique > k){
                freq[s[i] - 'a']--;
                if(freq[s[i] - 'a'] == 0)
                    unique--;
                i++;
            }
            if(unique == k) 
                ans = max(ans, j-i+1);
        }
        return ans;
    }
};
