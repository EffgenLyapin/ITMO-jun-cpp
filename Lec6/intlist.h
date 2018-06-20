#ifndef INTLIST_H
#define INTLIST_H

#include <assert.h>
#include <ostream>
class IntList
{
public:
    // РЕЗУЛЬТАТ: создает пустой список
    IntList() : first (nullptr) {}

    ~IntList()
    {
        pop_all();
    }

    IntList(const IntList &other)
        :first(nullptr), last(nullptr)
    {
        push_all(other);
    }

    // РЕЗУЛЬТАТ: возвращает true если список пустой
    bool empty() const
    {
        return first == nullptr;
    }

    // ТРЕБОВАНИЕ: список не пустой
    // РЕЗУЛЬТАТ:  Возвращает (по ссылке) первый элемент
    int & front()
    {
        assert(!empty());
        return first->datum;
    }

    // РЕЗУЛЬТАТ: вставляет данные в начало списка
    void push_front(int datum)
    {
        Node *p = new Node;
        p->datum = datum;
        p->next = first;
        first = p;
    }

    // ТРЕБОВАНИЕ: список не пустой
    // РЕЗУЛЬТАТ:  удаляет первый элемент
    void pop_front()
    {
        assert(!empty());
//        delete first;
//        first = first->next;

        Node *victim = first;
        first = first->next;
        delete victim;
    }

    void print(std::ostream &os) const
    {
        for (Node *np = first; np; np = np->next)
        {
            os << np->datum << " ";
        }

    }

    // РЕЗУЛЬТАТ: удаляем все элементы
    void pop_all()
    {
        while(!empty())
            pop_front();
    }

    void push_back(int datum)
    {
        Node *p = new Node;
        p->datum = datum;
        p->next = nullptr;
        if (empty()) { first = last = p; }
        else
        {
            last->next = p;
            last = p;
        }

    }

    void push_all(const IntList &other)
    {
        for(Node *np = first; np; np = np->next)
        {
            push_back(np->datum);
        }
    }

    IntList & operator=(const IntList &rhs)
    {
        if(this == &rhs) return *this;
        pop_all();
        push_all(rhs);
        return *this;
    }

private:
    struct Node {
        int datum;
        Node *next;
    };

    Node *first;
    Node *last;



};

#endif // INTLIST_H
