class BrowserHistory {
public:
    stack<string> bSt , fwdSt;
    BrowserHistory(string homepage) {
        bSt.push(homepage);
    }
    
    void visit(string url) {
        while(!fwdSt.empty()){
            fwdSt.pop();
        }
        bSt.push(url);
    }
    
    string back(int steps) {
        while(steps--){
            if(bSt.size() > 1){
                fwdSt.push(bSt.top());
                bSt.pop();
            }
            else{
                break;
            }
        }
        return bSt.top();
    }
    
    string forward(int steps) {
        while(steps--){
            if(!fwdSt.empty()){
                bSt.push(fwdSt.top());
                fwdSt.pop();
            }
            else{
                break;
            }
        }
        return bSt.top();
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */