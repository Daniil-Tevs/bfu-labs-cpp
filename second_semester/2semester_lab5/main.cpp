#include <iostream>
#include <fstream>
struct Elem
{
    int data;
    Elem* left;
    Elem* right;
    Elem* parent;
};
Elem* make(int  data, Elem* p)
{
    Elem* q = new Elem;
    q->data = data;
    q->left = nullptr;
    q->right = nullptr;
    q->parent = p;
    return q;
}
void add(int data, Elem*& root)
{
    if(root == nullptr)
    {
        root = make(data, nullptr);
        return;
    }
    Elem* v = root;
    while((data<v->data && v->left != nullptr) || (data>v->data && v->right != nullptr))
        if(data<v->data)
            v=v->left;
        else
            v=v->right;
    if(data == v->data)
        return;
    Elem* u = make(data,v);
    if(data<v->data)
        v->left = u;
    else
        v->right = u;
}

///Инфиксный обход дерева
void pass(Elem*v)
{
    if(v== nullptr)
        return;
    pass(v->left);
    std::cout<<v->data<<std::endl;
    pass(v->right);
}
///Префиксный обход
void pass_pref(Elem*v)
{
    if(v== nullptr)
        return;
    std::cout<<v->data<<std::endl;
    pass(v->left);
    pass(v->right);
}
///Постфиксный обход
void pass_post(Elem*v)
{
    if(v== nullptr)
        return;
    pass(v->left);
    pass(v->right);
    std::cout<<v->data<<std::endl;
}
Elem* search(int data,Elem* v)
{
    if(v== nullptr)
        return v;
    if(v->data == data)
        return v;
    if(data < v->data)
        return search(data,v->left);
    else
        return search(data,v->right);
}
void Delete(int data, Elem*& root)
{
    Elem* u = search(data,root);
    if(u == nullptr)
        return;
    if(u->left == nullptr && u->right == nullptr && u==root)
    {
        root = nullptr;
        delete u;
        return;
    }
    else if(u->left != nullptr && u->right == nullptr && u==root)
    {
        u->left->parent = nullptr;
        root = u->left;
        return;
    }
    else if(u->left == nullptr && u->right != nullptr && u==root)
    {
        u->right->parent = nullptr;
        root = u->right;
        return;
    }
    if(u->left != nullptr && u->right != nullptr)
    {
        Elem* t =u->right;
        while(t->left != nullptr)
            t = t->left;
        u->data = t->data;
        u=t;
    }
    Elem* t;
    if (u->left == nullptr)
        t = u->right;
    else
        t = u->left;

    if(t!=nullptr)
        t->parent = u->parent;
    if(u==root)
        return;
    else if(u->parent->left == u)
        u->parent->left = t;
    else
        u->parent->right = t;
    delete u;
}
int deep(Elem*v,Elem*t)
{
    static int s=0;
    if(v == nullptr)
        return 0;
    else
        s++;
    deep(v->left,v);
    deep(v->right,v);
    if(t==v) {
        int a=s;
        s = 0;
        t= nullptr;
        return a;
    }
}

int main() {
    std::ifstream in("../input.txt");
    std::ofstream out("../output.txt");
    Elem* root = nullptr;
    std::string tmp;
    while(!in.eof())
    {
        in>>tmp;
        int number=0;
        unsigned int t=tmp.size()-1;
        while(t>0)
        {
            number += (tmp[t]-48)*pow(10,tmp.size()-t-1);
            t--;
        }
        if(tmp[0]=='+')
        {
            add(number,root);
        }
        else if(tmp[0]=='-')
        {
            Delete(number,root);
        }
        else if(tmp[0]=='?')
        {
            Elem* vsp = search(number,root);
            if(vsp != nullptr)
                out<<deep(vsp,vsp)<<" ";
            else
                out<<"n ";
        }
        else if(tmp[0]=='E')
            break;
    }
    pass(root);
    return 0;
}
