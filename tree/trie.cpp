#include<bits/stdc++.h>
using namespace std;
struct trie_node
{
    trie_node *ptr[26];
    bool isword;
};
class trie{
    
    public:
    trie_node *root;
    trie()
    {
        root=create_node();
    }
    trie_node *create_node()
    {
        trie_node *new_node=new trie_node();
        for(int i=0;i<26;i++)
            new_node->ptr[i]=NULL;
        new_node->isword=false;
        return new_node;
    }
    void insert(trie_node *root,string s,int ind)
    {
        trie_node *node=NULL;
        if(s[ind]=='\0'){
            root->isword=true;
            return;
        }
        
        if(root->ptr[s[ind]-'a']==NULL){
            node=create_node();
            root->ptr[s[ind]-'a']=node;
        }
        insert(root->ptr[s[ind]-'a'],s,ind+1);
    }
    bool isexist(trie_node *root,string s,int ind)
    {
        if(s[ind]=='\0'){
            return root->isword;
        }
        if(root->ptr[s[ind]-'a']==NULL)
        return false;
        return isexist(root->ptr[s[ind]-'a'],s,ind+1);
    }
    void delete_word(trie_node *root,string s,int ind)
    {
        if(s[ind]=='\0'){
            root->isword=false;
            return;
        }
        if(root->ptr[s[ind]-'a']==NULL)
        {
            cout<<"Word does not exist";
            return;
        }

        delete_word(root->ptr[s[ind]-'a'],s,ind+1);
    }
    bool startwithprefix(trie_node *root,string s,int ind)
    {
        if(s[ind]=='\0'){
            return true;
        }
        if(root->ptr[s[ind]-'a']==NULL)
        return false;
        return startwithprefix(root->ptr[s[ind]-'a'],s,ind+1);
    }
    
};
int main()
{
    trie obj;
    int temp=1;
    while(temp)
    {
        cout<<"\nEnter the operation:"<<endl;
        cout<<"1.insertion\n2.deletion\n3.isexist\n4.starts with prefix\n5.exit"<<endl;
        int ch;
        cin>>ch;
        string s;
        switch (ch)
        {
        case 1: cin>>s;
                obj.insert(obj.root,s,0);
                break;
        
        case 2: cin>>s;
                obj.delete_word(obj.root,s,0);
                break;
         case 3: cin>>s;
                 if(obj.isexist(obj.root,s,0))
                    cout<<"Word exist";
                  else
                    cout<<"Word does not exist";
                break;
        case 4:cin>>s;
                if(obj.startwithprefix(obj.root,s,0))
                    cout<<"Word exist with entered prefix";
                  else
                    cout<<"Word does not exist with entered";
                break;
                
        case 5: temp=0;

        }
    }

}
