class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        vector<int> ones;
        vector<int> zeros;
        int idx = 31;
        while (ones.size() == 0 || zeros.size() == 0) {
            if (idx < 0)
                return 0;
            split(nums, idx, ones, zeros);
            idx--;
        }
        return findMax(ones, zeros, idx, 1);
    }
    
    uint findMax(vector<int> ones, vector<int> zeros, int idx, uint _xor) {
        if (idx < 0)
            return _xor;
        uint __xor = _xor;

        vector<int> ones_ones;
        vector<int> ones_zeros;
        vector<int> zeros_ones;
        vector<int> zeros_zeros;
        split(ones, idx, ones_ones, ones_zeros);
        split(zeros, idx, zeros_ones, zeros_zeros);

        if ((ones_ones.size() == 0 || zeros_zeros.size() == 0) &&
            (ones_zeros.size() == 0 || zeros_ones.size() == 0))
        {
            __xor = __xor << 1;
            return findMax(ones, zeros, idx - 1, __xor);
        }

        else 
        {
            __xor = (__xor << 1) + 1;
            uint a = 0, b = 0;
            if (ones_ones.size() > 0 && zeros_zeros.size() > 0)
                a = findMax(ones_ones, zeros_zeros, idx - 1, __xor);
            if (ones_zeros.size() > 0 && zeros_ones.size() > 0)
                b = findMax(ones_zeros, zeros_ones, idx - 1, __xor);
            return a > b ? a : b;
        }
    }
    
    void split(vector<int>& nums, int idx, vector<int>& ones, vector<int>& zeros) {
        ones.clear();
        zeros.clear();
        uint temp = 1 << idx;
        for (int i = 0; i < nums.size(); i++) {
            int val = nums[i];
            if ((uint)(temp & val) == 0)
                zeros.push_back(val);
            else 
                ones.push_back(val);
        }
    }
};