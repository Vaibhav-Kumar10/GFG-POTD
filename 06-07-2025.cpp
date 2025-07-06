class Solution {
  public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        sort(a.begin(), a.end());
        reverse(a.begin(), a.end());
        sort(b.begin(), b.end());
        reverse(b.begin(), b.end());

        priority_queue<pair<int, pair<int, int>>>pq;
        set<pair<int, int>> vis;

        pq.push({a[0] + b[0], {0, 0}});
        vis.insert({0, 0});
        vector<int> ans;

        while(ans.size() < k){
            auto top = pq.top();
            pq.pop();
            int sum = top.first;
            int i = top.second.first;
            int j = top.second.second;
            ans.push_back(sum);

            if(vis.find({i+1, j}) == vis.end()){
                pq.push({a[i+1] + b[j], {i+1, j}});
                vis.insert({i+1, j});
            }
            if(vis.find({i, j+1}) == vis.end()){
                pq.push({a[i] + b[j+1], {i, j+1}});
                vis.insert({i, j+1});
            }
        }
        return ans;
    }
};
