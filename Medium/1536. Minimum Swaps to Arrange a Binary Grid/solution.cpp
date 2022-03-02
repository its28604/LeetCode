class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        auto zero_arr = getZeroNumArr(grid);
        auto swap_count = sortAndCount(zero_arr);
        return swap_count;
    }

    vector<int> getZeroNumArr(vector<vector<int>>& grid) {
        vector<int> zero_arr;
        for (int i = 0; i < grid.size(); i++) {
            auto arr = grid[i];
            auto zero_num = getZeroNum(arr);
            zero_arr.push_back(zero_num);
        }
        return zero_arr;
    }

    int getZeroNum(vector<int>& arr) {
        int count = 0;
        for (int i = arr.size() - 1; i >= 0; i--) {
            if (arr[i] == 0) {
                count++;
            }
            else {
                return count;
            }
        }
        return count;
    }

    int sortAndCount(vector<int>& zero_arr) {
        int swap_count = 0;
        int n = zero_arr.size() - 1;
        for (int i = 0; i < zero_arr.size() - 1; i++) {
            int j = i;
            for (; j < zero_arr.size(); j++) {
                if (zero_arr[j] - n >= 0) break;
            }
            if (j == zero_arr.size())
                return -1;

            auto s = swap(zero_arr, i, j);
            swap_count += s;
            n--;
        }
        return swap_count;
    }

    int swap(vector<int>& zero_arr, int i, int j) {
        int count = 0;
        for (;j > i; j--) {
            auto temp = zero_arr[j - 1];
            zero_arr[j - 1] = zero_arr[j];
            zero_arr[j] = temp;
            count++;
        }
        return count;
    }
};