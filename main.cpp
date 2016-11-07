#include <iostream>
#include <string>
#include "binarysearchtree.h"

using namespace std;

int main()
{
  BinarySearchTree<int, std::string> btree;
  btree.add(4, "four");
  btree.add(10, "ten");
  btree.add(1, "one");
  btree.add(5, "five");
  std::cout << "size: " << btree.size() <<std::endl;

  std::cout << "6: " << btree.hasKey(6) << std::endl;
  std::cout << "5: " << btree.hasKey(5) << std::endl;

  std::cout << "10 - " << btree.get(10) << std::endl;
  std::cout << "1 - " << btree.get(1) << std::endl;
  std::cout << "5 - " << btree.get(5) << std::endl;

  std::cout << "Min value: " << btree.minValue() << std::endl;
  std::cout << "Max valie: " << btree.maxValue() << std::endl;

  btree.remove(1);

  std::cout << "Min value: " << btree.minValue() << std::endl;
  std::cout << "Max valie: " << btree.maxValue() << std::endl;

  std::cout << "size: " << btree.size() <<std::endl;
  return 0;
}

