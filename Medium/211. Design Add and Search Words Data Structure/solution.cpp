class WordDictionary {
public:
    
    WordDictionary() {
    }
    
    void addWord(string word) {
        A* ch = root;
        const char* cs = word.c_str();
        for (int i = 0; i < word.length(); i++) {
            char c = *cs++;
            auto temp = addChild(ch, c);
            ch = temp;
        }
        addChild(ch, '\0');
    }
    
    bool search(string word) {
        return find(root, word.c_str());
    }

private:
    struct A {
        A* next[27] = { NULL };
    };
    A* root = new A();

    A* addChild(A* ch, char c) {
        int idx = getIdx(c);
        if (ch->next[idx] != NULL)
            return ch->next[idx];
        A* _ch = new A();
        ch->next[idx] = _ch;
        return _ch;
    }

    bool find(A* ch, const char* c) {
        if (*c == '.') {
            for (int i = 0; i < 27; i++) {
                A* _ch = ch->next[i];
                if (_ch != NULL && find(_ch, c + 1))
                    return true;
            }
        }
        else {
            int idx = getIdx(*c);
            if (ch->next[idx] != NULL) {
                if (idx == 26)
                    return true;
                return find(ch->next[idx], c + 1);
            }
        }
        return false;
    }

    int getIdx(const char c) {
        int idx;
        idx = (int)c - 97;
        if (idx == -97)
            idx = 26;
        return idx;
    }

};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */