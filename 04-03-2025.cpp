class Solution {
  public:
    int countAtMostK(vector<int> &arr, int k) {
        unordered_map<int, int>mp;
        int ans = 0, i = 0;
        for(int j = 0; j < arr.size(); j++){
            mp[arr[j]]++;
            if(mp[arr[j]] == 1)
                k--;
            while(k < 0){
                mp[arr[i]]--;
                if(mp[arr[i]] == 0)
                    k++;
                i++;
            }
            ans  += j-i+1;
        }
        return ans;
    }
};
