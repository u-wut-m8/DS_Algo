#include<bits/stdc++.h>

using namespace std;

int main()
 {
     long long int t;
     cin>>t;
     while(t--)
     {
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        int left[n];
        int right[n];
        left[0]=a[0];
        right[n-1]=a[n-1];
        for(int i=1;i<n;i++)
        {
            if(a[i-1]>left[i-1])
                left[i]=a[i-1];
            else
                left[i]=left[i-1];
        }
        for(int i=n-2;i>=0;i--)
        {
            if(a[i+1]>right[i+1])
                right[i]=a[i+1];
            else
                right[i]=right[i+1];
        }
        int ans=0;

        for(int i=0;i<n;i++)
        {
            if(left[i]>a[i] && right[i]>a[i])
                ans+=min(left[i],right[i])-a[i];
        }

        cout<<ans<<endl;
    }
 }
