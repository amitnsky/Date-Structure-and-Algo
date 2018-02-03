#include <iostream>

using namespace std;

void printArr(int a[],int n){
    for(int i=1;i<=n;i++){
        cout<<a[i]<<",";
    }
    cout<<endl;
}
void adjust(int a[],int index,int n){
    int item=a[index];
    int i=2*index;
    while(i<=n){
        if(i<n&&a[i]<a[i+1]){
            i+=1;
        }
        if(item>a[i]){
            break;
        }
        a[i/2]=a[i];
        i*=2;
    }
    a[i/2]=item;
}
//n is size of array including new element to be inserted
void insert(int a[],int t,int n){
    int i=n;
    while(i>1&&a[i/2]<t){
        if(a[i/2]<t){
            a[i]=a[i/2];
            i/=2;
        }
    }
    a[i]=t;
}
int delMax(int a[],int n){
    int item=a[1];
    a[1]=a[n];
    adjust(a,1,n-1);
    return item;
}
void heapify(int a[],int n){
    for(int i=n;i>1;i--){
        adjust(a,i/2,n);
    }
}
void heapSort(int a[],int n){
    int item;
    for(int i=n;i>1;i--){
        item=delMax(a,i);
        a[i]=item;
    }
}
int main()
{
   int arr[11]={0,55,35,45,70,80,60,85,50};
   int n=8;
   heapify(arr,n);
   heapSort(arr,n);
   printArr(arr,n);
   return 0;
}
