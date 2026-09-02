#include "list.h"
#include <iostream>

using namespace std;

int main()
{
	List<int> list;
	list.insert(0, 10);
	list.insert(1, 20);
	list.insert(2, 30);

	cout << list.size() << '\n';

return 0;
}