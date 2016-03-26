#include <iostream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <iterator>
#include <thread>

using namespace std;

int NN = 10000000;


void myQuickSort(int* mylist, int min, int max){

	int pivot = mylist[(min + max) >> 1];
	int left = min, right = max;

    while (left < right) {
		while (mylist[left] < pivot)	left++;
		while (mylist[right] > pivot) 	right--;
		if (left <= right) {
            swap(mylist[left], mylist[right]);
            left++;		right--;
		}
	}
    if (min < right) 
        myQuickSort(mylist, min, right);
    
    if (left < max) 
    	myQuickSort(mylist, left, max);
}
void imprimir(vector<int> vec){
	ostream_iterator<int> oit(cout, " ");
	copy(vec.begin(), vec.end(), oit);
	cout << "\n";
}
void start_threads(int* vec,int n_tam){
	
	unsigned n_cores = thread::hardware_concurrency();
//n_cores = 100000;

	thread th[n_cores];
	int n_part = n_tam / n_cores;
	for(int i=0; i < n_cores ; i++){
		th[i]= thread(myQuickSort,&vec[0],i*n_part,n_part*(i+1));
	}
	for(int i=0; i < n_cores ; i++){
		th[i].join();
	}
	myQuickSort(&vec[0],0, n_tam);
}

int RandomNumbers(){	return (rand() % NN);}

int main()
{
    srand(time(NULL));
	long n_tam = NN;
	vector<int> vec(n_tam);
	generate(vec.begin(),vec.end(),RandomNumbers);
//	thread t1 ( myQuickSort,&vec[0],0, tam-1);
	start_threads(&vec[0],NN);
//	imprimir(vec);
	//t1.join();

    return 0;
}
