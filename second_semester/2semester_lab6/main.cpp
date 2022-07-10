#include <iostream>
struct node
{
    int data;
    node* parent;
    node* left;
    node* right;
};
node* make(int data, node* p)
{
    node* q = new node;
    q->data = data;
    q->left = nullptr;
    q->right = nullptr;
    q->parent = p;
    return q;
}
void add(int data, node*& root) {
    if (root == nullptr) {
        root = make(data, root);
        return;
    }
    node *v = root;
    while ((data < v->data && v->left != nullptr) || (data > v->data && v->right != nullptr)) {
        if (data < v->data && v->left != nullptr)
            v = v->left;
        else
            v = v->right;
    }
    if (data == v->data)
        return;
    node *u = make(data, v);
    if (data < v->data)
        v->left = u;
    else
        v->right = u;
}
node* search(int data,node* v)
{
    if(v == nullptr)
        return v;
    if(v->data == data)
        return v;
    if(data < v->data)
        return search(data,v->left);
    else
        return search(data,v->right);
}
void Delete(int data, node*& root)
{
    node* u = search(data,root);
    if(u == nullptr)
        return;
    if(u->left == nullptr && u->right == nullptr && u==root)
    {
        root = nullptr;
        delete u;
        return;
    }
    if(u->left != nullptr && u->right != nullptr)
    {
        node* t =u->right;
        while(t->left != nullptr)
            t = t->left;
        u->data = t->data;
        u=t;
    }
    node* t;
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
void pass(node* v)
{
    if(v == nullptr)
        return;
    pass(v->left);
    std::cout<<v->data<<" "<<std::endl;
    pass(v->right);
}

int main() {
    node* root = nullptr;
    add(10,root);
    add(7,root);
    add(15,root);
    add(5,root);
    add(12,root);
    add(11,root);
    Delete(12,root);
    pass(root);
    int n=11;
    if(search(n,root)!=nullptr)
        std::cout<<"tree has element with data: "<<search(n,root)->data<<std::endl;
    else
        std::cout<<"tree doesn't have got this element\n";
    return 0;
}
