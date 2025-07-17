class Solution {
  public:
    vector<vector<int>> primeFactors(int num) {
        vector<vector<int>> factors;
        int count = 0;
        while (num % 2 == 0) {
            num /= 2;
            count++;
        }
        if (count > 0) factors.push_back({2, count});
        for (int i = 3; i * i <= num; i += 2) {
            count = 0;
            while (num % i == 0) {
                num /= i;
                count++;
            }
            if (count > 0) 
                factors.push_back({i, count});
        }
        if (num > 1)
            factors.push_back({num, 1});
        return factors;
    }
    int maxKPower(int n, int k) {
        vector<vector<int>> factors = primeFactors(k);
        int result = INT_MAX;
        for (auto &factor : factors) {
            int prime = factor[0], freqInK = factor[1], count = 0;
            for (int i = 1; i <= n; i++) {
                int x = i;
                while (x % prime == 0) {
                    count++;
                    x /= prime;
                }
            }
            result = min(result, count / freqInK);
        }    
        return result;
    }
};
