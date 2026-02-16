class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> cars;
        for(int i=0 ; i<position.size() ; i++){
            cars.push_back({position[i],speed[i]});
        }

        sort(cars.begin(),cars.end());
        stack<double>st;

        for(int i=0 ; i<cars.size() ; i++){
            double time = (double)(target-cars[i].first)/cars[i].second; // time = distance/speed

            while(!st.empty() && time >= st.top()){
                st.pop();
            }
            st.push(time);
        }
        return st.size();
    }
};