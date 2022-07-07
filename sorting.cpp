#include <bits/stdc++.h>
using namespace std;

void print(vector<int> &arr){
    for(auto i:arr){
        cout << i << " ";
    }
    cout << endl;
}


void modifiedCountSort(vector<int> &arr,int e){
    vector<int> count(10,0);
    for(auto i:arr){
        count[(i/e)%10]++;
    }
    
    for(int i=1;i<10;i++){
        count[i]=count[i]+count[i-1];
    }
    
    for(int i=9;i>0;i--){
        count[i]=count[i-1];
    }
    count[0]=0;
    int n=arr.size();    
    vector<int> temp(n);
    for(auto i:arr){
        temp[count[(i/e)%10]]=i;
        count[(i/e)%10]++;
    }
    for(int i=0;i<n;i++){
        arr[i]=temp[i];
    }
}
void radixSort(vector<int> &arr){
    int maxVal=INT_MIN;
    for(auto i:arr){
        maxVal=max(maxVal,i);
    }
    
    int e=1;
    while(e<=maxVal){
        modifiedCountSort(arr,e);
        e*=10;
    }
    
}

void countSort(vector<int> &arr){
    vector<int> count(256,0);
    for(int i=0;i<arr.size();i++){
        count[arr[i]]++;
    }
    for(int i=1;i<256;i++){
        count[i]+=count[i-1];
    }
    
    for(int i=255;i>0;i--){
        count[i]=count[i-1];
    }
    
    count[0]=0;
    int n=arr.size();
    vector<int> temp(n);
    for(int i=0;i<n;i++){
        temp[count[arr[i]]]=arr[i];
        count[arr[i]]++;
    }
    for(int i=0;i<n;i++){
        arr[i]=temp[i];
    }
    
}


void heapify(vector<int> &arr,int i,int n){
    
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;
    if(left<n && arr[left]>arr[largest]){
        largest=left;
    }
    if(right<n && arr[right]>arr[largest]){
        largest=right;
    }
    if(largest!=i){
        swap(arr[i],arr[largest]);
        heapify(arr,largest,n);
    }
}

void heapSort(vector<int> &arr){
    int n=arr.size();
    for(int i=n/2-1;i>=0;i--){
        heapify(arr,i,n);
    }
    
    for(int i=n-1;i>=0;i--){
       swap(arr[0],arr[i]);
       heapify(arr,0,i);
    }
}

int partition(vector<int> &arr,int l,int r){
    int pivot = arr[r];
    int i=l-1;
    for(int j=l;j<=r-1;j++){
        if(pivot>arr[j]){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[r]);
    return i+1;
}
void quickSort(vector<int> &arr,int l,int r){
    if(l<r){
        int indx=partition(arr,l,r);
        quickSort(arr,l,indx-1);
        quickSort(arr,indx+1,r);
    }
}

void merge(vector<int> &arr,int l,int mid,int r){
    int n=r-l+1;
    vector<int> temp(n);
    int i=l;
    int j=mid+1;
    int k=0;
    while(i<=mid && j<=r){
        if(arr[i]<arr[j]){
            temp[k++]=arr[i++];
        }else{
            temp[k++]=arr[j++];
        }
    }
    while(i<=mid){
        temp[k++]=arr[i++];
    }
    while(j<=r){
        temp[k++]=arr[j++];
    }
    k=0;
    for(i=l;i<=r;i++){
        arr[i]=temp[k++];
    }
}

void mergeSort(vector<int> &arr,int l,int r){
    if(l<r){
        int mid=(l+r)/2;
        mergeSort(arr,l,mid);
        mergeSort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
}

void insertionSort(vector<int> &arr){
    int n=arr.size();
    for(int i=1;i<n;i++){
        int j=i-1;
        int t=arr[i];
        while(j>=0 && arr[j]>t){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=t;
    }
}


void bubbleSort(vector<int> &arr){
    int n=arr.size();
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}


void selectionSort(vector<int> &arr){
    int n=arr.size();
    for(int i=0;i<n;i++){
        int indx=i;
        for(int j=i;j<n;j++){
            if(arr[j]<arr[indx]){
                indx=j;
            }
        }
        swap(arr[i],arr[indx]);
    }
}



int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    // selectionSort(arr);
    // bubbleSort(arr);
    //insertionSort(arr);
    // mergeSort(arr,0,arr.size()-1);
    // quickSort(arr,0,arr.size()-1);
    // heapSort(arr);
    // countSort(arr);
    // radixSort(arr);
    print(arr);
    
}