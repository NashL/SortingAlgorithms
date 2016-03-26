#include <iostream>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <iterator>
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

int RandomNumbers(){	return (rand() % NN);}

int main()
{
    srand(time(NULL));
	long tam = NN;
	vector<int> vec(tam);
	generate(vec.begin(),vec.end(),RandomNumbers);
    myQuickSort(&vec[0],0, tam-1);
//	imprimir(vec);
    return 0;
}
