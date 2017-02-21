string getTask(vector<string> list, int n) {
        int lastIndex = 0;
        while(list.size() > 1) {
            int removeIndex = ((lastIndex + n - 1) % list.size());
            lastIndex = removeIndex;
            list.erase(list.begin() + removeIndex);
        }
        
        return list[0];
    }

/* TIMES OUT FOR LARGE n
string getTask(vector<string> list, int n) {
        int lastIndex = 0;
        
        queue<int> indices;
        for(int i = 0; i < list.size(); i++) {
            indices.emplace(i);
        }
        
        while(!indices.empty()) {
            for(int i = 1; i < n; i++) {
                indices.emplace(indices.front());
                indices.pop();
            }
            
            lastIndex = indices.front();
            indices.pop();
        }
        
        return list[lastIndex];
    }
*/
