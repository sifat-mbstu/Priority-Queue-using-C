#include<stdio.h>
void max_heapify(int arr[], int node, int N)
{
    int L = node*2+1;
    int R = L+1;
    int maxIndex = node;
    
    if(L<N && arr[L]>arr[maxIndex])
        maxIndex = L;
    
    if(R<N && arr[R]>arr[maxIndex])
        maxIndex = R;
    
    if(maxIndex!=node)
    {
        int tmp = arr[node];
        arr[node] = arr[maxIndex];
        arr[maxIndex] = tmp;
        max_heapify(arr,maxIndex,N);
    }
}

void push_Maxheap(int arr[], int arraySize, int data)
{
    int root, index = arraySize;
    arr[arraySize] = data;
    
    while(index>0)
    {
        root = (index-1)/2;
        if(arr[index]>arr[root]){
            int tmp = arr[index];
            arr[index] = arr[root];
            arr[root] = tmp;
            index = root;
            }
        else break;
    }
}

int pop_Maxheap(int arr[], int N)
{
    int ret = arr[0];
    arr[0] = arr[N-1];
    int L,R,root;
    root = 0;
    while(root<N-1)
    {
        L = root*2 + 1;
        R = L+1;
        int MaxIndex = root;
        if(L<N-1 && arr[L]>arr[MaxIndex])
            MaxIndex = L;
        if(R<N-1 && arr[R] > arr[MaxIndex])
            MaxIndex = R;
        if(MaxIndex!=root)
        {
            int tmp = arr[root];
            arr[root] = arr[MaxIndex];
            arr[MaxIndex] = tmp;
            root = MaxIndex;
        }
        else break;
    }
    return ret;
}

int top_maxHeap(int* array, int n) {
    return array[0];
}


int main() {

    int numberOfElement = 6;
    int array[100] = {1,5,8,2,15,2};
    
    for(int i=numberOfElement/2; i>=0; i--){
        max_heapify(array,i,numberOfElement);
    }
    
    push_Maxheap(array, numberOfElement, 90);
    
    while (numberOfElement>0) {
        printf("Top = %d\n", top_maxHeap(array, numberOfElement));
        pop_Maxheap(array, numberOfElement);
        numberOfElement--;
    }
    
    return 0;
}
