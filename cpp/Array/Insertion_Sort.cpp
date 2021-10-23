#include<iostream>
using namespace std;
class isort
{
    int a[25],n;
    public:
    void input()
    {
        cout<<"Enter the size of the array: ";
        cin>>n;
        cout<<"Enter the elements of the array: ";
        for(int i=1;i<=n;i++)
        cin>>a[i];
    }
    void insertion()
    {
        int c1=0,c2;
        for(int i=2;i<=n;i++)
        {
            c2=1;
            int current=a[i];
            int j=i-1;
            while(current<a[j] && j>0)
            {
                a[j+1]=a[j];
                j--;
                if(j!=0)
                c2++;
            }
            a[j+1]=current;
            cout<<"No of comparision made in "<<i-1<<" pass :"<<c2<<endl;
            cout<<"Array after "<<i-1<<" pass :";
            output();
            c1+=c2;
        }
        cout<<"Total no of comparisions made :"<<c1<<endl;
    }
    void output()
    {
        for(int i=1;i<=n;i++)
        cout<<a[i]<<" ";
        cout<<endl;
    }
};

int main()
{
    isort i;
    i.input();
    cout<<"Unsorted Array :";
    i.output();
    i.insertion();
    cout<<"Sorted Array :";
    i.output();
    return 0;
}
