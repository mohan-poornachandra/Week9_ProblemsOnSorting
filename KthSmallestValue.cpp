//Given an array and a no. k, return the Kth smallest value in the array.

#include<iostream>
#include<vector>

using namespace std;

void insertionsort(vector<int> &arr)
{
    int n=arr.size();
    for(int i=1;i<n;i++)
    {
        for(int j=i;j>0;j--)
        {
            if(arr[j]<arr[j-1])
             swap(arr[j],arr[j-1]);
        }
    }
}
int main()
{
    int n,k;
    cout<<"Enter no. of elements(n): ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Enter array elements: ";
    for(int i=0;i<n;i++)
      cin>>arr[i];

    insertionsort(arr); //Sorting to find the kth smallest element.
    
    cout<<"Enter the value of K(<=n): "; cin>>k;
    cout<<"Kth smallest element is  "<<arr[k-1];
}