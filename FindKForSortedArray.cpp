//Question: Given an array, arr[], containing ‘n’ integers, the task is to find an integer (say K) such that after replacing each 
//and every index of the array by |a_i - K| where (i ∈ [1, n]) results in a sorted array. If no such integer exists that 
//satisfies the above condition, then return -1. Find the range of ‘K’.

//REFER NOTES FOR A DETAILED SOLUTION.
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

float min(float a,float b)
{
    if(a>b) return b;
    else return a;
}
float max(float a,float b)
{
    if(a>b) return a;
    else return b;
}
bool findk(vector<int> &arr, vector<int> &range)
{

    float kmin=-9999,kmax=9999;
    int n=arr.size();
    for(int i=0;i<n-1;i++)
    {
        if(arr[i+1]>=arr[i])
          kmax= min(kmax,(float)(arr[i+1]+arr[i])/2);

        else 
           kmin= max(kmin,(float)(arr[i+1]+arr[i])/2);

        if(kmin>kmax) return false;
    }
    if(kmin!=(int)kmin )
      kmin = (int)kmin + 1;
    kmax = (int)kmax;
    
    range[0]=kmin;
    range[1]=kmax;
    return true;
}
int main()
{
    int n;
    cout<<"Enter n value: "; cin>>n;
    vector<int> arr(n);
    cout<<"Enter elements: "<<endl;
    for(int i=0;i<n;i++)
      cin>>arr[i];

    vector<int> ans(2);
    bool flag = findk(arr,ans);
    if(flag)
   { 
    cout<<"Range of values are: "<<endl;
    if(ans[0]==ans[1]) cout<<ans[1];
    else
      for(int i=ans[0];i<=ans[1];i++)
        cout<<i<<" ";
    }
    else cout<<"No value of k is possible "<<endl;
}