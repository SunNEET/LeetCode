class MovingAverage {
private:
    queue<int> qi;
    int size;
    double sum;
public:
    MovingAverage(int size) {
        this->size = size;
        this->sum = 0.0;
    }
    
    double next(int val) {
        if(this->qi.size() < this->size) {
            this->sum += val;
            this->qi.push(val);
            return this->sum/this->qi.size();
        } else {
            this->sum -= this->qi.front();
            this->qi.pop();
            this->qi.push(val);
            this->sum += val;
            return this->sum/this->qi.size();
        }
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */