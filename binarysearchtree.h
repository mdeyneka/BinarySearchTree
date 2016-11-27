#ifndef BinarySearchTree_H
#define BinarySearchTree_H

#include <queue>
#include <memory>
#include "node.h"

template<typename K, typename V>
using node_ptr = std::shared_ptr<Node<K,V>>;

template<typename K, typename V>
class BinarySearchTree
{
private:
    node_ptr<K,V> root;
public:
    BinarySearchTree<K,V>();
    void add(const K &key, const V &value);
    bool hasKey(const K &key) const;
    const V& get(const K &key) const;
    void remove(const K &key);
    int size() const;
    const V& minValue() const;
    const V& maxValue() const;
};

template<typename K, typename V>
BinarySearchTree<K,V>::BinarySearchTree(){
    root = nullptr;
}

template<typename K, typename V>
void BinarySearchTree<K,V>::add(const K &key, const V &value)
{
    node_ptr<K,V> x = root, y = nullptr;

    while(x != nullptr)
    {
        if(key == x->getKey())
        {
            x->setValue(value);
            return;
        } else {
            y = x;
            if(x->getKey() > key)
            {
                x = x->left;
            } else {
                x = x->right;
            }
        }
    }

    node_ptr<K,V> temp(new Node<K, V>(key, value));
    if(y == nullptr)
    {
        root = temp;
    } else {
        if(y->getKey() > key)
        {
            y->left = temp;
        } else {
            y->right = temp;
        }
    }
}

template<typename K, typename V>
bool BinarySearchTree<K,V>::hasKey(const K &key) const
{
    node_ptr<K,V> x = root;
    while(x != nullptr)
    {
        if(key == x->getKey())
        {
            return true;
        }

        if(x->getKey() > key)
        {
            x = x->left;
        } else {
            x = x->right;
        }
    }
    return false;
}

template<typename K, typename V>
const V& BinarySearchTree<K,V>::get(const K &key) const
{
    node_ptr<K,V> x = root;
    while(x != nullptr)
    {
        if(key == x->getKey())
        {
            return x->getValue();
        }

        if(x->getKey() > key)
        {
            x = x->left;
        } else {
            x = x->right;
        }
    }
    return nullptr;
}

template<typename K, typename V>
void BinarySearchTree<K,V>::remove(const K &key)
{
    node_ptr<K,V> x = root, y = nullptr;

    while(x != nullptr)
    {
        if(key == x->getKey())
        {
            break;
        } else {
            y = x;
            if(x->getKey() > key)
            {
                x = x->left;
            } else {
                x = x->right;
            }
        }
    }

    if(x == nullptr) return;

    if(x->right == nullptr)
    {
        if(y == nullptr)
        {
            root = x->left;
        } else {
            if(x == y->left)
            {
                y->left = x->left;
            } else {
                y->right = x->left;
            }
        }
    } else {
        node_ptr<K,V> left_most = x->right;
        y = nullptr;
        while(left_most->left != nullptr)
        {
            y = left_most;
            left_most = left_most->left;
        }

        if(y != nullptr)
        {
            y->left = left_most->right;
        } else {
            x->right = left_most->right;
        }
        x->setKey(left_most->getKey());
        x->setValue(left_most->getValue());
      }
}

template<typename K, typename V>
int BinarySearchTree<K,V>::size() const
{
    int count = 0;
    if(root == nullptr) return 0;

    std::queue<node_ptr<K,V>> queue;

    queue.push(root);
    while(!queue.empty())
    {
        node_ptr<K,V> current_node = queue.front();
        queue.pop();
        count++;
        if(current_node->left != nullptr) queue.push(current_node->left);
        if(current_node->right != nullptr) queue.push(current_node->right);
    }

    return count;
}

template<typename K, typename V>
const V& BinarySearchTree<K,V>::minValue() const
{
    node_ptr<K,V> current_node = root;
    while(current_node->left != nullptr)
    {
        current_node = current_node->left;
    }
    return current_node->getValue();
}

template<typename K, typename V>
const V& BinarySearchTree<K,V>::maxValue() const
{
    node_ptr<K,V> current_node = root;
    while(current_node->right != nullptr)
    {
        current_node = current_node->right;
    }
    return current_node->getValue();
}

#endif // BinarySearchTree_H
