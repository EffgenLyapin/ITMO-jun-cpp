#ifndef LIST_H
#define LIST_H

#include <assert.h>
#include <ostream>

template <typename T>
class List
{
public:
    // РЕЗУЛЬТАТ: создает пустой список
    List() : first (nullptr) {}

    ~List()
    {
        pop_all();
    }

    List(const List &other)
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
    T & front()
    {
        assert(!empty());
        return first->datum;
    }

    // РЕЗУЛЬТАТ: вставляет данные в начало списка
    void push_front(T datum)
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

    void push_back(T datum)
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

    void push_all(const List &other)
    {
        for(Node *np = first; np; np = np->next)
        {
            push_back(np->datum);
        }
    }

    List & operator=(const List &rhs)
    {
        if(this == &rhs) return *this;
        pop_all();
        push_all(rhs);
        return *this;
    }





private:

    struct Node {
        T datum;
        Node *next;
    };

    Node *first;
    Node *last;

public:

    class Iterator
    {
        friend class List;

    public:
        Iterator() : node_ptr(nullptr) {}

        T & operator*() const;
        Iterator & operator++();
        bool operator==(Iterator rhs) const;
        bool operator!=(Iterator rhs) const;

      private:
        Iterator(Node *np)
          : node_ptr(np) { }

        Node *node_ptr;

    };


    Iterator begin()
    {
        return Iterator(first);
    }

    Iterator end()
    {
        return Iterator();
    }






};


template <typename T>
typename List<T>::Iterator & List<T>::Iterator::operator++() {
    assert(node_ptr);
    node_ptr = node_ptr->next;
    return *this;
}

template <typename T>
bool List<T>::Iterator::operator==(Iterator rhs) const {
    return node_ptr == rhs.node_ptr;
}

template <typename T>
bool List<T>::Iterator::operator!=(Iterator rhs) const {
    return node_ptr != rhs.node_ptr;
}


#endif // LIST_H
