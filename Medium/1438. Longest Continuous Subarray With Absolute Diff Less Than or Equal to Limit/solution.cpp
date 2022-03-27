class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        auto idx_p = 0;
        auto idx_n = 0;
        auto arr_max = 0;
        map<int, int> count_map;
        auto max_num = nums[0];
        auto min_num = nums[0];
        while (idx_n < nums.size()) {
            auto n = nums[idx_n];
            if (n > max_num)
                max_num = n;
            if (n < min_num)
                min_num = n;

            if (Abs(min_num - n) > limit || Abs(max_num - n) > limit)
            {
                auto p = nums[idx_p];
                auto count = count_map.find(p)->second;
                count--;
                count_map[p] = count;
                auto _review = count == 0;
                idx_p++;
                if (_review) {
                    max_num = min_num = nums[idx_p];
                    for (int j = idx_p; j <= idx_n; j++) {
                        auto v = nums[j];
                        if (v > max_num)
                            max_num = v;
                        if (v < min_num)
                            min_num = v;
                    }
                }
            }
            else
            {
                auto iter = count_map.find(n);
                if (iter != count_map.end())
                {
                    auto count = iter->second;
                    count++;
                    count_map[n] = count;
                }
                else {
                    count_map[n] = 1;
                }

                idx_n++;
            }
            auto continues_count = idx_n - idx_p;
            if (continues_count > arr_max)
                arr_max = continues_count;
        }
        return arr_max;
    }
    
    int Abs(int n) {
        return n > 0 ? n : n * -1;
    }
}