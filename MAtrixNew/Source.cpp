#include "iostream"
#include<fstream>
#include<vector>
#include<string>
using namespace std;
//construct the structure



struct Node
{
	int data;
	Node* right;
	Node* down;
};

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
int getNumF(string nombredelArchivo)
{
	ifstream archivoMatrices1(nombredelArchivo, ios::in);
	bool restCol = false;
	int columnas = 0;
	int filas = 0;
	int line;

	while (archivoMatrices1 >> line)
	{
		if (restCol == false) {
			columnas++;
		}

		if (archivoMatrices1.peek() == '\n') //detect "\n"
		{
			restCol = true;
			filas++;

		}

	}
	archivoMatrices1.close();
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
		return columnas;
	}
	archivoMatrices.close();
	return columnas;
}
int  NUMF = getNumF("matriz1.txt");
int  NUMCOL = getNumC("matriz1.txt");
int main() {

	string  archivo;
	vector <vector<int> >arreglo;

	cout << NUMF  << endl;
	cout << NUMCOL << endl;
	system("pause");
	ifstream archivoMatrices(archivo, ios::in);
	if (!archivoMatrices) {
		cout << "error" << endl;
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

		Node * head_node = Matrix2LLFun(arreglo, 0, 0, NUMF, NUMCOL);

		//finally printing out the linked list.
		//now make two pointers one will move row wise and other will move colomn wise.
		Node *row_pointer, *col_pointer;
		row_pointer = head_node;

		//Imprimir nodos
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
		int opcion = 0;
		system("pause");




	}


}