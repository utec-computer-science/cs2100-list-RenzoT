#include <iostream>
#include "node.h"
#include "list.h"

using namespace std;

int main(){
    List<int> list;
    list.push_front(5);
    list.push_back(2);
    list.push_front(3);
    cout << list;

}