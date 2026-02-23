class Solution {
public:
    string predictPartyVictory(string senate) {
        queue<int> dq, rq;
        int n = senate.size();

        for(int i=0 ; i<senate.size() ; i++){
            if(senate[i] == 'R'){
                rq.push(i);
            }
            if(senate[i] == 'D'){
                dq.push(i);
            }
        }

        while(!rq.empty() && !dq.empty()){
            int rfront = rq.front();
            rq.pop();
            int dfront = dq.front();
            dq.pop();

            if(rfront < dfront){
                rq.push(rfront+n);
            }
            else{
                dq.push(dfront+n);
            }
        }
        if(dq.empty()){
            return "Radiant";
        }
        return "Dire";
    }
};