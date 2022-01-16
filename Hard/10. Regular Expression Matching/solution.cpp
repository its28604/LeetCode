class Solution {
public:
    bool isMatch(string s, string p) {
        char* cur_s = s.data();
        char* cur_p = p.data();
        bool comp = BasicJudgment(cur_s, cur_p);
        if (!comp)
            return false;
        return Compare(cur_s, cur_p);
    }
    
    bool Compare(char* cur_s, char* cur_p) {
        cout << "Compare, cur_s:" << *cur_s << ", cur_p:" << *cur_p << '\n';
        if (*cur_p == *cur_s && *cur_p == '\0')
            return true;

        char* next_s = cur_s + 1;
        char* next_p = cur_p + 1;

        if (*cur_p == '.' && *next_p == '*') {
            return UniversalCharExpression(cur_s, cur_p + 2);
        }
        if ((*cur_p == '.' && *cur_s != '\0') || *cur_p == *cur_s) {
            if (*next_p == '*') {
                bool comp = DuplicateExpression(cur_s, cur_p);
                if (comp)
                    return true;
                else Compare(cur_s, cur_p + 2);
            }
            return Compare(cur_s + 1, cur_p + 1);
        }
        else {
            if (*cur_p == '\0')
                return false;

            if (*next_p == '*') 
                return Compare(cur_s, cur_p + 2);

            return false;
        }
    }

    bool BasicJudgment(char* cur_s, char* cur_p) {
        vector<string> nor_ex_list;
        string nor_ex = "";
        char* flag = cur_p;
        while (*flag != '\0') {
            char* next = flag + 1;
            if (*next != '*') {
                if (nor_ex == "") 
                    nor_ex = *flag;
                else 
                    nor_ex += *flag;
                flag += 1;
            }
            else {
                if (nor_ex != "") {
                    nor_ex_list.push_back(nor_ex);
                    nor_ex = "";
                }
                flag += 2;
            }
        }

        if (nor_ex != ""){
            nor_ex += '$';
            nor_ex_list.push_back(nor_ex);
        }

        for (auto &v : nor_ex_list) {
            cout << "BasicJudgment, v:" << v << '\n';
            string s(cur_s);
            if (!Contains(cur_s, v.data()))
                return false;
        }
        return true;
    }

    bool Contains(char* cur_s, char* cur_p) {
        if (*cur_p == '$')
            return *cur_s == '\0';

        if (*cur_p == '\0')
            return true;

        if (*cur_s == '\0')
            return false;

        if (*cur_s == *cur_p || *cur_p == '.') {
            bool contains = Contains(cur_s + 1, cur_p + 1);
            if (contains)
                return true;
        }

        return Contains(cur_s + 1, cur_p);
    }

    bool DuplicateExpression(char* cur_s, char* cur_p) {
        char* flag_s = cur_s;

        int actual_count = 0;
        while (*flag_s == *cur_s) {
            actual_count++;
            flag_s++;
        }
        bool comp = false;
        while (!comp && actual_count >= 0) {
            cout << "BasicJudgment, cur_s:" << *cur_s <<", actual_count:" << actual_count << '\n';
            comp = Compare(cur_s + actual_count--, cur_p + 2);
            cout << "_BasicJudgment, cur_s:" << *cur_s <<", actual_count:" << actual_count << '\n';
        }
        return comp;
    }

    bool UniversalCharExpression(char* cur_s, char* cur_p) {
        bool comp = Compare(cur_s, cur_p);
        if (comp)
            return true;
        if (*cur_s == '\0')
            return false;
        
        return UniversalCharExpression(cur_s + 1, cur_p);
    }
};