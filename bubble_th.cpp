#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <iterator>
#include <thread>

using namespace std;
int  NN = 100000;

int n_threads;

int RandomNumber () { return (rand()%NN); }

void imprimir(vector<int> a){
	cout << "[ ";
	ostream_iterator<int> out_it (cout, " ");
	copy(a.begin(),a.end(), out_it );
	cout << "]\n";
}

void bubble_sort_ini(int* a , int n){

    int st = n>>1;
	for(int i=1; i<st ; i++){
		for(int j=0; j<n-i ; j++){
            //cout << "j = " << j << endl;
			if(a[j] > a[j+1])
				swap(a[j],a[j+1]);
		}
	}
}

void bubble_sort_end(int* a , int n){
    int st= n>>1;
	for(int i=1; i<st ; i++){
		for(int j = n-1; j>=i; j--){
            //cout << "j = " << j << endl;
			if(a[j] < a[j-1])
				swap(a[j],a[j-1]);
		}
	}
}

void launch_threads(int *a,int n){
	thread t1( bubble_sort_ini, a, n);
	thread t2( bubble_sort_end, a, n);
	t1.join();
	t2.join();
}

int main(){
	srand(time(NULL));
	
	vector<int> a(NN);
	generate(a.begin(),a.end(), RandomNumber); // Gen va
	launch_threads(&a[0],NN);
	//bubble_sort(&a[0],n);
//	thread th1(bubbles_threads,&a[0],n);
//	thread th2(bubbles_threads,&a[0],n);
//	th1.join();
//	th2.join();

//	imprimir(a);
}
