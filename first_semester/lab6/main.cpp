#include <iostream>


struct Elem
{
    int data;
    Elem* left;
    Elem* right;
    Elem* parent;
};
Elem* make(int  data, Elem* p) {
    Elem *q = new Elem;
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

void pass(Elem*v) {
    if (v == nullptr)
        return;
    pass(v->left);
    std::cout << v->data << std::endl;
    pass(v->right);
}


int main() {
    Elem *root = nullptr;
    add(10, root);
    add(6, root);
    add(15, root);
    add(116, root);
    add(12, root);
    add(1, root);
    add(7, root);
    pass(root);
}