#include<iostream>
#include<vector>
using namespace std;
//冒泡排序  前-》后 小-》大 稳定
void bubble_sort(vector<int>& arr){
    for(int i=0;i<arr.size();i++){
        for(int j=0;j<arr.size()-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}
//选择排序  不稳定
void select_sort(vector<int>& arr){
    for(int i=0;i<arr.size();i++){
        int tmp=i;
        for(int j=i+1;j<arr.size();j++){
            if(arr[tmp]>arr[j]){
                tmp=j;
            }
        }          
        swap(arr[tmp],arr[i]);
    }
}
//插入排序  稳定
void insert(vector<int>& arr){
    int n=arr.size();
    for(int i=1;i<arr.size();i++){
        int cur=arr[i];
        int pre=i-1;
        while(pre>=0&&arr[pre]>cur){
            arr[pre+1]=arr[pre];
            pre--;
        }
        arr[pre+1]=cur;
    }
}
//希尔排序
void shell_sort(vector<int>& arr){
    for(int gap=arr.size()/2;gap>0;gap/=2){
        for(int i=gap;i<arr.size();i++){
            int j=i;
            int tmp=arr[j];
            if(arr[j-gap]>arr[j]){
                while(j-gap>=0&&tmp<arr[j-gap]){
                    arr[j]=arr[j-gap];
                    j-=gap;
                }
                arr[j]=tmp;
            }
        }
    }
}
//堆排序
void adjust(vector<int>& arr,int len,int idx){
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;
    int max = idx;
    if(left<len&&arr[left]>arr[max])
        max = left;
    if(right<len&&arr[right]>arr[max]){
        max = right;
    }
    if(max!=idx){
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
void quicksort(vector<int>& nums,int l,int r){
        if(l>=r){
            return;
        }
        int piv=nums[rand()%(r-l+1)+l];
        int i=l-1,j=r+1;
        while(i<j){
            while(nums[++i]<piv);
            while(nums[--j]>piv);
            if(i<j) swap(nums[i],nums[j]);
        }
        quicksort(nums, l, j);
        quicksort(nums, j+1, r);
}
int main()
{
    vector<int> arr = {8, 1, 14, 3, 21, 5, 7, 10};
    //heapsort(arr);
    quicksort(arr, 0, arr.size() - 1);
    for (int i = 0; i < arr.size(); i++)
    {
        cout<<arr[i]<<endl;
    }
    return 0;
}
