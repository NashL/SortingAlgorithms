#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <iterator>
#include <time.h>
#include <thread>

using namespace std;
int NN = 100000;

void selection_sort_ini(int* vec, int n){

	int min, tm = n/2;
	for(int i=0 ; i< n/2 ; i++){
		min = i;
		for(int j= i+1; j<n ; j++){
			if( vec[j] < vec[min]){
				min = j;
			}
//cout << ".";
		}
		swap(vec[min], vec[i]);
	}
}
void selection_sort_end(int* vec, int n){

	int max, tm = n/2;

	for(int i=n-1 ; i> n/2 ; i--){
		max = i;
		for(int j= i-1; j>=0 ; j--){
			if( vec[j] > vec[max]){
				max = j;
			}
//cout << "_";
		}
		swap(vec[max], vec[i]);
	}
}

void launch_threads(int *vec, int n){

    thread t1(selection_sort_ini,&vec[0],n);
    thread t2(selection_sort_end,&vec[0],n);
    t1.join();
    t2.join();
}


int RandomNumbers() { return (rand() % NN); }

int main(){

	srand(time(NULL));
	int n = NN;
	vector<int> vec(n);
	generate(vec.begin(), vec.end(), RandomNumbers);
	launch_threads(&vec[0], n);

//	cout << rand_r(1)%20 << endl;

	//selection_sort(&vec[0], n);
//ostream_iterator<int> out_it(cout, " ");
//	copy(vec.begin(), vec.end(), out_it);
//	cout << endl;
}
