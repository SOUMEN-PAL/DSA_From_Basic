#include<bits/stdc++.h>
using namespace std;

class minHeap{
    int *arr;
    int size;
    int capacity;
    public:
        minHeap(int n){
            arr = new int[n];
            size= 0;
            capacity = n;
        }

        minHeap(int Arr[] , int n){
            arr = Arr;
            size = n;
            buildHeap(arr , n);
        }

        //Utility functions
        int left(int i){
            return 2 * i + 1;
        }

        int right(int i){
            return 2 * i + 2;
        }

        int parent(int i){
            int p = floor((i-1)/2);
            return p;
        }

        void insert(int data){
            if(size == capacity){
                return;
            }
            size++;
            arr[size-1] = data;
            // for insert we need to use bubble up approach
            for(int i = size - 1 ; i != 0 && arr[parent(i)] > arr[i] ;){
                swap(arr[parent(i)] , arr[i]);
                i = parent(i);
            }
        }

        // Heapify
        void minHeapify(int i){
            int lt = left(i);
            int rt = right(i);
            int smallest = i;
            if(lt < size and arr[lt] < arr[smallest]){
                smallest = lt;
            }

            if(rt < size and arr[rt] < arr[smallest]){
                smallest = rt;
            }

            if(smallest != i){
                swap(arr[i] , arr[smallest]);
                minHeapify(smallest);//kyuki current bade elemnt ko mene niche laa diya
            }
        }


        void extractMin(){
            if(size == 0){
                return;
            }
            if(size == 1){
                return;
            }
            int min = arr[0];
            swap(arr[0] , arr[size - 1]);
            size--;
            minHeapify(0);
            cout<<"smalles value is: "<< min<<endl;
        }


        void decreaseKey(int i , int val){
            arr[i] = val;
            while(i != 0 and arr[i] < arr[parent(i)]){
                swap(arr[i] , arr[parent(i)]);
                i = parent(i);
            }
        }

        void increaseKey(int i , int val){
            arr[i] = val;
            minHeapify(i);
        }


        void d_lete(int i){
            decreaseKey(i , INT_MIN);
            extractMin();
        }

        void print_heap(){
            for(int i = 0 ; i<size ; i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
        

        void buildHeap(int arr[] , int n){
            for(int i = (n/2) - 1 ; i != 0 ; i--){
                minHeapify(i);
            }
        }
};


int main(){
    int arr[] = {10,34,23,67,12};
    int n = sizeof(arr)/sizeof(arr[0]);
    minHeap myHeap(arr , n);

    myHeap.print_heap();
    myHeap.d_lete(2);
    myHeap.print_heap();


    return 0;
}