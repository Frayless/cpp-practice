class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //判断字符串是否重复，利用哈希表记录每个字符出现的次数
        //时间复杂度O(n),空间复杂度O(length(set(s)))
        int length = s.length();
        int left = 0;
        int curl = 0,maxl = 0;
        unordered_map<char, int> map;
        for(int right = 0; right < length; right++){
            map[s[right]] += 1;
            while(map[s[right]] > 1){
                //左指针移动后在减去hash中其重复的次数
                map[s[left]] -= 1;
                left += 1;
            }
            curl = right - left + 1;
            if(curl > maxl) maxl = curl;
        }
        return maxl;
    }
};
