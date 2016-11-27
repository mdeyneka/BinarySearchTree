#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string>
#include <memory>

template<typename K, typename V> class Node;

template<typename K, typename V>
using node_ptr = std::shared_ptr<Node<K,V>>;

template<typename K, typename V>
class Node
{
private:
    K key;
    V value;
public:
    node_ptr<K,V> left, right;
    Node(const K &key, const V &value);
    ~Node();
    void setKey(const K &key);
    const K& getKey() const;
    void setValue(const V &value);
    const V& getValue() const;
    bool operator > (const Node<K,V>& node) const;
    bool operator == (const Node<K,V>& node) const;
};

template<typename K, typename V>
Node<K,V>::Node(const K &key, const V &value) : key(key), value(value)
{
    this->left = nullptr;
    this->right = nullptr;
}

template<typename K, typename V>
Node<K,V>::~Node()
{
    std::cout << "Deleting Node with key: " << this->key << std::endl;
}

template<typename K, typename V>
void Node<K,V>::setKey(const K &key)
{
    this->key = key;
}

template<typename K, typename V>
const K& Node<K,V>::getKey() const
{
    return key;
}

template<typename K, typename V>
void Node<K,V>::setValue(const V &value)
{
    this->value = value;
}

template<typename K, typename V>
const V& Node<K,V>::getValue() const
{
    return value;
}

template<typename K, typename V>
bool Node<K,V>::operator > (const Node<K,V>& node) const
{
    return this->key > node.key;
}

template<typename K, typename V>
bool Node<K,V>::operator ==(const Node<K, V> &node) const
{
    return this->key == node.key;
};

#endif // NODE_H
