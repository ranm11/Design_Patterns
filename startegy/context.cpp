#include "context.h"
#include "node.h"

ConcreteStrategyC::ConcreteStrategyC(std::string conctereStagtegyStr):_algorithm_description(std::move(conctereStagtegyStr))
{
    buildRandomBST(10);
    std::cout<<"inorder search"<<std::endl;
    inorderSearch(bst);
    std::cout<<"postOrderSearch search"<<std::endl;
    postOrderSearch(bst);
    std::cout<<"preOrderSearch search"<<std::endl;
    preOrderSearch(bst);
    std::cout<<"inverse tree"<<std::endl;
    inverseBinaryTree(bst);
    std::cout<<"inorder search"<<std::endl;
    inorderSearch(bst);
}

std::string ConcreteStrategyC::doAlgorithm(std::string data) const
{
    std::cout<<_algorithm_description<<std::endl;
    int elmnt_to_search = 6;
    std::cout<<"srearch elmnt "<<elmnt_to_search<<" "<<search_in_BST(bst,elmnt_to_search)<<std::endl;
    elmnt_to_search = 9;
    std::cout<<"srearch elmnt "<<elmnt_to_search<<" "<<search_in_BST(bst,elmnt_to_search)<<std::endl;
    return _algorithm_description; 
}

void ConcreteStrategyC::buildRandomBST(int NOF_nodes)
{
    bst = new node(13);
    bst->l_node = new node(8);
    bst->r_node = new node(20);
    
    bst->l_node->l_node = new node(5);
    bst->l_node->r_node = new node(9);

    bst->r_node->l_node = new node(14);
    bst->r_node->r_node = new node(22);
}

bool ConcreteStrategyC::search_in_BST(node* _node, int elmnt) const
{
    if(_node==nullptr)
    {
        return false;
    }
    if(_node->data == elmnt)
    {
        return true;
    }
    if(_node->data > elmnt)
    {
        return search_in_BST(_node->l_node,elmnt);
    }
    if(_node->data < elmnt)
    {
        return search_in_BST(_node->r_node,elmnt);
    }

}

void ConcreteStrategyC::inorderSearch(node* _node)
{
    //visit left 
    // visit root
    // visit right 
    if(_node==nullptr)
    {
        return;
    }
    inorderSearch(_node->l_node);
    std::cout<<"visit "<<_node->data<<std::endl;
    inorderSearch(_node->r_node);
}

void ConcreteStrategyC::postOrderSearch(node* _node)
{
    // visit left
    //visit right
    // visit root
 if(_node==nullptr)
 {
     return;
 }   
    postOrderSearch(_node->l_node);
    postOrderSearch(_node->r_node);
    std::cout<<"visit "<<_node->data<<std::endl;

}

void ConcreteStrategyC::preOrderSearch(node* _node)
{
    // visit left
    //visit right
    // visit root
 if(_node==nullptr)
 {
     return;
 }  
 std::cout<<"visit "<<_node->data<<std::endl; 
    preOrderSearch(_node->l_node);
    preOrderSearch(_node->r_node);
    

}

void ConcreteStrategyC::inverseBinaryTree(node* _node)
{
    //post order traversal with swap legs for each node
    if(_node==nullptr)
    {
        return;
    }    
    inverseBinaryTree(_node->l_node);
    inverseBinaryTree(_node->r_node);
    //visit
    node* tmp = _node->r_node;
    _node->r_node = _node->l_node;
    _node->l_node = tmp;
}