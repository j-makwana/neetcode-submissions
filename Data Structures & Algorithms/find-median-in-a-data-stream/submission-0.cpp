class MedianFinder {
    private:
        priority_queue<int> max_heap_SMALL;
        priority_queue<int, vector<int>, greater<int>> min_heap_LARGE;
        int small_size;
        int large_size;

public:
    MedianFinder() {
       this->small_size = 0;
       this->large_size = 0; 

    }
    
    void addNum(int num) {
        //every time you add a num
        //if the lists are empty, add to the small
        if(small_size == 0 && large_size ==0 ){
            //add to small heap
            min_heap_LARGE.push(num);
            large_size++;
            return;
        }
        if(num <= min_heap_LARGE.top()){
            //push to small heap
            max_heap_SMALL.push(num);
            small_size++;
        }else{
            //push to large heap;
            min_heap_LARGE.push(num);
            large_size++;

        }
        while((large_size - small_size) >1){
            int top = min_heap_LARGE.top();
            min_heap_LARGE.pop();
            ///add to small max heap
            max_heap_SMALL.push(top);
            large_size--;
            small_size++;
        }
           while((small_size - large_size) >1){
            int top = max_heap_SMALL.top();
            max_heap_SMALL.pop();
            ///add to small max heap
            min_heap_LARGE.push(top);
            large_size++;
            small_size--;
        }


        
    }
    
    double findMedian() {
    if((small_size+large_size)==0){
        return 0.0;
    }
        if((small_size+large_size)%2 !=0){
            //check which one is larger
            if(small_size>large_size){
                return static_cast<double>(max_heap_SMALL.top());
            }else{
                return static_cast<double>(min_heap_LARGE.top()); 
            }
        }else{
            return (static_cast<double>(max_heap_SMALL.top()) + static_cast<double>(min_heap_LARGE.top())) /2;
        }
        
    }
};
