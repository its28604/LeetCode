class Solution {
public:
    bool isMatch(string s, string p) {
        char* cur_s = s.data();
        char* cur_p = p.data();
        return Compare(cur_s, cur_p);
    }
    
    bool Compare(char* cur_s, char* cur_p) {
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
            if (*next_p == '*') 
                return Compare(cur_s, cur_p + 2);
            else 
                return false;
        }
    }

    bool DuplicateExpression(char* cur_s, char* cur_p) {

        char* next_p = cur_p + 1;
        char* anext_p = cur_p + 2;

        int atleast_count = 0;
        while (*anext_p == *cur_p) {
            atleast_count++;
            anext_p++;
        }


        char* flag_s = cur_s;

        int actual_count = 0;
        while (*flag_s == *cur_s) {
            actual_count++;
            flag_s++;
        }

        if (actual_count >= atleast_count){
            bool comp = false;
            while (!comp && actual_count != 0) {
                comp = Compare(cur_s + actual_count--, cur_p + 2 + atleast_count);
            }
            return comp;

        }
        else return false;
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