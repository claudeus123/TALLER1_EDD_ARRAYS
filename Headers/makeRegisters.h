#include <iostream>
using namespace std;

class makeRegisters{
	public:
		makeRegisters();
		string* getRegions();
		int* getRegisters();
		void fillArray(int vector[], int length);
		void fillArrayString(string vector[], int length);
		void swapStr(string array[],int number1, int number2);
		void swapInt(int array[],int number1, int number2);
		void sort(string reference[], string regions[], int registers[], int length);
		void printFormat(string array[], int arrayInt[],int length);
		void readFile(string file);
		~makeRegisters();

	private:
		string regions[16];
		int registers[16];
		
};
