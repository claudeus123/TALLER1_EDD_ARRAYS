#include "Headers/makeRegisters.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>

using namespace std;

makeRegisters::makeRegisters(){
	fillArray(registers, 16);
	fillArrayString(regions, 16);
}
//Relleno de los vectores con su respectivo formato
void makeRegisters::fillArray(int vector[], int length){
	for (int i = 0; i < length; i ++){
		vector[i] = 0;
	}
}


void makeRegisters::fillArrayString(string vector[], int length){
	for(int i = 0; i < length; i ++ ){
		if (i < 9) vector[i] = "0" + to_string(i+1);
		else {
			vector[i] = to_string(i+1);
		}
	}
}

//Metodo SORT, implementado en caso de ser necesario, ordena la lista dado una referencia entregada
void makeRegisters::swapStr(string array[],int number1, int number2){
	string aux = array[number1];
	array[number1] = array[number2];
	array[number2] = aux;	
}

void makeRegisters::swapInt(int array[],int number1, int number2){
	int aux = array[number1];
	array[number1] = array[number2];
	array[number2] = aux;	
}

void makeRegisters::sort(string reference[], string regions[], int registers[], int length){
	for(int i =0 ; i < length - 1; i ++){
		for (int j = i; j < length; j++){
			if (reference[i] == regions[j]){
				swapStr(regions,i,j);
				swapInt(registers,i,j);
				break;
			}
		}
	}
}
//Imprime en el formato indicado
void makeRegisters::printFormat(string array[], int arrayInt[],int length){
	cout << "Codigo Region; registros" << endl;
	for (int i = 0; i < length; i++){
		cout << array[i] << "; " << arrayInt[i] << endl;
	}
}
//Lee el archivo y los agrega a los arreglos
void makeRegisters::readFile(string file){
	ifstream myFileStream(file);
	string code;
	string line;
	int number;
	
	getline(myFileStream,line);
	while(getline(myFileStream,line)){
		stringstream ss(line);
		getline(ss,code,';');
		number = stoi(code);

		registers[number-1] += 1;
	}	
	myFileStream.close();
}
//Corresponde al destructor de la clase
makeRegisters::~makeRegisters(){}
//GETS
string * makeRegisters::getRegions(){
	return this->regions;
}

int * makeRegisters::getRegisters(){
	return this->registers;
}
