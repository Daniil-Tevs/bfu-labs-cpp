#include <iostream>
#include <chrono>
#define N 10000
#define M 100

class Timer
{
private:
    using clock_t = std::chrono::high_resolution_clock;
    using second_t = std::chrono::duration<double, std::ratio<1> >;
    std::chrono::time_point<clock_t> m_beg;
public:
    Timer() : m_beg(clock_t::now())
    {
    }
    void reset()
    {
        m_beg = clock_t::now();
    }
    double elapsed() const
    {
        return std::chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();
    }
};
struct T_list{
    T_list* next;
    int number;
};
void ADD(T_list* head,int number)
{
    auto* p = new T_list;
    p->number = number;
    p->next = head->next;
    head->next = p;
}
//int SIZE(T_list* head)
//{
//    int s=0;
//    auto* p = head->next;
//    while(p != nullptr)
//    {
//        s++;
//        p = p->next;
//    }
//    return s;
//}
//void REPLACE(T_list* head,int number, int position)
//{
//    auto* p = head->next;
//    int s=0;
//    while(p != nullptr)
//    {
//        if(s == N-position)
//        {
//            p->number = number;
//            break;
//        }
//        s++;
//        p = p->next;
//    }
//}
void INSERT(T_list* head,int number, int position)
{
    auto* p = head->next;
    auto* tmp = new T_list;
    int s=1;
//    tmp->number = number;
    while(p != nullptr)
    {
        if(s == position)
        {
            tmp->next=p->next;
            p->next=tmp;
            tmp->number=p->number;
            p->number = number;
            break;
        }
        s++;
        p = p->next;
    }
}
void PRINT(T_list* head)
{
    auto* p = head->next;
    while(p != nullptr)
    {
        std::cout<<p->number<<" ";
        p = p->next;
    }
}
void CLEAR(T_list* head)
{
    T_list* tmp;
    auto* p = head->next;
    while(p != nullptr)
    {
        tmp=p;
        p = p->next;
        delete tmp;
    }
}

int main() {
    auto* head = new T_list;
    head->next= nullptr;
    for(int i=0;i<N;i++)
        ADD(head,1+rand()%100);
//    PRINT(head);
    Timer t1;
    for(int i=0;i<M;i++)
        INSERT(head,-1-rand()%99,rand()%N);
    std::cout<<t1.elapsed()<<"\n";
//    PRINT(head);
    int* mass = new int[N+M];
    for(int i=0;i<N;i++)
        mass[i]=1+rand()%100;
    int tmp;
    Timer t2;
    for(int i=0;i<M;i++) {
        tmp=rand() % N;
        for(int j=N-M+i+1;j>=tmp;j--)
            mass[j]=mass[j-1];
        mass[tmp]=-1-rand()%100;
    }
    std::cout<<t2.elapsed();
    delete[] mass;
    CLEAR(head);
    delete head;
    return 0;
}
