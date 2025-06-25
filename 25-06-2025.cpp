class Solution {
  public:
    bool sameFreq(string& s) {
        vector<int> freq(26, 0); 
        for (char c : s) 
            freq[c - 'a']++;
        unordered_map<int, int> freqCount; 
        for (int f : freq) 
            if (f > 0) 
                freqCount[f]++;
        if (freqCount.size() == 1)
            return true;
        if (freqCount.size() == 2) {
            auto it = freqCount.begin();
            int freq1 = it->first, count1 = it->second;
            ++it;
            int freq2 = it->first, count2 = it->second;
            if ((freq1 == 1 && count1 == 1) || (freq2 == 1 && count2 == 1)) 
                return true;
            if (abs(freq1 - freq2) == 1 &&
                ((count1 == 1 && freq1 > freq2) || 
                (count2 == 1 && freq2 > freq1))) 
                return true;
        }
        return false;
    }
};
