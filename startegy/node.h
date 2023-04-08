
#pragma once


class node
{
    public:
    node(int _data)
    {
        l_node=nullptr;
        r_node=nullptr;
        data=_data;
    }
    //node(node* m_node, int m_data)_node(m_node),data(m_data){}
    node* l_node;
    node* r_node;
    int data;
};  