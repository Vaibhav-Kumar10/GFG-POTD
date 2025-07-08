class Solution {
  public:
    vector<int> findGreater(vector<int>& arr) {
        int n = arr.size();
        map<int, int> freq;
        vector<int> ans(n, -1);
        stack<int> st;
        for(int el : arr)   
            freq[el]++;
        for(int i = 0; i < n; i++){
            while(!st.empty() && freq[arr[i]] > freq[arr[st.top()]]){
                ans[st.top()] = arr[i];
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};
