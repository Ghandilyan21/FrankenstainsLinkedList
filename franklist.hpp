#include <iostream>
#include "franklist.h"

// Node default constructors and destructor

template <typename T>
Frankenstein::FrankList<T>::Node::Node() 
                : next(nullptr)
                , prev(nullptr)
                , asc(nullptr)
                , desc(nullptr)
{

}

template <typename T>
Frankenstein::FrankList<T>::Node::Node(T val) 
                        : Frankenstein::FrankList<T>::Node::Node()
{
    this -> val = val;
}

template <typename T>
Frankenstein::FrankList<T>::Node::~Node()
{
    if (this -> next)
        delete this -> next;
    if (this -> prev)
        delete this -> prev;
    if (this -> asc)
        delete this -> asc;
    if (this -> desc)
        delete this -> desc; 
}

// base iterator implementation

template <typename T>
Frankenstein::FrankList<T>::base_iterator::base_iterator(Node* ptr) //O(1)
{
    this -> ptr = ptr;
}

template <typename T>
Frankenstein::FrankList<T>::base_iterator::~base_iterator()
{
    this -> ptr = nullptr;
}

template <typename T>
bool Frankenstein::FrankList<T>::base_iterator::operator==(const base_iterator& rhv) const //O(1)
{
    return this -> ptr == rhv.ptr;
}

template <typename T>
bool Frankenstein::FrankList<T>::base_iterator::operator!=(const base_iterator& rhv) const //O(1)
{
    return this -> ptr != rhv.ptr;
}

// const_iterator implementation

template <typename T>
Frankenstein::FrankList<T>::const_iterator::const_iterator(const base_iterator& rhv) //O(1)
                            : Frankenstein::FrankList<T>::base_iterator::base_iterator(rhv.ptr)
{

}

template <typename T>
Frankenstein::FrankList<T>::const_iterator::const_iterator(base_iterator&& rhv) //O(1)
                            : Frankenstein::FrankList<T>::base_iterator::base_iterator(rhv.ptr)
{
    rhv.ptr = nullptr;
}

        
template <typename T>
const Frankenstein::FrankList<T>::const_iterator& Frankenstein::FrankList<T>::const_iterator::operator=(const base_iterator& rhv) //O(1)
{
    this -> ptr = rhv.ptr;
    return *this;
}

template <typename T>
const Frankenstein::FrankList<T>::const_iterator& Frankenstein::FrankList<T>::const_iterator::operator=(base_iterator&& rhv) //O(1)
{
    this -> ptr = rhv.ptr;
    rhv.ptr = nullptr;
    return *this;
}

template <typename T>
Frankenstein::FrankList<T>::const_reference Frankenstein::FrankList<T>::const_iterator::operator*() const //O(1)
{
    return this -> ptr -> val;
}

template <typename T>
Frankenstein::FrankList<T>::const_pointer Frankenstein::FrankList<T>::const_iterator::operator->() const //O(1)
{
    return this -> ptr;
}

template <typename T>
const Frankenstein::FrankList<T>::const_iterator& Frankenstein::FrankList<T>::const_iterator::operator++() //O(1)
{
    this -> ptr = this -> ptr -> next;
    return *this;
}

template <typename T>
const Frankenstein::FrankList<T>::const_iterator Frankenstein::FrankList<T>::const_iterator::operator++(value_type) //O(1)
{
    Frankenstein::FrankList<T>::const_iterator tmp(*this);
    ++(*this);
    return tmp;
}

template <typename T>
const Frankenstein::FrankList<T>::const_iterator& Frankenstein::FrankList<T>::const_iterator::operator--() //O(1)
{
    this -> ptr = this -> ptr -> prev;
    return *this;
}

template <typename T>
const Frankenstein::FrankList<T>::const_iterator Frankenstein::FrankList<T>::const_iterator::operator--(value_type) //O(1)
{
    Frankenstein::FrankList<T>::const_iterator tmp(*this);
    --(*this);
    return tmp;
}

template <typename T>
Frankenstein::FrankList<T>::const_iterator::const_iterator(Node* ptr) //O(1)
{
    Frankenstein::FrankList<T>::base_iterator::base_iterator(ptr);
}

// iterator implementation

template <typename T>
Frankenstein::FrankList<T>::iterator::iterator(const base_iterator& rhv) //O(1)
{
    Frankenstein::FrankList<T>::const_iterator::const_iterator(rhv.ptr);
}

template <typename T>
Frankenstein::FrankList<T>::iterator::iterator(base_iterator&& rhv) //O(1)
{
    Frankenstein::FrankList<T>::const_iterator::const_iterator(rhv.ptr);
    rhv.ptr = nullptr;
}

template <typename T>
Frankenstein::FrankList<T>::reference Frankenstein::FrankList<T>::iterator::operator*() //O(1)
{
    return this -> ptr -> val;
}

template <typename T>
Frankenstein::FrankList<T>::pointer Frankenstein::FrankList<T>::iterator::operator->() //O(1)
{
    return this -> ptr;
}

template <typename T>
const Frankenstein::FrankList<T>::iterator& Frankenstein::FrankList<T>::iterator::operator=(const base_iterator& rhv) //O(1)
{
    this -> ptr = rhv.ptr;
    return *this;
}

template <typename T>
const Frankenstein::FrankList<T>::iterator& Frankenstein::FrankList<T>::iterator::operator=(base_iterator&& rhv) //O(1)
{
    this -> ptr = rhv.ptr;
    rhv.ptr = nullptr;
    return *this;
}

template <typename T>
Frankenstein::FrankList<T>::iterator::iterator(Node* ptr) //O(1)
{
    Frankenstein::FrankList<T>::const_iterator::const_iterator(ptr);
}

// const_reverse_iterator implementation

template <typename T>
Frankenstein::FrankList<T>::const_reverse_iterator::const_reverse_iterator(const base_iterator& rhv) //O(1)
{
    Frankenstein::FrankList<T>::base_iterator::base_iterator(rhv.ptr);
}

template <typename T>
Frankenstein::FrankList<T>::const_reverse_iterator::const_reverse_iterator(base_iterator&& rhv) //O(1)
{
    Frankenstein::FrankList<T>::base_iterator::base_iterator(rhv.ptr);
    rhv.ptr = nullptr;
}

template <typename T>    
const Frankenstein::FrankList<T>::const_reverse_iterator& Frankenstein::FrankList<T>::const_reverse_iterator::operator=(const base_iterator& rhv) //O(1)
{
    this -> ptr = rhv.ptr;
    return *this;
}

template <typename T>
const Frankenstein::FrankList<T>::const_reverse_iterator& Frankenstein::FrankList<T>::const_reverse_iterator::operator=(base_iterator&& rhv) //O(1)
{
    this -> ptr = rhv.ptr;
    rhv.ptr = nullptr;
    return *this;
}

template <typename T>
Frankenstein::FrankList<T>::const_reference Frankenstein::FrankList<T>::const_reverse_iterator::operator*() const //O(1)
{
    return this -> ptr -> val;
}

template <typename T>
Frankenstein::FrankList<T>::const_pointer Frankenstein::FrankList<T>::const_reverse_iterator::operator->() const //O(1)
{
    return this -> ptr;
}

template <typename T>
const Frankenstein::FrankList<T>::const_reverse_iterator& Frankenstein::FrankList<T>::const_reverse_iterator::operator++() //O(1)
{
    this -> ptr = this -> ptr -> prev;
    return *this;
}

template <typename T>
const Frankenstein::FrankList<T>::const_reverse_iterator Frankenstein::FrankList<T>::const_reverse_iterator::operator++(value_type) //O(1)
{
    Frankenstein::FrankList<T>::const_reverse_iterator tmp(*this);
    ++(*this);
    return tmp;
}

template <typename T>
const Frankenstein::FrankList<T>::const_reverse_iterator& Frankenstein::FrankList<T>::const_reverse_iterator::operator--() //O(1)
{
    this -> ptr = this -> ptr -> next;
    return *this;
}

template <typename T>
const Frankenstein::FrankList<T>::const_reverse_iterator Frankenstein::FrankList<T>::const_reverse_iterator::operator--(value_type) //O(1)
{
    Frankenstein::FrankList<T>::const_reverse_iterator tmp(*this);
    --(*this);
    return tmp;
}

template <typename T>
Frankenstein::FrankList<T>::const_reverse_iterator::const_reverse_iterator(Node* ptr) //O(1)
{
    Frankenstein::FrankList<T>::base_iterator::base_iterator(rhv.ptr);
}

// reverse_iterator implementation

template <typename T>
Frankenstein::FrankList<T>::reverse_iterator::reverse_iterator(const base_iterator& rhv) //O(1)
{
    Frankenstein::FrankList<T>::const_reverse_iterator::const_reverse_iterator(rhv.ptr);
}

template <typename T>
Frankenstein::FrankList<T>::reverse_iterator::reverse_iterator(base_iterator&& rhv) //O(1)
{
    Frankenstein::FrankList<T>::const_reverse_iterator::const_reverse_iterator(rhv.ptr);
    rhv.ptr = nullptr;
}

template <typename T>
Frankenstein::FrankList<T>::reference Frankenstein::FrankList<T>::reverse_iterator::operator*() //O(1)
{
    return this -> ptr -> val;
}

template <typename T>
Frankenstein::FrankList<T>::pointer Frankenstein::FrankList<T>::reverse_iterator::operator->() //O(1)
{
    return this -> ptr;
}

template <typename T>
const Frankenstein::FrankList<T>::reverse_iterator& Frankenstein::FrankList<T>::reverse_iterator::operator=(const base_iterator& rhv) //O(1)
{
    this -> ptr = rhv.ptr;
    return *this;
}

template <typename T>
const Frankenstein::FrankList<T>::reverse_iterator& Frankenstein::FrankList<T>::reverse_iterator::operator=(base_iterator&& rhv) //O(1)
{
    this -> ptr = rhv.ptr;
    rhv.ptr = nullptr;
    return *this;
}

template <typename T>
Frankenstein::FrankList<T>::reverse_iterator::reverse_iterator(Node* ptr) //O(1)
{
    Frankenstein::FrankList<T>::const_reverse_iterator::const_reverse_iterator(ptr);
}

// const_asc_iterator implementation

template <typename T>
Frankenstein::FrankList<T>::const_asc_iterator::const_asc_iterator(const base_iterator& rhv) //O(1)
{
    Frankenstein::FrankList<T>::base_iterator::base_iterator(rhv.ptr);
}

template <typename T>
Frankenstein::FrankList<T>::const_asc_iterator::const_asc_iterator(base_iterator&& rhv) //O(1)
{
    Frankenstein::FrankList<T>::base_iterator::base_iterator(rhv.ptr);
    rhv.ptr = nullptr;
}

template <typename T>
const Frankenstein::FrankList<T>::const_asc_iterator& Frankenstein::FrankList<T>::const_asc_iterator::operator=(const base_iterator& rhv) //O(1)
{
    this -> ptr = rhv.ptr;
    return *this;
}

template <typename T>
const Frankenstein::FrankList<T>::const_asc_iterator& Frankenstein::FrankList<T>::const_asc_iterator::operator=(base_iterator&& rhv) //O(1)
{
    this -> ptr = rhv.ptr;
    rhv.ptr = nullptr;
    return *this;
}

template <typename T>
Frankenstein::FrankList<T>::const_reference Frankenstein::FrankList<T>::const_asc_iterator::operator*() const //O(1)
{
    return this -> ptr -> val;
}

template <typename T>
Frankenstein::FrankList<T>::const_pointer Frankenstein::FrankList<T>::const_asc_iterator::operator->() const //O(1)
{
    return this -> ptr;
}

template <typename T>
const Frankenstein::FrankList<T>::const_asc_iterator& Frankenstein::FrankList<T>::const_asc_iterator::operator++() //O(1)
{
    this -> ptr = this -> ptr -> asc;
    return *this;
}

template <typename T>
const Frankenstein::FrankList<T>::const_asc_iterator Frankenstein::FrankList<T>::const_asc_iterator::operator++(value_type) //O(1)
{
    Frankenstein::FrankList<T>::const_asc_iterator tmp(*this);
    ++(*this);
    return tmp;
}

template <typename T>
const Frankenstein::FrankList<T>::const_asc_iterator& Frankenstein::FrankList<T>::const_asc_iterator::operator--() //O(1)
{
    this -> ptr = this -> ptr -> desc;
    return *this;
}

template <typename T>
const Frankenstein::FrankList<T>::const_asc_iterator Frankenstein::FrankList<T>::const_asc_iterator::operator--(value_type) //O(1)
{
    Frankenstein::FrankList<T>::const_asc_iterator tmp(*this);
    --(*this);
    return tmp;
}

template <typename T>
Frankenstein::FrankList<T>::const_asc_iterator::const_asc_iterator(Node* ptr) //O(1)
{
    Frankenstein::FrankList<T>::base_iterator::base_iterator(ptr);
}

// asc_iterator implementation

template <typename T>
Frankenstein::FrankList<T>::asc_iterator::asc_iterator(const base_iterator& rhv) //O(1)
{
    Frankenstein::FrankList<T>::const_asc_iterator::const_asc_iterator(rhv.ptr);
}

template <typename T>
Frankenstein::FrankList<T>::asc_iterator::asc_iterator(base_iterator&& rhv) //O(1)
{
    Frankenstein::FrankList<T>::const_asc_iterator::const_asc_iterator(rhv.ptr);
    rhv.ptr = nullptr;
}

template <typename T>
Frankenstein::FrankList<T>::reference Frankenstein::FrankList<T>::asc_iterator::operator*() //O(1)
{
    return this -> ptr -> val;
}

template <typename T>
Frankenstein::FrankList<T>::pointer Frankenstein::FrankList<T>::asc_iterator::operator->() //O(1)
{
    return this -> ptr;
}

template <typename T>
const Frankenstein::FrankList<T>::asc_iterator& Frankenstein::FrankList<T>::asc_iterator::operator=(const base_iterator& rhv) //O(1)
{
    this->ptr = rhv.ptr;
    return *this;
}


template <typename T>
const Frankenstein::FrankList<T>::asc_iterator& Frankenstein::FrankList<T>::asc_iterator::operator=(base_iterator&& rhv) //O(1)
{
    this->ptr = rhv.ptr;
    rhv.ptr = nullptr;
    return *this;
}

template <typename T>
Frankenstein::FrankList<T>::asc_iterator::asc_iterator(Node* ptr) //O(1)
{
    Frankenstein::FrankList<T>::const_asc_iterator::const_asc_iterator(ptr);
}

// const_desc_iterator implementation

template <typename T>
Frankenstein::FrankList<T>::const_desc_iterator::const_desc_iterator(const base_iterator& rhv) //O(1)
{
    Frankenstein::FrankList<T>::base_iterator::base_iterator(rhv.ptr);
}

template <typename T>
Frankenstein::FrankList<T>::const_desc_iterator::const_desc_iterator(base_iterator&& rhv) //O(1)
{
    Frankenstein::FrankList<T>::base_iterator::base_iterator(rhv.ptr);
    rhv.ptr = nullptr;
}

template <typename T>    
const Frankenstein::FrankList<T>::const_desc_iterator& Frankenstein::FrankList<T>::const_desc_iterator::operator=(const base_iterator& rhv) //O(1)
{
    this -> ptr = rhv.ptr;
    return *this;
}

template <typename T>
const Frankenstein::FrankList<T>::const_desc_iterator& Frankenstein::FrankList<T>::const_desc_iterator::operator=(base_iterator&& rhv) //O(1)
{
    this -> ptr = rhv.ptr;
    rhv.ptr = nullptr;
    return *this;
}

template <typename T>
Frankenstein::FrankList<T>::const_reference Frankenstein::FrankList<T>::const_desc_iterator::operator*() const //O(1)
{
    return this -> ptr -> val;
}

template <typename T>
Frankenstein::FrankList<T>::const_pointer Frankenstein::FrankList<T>::const_desc_iterator::operator->() const //O(1)
{
    return this -> ptr;
}

template <typename T>
const Frankenstein::FrankList<T>::const_desc_iterator& Frankenstein::FrankList<T>::const_desc_iterator::operator++() //O(1)
{
    this -> ptr = this -> ptr -> desc;
    return *this;
}

template <typename T>
const Frankenstein::FrankList<T>::const_desc_iterator Frankenstein::FrankList<T>::const_desc_iterator::operator++(value_type) //O(1)
{
    Frankenstein::FrankList<T>::const_desc_iterator tmp(*this);
    ++(*this);
    return tmp;
}

template <typename T>
const Frankenstein::FrankList<T>::const_desc_iterator& Frankenstein::FrankList<T>::const_desc_iterator::operator--() //O(1)
{
    this -> ptr = this -> ptr-> asc;
    return *this;
}

template <typename T>
const Frankenstein::FrankList<T>::const_desc_iterator Frankenstein::FrankList<T>::const_desc_iterator::operator--(value_type) //O(1)
{
    Frankenstein::FrankList<T>::const_desc_iterator tmp(*this);
    --(*this);
    return tmp;
}

template <typename T>
Frankenstein::FrankList<T>::const_desc_iterator::const_desc_iterator(Node* ptr) //O(1)
{
    Frankenstein::FrankList<T>::base_iterator::base_iterator(ptr);
}

// desc_iterator implementation

template <typename T>
Frankenstein::FrankList<T>::desc_iterator::desc_iterator(const base_iterator& rhv) //O(1)
{
    Frankenstein::FrankList<T>::const_desc_iterator::const_desc_iterator(rhv.ptr);
}

template <typename T>
Frankenstein::FrankList<T>::desc_iterator::desc_iterator(base_iterator&& rhv) //O(1)
{
    Frankenstein::FrankList<T>::const_desc_iterator::const_desc_iterator(rhv.ptr);
    rhv.ptr = nullptr;
}

template <typename T>
Frankenstein::FrankList<T>::reference Frankenstein::FrankList<T>::desc_iterator::operator*() //O(1)
{
    return this -> ptr -> val;
}

template <typename T>
Frankenstein::FrankList<T>::pointer Frankenstein::FrankList<T>::desc_iterator::operator->() //O(1)
{
    return this -> ptr;
}

template <typename T>
const Frankenstein::FrankList<T>::desc_iterator& Frankenstein::FrankList<T>::desc_iterator::operator=(const base_iterator& rhv) //O(1)
{
    this->ptr = rhv.ptr;
    return *this;
}

template <typename T>
const Frankenstein::FrankList<T>::desc_iterator& Frankenstein::FrankList<T>::desc_iterator::operator=(base_iterator&& rhv) //O(1)
{
    this->ptr = rhv.ptr;
    rhv.ptr = nullptr;
    return *this;
}

template <typename T>
Frankenstein::FrankList<T>::desc_iterator::desc_iterator(Node* ptr) //O(1)
{
    Frankenstein::FrankList<T>::const_desc_iterator::const_desc_iterator(ptr);
}

// const_multi_iterator implementation


template <typename T>
Frankenstein::FrankList<T>::const_multi_iterator::const_multi_iterator(const base_iterator& rhv) //O(1)
{
    Frankenstein::FrankList<T>::base_iterator::base_iterator(rhv.ptr);
}

template <typename T>
Frankenstein::FrankList<T>::const_multi_iterator::const_multi_iterator(base_iterator&& rhv) //O(1)
{
    Frankenstein::FrankList<T>::base_iterator::base_iterator(rhv.ptr);
    rhv.ptr = nullptr;
}

template <typename T>
const Frankenstein::FrankList<T>::const_multi_iterator& Frankenstein::FrankList<T>::const_multi_iterator::operator=(const base_iterator& rhv) //O(1)
{
    this -> ptr = rhv.ptr;
    return *this;
}

template <typename T>
const Frankenstein::FrankList<T>::const_multi_iterator& Frankenstein::FrankList<T>::const_multi_iterator::operator=(base_iterator&& rhv) //O(1)
{
    this -> ptr = rhv.ptr;
    rhv.ptr = nullptr;
    return *this;
}

template <typename T>
Frankenstein::FrankList<T>::const_reference Frankenstein::FrankList<T>::const_multi_iterator::operator*() const //O(1)
{
    return this -> ptr -> val;
}

template <typename T>
Frankenstein::FrankList<T>::const_pointer Frankenstein::FrankList<T>::const_multi_iterator::operator->() const //O(1)
{
    return this -> ptr;
}

template <typename T>
const Frankenstein::FrankList<T>::const_multi_iterator& Frankenstein::FrankList<T>::const_multi_iterator::operator++() //O(1)
{
    if (this -> mode) 
    {
        this->ptr = this->ptr->next;
    }
    else 
    {
        this->ptr = this->ptr->asc;
    }
    return *this;
}

template <typename T>
const Frankenstein::FrankList<T>::const_multi_iterator Frankenstein::FrankList<T>::const_multi_iterator::operator++(value_type) //O(1)
{
    Frankenstein::FrankList<T>::const_multi_iterator tmp(*this);
    ++(*this);
    return tmp;
}

template <typename T>
const Frankenstein::FrankList<T>::const_multi_iterator& Frankenstein::FrankList<T>::const_multi_iterator::operator--() //O(1)
{
    if (this -> mode) 
    {
        this -> ptr = this -> ptr -> desc;
    }
    else 
    {
        this -> ptr = this -> ptr -> prev;
    }
    return *this;
}

template <typename T>
const Frankenstein::FrankList<T>::const_multi_iterator Frankenstein::FrankList<T>::const_multi_iterator::operator--(value_type) //O(1)
{
    Frankenstein::FrankList<T>::const_multi_iterator tmp(*this);
    --(*this);
    return tmp;
}

template <typename T>
void Frankenstein::FrankList<T>::const_multi_iterator::chmod() //O(1)
{
    this -> mode = !(this -> mode);
}

template <typename T>
Frankenstein::FrankList<T>::const_multi_iterator::const_multi_iterator(Node* ptr) //O(1)
{
    Frankenstein::FrankList<T>::base_iterator::base_iterator(ptr);
}

// multi_iterator implementation


template <typename T>
Frankenstein::FrankList<T>::multi_iterator::multi_iterator(const base_iterator& rhv) //O(1)
{
    Frankenstein::FrankList<T>::const_multi_iterator::const_multi_iterator(rhv.ptr);
}

template <typename T>
Frankenstein::FrankList<T>::multi_iterator::multi_iterator(base_iterator&& rhv) //O(1)
{
    Frankenstein::FrankList<T>::const_multi_iterator::const_multi_iterator(rhv.ptr);
    rhv.ptr = nullptr;
}

template <typename T>
Frankenstein::FrankList<T>::reference Frankenstein::FrankList<T>::multi_iterator::operator*() //O(1)
{
    return this -> ptr -> val;
}

template <typename T>
Frankenstein::FrankList<T>::pointer Frankenstein::FrankList<T>::multi_iterator::operator->() //O(1)
{
    return this -> ptr;
}

template <typename T>
const Frankenstein::FrankList<T>::multi_iterator& Frankenstein::FrankList<T>::multi_iterator::operator=(const base_iterator& rhv) //O(1)
{
    this -> ptr = rhv.ptr;
    return *this;
}

template <typename T>
const Frankenstein::FrankList<T>::multi_iterator& Frankenstein::FrankList<T>::multi_iterator::operator=(base_iterator&& rhv) //O(1)
{
    this -> ptr = rhv.ptr;
    rhv.ptr = nullptr;
    return *this;
}

template <typename T>
Frankenstein::FrankList<T>::multi_iterator::multi_iterator(Node* ptr) //O(1)
{
    Frankenstein::FrankList<T>::const_multi_iterator::const_multi_iterator(ptr);
}

// const_multi_reverse_iterator implementation


template <typename T>
Frankenstein::FrankList<T>::const_multi_reverse_iterator::const_multi_reverse_iterator(const base_iterator& rhv) //O(1)
{
    Frankenstein::FrankList<T>::base_iterator::base_iterator(rhv.ptr);
}

template <typename T>
Frankenstein::FrankList<T>::const_multi_reverse_iterator::const_multi_reverse_iterator(base_iterator&& rhv) //O(1)
{
    Frankenstein::FrankList<T>::base_iterator::base_iterator(rhv.ptr);
    rhv.ptr = nullptr;
}

template <typename T>
const Frankenstein::FrankList<T>::const_multi_reverse_iterator& Frankenstein::FrankList<T>::const_multi_reverse_iterator::operator=(const base_iterator& rhv) //O(1)
{
    this -> ptr = rhv.ptr;
    return *this;
}

template <typename T>
const Frankenstein::FrankList<T>::const_multi_reverse_iterator& Frankenstein::FrankList<T>::const_multi_reverse_iterator::operator=(base_iterator&& rhv) //O(1)
{
    this -> ptr = rhv.ptr;
    rhv.ptr = nullptr;
    return *this;
}

template <typename T>
Frankenstein::FrankList<T>::const_reference Frankenstein::FrankList<T>::const_multi_reverse_iterator::operator*() const //O(1)
{
    return this -> ptr -> val;
}

template <typename T>
Frankenstein::FrankList<T>::const_pointer Frankenstein::FrankList<T>::const_multi_reverse_iterator::operator->() const //O(1)
{
    return this -> ptr;
}

template <typename T>
const Frankenstein::FrankList<T>::const_multi_reverse_iterator& Frankenstein::FrankList<T>::const_multi_reverse_iterator::operator++() //O(1)
{
    if (this -> mode) 
    {
        this -> ptr = this -> ptr -> prev;
    }
    else 
    {
        this -> ptr = this -> ptr -> desc;
    }
    return *this;
}

template <typename T>
const Frankenstein::FrankList<T>::const_multi_reverse_iterator Frankenstein::FrankList<T>::const_multi_reverse_iterator::operator++(value_type) //O(1)
{
    Frankenstein::FrankList<T>::const_multi_reverse_iterator tmp(*this);
    ++(*this);
    return tmp;
}

template <typename T>
const Frankenstein::FrankList<T>::const_multi_reverse_iterator& Frankenstein::FrankList<T>::const_multi_reverse_iterator::operator--() //O(1)
{
    if (this -> mode) 
    {
        this -> ptr = this -> ptr -> next;
    }
    else 
    {
        this -> ptr = this->ptr->asc;
    }
    return *this;
}

template <typename T>
const Frankenstein::FrankList<T>::const_multi_reverse_iterator Frankenstein::FrankList<T>::const_multi_reverse_iterator::operator--(value_type) //O(1)
{
    Frankenstein::FrankList<T>::const_multi_reverse_iterator tmp(*this);
    --(*this);
    return tmp;
}

template <typename T>
void Frankenstein::FrankList<T>::const_multi_reverse_iterator::chmod() //O(1)
{
    this -> mode = !(this -> mode);
}

template <typename T>
Frankenstein::FrankList<T>::const_multi_reverse_iterator::const_multi_reverse_iterator(Node* ptr) //O(1)
{
    Frankenstein::FrankList<T>::base_iterator::base_iterator(ptr);
}

// multi_reverse_iterator implementation

template <typename T>
Frankenstein::FrankList<T>::multi_reverse_iterator::multi_reverse_iterator(const base_iterator& rhv) //O(1)
{
    Frankenstein::FrankList<T>::const_multi_reverse_iterator::const_multi_reverse_iterator(rhv.ptr);
}

template <typename T>
Frankenstein::FrankList<T>::multi_reverse_iterator::multi_reverse_iterator(base_iterator&& rhv) //O(1)
{
    Frankenstein::FrankList<T>::const_multi_reverse_iterator::const_multi_reverse_iterator(rhv.ptr);
    rhv.ptr = nullptr;
}

template <typename T>
Frankenstein::FrankList<T>::reference Frankenstein::FrankList<T>::multi_reverse_iterator::operator*() //O(1)
{
    return this -> ptr -> val;
}

template <typename T>
Frankenstein::FrankList<T>::pointer Frankenstein::FrankList<T>::multi_reverse_iterator::operator->() //O(1)
{
    return this -> ptr;
}

template <typename T>
const Frankenstein::FrankList<T>::multi_reverse_iterator& Frankenstein::FrankList<T>::multi_reverse_iterator::operator=(const base_iterator& rhv) //O(1)
{
    this -> ptr = rhv.ptr;
    return *this;
}

template <typename T>
const Frankenstein::FrankList<T>::multi_reverse_iterator& Frankenstein::FrankList<T>::multi_reverse_iterator::operator=(base_iterator&& rhv) //O(1)
{
    this -> ptr = rhv.ptr;
    rhv.ptr = nullptr;
    return *this;
}

template <typename T>
Frankenstein::FrankList<T>::multi_reverse_iterator::multi_reverse_iterator(Node* ptr) //O(1)
{
    Frankenstein::FrankList<T>::const_multi_reverse_iterator::const_multi_reverse_iterator(ptr);
}

// Constructors for Frankenstein

template <typename T>
std::ostream& operator<<(std::ostream& out, const Frankenstein::FrankList<T>& rhv)
{
    out << "{ ";

    for (auto i = rhv.cbegin(); i != rhv.cend(); ++i) 
        out << *i << " ";

    out << "}";

    return out;
}

template <typename T>
Frankenstein::FrankList<T>::FrankList() // O(1)
                    : head(nullptr)
                    , tail(nullptr)
                    , ahead(nullptr)
                    , atail(nullptr)
{

}


template <typename T>
Frankenstein::FrankList<T>::FrankList(size_type size) //O(n)
                    : head(nullptr)
                    , tail(nullptr)
                    , ahead(nullptr)
                    , atail(nullptr)
{
    for (size_type i = 0; i < size; ++i)
        Frankenstein::FrankList<T>::push_back(value_type());
}

template <typename T>
Frankenstein::FrankList<T>::FrankList(size_type size, const_reference init) //O(n)
                            : head(nullptr)
                            , tail(nullptr)
                            , ahead(nullptr)
                            , atail(nullptr)
{
    for (size_type i = 0; i < size; ++i) {
        Frankenstein::FrankList<T>::push_back(init);
    }
}

template <typename T>
Frankenstein::FrankList<T>::FrankList(const FrankList<value_type>& rhv) //O(n)
                            : head(nullptr)
                            , tail(nullptr)
                            , ahead(nullptr)
                            , atail(nullptr)
{
    for (auto i = rhv.cbegin(); i != rhv.cend(); ++i)
        Frankenstein::FrankList<T>::push_back(*i);
}

template <typename T>
Frankenstein::FrankList<T>::FrankList(FrankList<value_type>&& rhv) //O(n)
                            : head(rhv.head)
                            , tail(rhv.tail)
                            , ahead(rhv.ahead)
                            , atail(rhv.atail)
{
    rhv.head = nullptr;
    rhv.tail = nullptr;
    rhv.ahead = nullptr;
    rhv.atail = nullptr;
}

template <typename T>
Frankenstein::FrankList<T>::FrankList(std::initializer_list<value_type> init) //O(n)
                            : head(nullptr)
                            , tail(nullptr)
                            , ahead(nullptr)
                            , atail(nullptr)
{
    for (auto i : init)
        Frankenstein::FrankList<T>::push_back(i);
}


template <typename T>
template <typename input_iterator>
Frankenstein::FrankList<T>::FrankList(input_iterator f, input_iterator l) //O(n)
                            : head(nullptr)
                            , tail(nullptr)
                            , ahead(nullptr)
                            , atail(nullptr)
{
    for (input_iterator i = f; i != l; ++i)
        Frankenstein::FrankList<T>::push_back(*i);
}

template <typename T>
Frankenstein::FrankList<T>::~FrankList()
{
    Frankenstein::FrankList<T>::clear();
}

// Frankenstein methods and operators 

template <typename value_type>
void Frankenstein::FrankList<value_type>::swap(FrankList<value_type>& rhv) //O(1)
{
    std::swap(this -> head, rhv.head);
    std::swap(this -> tail, rhv.tail);
    std::swap(this -> ahead, rhv.ahead);
    std::swap(this -> atail, rhv.atail);
}


template <typename T>
Frankenstein::FrankList<T>::size_type Frankenstein::FrankList<T>::size() const //O(n)
{
    size_type size = 0;
    for (auto i = Frankenstein::FrankList<T>::cbegin(); i != Frankenstein::FrankList<T>::cend(); ++i)
        ++size;

    return size;
}

template <typename T>
bool Frankenstein::FrankList<T>::empty() const //O(1) 
{
    return !( this -> head );
}

template <typename T>
void Frankenstein::FrankList<T>::resize(size_type s, const_reference init = value_type()) //O(n)
{
    size_type m_s = Frankenstein::FrankList<T>::size();
    if (s < m_s)
        for (size_type i = 0; i < m_s - s; ++i)
            Frankenstein::FrankList<T>::pop_back();
    else
        for (size_type i = 0; i < s - m_s; ++i)
            Frankenstein::FrankList<T>::push_back(init);
}

template <typename T>
void Frankenstein::FrankList<T>::clear() noexcept //O(n)
{
    while (this -> head) 
    {
        Node* tmp = this -> head;
        this -> head = head -> next;
        delete tmp;
    }
    this -> head = nullptr;
    this -> tail = nullptr;
    this -> ahead = nullptr;
    this -> atail = nullptr;
}

template <typename T>
void Frankenstein::FrankList<T>::push_front(const_reference elem) //~O(1)
{
    Node* tmp = new Node(elem);
    if (!(this -> head)) 
    {
        this -> head = tmp;
        this -> tail = this -> head;
    }
    else 
    {
        tmp -> next = this -> head;
        head -> prev = tmp;
        this -> head = tmp;
    }
    Frankenstein::FrankList<T>::put_in_sorted_order(this -> head);
}


template <typename T>
void Frankenstein::FrankList<T>::pop_front() //O(1)
{
    assert(this -> head != nullptr);
    
    if (!(this -> head -> next)) 
    {
        Frankenstein::FrankList<T>::clear();
        return;
    }
    if (this -> head -> asc)
        this -> head -> asc -> desc = this -> head -> desc;
    if (this -> head -> desc)
        this -> head -> desc -> asc = this -> head->asc;

    this -> head = this -> head -> next;
    delete this -> head -> prev;
    this -> head -> prev = nullptr;
}

template <typename T>
void Frankenstein::FrankList<T>::push_back(const_reference elem) //~O(1)
{
    Node* tmp = new Node(elem);
    if (!(this -> head)) 
    {
        this -> head = tmp;
        this -> tail = this -> head;
    }
    else 
    {
        this -> tail -> next = tmp;
        tmp -> prev = this -> tail;
        this -> tail = tmp;
    }
    Frankenstein::FrankList<T>::put_in_sorted_order(this -> tail);
}

template <typename T>
void Frankenstein::FrankList<T>::pop_back() //O(1)
{
    assert(head != nullptr);

    if (!(this ->  head -> next)) 
    {
        Frankenstein::FrankList<T>::clear();
        return;
    }
    if (this -> tail -> asc)
        this -> tail -> asc -> desc = this -> tail -> desc;
    if (this -> tail -> desc)
        this -> tail -> desc -> asc = this -> tail -> asc;

    this -> tail = this -> tail -> prev;
    delete this -> tail -> next;
    this -> tail -> next = nullptr;
}

template <typename T>
Frankenstein::FrankList<T>::const_reference Frankenstein::FrankList<T>::front() const //O(1)
{
    assert((this -> head) != nullptr);
    return head -> val;
}

template <typename T>
Frankenstein::FrankList<T>::reference Frankenstein::FrankList<T>::front() //O(1)
{
    assert((this -> head) != nullptr);
    return this -> head -> val;
}

template <typename T>
Frankenstein::FrankList<T>::const_reference Frankenstein::FrankList<T>::back() const //O(1)
{
    assert((this -> head) != nullptr);
    return this -> tail -> val;
}

template <typename T>
Frankenstein::FrankList<T>::reference Frankenstein::FrankList<T>::back() //O(1)
{
    assert((this -> head) != nullptr);
    return this -> tail -> val;
}

template <typename T>
Frankenstein::FrankList<T>::const_reference Frankenstein::FrankList<T>::min() const //O(1)
{
    assert((this -> head) != nullptr);
    return this -> ahead -> val;
}

template <typename T>
Frankenstein::FrankList<T>::reference Frankenstein::FrankList<T>::min() //O(1)
{
    assert((this -> head) != nullptr);
    return this -> ahead -> val;
}

template <typename T>
Frankenstein::FrankList<T>::const_reference Frankenstein::FrankList<T>::max() const //O(1)
{
    assert((this -> head) != nullptr);
    return this -> atail -> val;
}

template <typename T>
Frankenstein::FrankList<T>::reference Frankenstein::FrankList<T>::max() //O(1)
{
    assert((this -> head) != nullptr);
    return this -> atail -> val;
}

template <typename T>
const Frankenstein::FrankList<T>& Frankenstein::FrankList<T>::operator=(const Frankenstein::FrankList<value_type>& rhv) //O(n)
{
    if (this == &rhv)
        return *this;

    Frankenstein::FrankList<T>::clear();

    for (auto i = rhv.cbegin(); i != rhv.cend(); ++i)
        Frankenstein::FrankList<T>::push_back(*i);

    return *this;
}

template <typename T>
const Frankenstein::FrankList<T>& Frankenstein::FrankList<T>::operator=(Frankenstein::FrankList<value_type>&& rhv) //O(n)
{
    Frankenstein::FrankList<T>::clear();

    this -> head = rhv.head;
    this -> tail = rhv.tail;
    this -> ahead = rhv.ahead;
    this -> atail = rhv.atail;

    rhv.head = nullptr;
    rhv.tail = nullptr;
    rhv.ahead = nullptr;
    rhv.atail = nullptr;

    return *this;
}

template <typename T>
const Frankenstein::FrankList<T>& Frankenstein::FrankList<T>::operator=(std::initializer_list<value_type> init) //O(n)
{
    Frankenstein::FrankList<T>::clear();

    for (auto i : init)
        Frankenstein::FrankList<T>::push_back(i);
    
    return *this;
}

template <typename T>
bool Frankenstein::FrankList<T>::operator==(const FrankList<value_type>& rhv) const //O(n)
{
    if ((this -> size()) != rhv.size())
        return false;
    
    Node* it1 = this -> ahead;
    Node* it2 = rhv.ahead;

    for (; it1; it1 = it1 -> next, it2 = it2 -> next)
        if (it1 -> val != it2 -> val)
            return false;
    
    return true;
}

template <typename T>
bool Frankenstein::FrankList<T>::operator!=(const FrankList<value_type>& rhv) const //O(n)
{
    return !(*this == rhv);
}

template <typename T>
bool Frankenstein::FrankList<T>::operator<(const FrankList<value_type>& rhv) const //O(n)
{
    size_type s1 = this -> size();
    size_type s2 = rhv.size();

    if (s1 < s2)
        return true;
    
    if (s1 == s2) {
        Node* it1 = this -> ahead;
        Node* it2 = rhv.ahead;
        for (; it1; it1 = it1 -> next, it2 = it2 -> next) {
            if ((it1 -> val) < (it2 -> val))
                return true;
            if ((it1 -> val) > (it2 -> val))
                return false;
        }
    }

    return false;
}

template <typename T>
bool Frankenstein::FrankList<T>::operator<=(const FrankList<value_type>& rhv) const //O(n)
{
    return ((*this < rhv) || (*this == rhv));
}

template <typename T>
bool Frankenstein::FrankList<T>::operator>(const FrankList<value_type>& rhv) const //O(n)
{
    return !(*this <= rhv);
}

template <typename T>
bool Frankenstein::FrankList<T>::operator>=(const FrankList<value_type>& rhv) const //O(n)
{
    return !(*this < rhv);
}

template <typename T>
Frankenstein::FrankList<T>::const_iterator Frankenstein::FrankList<T>::cbegin() const //O(1)
{
    return Frankenstein::FrankList<T>::const_iterator(this -> head);
}

template <typename T>
Frankenstein::FrankList<T>::const_iterator Frankenstein::FrankList<T>::cend() const //O(1)
{
    return Frankenstein::FrankList<T>::const_iterator(this -> tail -> next);
}

template <typename T>
Frankenstein::FrankList<T>::const_reverse_iterator Frankenstein::FrankList<T>::crbegin() const //O(1)
{
    return Frankenstein::FrankList<T>::const_reverse_iterator(this -> tail);
}

template <typename T>
Frankenstein::FrankList<T>::const_reverse_iterator Frankenstein::FrankList<T>::crend() const //O(1)
{
    return Frankenstein::FrankList<T>::const_reverse_iterator(this -> head -> prev);
}

template <typename T>
Frankenstein::FrankList<T>::const_asc_iterator Frankenstein::FrankList<T>::cabegin() const //O(1)
{
    return Frankenstein::FrankList<T>::const_asc_iterator(this -> ahead);
}

template <typename T>
Frankenstein::FrankList<T>::const_asc_iterator Frankenstein::FrankList<T>::caend() const //O(1)
{
    return Frankenstein::FrankList<T>::const_asc_iterator(this -> atail -> asc);
}

template <typename T>
Frankenstein::FrankList<T>::const_desc_iterator Frankenstein::FrankList<T>::cdbegin() const //O(1)
{
    return Frankenstein::FrankList<T>::const_desc_iterator(this -> atail);
}

template <typename T>
Frankenstein::FrankList<T>::const_desc_iterator Frankenstein::FrankList<T>::cdend() const //O(1)
{
    return Frankenstein::FrankList<T>::const_desc_iterator(this -> ahead -> desc);
}

template <typename T>
Frankenstein::FrankList<T>::const_multi_iterator Frankenstein::FrankList<T>::cmbegin() const //O(1)
{
    return Frankenstein::FrankList<T>::const_multi_iterator(this -> head);
}

template <typename T>
Frankenstein::FrankList<T>::const_multi_iterator Frankenstein::FrankList<T>::cmend() const //O(1)
{
    return Frankenstein::FrankList<T>::const_iterator(this -> tail -> next);
}

template <typename T>
Frankenstein::FrankList<T>::const_multi_iterator Frankenstein::FrankList<T>::cmabegin() const //O(1)
{
    return Frankenstein::FrankList<T>::const_multi_iterator(this -> ahead);
}

template <typename T>
Frankenstein::FrankList<T>::const_multi_iterator Frankenstein::FrankList<T>::cmaend() const //O(1)
{
    return Frankenstein::FrankList<T>::const_multi_iterator(this -> atail -> asc);
}

template <typename T>
Frankenstein::FrankList<T>::const_multi_reverse_iterator Frankenstein::FrankList<T>::cmrbegin() const //O(1)
{
    return Frankenstein::FrankList<T>::const_multi_reverse_iterator(this -> tail);
}

template <typename T>
Frankenstein::FrankList<T>::const_multi_reverse_iterator Frankenstein::FrankList<T>::cmrend() const //O(1)
{
    return Frankenstein::FrankList<T>::const_iterator(this -> head -> prev);
}

template <typename T>
Frankenstein::FrankList<T>::const_multi_reverse_iterator Frankenstein::FrankList<T>::cmrdbegin() const //O(1)
{
    return Frankenstein::FrankList<T>::const_multi_reverse_iterator(this -> atail);
}

template <typename T>
Frankenstein::FrankList<T>::const_multi_reverse_iterator Frankenstein::FrankList<T>::cmrdend() const //O(1)
{
    return Frankenstein::FrankList<T>::const_multi_reverse_iterator(this -> ahead -> desc);
}

template <typename T>
Frankenstein::FrankList<T>::iterator Frankenstein::FrankList<T>::begin() //O(1)
{
    return Frankenstein::FrankList<T>::iterator(this -> head);
}

template <typename T>
Frankenstein::FrankList<T>::iterator Frankenstein::FrankList<T>::end() //O(1)
{
    return Frankenstein::FrankList<T>::iterator(this -> tail -> next);
}

template <typename T>
Frankenstein::FrankList<T>::reverse_iterator Frankenstein::FrankList<T>::rbegin() //O(1)
{
    return Frankenstein::FrankList<T>::reverse_iterator(this -> tail);
}

template <typename T>
Frankenstein::FrankList<T>::reverse_iterator Frankenstein::FrankList<T>::rend() //O(1)
{
    return Frankenstein::FrankList<T>::reverse_iterator(this -> head -> prev);
}

template <typename T>
Frankenstein::FrankList<T>::asc_iterator Frankenstein::FrankList<T>::abegin() //O(1)
{
    return Frankenstein::FrankList<T>::asc_iterator(this -> ahead);
}

template <typename T>
Frankenstein::FrankList<T>::asc_iterator Frankenstein::FrankList<T>::aend() //O(1)
{
    return Frankenstein::FrankList<T>::asc_iterator(this -> atail -> asc);
}

template <typename T>
Frankenstein::FrankList<T>::desc_iterator Frankenstein::FrankList<T>::dbegin() //O(1)
{
    return Frankenstein::FrankList<T>::desc_iterator(this -> atail);
}

template <typename T>
Frankenstein::FrankList<T>::desc_iterator Frankenstein::FrankList<T>::dend() //O(1)
{
    return Frankenstein::FrankList<T>::desc_iterator(this -> ahead -> desc);
}

template <typename T>
Frankenstein::FrankList<T>::multi_iterator Frankenstein::FrankList<T>::mbegin() //O(1)
{
    return Frankenstein::FrankList<T>::multi_iterator(this -> head);
}

template <typename T>
Frankenstein::FrankList<T>::multi_iterator Frankenstein::FrankList<T>::mend() //O(1)
{
    return Frankenstein::FrankList<T>::iterator(this -> tail -> next);
}

template <typename T>
Frankenstein::FrankList<T>::multi_iterator Frankenstein::FrankList<T>::mabegin() //O(1)
{
    return Frankenstein::FrankList<T>::multi_iterator(this -> ahead);
}

template <typename T>
Frankenstein::FrankList<T>::multi_iterator Frankenstein::FrankList<T>::maend() //O(1)
{
    return Frankenstein::FrankList<T>::multi_iterator(this -> atail -> asc);
}

template <typename T>
Frankenstein::FrankList<T>::multi_reverse_iterator Frankenstein::FrankList<T>::mrbegin() //O(1)
{
    return Frankenstein::FrankList<T>::multi_reverse_iterator(this -> tail);
}

template <typename T>
Frankenstein::FrankList<T>::multi_reverse_iterator Frankenstein::FrankList<T>::mrend() //O(1)
{
    return Frankenstein::FrankList<T>::iterator(this -> head -> prev);
}

template <typename T>
Frankenstein::FrankList<T>::multi_reverse_iterator Frankenstein::FrankList<T>::mrdbegin() //O(1)
{
    return Frankenstein::FrankList<T>::multi_reverse_iterator(this -> atail);
}

template <typename T>
Frankenstein::FrankList<T>::multi_reverse_iterator Frankenstein::FrankList<T>::mrdend() //O(1)
{
    return Frankenstein::FrankList<T>::multi_reverse_iterator(this -> ahead -> des);
}

template <typename T>
template <typename iter>
iter Frankenstein::FrankList<T>::insert(iter pos, size_type size, const_reference val) //O(n)
{
    static_assert(std::is_base_of<base_iterator, iter>::value == true, "uncorrect iterator");
    for (size_type i = 0; i < s; ++i)
        pos = Frankenstein::FrankList<T>::insert(pos, val);
    
    return pos;
}

template <typename T>
template <typename iter>
iter Frankenstein::FrankList<T>::insert(iter pos, std::initializer_list<value_type> init) //O(n)
{
    static_assert(std::is_base_of<base_iterator, iter>::value == true, "uncorrect iterator");
    for (auto i : init) 
        pos = Frankenstein::FrankList<T>::insert(pos, i);
    
    return pos;
}

template <typename T>
template <typename iter, typename input_iterator>
iter Frankenstein::FrankList<T>::insert(iter pos, input_iterator f, input_iterator l) //O(n)
{
    static_assert(std::is_base_of<base_iterator, iter>::value == true, "uncorrect iterator");
    for (auto i = f; i != l; ++i)
        pos = Frankenstein::FrankList<T>::insert(pos, *i);
    
    return pos;
}

template <typename T>
template <typename iter>
iter Frankenstein::FrankList<T>::erase(iter pos) //O(1)
{
    static_assert(std::is_base_of<base_iterator, iter>::value == true, "uncorrect iterator");
    Node* ptr = pos.ptr;
    iter tmp(pos);
    ++tmp;
    if (pos.ptr == (this -> head)) 
    {
        Frankenstein::FrankList<T>::pop_front();
        return tmp;
    }
    if (pos.ptr == (this -> tail)) 
    {
        Frankenstein::FrankList<T>::pop_back();
        return tmp;
    }

    if (ptr -> prev)
        ptr -> prev -> next = ptr -> next;
    if (ptr -> next)
        ptr -> next -> prev = ptr -> prev;
    if (ptr -> desc)
        ptr -> desc -> asc = ptr -> asc;
    if (ptr -> asc)
        ptr -> asc -> desc = ptr -> desc;

    delete pos.ptr;

    return tmp;
}

template <typename T>
template <typename iter>
iter Frankenstein::FrankList<T>::erase(iter f, iter l) //O(n)
{
    iter tmp(f);

    while (tmp != l)
        tmp = Frankenstein::FrankList<T>::erase(tmp);
    
    return tmp;
}


template <typename T>
Frankenstein::FrankList<T>::size_type Frankenstein::FrankList<T>::remove(const_reference val) //O(n)
{
    size_type cnt = 0;
    iterator i = Frankenstein::FrankList<T>::begin();

    while (i != Frankenstein::FrankList<T>::end()) 
    {
        if (*i == val) 
        {
            i = Frankenstein::FrankList<T>::erase(i);
            ++cnt;    
        }
        else
            ++i;
    }

    return cnt;
}

template <typename T>
template <typename unary_predicate>
Frankenstein::FrankList<T>::size_type Frankenstein::FrankList<T>::remove_if(unary_predicate func) //O(n)
{
    size_type cnt = 0;
    iterator i = Frankenstein::FrankList<T>::begin();

    while (i != Frankenstein::FrankList<T>::end()) 
    {
        if (func(*i)) 
        {
            i = Frankenstein::FrankList<T>::erase(i);
            ++cnt;
        }
        else
            ++i;
    }

    return cnt;
}

template <typename T>
void Frankenstein::FrankList<T>::reverse() //O(n)
{
    std::swap(this -> head, this -> tail);
    Node* i = this -> head;
    while (i) 
    {
        std::swap(i -> next, i -> prev);
        i = i -> next;
    }
}

template <typename T>
void Frankenstein::FrankList<T>::sort(bool reversed = false) //O(n)
{
    if (!(this -> ahead))
        return;
    if (!reversed) 
    {
        this -> head = this -> ahead;
        this -> tail = this -> atail;
        Node* i = this -> ahead;
        if (i -> prev)
            i -> prev -> next = nullptr;
        i -> prev = nullptr;
        while (i) 
        {
            i -> next = i -> asc;
            if (i -> next)
                i -> next -> prev = i;
    
            i = i -> next;
        }
    }
    else 
    {
        this -> head = this -> atail;
        this -> tail = this -> ahead;
        Node* i = this -> atail;
        if (i -> prev)
            i -> prev -> next = nullptr;
        
        i -> next = nullptr;
        while (i) 
        {
            i -> next = i -> desc;
            if (i -> next)
                i -> next -> prev = i;
    
            i = i -> next;
        }
    }
}

template <typename T>
Frankenstein::FrankList<T>::iterator Frankenstein::FrankList<T>::find(const_reference elem) //O(n)
{
    iterator i = Frankenstein::FrankList<T>::begin();
    while (i != Frankenstein::FrankList<T>::end() && *i != elem)
        ++i;
    
    Frankenstein::FrankList<T>::organize_left(i.ptr);

    return iterator(i);
}

template <typename T>
Frankenstein::FrankList<T>::iterator Frankenstein::FrankList<T>::rfind(const_reference elem) //O(n)
{
    reverse_iterator i = Frankenstein::FrankList<T>::rbegin();
    while (i != Frankenstein::FrankList<T>::rend() && *i != elem)
        ++i;
    
    Frankenstein::FrankList<T>::organize_right(it.ptr);
    return iterator(i);
}


template <typename T>
template <typename unary_predicate>
void Frankenstein::FrankList<T>::traverse(unary_predicate func, bool sorted = false, bool reversed = false) //O(n)
{
    if (!(this -> head))
        return;
    if (!sorted && !reversed)
        for (auto i = Frankenstein::FrankList<T>::begin(); i != Frankenstein::FrankList<T>::end(); ++i)
            func(*i);
    else if (!sorted)
        for (auto i = Frankenstein::FrankList<T>::rbegin(); i != Frankenstein::FrankList<T>::rend(); ++i)
            func(*i);
    else if (!reversed)
        for (auto i = Frankenstein::FrankList<T>::abegin(); i != Frankenstein::FrankList<T>::aend(); ++i)
            func(*i);
    else
        for (auto i = Frankenstein::FrankList<T>::dbegin(); i != Frankenstein::FrankList<T>::dend(); ++i)
            func(*i);
}

template <typename T>
void Frankenstein::FrankList<T>::print(bool sorted = false, bool reversed = false) //O(n)
{
    if (!(this -> head)) 
    {
        std::cout << "{  }";
        return;
    }

    std::cout << "{ ";

    if (!sorted && !reversed) 
        for (auto i = Frankenstein::FrankList<T>::begin(); i != Frankenstein::FrankList<T>::end(); ++i)
            std::cout << *i << " ";
    else if (!sorted) 
        for (auto i = Frankenstein::FrankList<T>::rbegin(); i != Frankenstein::FrankList<T>::rend(); ++i)
            std::cout << *i << " ";
    else if (!reversed)
        for (auto i = Frankenstein::FrankList<T>::abegin(); i != Frankenstein::FrankList<T>::aend(); ++i)
            std::cout << *i << " ";
    else
        for (auto i = Frankenstein::FrankList<T>::dbegin(); i != Frankenstein::FrankList<T>::dend(); ++i)
            std::cout << *i << " ";

    std::cout << "}";
}

template <typename T>
void Frankenstein::FrankList<T>::put_in_sorted_order(Node* ptr) //O(n)
{
    assert(ptr != nullptr);
    if (!(this -> ahead)) 
    {
        this -> ahead = ptr;
        this -> atail = ptr;
        return;
    }
    Node* i = this -> ahead;
    while ((i -> val) <= (ptr -> val) && i -> asc)
        i = i -> asc;

    if ((i -> val) < (ptr -> val)) 
    {
        ptr -> asc = i -> asc;
        i -> asc = ptr;
        ptr -> desc = i;
        if (!(ptr -> asc))
            this -> atail = ptr;
    }
    else 
    {
        ptr -> desc = i -> desc;
        if (i -> desc)
            i -> desc -> asc = ptr;
        else
            this -> ahead = ptr;
        ptr -> asc = i;
        i -> desc = ptr;
    }
}

template <typename T>
void Frankenstein::FrankList<T>::organize_left(Node* ptr) //O(1)
{
    assert(ptr != nullptr);
    if (ptr == (this - > head))
        return;
    Node* prev = ptr -> prev;
    Node* next = ptr -> next;
    if (prev) 
    {
        if (prev -> prev)
            prev -> prev -> next = ptr;
        
        prev -> prev = ptr;
        prev -> next = next;
        ptr -> next = prev;
    }
    if (next)
        next -> prev = prev;
    if (prev == (this -> head))
        this -> head = ptr;
    if (ptr == this -> tail)
        this -> tail = prev;
}

template <typename T>
void Frankenstein::FrankList<T>::organize_right(Node* ptr) //O(1)
{
    assert(ptr != nullptr);
    if (ptr == (this -> tail))
        return;

    Node* prev = ptr->prev;
    Node* next = ptr->next;

    if (next) 
    {
        if (next -> next)
            next -> next -> prev = ptr;

        next -> next = ptr;
        next -> prev = prev;
        ptr -> prev = next;
    }
    if (prev)
        prev -> next = next;
    if (next == (this -> tail))
        this -> tail = ptr;
    if (ptr == (this -> head))
        this -> head = next;
}

template <typename T>
template <typename iter>
iter Frankenstein::FrankList<T>::insert_def(iter pos, const_reference val) //O(1)
{
    assert(pos.ptr != nullptr);
    if (pos.ptr == (this -> head))
        Frankenstein::FrankList<T>::push_front(val);
    else 
    {
        Node* tmp = new Node(val);
        pos.ptr -> prev -> next = tmp;
        tmp -> prev = pos.ptr -> prev;
        pos.ptr -> prev = tmp;
        tmp -> next = pos.ptr;
        
        Frankenstein::FrankList<T>::put_in_sorted_order(tmp);
    }

    return pos;
}

template <typename T>
template <typename iter>
iter Frankenstein::FrankList<T>::insert_rev(iter pos, const_reference val) //O(1)
{
    assert(pos.ptr != nullptr);
    Frankenstein::FrankList<T>::insert_def(pos, val);
    ++pos;

    return pos;
}