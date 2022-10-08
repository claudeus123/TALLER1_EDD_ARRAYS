#include "Headers/makeRegisters.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>

using namespace std;

int main() {
	int regionsSize = 16;
	makeRegisters system = makeRegisters();
	system.readFile("Microdato_Censo2017-Personas.csv");
	//string references[16] = {"15","01","02","03","04","05","06","07","16","08","09","14","10","11","12","13"};
	//system.sort(references,system.getRegions(),system.getRegisters(),regionsSize);
	system.printFormat(system.getRegions(),system.getRegisters(),regionsSize);
	
}
