class Solution {
public:
    unordered_map<string, int> map;
    int maxCoins(vector<int>& nums) {

        removeAllZeros(nums);

        int score = 0;
        int max_child_score = 0;

        for (int i = 0; i < nums.size(); i++) {
            int child_score = 0;
            child_score = ballonsRecursive(i, nums);
            if (child_score > max_child_score) {
                max_child_score = child_score;
            }
        }
        return score + max_child_score;
    }

    int ballonsRecursive(int idx, vector<int> nums) {
        int val = nums[idx];
        int score = brust(idx, nums);
        int max_child_score = 0;
        if (nums.size() == 0)
            return score;

        string seq = join(nums, ',');
        if (map.find(seq) != map.end()) {
            max_child_score = map[seq];
        }
        else {
            for (int i = 0; i < nums.size(); i++) {
                int child_score = ballonsRecursive(i, nums);
                if (child_score > max_child_score) {
                    max_child_score = child_score;
                }
            }
            map[seq] = max_child_score;
        }
        cout << val << "<=" << score << "|" << seq << "<=" << max_child_score << endl;
        return score + max_child_score;
    }
    
    int brust(int idx, vector<int>& nums) {
        vector<int>::iterator iter = nums.begin();
        iter += idx;
        int v1 = (iter == nums.begin()) ? 1 : *(iter - 1);
        int v2 = *iter;
        int v3 = ((iter + 1) == nums.end()) ? 1 : *(iter + 1);
        nums.erase(iter);
        return v1 * v2 * v3;
    }

    void removeAllZeros(vector<int>& nums) {
        for (auto iter = nums.begin(); iter < nums.end(); iter++) {
            if (*iter == 0) {
                nums.erase(iter);
            }
        }
    }

    string join(vector<int> vec, char c) {
        stringstream stream;
        string result;
        for (auto iter = vec.begin(); iter < vec.end() - 1; iter++) {
            stream << *iter;
            stream << c;
        }
        stream << *(vec.end() - 1);
        stream >> result;
        return result;
    }
};