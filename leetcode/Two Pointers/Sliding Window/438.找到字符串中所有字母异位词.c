// 定长滑动窗口
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int len_s = s.length(), len_p = p.length();
        int left = 0;
        vector<int> ans;
        unordered_map<char, int> map_p, map_s;
        for(auto ch : p) map_p[ch] += 1;
        for(int i = 0; i < len_p; i++){
            map_s[s[i]] += 1;
        }
        for(int right = len_p - 1; right < len_s; right++){
            //left = right >= len_p - 1 ? right - (len_p - 1) :  0;
            if(right > len_p - 1) map_s[s[right]] += 1;
            if(map_s == map_p) ans.push_back(left); 
            map_s[s[left]] -= 1;
            if(map_s[s[left]] == 0) map_s.erase(s[left]);
            left += 1;
        }
        return ans;
    }
};

// 由两个hash转变为1维数组存储
// 不定长滑动窗口
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        vector<int> cnt(26);
        int left = 0;
        for(auto ch : p) cnt[ch - 'a'] += 1;
        for(int right = 0; right < s.length(); right++){
            int cur = s[right] - 'a';
            cnt[cur] -= 1; 
            while(cnt[cur] < 0){
                cnt[s[left] - 'a'] += 1;
                left += 1;
            }
            if(right - left + 1 == p.length()) ans.push_back(left);
        }
        return ans;
    }
};
