#include <bits/stdc++.h>
#include "LinkedList.h"
using namespace std;

int main()
{
    LinkedList ll;
    ll.push_back(10);
    ll.push_back(23);
    ll.push_front(9);
    ll.pop_back();
    ll.print();
    return 0;
}