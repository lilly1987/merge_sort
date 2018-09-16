#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/// <summary>
/// 2차원 배열 초기화
/// 실제론 호출된곳에 저장 안됨
/// </summary>
//void arr_new2(int **arr,int v1,int v2) {
//	arr= new int *[v1];
//	//arr= new int *[v1];
//	cout << arr << '\t' << &arr << endl;
//	for (int i = 0; i < v1; i++) {
//		arr[i] = new int[v2];
//	cout << arr <<'\t'<< &arr <<'\t'<< arr[i] << '\t' << &arr[i] << endl;
//	}
//}

/// <summary>
/// 2차원 배열 초기화
/// 안됨
/// </summary>
//void arr_new2(int ***ar,int v1,int v2) {
//	int **arr= new int *[v1];
//	//arr= new int *[v1];
//	cout << ar << '\t' << &ar << '\t' << arr << '\t' << &arr << endl;
//	for (int i = 0; i < v1; i++) {
//		arr[i] = new int[v2];
//	cout << ar << '\t'<< &ar << '\t' << arr <<'\t'<< &arr <<'\t'<< arr[i] << '\t' << &arr[i] << endl;
//	}
//	ar = &arr;
//}

/// <summary>
/// 2차원 배열 초기화
/// 아오 2차원 배열 참조 하는 예제를 쓰는데가 어떻게 하나도 없냐
/// </summary>
void arr_new2(int **&arr, unsigned int v1, unsigned int v2) {
	 arr= new int *[v1];
	//arr= new int *[v1];
	//cout << ar << '\t' << &ar << '\t' << arr << '\t' << &arr << endl;
	for (int i = 0; i < v1; i++) {
		arr[i] = new int[v2];
	//cout << ar << '\t'<< &ar << '\t' << arr <<'\t'<< &arr <<'\t'<< arr[i] << '\t' << &arr[i] << endl;
	}
	//ar = &arr;
}

/// <summary>
/// 2차원 배열 초기화
/// 
/// </summary>
int** arr_new2(unsigned int v1, unsigned int v2) {
	//int **arr= new int *[v1];
	int **arr= new int *[v1];
	cout << arr << '\t' << &arr << endl;
	for (int i = 0; i < v1; i++) {
		arr[i] = new int[v2];
	cout << arr <<'\t'<< &arr <<'\t'<< arr[i] << '\t' << &arr[i] << endl;
	}
	//ar = &arr;	
	return arr;
}

/// <summary>
/// 2차원 배열 제거 
/// 
/// </summary>
void arr_del2(int **&arr, unsigned int v1) {
	for (int i = 0; i < v1; i++) {
		delete[] arr[i];
	}
	delete[] arr;
}

void arr_rnd(int *&arr,unsigned int c,unsigned int max) {
	srand((int)time(NULL));
	for (unsigned int i = 0; i < c; i++) { //랜덤 발생
		arr[i] = rand() % max;
	}
}

void arr_rnd(int *&arr,unsigned int c) {
	arr_rnd(arr, c, 100);
}