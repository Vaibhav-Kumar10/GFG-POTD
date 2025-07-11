class Solution {
  public:
    int countConsec(int n) {
        int first = 0, second = 1, ans = 1;
        for(int i = 3; i <= n; i++){
            int next = first + second;
            first = second;
            second = next;
            ans = ans*2 + next;
        }
        return ans;
    }
};
