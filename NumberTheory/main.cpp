#include <iostream>
#include <queue>

void swap(long long *num1, long long *num2){
    *num1 ^= *num2;
    *num2 ^= *num1;
    *num1 ^= *num2;
}

class MaxHeap{
private:
    long long heap_size, *heapArr, capacity;
public:
    MaxHeap(int cap){
        heap_size = 0;
        capacity = cap;
        heapArr = new long long[cap];
    }
    long long parent(long long index){
        return (index-1)>>1;
    }
    long long left(long long index){
        return (index<<1)+1;
    }
    long long right(long long index){
        return (index<<1)+2;
    }
    void percUp(long long index){
        while(index>>1 >= 0){
            if(heapArr[index] > heapArr[parent(index)])
                swap(&heapArr[index], &heapArr[parent(index)]);
            index = parent(index);
        }
    }
    void insert(long long val){
        if(heap_size == capacity){
            std::cout<<"Heap full!"<<std::endl;
            return;
        }
        heap_size++;
        long long index = heap_size-1;
        heapArr[index] = val;
        percUp(index);
    }
    long long maxChild(long long index){
        if(right(index) > heap_size)
            return left(index);
        else
            if(heapArr[right(index)] > heapArr[left(index)])
                return right(index);
            else
                return left(index);
    }
    void percDown(long long index){
        while(left(index) <= heap_size){
            long long mc = maxChild(index);
            if(heapArr[index] < heapArr[mc])
                swap(&heapArr[index], &heapArr[mc]);
            index = mc;
        }
    }
    void deleteMax(){
        long long retval = *heapArr;
        long long index = heap_size-1;
        *heapArr = heapArr[index];
        heap_size--;
        percDown(0);
        std::cout<<"Deleted item: "<<retval<<std::endl;
    }
    void buildHeap(long long *arr, long long n){
        long long index = (n-1)>>1;
        heap_size = n;
        for(long long i=0;i<n;i++)
            heapArr[i] = arr[i];
        while(index >= 0){
            percDown(index);
            index--;
        }
    }
    long long retMax(){
        return *heapArr;
    }
    ~MaxHeap(){
        delete[] heapArr;
    }
};

int main(){
    // long long *a, N, q, temp1, temp2;
    // std::cin>>N;
    // a = new long long[N];
    // for(long long i=0;i<N;i++)
    //     std::cin>>*(a+i);
    // std::cin>>q;
    // MaxHeap mh(q+N);
    // mh.buildHeap(a, N);
    // while(q--){
    //     std::cin>>temp1;
    //     if(temp1 == 2)
    //         std::cout<<mh.retMax()<<std::endl;
    //     else{
    //         std::cin>>temp2;
    //         mh.insert(temp2);
    //     }
    // }
    // delete[] a;
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
	pq.push(10);
	pq.push(20);
	pq.push(5);
	while(!pq.empty()){
		std::cout<<pq.top()<<' ';
		pq.pop();
	}
    std::cout<<std::endl;
    return 0;
}