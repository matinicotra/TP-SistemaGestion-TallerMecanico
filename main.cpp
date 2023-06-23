#include <iostream>
using namespace std;

#include "TrabajoManager.h"
#include "Trabajo.h"
int main()
{
	TrabajoManager aux;
//	Trabajo reg(1, 1, "abc123", "31835788", "1324253", "3425343", 2);
	Trabajo reg;
	aux.Listar(reg);

    return 0;
}
