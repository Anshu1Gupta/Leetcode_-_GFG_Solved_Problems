class MedianFinder {
public:
    priority_queue<int>left;
    priority_queue<int,vector<int>,greater<int>>right;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(left.empty()&&right.empty()){
            left.push(num);
        }
        else if(left.size()==right.size()){
            if(num>right.top()){
                left.push(right.top());
                right.pop();
                right.push(num);
            }
            else{
                left.push(num);
            }
        }
        else{
            if(num<left.top()){
                right.push(left.top());
                left.pop();
                left.push(num);
            }
            else{
                right.push(num);
            }
        }
        
        
    }
    
    double findMedian() {
        
        int n=left.size();
        int m=right.size();
        
        if((n+m)%2==0){
            return (left.top()+right.top())/(2.0);
        }
        else return left.top()*1.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */