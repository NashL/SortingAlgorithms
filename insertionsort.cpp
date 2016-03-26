#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <vector>

using namespace std;

int NN = 100000;
void insertion_sort (int* arr, int length){

	for (int i = 1, j; i < length; i++){
		j = i;
		//cout << i << endl;
		while (j && (arr[j] < arr[j-1])){
            swap(arr[j],arr[j-1]);
			j--;
			}
		}
}

int RandomNumbers(){return (rand()%NN);}

void imprimir(vector<int> vec){
	ostream_iterator<int> out(cout, " ");
	copy(vec.begin(),vec.end(),out);
	cout << "\n";
}
int main()
{
    srand(time(NULL));
    int tam = NN;
    vector<int> vec(tam);
    generate(vec.begin(),vec.end(),RandomNumbers);

    insertion_sort(&vec[0],tam);
//	imprimir(vec);
    //cout << endl;
/*    for (int i = 0; i < 100; i++) {

        cout<< vec[i]<<" ";
    }
  */  return 0;

}
