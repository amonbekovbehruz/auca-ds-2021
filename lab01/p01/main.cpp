#include <iostream>

int main() 
{
#ifdef AUCA_DEBUG
	std::cout << "Author: Amonbekov Behruz\n";
#endif
	std::cout << "Hello, C++ " << __cplusplus << "!!!\n";
}