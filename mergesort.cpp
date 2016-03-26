#include <iostream>
#include <stdlib.h>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;

int NN = 10000000;
void merge (int *array_n, int n_tam, int m_edio) {
    int i, j, k;
    int *aux = new int [n_tam];
    for (i = 0, j = m_edio, k = 0; k < n_tam; k++) {
        if (j == n_tam)
            aux[k] = array_n[i++];
        else
            if(i == m_edio)
                aux[k] =array_n[j++];
            else
                if (array_n[j] < array_n[i])
                    aux[k] = array_n[j++];
                else
                    aux[k] = array_n[i++];
    }

    for (i = 0; i < n_tam; i++) {
        array_n[i] = aux[i];
    }
    delete [] aux;
}

void merge_sort (int *array_n, int tam) {
    if (tam < 2){
        return;

    }
    int medio = tam >> 1;

    merge_sort(array_n, medio);
    merge_sort(array_n + medio, tam - medio);
    merge(array_n, tam, medio);
}

int RandomNumbers(){	return rand()%NN;}

void imprimir(vector<int> v){
	ostream_iterator<int> osit(cout," ");
	copy(v.begin(), v.end(), osit);
	cout << "\n";
}

int main () {
	srand(time(NULL));
	int n_tam = NN;
	vector<int> vec(n_tam);
	generate(vec.begin(), vec.end(), RandomNumbers);
    merge_sort(&vec[0], n_tam);
//	imprimir(vec);

    return 0;
}
