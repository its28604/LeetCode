class WordDictionary {
public:
    
    WordDictionary() {
    }
    
    void addWord(string word) {
        Character &ch = root;
        for (int i = 0; i < word.length(); i++) {
            char c = word[i];
            auto temp = ch.AddChild(c);
            cout << ch.child.size() << "(ch)\n";
            cout << root.child.size() << "(root)\n";
            ch = temp;
        }
    }
    
    bool search(string word) {
        return root.Find(word.c_str());
    }

private:
    struct Character {
        public: 
            char Self;
            Character(char c) {
                Self = c;
            }
        
            Character AddChild(char c) { 
                cout << "AddChild(" << c << "), ch = " << Self << ", child count = " << child.size() << "\n";
                for (Character ch : child) {
                    cout << "Child exist..." << ch.Self << "...";
                    if (ch.Self == c) {
                        cout << "yes\n";
                        return ch;
                    }
                    cout << "not\n";
                }
                auto _ch = Character(c);
                child.push_back(_ch);
                cout << child.size() << "\n";
                return _ch;
            }

            bool Find(const char* c) {
                cout << "Find(" << *c << "), " << Self << ", " << child.size() << "\n";
                bool _dots_flag = false;
                bool _found_flag = false;
                if (*c == '.') 
                    _dots_flag = true;
                if (*c == '\0')
                    return true;
                    
                for (Character ch : child) {
                    cout << "for: ch=" << ch.Self << "\n";
                    if (_dots_flag){
                        if (ch.Find(c++))
                            return true;
                    }
                    else if (ch.Self == *c) {
                        if (_dots_flag) {
                            _found_flag = true;
                        }

                        return ch.Find(c++);
                    }
                }
                return false;
            }
            vector<Character> child;
        private:
    };
    Character root = Character('0');
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */