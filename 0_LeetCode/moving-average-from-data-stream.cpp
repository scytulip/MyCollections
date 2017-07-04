/*
346. Moving Average from Data Stream My Submissions QuestionEditorial Solution
Total Accepted: 3568 Total Submissions: 5982 Difficulty: Easy
Given a stream of integers and a window size, calculate the moving average of all integers in the sliding window.

For example,
MovingAverage m = new MovingAverage(3);
m.next(1) = 1
m.next(10) = (1 + 10) / 2
m.next(3) = (1 + 10 + 3) / 3
m.next(5) = (10 + 3 + 5) / 3
Show Company Tags
Show Tags
*/

class MovingAverage {
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        size_ = size;
        sum_ = 0;
    }
    
    double next(int val) {
        if (qavg.size()==size_) {
            sum_ -= qavg.front();
            qavg.pop();
        }
        qavg.push(val);
        sum_ += val;
        
        return (double)sum_/(double)(qavg.size());
    }
private:
    int size_;
    int sum_;
    queue<int> qavg;
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */