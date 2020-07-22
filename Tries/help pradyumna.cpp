#include <bits/stdc++.h>
using namespace std;
class trienode{
    public:
    char letter;
    bool eow;//end of word
    trienode** children=new trienode* [26];
    trienode()
    {
        letter='\0';
        eow=false;
        for(int i=0;i<26;i++)
            children[i]=NULL;
    }
};
void insert(string s,trienode* head)
{
    trienode* curr= head;
    int i=0;
    for(i=0;i<s.length();i++)
    {
        int index=s[i]-'a';
        if(curr->children[index]!=NULL)
        {
            curr=curr->children[index];
        }
        else
        {
            curr->children[index]=new trienode();
            curr->children[index]->letter=s[i];
            curr=curr->children[index];
        }
    }
        
        if(i==s.length())
        {
            curr->eow=true;
        }
    
}
void dfs(trienode* root,string in)
{	if(root->eow)
    	cout<<in<<endl;
    
    for(int i=0;i<26;i++)
    {	if(root->children[i])
        dfs(root->children[i],in+root->children[i]->letter);
    }
    
}
int complete(string search,trienode* head)
{	trienode* curr = head;
    for(int i=0;i<search.length();i++)
    {
        int index=search[i]-'a';
        if(curr->children[index]!=NULL)
        {
            curr=curr->children[index];
        }
        else
        {
            return 0;
        }
    }
 	dfs(curr,search);
        return 1;
}
int main()
{int n;
 cin>>n;
 string input;
 trienode* head=new trienode();
 for(int i=0;i<n;i++)
 {
     cin>>input;
    insert(input,head);
 }
/* for(int i=0;i<26;i++)
 {
     if(head->children[i])
     {
         cout<<head->children[i]->letter<<endl;
     }
 }*/
 int q;
 cin>>q;
 string search;
 int result;
 for(int i=0;i<q;i++)
 {
     cin>>search;
     result=complete(search,head);
     if(result==0)
     {
         cout<<"No suggestions"<<endl;
         insert(search,head);
     }
 }
 
    return 0;
}
