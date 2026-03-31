class MedianFinder {
public:
    priority_queue<int>max_pq;
    priority_queue<int,vector<int>,greater<int>>min_pq;

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(max_pq.empty() || num < max_pq.top()){
            max_pq.push(num);
        }
        else{
            min_pq.push(num);
        }

        if(abs((int)(max_pq.size()-min_pq.size())) > 1){
            min_pq.push(max_pq.top());
            max_pq.pop();
        }
        else if(max_pq.size() < min_pq.size()){
            max_pq.push(min_pq.top());
            min_pq.pop();
        }
    }
    
    double findMedian() {
        if(max_pq.size() == min_pq.size()){
            return (double)(max_pq.top()+min_pq.top())/2;
        }
        return max_pq.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */