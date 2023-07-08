#include <iostream>
using namespace std;
class SLL
{
    private:
    class SLL_Node
    {
        public:
        int data;
        SLL_Node *next;
        SLL_Node(int data = 0, SLL_Node *next = NULL)
        {
            this->data = data;
            this->next = next;
        }
    };
    int count;
    SLL_Node *root;
    public:
    SLL()
    {
        this->root = NULL;
        this->count = 0;
    }
    void push_back(int data)
    {
        this->count++;
        if(!this->root)
        {
            root=new SLL_Node();
            root->data=data;
        } 
        else
        {
            SLL_Node *t;
            for(t=root;t->next;t=t->next);
            t->next=new SLL_Node();
            t->next->data=data;
        }
    }
    void push_front(int data)
    {
        this->count++;
        if(!this->root) 
        {
            root=new SLL_Node();
            root->data=data;
        }
        else
        {
            SLL_Node *t=new SLL_Node();
            t->data=data;
            SLL_Node *tmp=root;
            t->next=root;
            root=t;
        }
    }
    void pop_back()
    {
        if(this->count==0) return;
        if(this->count==1) 
        {
            delete root;
            root=NULL;
        }
        else
        {
            SLL_Node *i=NULL,*j=NULL;
            for(j=root;j->next!=NULL;i=j,j=j->next);
            i->next=NULL;
            delete j;
        }
        this->count--;
    }
    void pop_front()
    {
        if(this->count==0) return;
        if(this->count==1) 
        {
            delete root;
            root=NULL;
        }
        else
        {
            SLL_Node *t=root->next;
            delete root;
            root=t;
        }
        this->count--;
    }
    void insertByIndex(int data, int index)
    {}
};

int main()
{
    SLL tmp;
    tmp.push_back(1);
    tmp.push_back(2);
    tmp.push_back(3);
    tmp.print();
    tmp.pop_front();
    tmp.pop_back();
    tmp.print();
    return 0;
}