class MedianFinder {
public:
    // Adds a number into the data structure.
    void addNum(int num) {
        ++length;
        if (max_heap.empty())
            max_heap.push(num);
        else if (num <= max_heap.top()) {
            max_heap.push(num);
        } else {
            min_heap.push(num);
        }
        while (max_heap.size()>length/2) {
            min_heap.push(max_heap.top());
            max_heap.pop();
        }
        while (min_heap.size()>length/2) {
            max_heap.push(min_heap.top());
            min_heap.pop();
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        if (length%2 == 1) 
            return max_heap.top();
        else
            return (double)(max_heap.top()+min_heap.top())/2;
    }
    
    MedianFinder() : max_heap(Heap(Compare(false))), min_heap(Heap(Compare(true))), length(0) {}

private:
    class Compare {
    public:
        Compare(bool flag) : flag_(flag) {}
        bool operator() (const int& a, const int& b) {
            return flag_ ? a>b : a<b;
        }
    private:
        // false MaxHeap
        bool flag_;
    };
    using Heap = priority_queue<int, vector<int>, Compare>;
    Heap max_heap;
    Heap min_heap;
    int length;
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();