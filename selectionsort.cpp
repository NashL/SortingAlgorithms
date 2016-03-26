#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <iterator>

using namespace std;
int NN = 100000;

void selection_sort(int* vec, int n){
	int min;
	for(int i=0 ; i< n-1 ; i++){
		min = i;
		for(int j= i+1; j<n ; j++){
			if( vec[j] < vec[min]){
				min = j;
			}
		}
		swap(vec[min], vec[i]);
	}
}

int RandomNumbers() { return (rand() % NN); }

int main(){
	srand(time(NULL));
	int n = NN;
	vector<int> vec(n);
	generate(vec.begin(), vec.end(), RandomNumbers);
	selection_sort(&vec[0], n);
//ostream_iterator<int> out_it(cout, " ");
//	copy(vec.begin(), vec.end(), out_it);
//	cout << endl;
}
