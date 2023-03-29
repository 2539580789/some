#include<iostream>
#include<vector>
using namespace std;
class Heap{
    public:
        vector<int> arr;
        Heap(vector<int>b):arr(b){}
        void adjust(vector<int> &arr, int len, int idx)
        {
            int left = 2 * idx + 1;
            int right = 2 * idx + 2;
            int max = idx;
            if (left < len && arr[left] > arr[max])
                max = left;
            if (right < len && arr[right] > arr[max])
            {
                max = right;
            }
            if (max != idx)
            {
                swap(arr[idx], arr[max]);
                adjust(arr, len, max);
            }
}
void heapsort(vector<int>& arr){
    for (int i = arr.size()/2 - 1; i >= 0;i--){
        adjust(arr, arr.size(), i);
    }
    for (int i = arr.size() - 1; i >= 1;i--){
        swap(arr[0], arr[i]);
        adjust(arr, i, 0);
    }
}
void heap_pop(vector<int>& arr){
    arr.pop_back();
    heapsort(arr);
}
};
int main()
{
    vector<int> arr = {8, 1, 14, 3, 21, 5, 7, 10};
    Heap a(arr);
    a.heapsort(arr);
    for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<endl;
    }
    a.heap_pop(arr);
    for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<endl;
    }
    return 0;
}