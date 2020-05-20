#include "pch.h"
#include <iostream>
#include <vector>

using namespace std;
using namespace sf;

int main()
{
	Game gra(300, 300, "siema");
	gra.initializeAll();
	gra.running();
 
	return 0;
}


