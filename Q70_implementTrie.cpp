class Trie {
    public:
        char data;
        vector<Trie*>children;
        bool isTerminal;
        Trie() {
            data='\0';
            // for(int i=0;i<26;i++)
            // {
            //     children[i]=NULL;
            // }
            children.resize(26,NULL);
            isTerminal=false;
        }
        
        void insert(string word) {
            if(word.size()==0)
            {
                this->isTerminal=true;
                return;
            }
            int idx=word[0]-'a';
            Trie* child;
            if(children[idx]!=NULL)
            {
                child=children[idx];
            }
            else
            {
                child = new Trie();
                children[idx]=child;
            }
            child->insert(word.substr(1));
        }
        
        bool search(string word) {
            if(word.size()==0)
            {
                return this->isTerminal;
            }
            int idx=word[0]-'a';
            Trie* child;
            if(children[idx]!=NULL)
            {
                child=children[idx];
            }
            else
            {
                return false;
            }
            return child->search(word.substr(1));
    
        }
        
        bool startsWith(string prefix) {
            if(prefix.size()==0)
            {
                return true;
            }
            int idx=prefix[0]-'a';
            Trie* child;
            if(children[idx]!=NULL)
            {
                child=children[idx];
            }
            else
            {
                return false;
            }
            return child->startsWith(prefix.substr(1));
    
        }
    };
    
    /**
     * Your Trie object will be instantiated and called as such:
     * Trie* obj = new Trie();
     * obj->insert(word);
     * bool param_2 = obj->search(word);
     * bool param_3 = obj->startsWith(prefix);
     */