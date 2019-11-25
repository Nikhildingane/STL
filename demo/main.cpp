#include <iostream>
#include "STLdll.h"


using namespace std;

int main()
{
    DS::DoublyCircularLL<int> obj;
    obj.InsertFirst(20);
    obj.InsertFirst(10);
    obj.Display();
    obj.DisplayRev();
    return 0;
}
