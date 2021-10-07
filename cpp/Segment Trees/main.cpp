#include<iostream>
#include<bits/stdc++.h>
using namespace std;



int constructST(int index,int* st,int arr[],int low, int high) //Seg Tree const
{
    if(low==high)
    {
        st[index]=arr[low];
        return arr[low];
    }
    
    int mid=(low+high)/2;
    
    st[index]=constructST(2*index+1,st,arr,low,mid)+constructST(2*index+2,st,arr,mid+1,high);
    
    return st[index];
}


int* STHeight(int arr[],int n)  // to find the max size of Seg Tree
{
    int x=(int)(ceil(log2(n)));
    
    int max_size=2*(int)(pow(2,x))-1;
    
    int *st=new int[max_size];
    
    constructST(0,st,arr,0,n-1);
    
    return st;
}

int getSum(int* st,int index,int low,int high,int l,int r) //sum of a given range(l-r)
{
    //3 cases arise:  
    //1)completely outside the l-r range ->return 0
    //2)completely inside the l-r range  ->return value at that index
    //3)overlapping with the l-r range   ->call getsum on both right and left child
    
    if(low>=l and high<=r)
        return st[index];
    if(l>high or r<low)
        return 0;
    
    int mid=(low+high)/2;
    return getSum(st,2*index+1,low,mid,l,r)+getSum(st,2*index+2,mid+1,high,l,r);
    
}

void updateST(int *st,int index,int low,int high,int diff,int i)
{
    if(i<low or i>high)
        return;
        
    st[index]+=diff;
    if(low!=high)
    {
        int mid=(low+high)/2;
        updateST(st,2*index+1,low,mid,diff,i);
        updateST(st,2*index+2,mid+1,high,diff,i);
    }
}

int* update(int* st,int arr[],int n,int i,int val)
{
    if(i<0 or i>n-1)
        return st;
    
    int diff=val-arr[i];
    arr[i]=val;     //update the value in array
    
    updateST(st,0,0,n-1,diff,i);  //update the values in Seg tree
    
    return st; //return updated Seg tree
}

int main()
{
    int arr[6]={1,2,3,4,5,6};
    int x=(int)(ceil(log2(6)));
    int max_size=2*(int)(pow(2,x))-1;
    int* st=STHeight(arr,sizeof(arr)/sizeof(arr[0]));
    for(int i=0;i<max_size;i++)
        cout<<st[i]<<" ";
    cout<<endl<<endl;
    cout<<getSum(st,0,0,5,1,3);
    cout<<endl;
    update(st,arr,6,3,7);
    for(int i=0;i<max_size;i++)
        cout<<st[i]<<" ";
    return 0;
}

