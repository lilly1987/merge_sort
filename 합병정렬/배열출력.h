#include <iostream> //std
#include <string> //getline


using namespace std;

void arr_out(const char * front,  int *arr, unsigned int v1, const char * back) {
	string  s = "" ;
	for (int i = 0; i < v1; i++) {
		s += to_string(arr[i]) + '\t';
	}
	cout << front << endl << s<< back<<endl;
}
void arr_out(const char * front,  int *arr, unsigned int v1) {
	arr_out(front, arr, v1, "");
}
void arr_out( int *arr, unsigned int v1, const char * back) {
	arr_out("", arr, v1, back);
}
void arr_out( int *arr, unsigned int v1) {
	arr_out("", arr, v1, "");
}

void arr_out2(const char * front,  int **arr, unsigned int v1, unsigned int v2, const  char * back) {
	
	string  s = "";
	for (int i = 0; i < v1; i++) {
		for (int j = 0; j < v2; j++) {
			s += to_string(arr[i][j]) + '\t';
		}
		s += '\n';
	}
	cout << front << endl << s<< back<<endl;
}
void arr_out2(const char * front,  int **arr, unsigned int v1, unsigned int v2) {
	arr_out2(front, arr, v1,v2, "");
}
void arr_out2(  int **arr, unsigned int v1, unsigned int v2, const char * back) {
	arr_out2("", arr, v1,v2, back);
}
void arr_out2(  int **arr, unsigned int v1, unsigned int v2) {
	arr_out2("", arr, v1,v2, "");
}
