class Solution {
public:
    bool isValid(string s) {
        stack<char> t;

        for(int i = 0; i<s.length(); i++) {
            t.push(s[i]);
            if(t.size() >= 3) {
                cout<<t.top()<<" "<<t.top()-1<<" "<<t.top()-2<<endl;
                if(t.top() == 'c') {
                    t.pop();
                    if(t.top() == 'b') {
                        t.pop();
                        if(t.top() == 'a') {
                            t.pop();
                            continue;
                            
                        }
                        t.push('b');
                    }
                    t.push('c');
                }
            }
        }
        if(t.size() == 0) {
            return true;
        }
        else{
            return false;
        }
    }
};