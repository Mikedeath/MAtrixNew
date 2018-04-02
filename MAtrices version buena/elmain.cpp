#include "iostream"
#include<fstream>
#include<vector>
#include <string>
#include <stdio.h>
#include <stdlib.h>
using namespace std;
//construct the structure

string matriz3;

struct Node
{
	int data;
	Node* right;
	Node* down;
};
int getNumF(string nombredelArchivo)
{
	bool restCol = false;
	int columnas = 0;
	int filas = 0;
	ifstream archivoMatrices(nombredelArchivo, ios::in);
	int line;

	while (archivoMatrices >> line)
	{
		if (restCol == false) {
			columnas++;
		}

		if (archivoMatrices.peek() == '\n') //detect "\n"
		{
			restCol = true;
			filas++;

		}

	}
	archivoMatrices.close();
	return filas;
}
int getNumC(string nombredelArchivo)
{
	bool restCol = false;
	int columnas = 0;
	int filas = 0;
	ifstream archivoMatrices(nombredelArchivo, ios::in);
	int line;

	while (archivoMatrices >> line)
	{
		if (restCol == false) {
			columnas++;
		}

		if (archivoMatrices.peek() == '\n') //detect "\n"
		{
			restCol = true;
			filas++;

		}

	}
	archivoMatrices.close();
	return columnas;
}

//this is the recurrsive fucntion of forming linked list from matrix.
Node* Matrix2LLFun(vector <vector<int> >arreglo, int rec_row, int rec_col, int row, int col) {
	if (rec_row > row - 1 || rec_col > col - 1)
		return NULL;
	Node* createNode = new Node; //created a node
	createNode->data = arreglo[rec_row][rec_col];
	createNode->right = Matrix2LLFun(arreglo, rec_row, rec_col + 1, row, col);
	createNode->down = Matrix2LLFun(arreglo, rec_row + 1, rec_col, row, col);
	return createNode;
}



///////////////////////////////////////////////////////////////////////////////////////////////
struct Node2
{
	int data;
	Node2* right;
	Node2* down;
};
Node2* Matrix2LLFun2(vector <vector<int> >arreglo2, int rec_row, int rec_col, int row, int col) {
	if (rec_row > row - 1 || rec_col > col - 1)
		return NULL;
	Node2* createNode = new Node2; //created a node
	createNode->data = arreglo2[rec_row][rec_col];
	createNode->right = Matrix2LLFun2(arreglo2, rec_row, rec_col + 1, row, col);
	createNode->down = Matrix2LLFun2(arreglo2, rec_row + 1, rec_col, row, col);
	return createNode;
}
int verify = 1;
int verify2 = 1;



//struct Node3
//{
//	int data;
//	Node3* right;
//	Node3* down;
//};
//Node3* Matrix2LLFun3(vector <vector<int> >arreglo3, int rec_row, int rec_col, int row, int col) {
//	if (rec_row > row - 1 || rec_col > col - 1)
//		return NULL;
//	Node3* createNode = new Node3; //created a node
//	createNode->data = arreglo3[rec_row][rec_col];
//	createNode->right = Matrix2LLFun3(arreglo3, rec_row, rec_col + 1, row, col);
//	createNode->down = Matrix2LLFun3(arreglo3, rec_row + 1, rec_col, row, col);
//	return createNode;
//}
//int verify3 = 1;
//void nodo3(Node3*&head_node3) {
//
//	vector <vector<int> >arreglo3;
//	int NUMF2 = getNumF(matriz3);
//	int NUMCOL2 = getNumC(matriz3);;
//	ifstream archivoMatrices2(matriz3, ios::in);
//	if (!archivoMatrices2) {
//		cout << "error" << endl;
//	}
//	else {
//		int codigo;
//		//Llenar el vector
//		for (int i = 0; i < NUMF2; i++)
//		{
//			vector<int>temp;
//			for (int j = 0; j < NUMCOL2; j++)
//			{
//				archivoMatrices2 >> codigo;
//				temp.push_back(codigo);
//			}
//
//			arreglo3.push_back(temp);
//		}
//
//		head_node3 = Matrix2LLFun3(arreglo3, 0, 0, NUMF2, NUMCOL2);
//	}
//
//}
//


void ponerNODOS(Node*&head_node, Node2*&head_node2) {
	string mat1;
	int  NUMF;
	int NUMCOL;
	int  NUMF2;
	int NUMCOL2;
	vector <vector<int> >arreglo;
	cout << "Ingrese el nombre del archivo 1" << endl;
	cin >> mat1;
	NUMF = getNumF(mat1);
	NUMCOL = getNumC(mat1);

	ifstream archivoMatrices(mat1, ios::in);
	if (!archivoMatrices) {
		cout << "Hay un error con el archivo" << endl;
	}
	else {
		int codigo;
		//Llenar el vector
		for (int i = 0; i < NUMF; i++)
		{
			vector<int>temp;
			for (int j = 0; j < NUMCOL; j++)
			{
				archivoMatrices >> codigo;
				temp.push_back(codigo);
			}

			arreglo.push_back(temp);
		}

		head_node = Matrix2LLFun(arreglo, 0, 0, NUMF, NUMCOL);

		//finally printing out the linked list.
		//now make two pointers one will move row wise and other will move colomn wise.
		Node *row_pointer, *col_pointer;
		row_pointer = head_node;
		//Imprimir nodos
		cout << "Matriz 1: " << endl;
		while (row_pointer)
		{
			col_pointer = row_pointer;
			while (col_pointer)
			{
				cout << col_pointer->data;
				col_pointer = col_pointer->right;
			}
			cout << endl;
			row_pointer = row_pointer->down;
		}
		verify = 0;

	}

	//////////////////////////////////////////////////////////////////////

	string mat2;
	vector <vector<int> >arreglo2;
	cout << "Ingrese el nombre del archivo 2" << endl;
	cin >> mat2;
	NUMF2 = getNumF(mat2);
	NUMCOL2 = getNumC(mat2);;
	ifstream archivoMatrices2(mat2, ios::in);
	if (!archivoMatrices2) {
		cout << "error" << endl;
	}
	else {
		int codigo;
		//Llenar el vector
		for (int i = 0; i < NUMF2; i++)
		{
			vector<int>temp;
			for (int j = 0; j < NUMCOL2; j++)
			{
				archivoMatrices2 >> codigo;
				temp.push_back(codigo);
			}

			arreglo2.push_back(temp);
		}

		head_node2 = Matrix2LLFun2(arreglo2, 0, 0, NUMF2, NUMCOL2);

		//finally printing out the linked list.
		//now make two pointers one will move row wise and other will move colomn wise.
		Node2 *row_pointer2, *col_pointer2;
		row_pointer2 = head_node2;
		//Imprimir nodos
		cout << "Matriz 2: " << endl;
		while (row_pointer2)
		{
			col_pointer2 = row_pointer2;
			while (col_pointer2)
			{
				cout << col_pointer2->data;
				col_pointer2 = col_pointer2->right;
			}
			cout << endl;
			row_pointer2 = row_pointer2->down;
			verify2 = 0;
		}
		///Verifier NXN

		if (NUMF != NUMF2 || NUMCOL != NUMCOL2) {
			cout << "Las matrices, nos son nxn" << endl;
			system("pause");
		}
		matriz3 = mat2;




	}




}

void print(Node*&head_node, Node2*&head_node2) {
	//Imprimir nodos 1
	Node *row_pointer, *col_pointer;
	row_pointer = head_node;
	cout << "Matriz 1: " << endl;

	while (row_pointer)
	{
		col_pointer = row_pointer;
		while (col_pointer)
		{
			cout << col_pointer->data;
			col_pointer = col_pointer->right;
		}
		cout << endl;
		row_pointer = row_pointer->down;
	}

	Node2 *row_pointer2, *col_pointer2;
	row_pointer2 = head_node2;

	//Imprimir nodos 2
	cout << "Matriz 2: " << endl;
	while (row_pointer2)
	{
		col_pointer2 = row_pointer2;
		while (col_pointer2)
		{
			cout << col_pointer2->data;
			col_pointer2 = col_pointer2->right;
		}
		cout << endl;
		row_pointer2 = row_pointer2->down;
	}



}
void suma(Node*&head_node, Node2*&head_node2) {
	//Imprimir nodos 1

	string nombreAR;
	Node *row_pointer, *col_pointer;
	row_pointer = head_node;
	Node2 *row_pointer2, *col_pointer2;
	row_pointer2 = head_node2;
	cout << endl;
	cout << "Que nombre le desea poner al archivo donde se guardara el resultado?" << endl;
	cin >> nombreAR;
	ofstream fs(nombreAR);
	fs.close();
	ofstream archivoOut(nombreAR, ios::app);
	cout << "Matriz Resultante" << endl;
	while (row_pointer&&row_pointer2)
	{
		col_pointer = row_pointer;
		col_pointer2 = row_pointer2;

		while (col_pointer&&col_pointer2)
		{
			col_pointer->data = col_pointer->data + col_pointer2->data;
			cout << col_pointer->data << " ";
			archivoOut << col_pointer->data << " ";
			col_pointer = col_pointer->right;
			col_pointer2 = col_pointer2->right;
		}
		cout << endl;
		archivoOut << "\n";
		row_pointer = row_pointer->down;
		row_pointer2 = row_pointer2->down;
	}



}

void resta(Node*&head_node, Node2*&head_node2) {


	string nombreAR;
	Node *row_pointer, *col_pointer;
	row_pointer = head_node;
	Node2 *row_pointer2, *col_pointer2;
	row_pointer2 = head_node2;
	cout << endl;
	cout << "Que nombre le desea poner al archivo donde se guardara el resultado?" << endl;
	cin >> nombreAR;
	ofstream fs(nombreAR);
	fs.close();
	ofstream archivoOut(nombreAR, ios::app);
	cout << "Matriz Resultante" << endl;
	while (row_pointer&&row_pointer2)
	{
		col_pointer = row_pointer;
		col_pointer2 = row_pointer2;

		while (col_pointer&&col_pointer2)
		{
			col_pointer->data = col_pointer->data - col_pointer2->data;
			cout << col_pointer->data << " ";
			archivoOut << col_pointer->data << " ";
			col_pointer = col_pointer->right;
			col_pointer2 = col_pointer2->right;
		}
		cout << endl;
		archivoOut << "\n";
		row_pointer = row_pointer->down;
		row_pointer2 = row_pointer2->down;
	}



}
void multiplicacion(Node*&head_node, Node2*&head_node2) {


	string nombreAR;
	Node *row_pointer, *col_pointer;
	row_pointer = head_node;
	Node2 *row_pointer2, *col_pointer2;
	row_pointer2 = head_node2;
	cout << endl;
	cout << "Que nombre le desea poner al archivo donde se guardara el resultado?" << endl;
	cin >> nombreAR;
	ofstream fs(nombreAR);
	fs.close();
	ofstream archivoOut(nombreAR, ios::app);
	cout << "Matriz Resultante" << endl;
	while (row_pointer&&row_pointer2)
	{
		col_pointer = row_pointer;
		col_pointer2 = row_pointer2;

		while (col_pointer&&col_pointer2)
		{
			col_pointer->data = col_pointer->data * col_pointer2->data;
			cout << col_pointer->data << " ";
			archivoOut << col_pointer->data << " ";
			col_pointer = col_pointer->right;
			col_pointer2 = col_pointer2->right;
		}
		cout << endl;
		archivoOut << "\n";
		row_pointer = row_pointer->down;
		row_pointer2 = row_pointer2->down;
	}



}

void multiplicacion(Node*&head_node, Node2*&head_node2) {
	//Imprimir nodos 1

	string nombreAR;
	Node *row_pointer, *col_pointer;
	row_pointer = head_node;
	Node2 *row_pointer2, *col_pointer2;
	row_pointer2 = head_node2;
	cout << endl;
	cout << "Que nombre le desea poner al archivo donde se guardara el resultado?" << endl;
	cin >> nombreAR;
	ofstream fs(nombreAR);
	fs.close();
	ofstream archivoOut(nombreAR, ios::app);
	cout << "Matriz Resultante" << endl;
	while (row_pointer&&row_pointer2)
	{
		col_pointer = row_pointer;
		col_pointer2 = row_pointer2;

		while (col_pointer&&col_pointer2)
		{
			col_pointer->data = col_pointer->data * col_pointer2->data;
			cout << col_pointer->data << " ";
			archivoOut << col_pointer->data << " ";
			col_pointer = col_pointer->right;
			col_pointer2 = col_pointer2->right;
		}
		cout << endl;
		archivoOut << "\n";
		row_pointer = row_pointer->down;
		row_pointer2 = row_pointer2->down;
	}



}



int main() {

	Node * head_node = NULL;
	Node2 * head_node2 = NULL;

	ponerNODOS(head_node, head_node2);
	if (verify == 0 && verify2 == 0) {
		int opcion = 0;
		cout << " " << endl;
		cout << "------Bienvenido------------" << endl;
		do {
			cout << "-----------Menu-----------" << endl;
			cout << "1) Suma " << endl;
			cout << "2) Resta" << endl;
			cout << "3) Multiplicacion" << endl;
			cout << "4) Calculo de determinante " << endl;
			cout << "5) Imprimir MAtrices " << endl;
			cout << "Ingrese el numero de su opcion" << endl;

			cin >> opcion;
			switch (opcion)
			{
			case 1:
				ponerNODOS(head_node, head_node2);
				suma(head_node, head_node2);
				break;
			case 2:
				ponerNODOS(head_node, head_node2);
				resta(head_node, head_node2);
				break;
			case 3:
				ponerNODOS(head_node, head_node2);
				break;
			case 4:
				ponerNODOS(head_node, head_node2);
				break;
			case 5:
				ponerNODOS(head_node, head_node2);
				cout << "Imprimiendo" << endl;
				print(head_node, head_node2);
				break;
			}



		} while (true);

	}











}