#include<bits/stdc++.h>
#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std; 


// This functions helps us find the longest Increasing subsequence in O(n*logn) time Complexity // 
int longestSubsequence(int n, int a[])
{
      vector<int> v;
       for(int i=0;i<n;i++){
           if(v.empty() || a[i]>v.back()){
                v.push_back(a[i]);
           }else{
               auto it = lower_bound(v.begin(),v.end(),a[i]);
               *it = a[i];
           }
       }
       return v.size();
}
int longestSubsequence2(int n, int a[])
{
      vector<int> v;
       for(int i=0;i<n;i++){
           if(v.empty() || a[i]>=v.back()){
                v.push_back(a[i]);
           }else{
               auto it = upper_bound(v.begin(),v.end(),a[i]);
               *it = a[i];
           }
       }
       return v.size();
}
int main() {
  
   cout << "Enter number of Elements" << endl;
   int n;
   cin >> n;

   cout << "Enter " << n << " " << "Elements" << endl;

   int arr[n];

   for(int i=0;i<n;i++){
      cin >> arr[i];
   }

   cout << "length of Longest Strictly Increasing Subsequence is " << longestSubsequence(n,arr) << endl;
   cout << "length of Longest Increasing Subsequence is " << longestSubsequence2(n,arr) << endl;
   

     
}
