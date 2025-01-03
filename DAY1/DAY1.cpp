

#include <iostream>
#include <climits>
using namespace std;
int  secondlargest(int A[], int size){
    if(size<2){
        return -1;
    }
    int max=INT_MIN;
    int prev=INT_MIN;
    for (int i =0; i<size;i++){
        if(max<A[i]){
            prev=max;
            max=A[i];
        }
        else if(prev<A[i]){
            prev=A[i];
        }
    }
    
    return prev;
}
int main(){
    int size;
    cout<<"Enter the size of an array : ";
    cin>>size;
    int A[size];
    cout<<"Enter the elements of array : ";
    for (int i=0; i<size;i++){
        cin>>A[i];
    }
    cout<<endl;
    int a=secondlargest(A,size);
    if(a<0){
        cout<<"No second largest element exists";
    }
    else{
        cout<<"Second Largest element is "<<a;
    }
    
    return 0;
}
