#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <thread>
#include <iterator>

using namespace std;
int NN = 10000000;

void merge_m (int* array_n, int n_tam, int m_edio) {
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

void merge_sort (int* array_n, int tam) {
    if (tam < 2){
        return;

    }
    int medio = tam >> 1;
	merge_sort(array_n, medio);
	merge_sort(array_n +medio , tam - medio);
	merge_m(array_n, tam, medio);
}

int RandomNumbers(){	return rand()%NN;}

void imprimir(vector<int> v){
	ostream_iterator<int> osit(cout," ");
	copy(v.begin(), v.end(), osit);
	cout << "\n";
}

void last_merge_call(int* array,int n_tam,int n_part){
	if (n_tam <= n_part)
		return;
	int medio = n_tam/2;
	last_merge_call(array,medio,n_part);
	last_merge_call(array+medio,n_tam-medio,n_part);
	merge_m(array,n_tam,medio);

}
void start_threads(int* vec, int n_tam){


	unsigned n_cores = thread::hardware_concurrency();
	//n_cores = 100000;
	thread th[n_cores];

	int n_part = n_tam / n_cores;
	for(int i=0; i < n_cores ; i++){
		th[i]= thread(merge_sort,&vec[i*n_part],n_part);
	}
	for(int i=0; i < n_cores ; i++){
		th[i].join();
	}
	last_merge_call(&vec[0],n_tam,n_part);

}


int main () {
	srand(time(NULL));
	int n_tam = NN;
//	unsigned n_cores = thread::hardware_concurrency();
	vector<int> vec(n_tam);
	generate(vec.begin(), vec.end(), RandomNumbers);
    start_threads(&vec[0],n_tam);
	//imprimir(vec);
	return 0;
}
