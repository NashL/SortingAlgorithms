#include <iostream>
#include <time.h>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;
int NN = 10000000;

int RandomNumber() {return (rand()%NN);}

void imprimir(vector<int> a){
	cout << "[ ";
	ostream_iterator<int> out_it (cout, " ");
	copy(a.begin(),a.end(), out_it );
	cout << "]\n";
}

void max_heapify( int *vec, int nodo, int tam){
    int raiz = nodo;
    while ( raiz*2+1 < tam ) {
        int hijo = 2*raiz + 1;
        if ((hijo + 1 < tam) && (vec[hijo] < vec[hijo+1]))
            hijo++;

        if (vec[raiz] < vec[hijo]) {
            swap( vec[hijo], vec[raiz] );
            raiz = hijo;
        }
        else
            return;
    }
}

void heap_sort(int *vec, int tam){
    int kn, fin;
    for (kn = (tam-2)/2; kn >=0; kn--)
        max_heapify( vec, kn, tam);

    for (fin=tam-1; fin > 0; fin--) {
        swap(vec[fin],vec[0]);
        max_heapify(vec, 0, fin);
    }
}

int main(){
	srand(time(NULL));
	int n_tam = NN;
	vector<int> vec(n_tam);
	generate(vec.begin(),vec.end(), RandomNumber); // Gen valores

    //imprimir(vec);

    heap_sort(&vec[0], n_tam);
    //imprimir(vec);

    return 0;
}
