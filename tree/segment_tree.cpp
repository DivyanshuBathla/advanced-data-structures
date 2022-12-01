
#include<bits/stdc++.h>
using namespace std;
class SegmentTree
{
    int * STree;
    size_t s;
    int n;
    int buildTree(vector<int> &arr,int sl,int sr,int index)
    {
        if(sl==sr)
        {
            STree[index]=arr[sl];
            return STree[index];
        }
        else
        {
            int mid=(sl+sr)/2;
            STree[index]=buildTree(arr,sl,mid,2*index+1)+buildTree(arr,mid+1,sr,2*index+2);
            return STree[index];
        }
    }
    void updateutils(int sl,int sr,int val,int index,int i)
    {
        if(sl<=index&&sr>=index)
        {
            
            STree[i]+=val;
            if(sl==sr)
                return;
            int mid=(sl+sr)/2;
            if(sl<=index&&index<=mid)
            {
                updateutils(sl,mid,val,index,2*i+1);
            }
            else
            {
                 updateutils(mid+1,sr,val,index,2*i+2);
            }
            // updateutils(sl,mid,val,index,2*i+1);
            //  updateutils(mid+1,sr,val,index,2*i+2);

        }
        
    }
    int rangeSutils(int sl,int sr,int ql,int qr,int i)
    {
        if(qr<sl||sr<ql) return 0;

        else if(ql<=sl&&sr<=qr)
        {
            return(STree[i]);
        }
        else
        {
            int mid=(sl+sr)/2;
            return rangeSutils(sl,mid,ql,qr,2*i+1)+rangeSutils(mid+1,sr,ql,qr,2*i+2);
        }
    }
    public:
    SegmentTree(vector<int> & arr)
    {
           n=arr.size();
           s=pow(2,ceil(log2(n)+1))-1;
           STree=new int(s);
           buildTree(arr,0,n-1,0);
    }
    int rangeS(int ql,int qr)
    {
        return rangeSutils(0,n-1,ql,qr,0);
    }
    void update(int pos,int val)
    {
        updateutils(0,n-1,val,pos,0);
    }
    void display()
    {
        
        for(int i=0;i<s;i++)
        {
            cout<<STree[i]<<" ";
        }
        cout<<endl;
    }
};
int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    SegmentTree stree(arr);
    stree.display();
    int q;
    cin>>q;
    
    for(int k=0;k<q;k++)
    {
        int ch;
        cin>>ch;
        int val,index,upval;
        
        int i,j;
        switch(ch)
        {
            case 1: cin>>index>>val;
                    upval=val-arr[index];
                    arr[index]=val;
                    stree.update(index,upval);
                    stree.display();
                    break;
            case 2: cin>>i>>j;
                    cout<<stree.rangeS(i,j)<<endl;
                    break; 
        }

    }

}
