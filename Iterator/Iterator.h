#pragma once
#include<iostream>
#include<string>
#include<cstring>
#include<vector>

using namespace std;
template <typename T, typename U>
class Iterator {
 public:
  typedef typename std::vector<T>::iterator iter_type;
  Iterator(U *p_data, bool reverse = false) : m_p_data_(p_data) {
    m_it_ = m_p_data_->m_data_.begin();
  }

  void First() {
    m_it_ = m_p_data_->m_data_.begin();
  }

  void Next() {
    m_it_++;
  }

  bool IsDone() {
    return (m_it_ == m_p_data_->m_data_.end());
  }

  iter_type Current() {
    return m_it_;
  }

 private:
  U *m_p_data_;
  iter_type m_it_;
};



template <class T>
class Container {
    friend class Iterator<T, Container>;

public:
    void Add(T a) {
        m_data_.push_back(a);
    }

    Iterator<T, Container>* CreateIterator() {
        return new Iterator<T, Container>(this);
    }

private:
    std::vector<T> m_data_;
};

class Athlete {
public:
    Athlete(string a = " ") : m_data_(a) {}

    void set_data(string a) {
        m_data_ = a;
    }

    string athlete() {
        return m_data_;
    }

private:
    string m_data_;
};



void iteratorTest() {
    //std::cout << "���õ�����ģʽ���˶�Ա���б���" << std::endl;
    //Container<int> cont;
   /* Container<string> conthk;
    conthk.Add("������");
    conthk.Add("������");
    conthk.Add("��ƿ�");*/
   /* for (int i = 0; i < 10; i++) {
        cont.Add(i);
    }*/

    /*Iterator<int, Container<int>>* it = cont.CreateIterator();
    for (it->First(); !it->IsDone(); it->Next()) {
        std::cout << *it->Current() << std::endl;
    }*/

    /*Iterator<string, Container<string>>* it3 = conthk.CreateIterator();
    for (it3->First(); !it3->IsDone(); it3->Next()) {
        std::cout << *it3->Current() << std::endl;
    }*/

    Container<Athlete> cont2;
    Athlete a("�˶�Ա1"), b("�˶�Ա2"), c("�˶�Ա3");
    cont2.Add(a);
    cont2.Add(b);
    cont2.Add(c);

    std::cout << "****************  ����ΪIterator�������������ģʽ  ******************" << std::endl;
    cout << "Container::Add : created a container named Athlete" << endl;
    cout << "Iterator : created a iterator to visit container" << endl;
    Iterator<Athlete, Container<Athlete>>* it2 = cont2.CreateIterator();
    for (it2->First(); !it2->IsDone(); it2->Next()) {
        std::cout << it2->Current()->athlete() << std::endl;
    }
    //delete it;
    delete it2;
    std::cout << "****************  Iterator�������������ģʽ����  ******************" << std::endl;
    //delete it3;
}



