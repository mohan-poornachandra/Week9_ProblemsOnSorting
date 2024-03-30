//Find the minimum operations required to sort the array in increasing order. In one operation ,
//you can set each occurrence of one element to 0.

//Here, we are given with an array which needs to be sorted by just replacing minimum  
//elements with 0. We need to return the no. of replaces made.

#include<iostream>
#include<vector>

using namespace std;

int main()
{
    int n;
    cout<<"Enter n value: "; cin>>n;
    vector<int> arr(n);
    cout<<"Enter elements: "<<endl;
    for(int i=0;i<n;i++)
      cin>>arr[i];

    int count=0;
    bool flag=true;
    //I iterate from the end and see if arr[i]<arr[i-1]. If so, I have to replace all left
    // elements with 0 so that the array gets sorted!

    for(int i=n-1;i>0;i--)
    {
        if(flag){
            if(arr[i]<arr[i-1])
            {
                count =i;   
                flag=false;
            }
        }
        else arr[i]=0;    

    }
    if(!flag) arr[0]=0; //The last element will be left as  the loop ends at i=0
    cout<<"New sorted array: "<<endl;
    for(int i=0;i<n;i++) cout<<arr[i]<<" ";
    cout<<endl;
    cout<<"Minimum operations: "<<count;


    
}