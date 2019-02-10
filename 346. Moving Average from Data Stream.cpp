class MovingAverage {
private:
    queue<int> window;
    int size;
    double sum;
public:
    /** Initialize your data structure here. */
    MovingAverage(int size):size(size) {
        sum = 0;
    }
    
    double next(int val) {
        sum += val;
        window.push(val);
        if(window.size() <= this->size) 
            return sum/window.size();
        else {
            sum -= window.front();
            window.pop();
            return sum/this->size;
        }
    }
};