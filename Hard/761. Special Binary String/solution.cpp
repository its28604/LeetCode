struct SS {
public:
    SS(string substr, int idx) {
        this->substr = substr;
        this->len = substr.length();
        this->idx = idx;
    }
    string substr;
    int len;
    int idx;
};

class Solution {
public:
    string makeLargestSpecial(string s) {
        auto subs = getSpecialSubstrings(s);
        string swap_str = s;
        for (int i = 0; i < subs.size() - 1; i++) {
            for (int j = i + 1; j < subs.size(); j++) {
                SS a = subs[i];
                SS b = subs[j];
                if (a.idx + a.len == b.idx) {
                    string temp = s;
                    temp.replace(a.idx, b.len, b.substr);
                    temp.replace(a.idx + b.len, a.len, a.substr);
                    cout << "a:" << a.substr << ", idx:" << a.idx << ", len:" << a.len  << "\n";
                    cout << "b:" << b.substr << ", idx:" << b.idx << ", len:" << b.len  << "\n";
                    cout << s << "=>" << temp << "\n";
                    if (temp > swap_str) {
                        swap_str = temp;
                    }
                }
            }
        };
        if (swap_str != s)
            swap_str = makeLargestSpecial(swap_str);
        return swap_str;
    }

    vector<SS> getSpecialSubstrings(string s) {
        vector<SS> sub = *(new vector<SS>());
        int number_of[2];
        int perfix = 0;
        for (int i = 0; i < s.length();i++) {
            number_of[0] = 0;
            number_of[1] = 0;
            for (int j = i; j < s.length(); j++) {
                int c = s[j] - '0';
                int cp = c == 0 ? 1 : 0;
                number_of[c]++;
                if (number_of[0] > number_of[1])
                    break;
                if (number_of[c] == number_of[cp]) {
                    int len = number_of[c] * 2;
                    cout << len << "(len)\n";
                    int idx = i;
                    SS* ss = new SS(s.substr(idx, len), idx);
                    sub.push_back(*ss);
                }
                cout << "c:" << c << ", [0]:" << number_of[0] << ", [1]:" << number_of[1] << "\n";
            }
        }
        return sub;
    }
};