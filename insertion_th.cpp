#include <iostream>
#include <vector>
#include <algorithm>
#include <thread>
#include <iterator>

using namespace std;

int NN = 100;
int v_max, v_min;
void insertion_sort (int* arr, int length, int id){

	for (int i = 1, j; i < length; i++){
		j = i;
		while (j && (arr[j] < arr[j-1])){
            swap(arr[j],arr[j-1]);
			j--;
			}
		}
}

void insertion_sort_m (int* arr, int length){
	for (int i = length-1, j; i >= 0; i--){
		j = i;
		while (j<length && (arr[j] > arr[j+1])){
	            swap(arr[j],arr[j+1]);
		    j++;
		}
	}
}

void insertion_sort_end (int* arr, int length){
	int top = length << 1;
cout << "top: " << top << endl;
cout << "length: " << length << endl;
	for (int i = length + 1, j; i < top; i++){
		j = i;
		while (j>length && (arr[j] < arr[j-1])){
			swap(arr[j],arr[j-1]);
			j--;
		}
	}
}

void launch_threads(int* a, int n){
    int n_threads = thread::hardware_concurrency();
 //   thread th[n_threads];
	thread thr;
	thread thr2;
/*    for(int i=0; i < n_threads; i++){
        th[i] = thread(insertion_sort_m,a,n,i);
    }
    for(int i=0; i < n_threads; i++)
        th[i].join();
*/
	thr =  thread(insertion_sort_m, a, n/2);
	thr2 = thread(insertion_sort_end, a, n/2);
	
	thr.join();
	thr2.join();

    /*

    thread t1(insertion_sort_ini, a, n);
    thread t2(insertion_sort_end, a, n);
    t1.join();
    t2.join();
    */
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
	v_min = 0;
	v_max = 0;
    vector<int> vec(tam);
    generate(vec.begin(),vec.end(),RandomNumbers);
    launch_threads(&vec[0],tam);
//	cout << "hola " << endl;
    //insertion_sort(&vec[0],tam);
	imprimir(vec);
    //cout << endl;
/*    for (int i = 0; i < 100; i++) {

        cout<< vec[i]<<" ";
    }
  */  return 0;

}
