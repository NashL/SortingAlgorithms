#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <iterator>

using namespace std;

int n_threads;
int NN = 100000;

int RandomNumber () { return (rand()%NN); }

void imprimir(vector<int> a){
	cout << "[ ";
	ostream_iterator<int> out_it (cout, " ");
	copy(a.begin(),a.end(), out_it );
	cout << "]\n";
}

void bubble_sort(int* a , int n){

	for(int i=1; i<n ; i++){
		for(int j=0; j<n-i; j++){
			if(a[j] > a[j+1]){
				swap(a[j],a[j+1]);
			}
		}
	}
}


int main(){
	srand(time(NULL));
	
	vector<int> a(NN);
	generate(a.begin(),a.end(), RandomNumber); // Gen va
	//launch_threads(&a[0],n);
	bubble_sort(&a[0],NN);

//	thread th1(bubbles_threads,&a[0],n);
//	thread th2(bubbles_threads,&a[0],n);

//	th1.join();
//	th2.join();

//	imprimir(a);
}
