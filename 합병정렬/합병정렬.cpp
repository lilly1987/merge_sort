#include <iostream> //std
#include <string> //getline
#include <time.h>
#include "배열출력.h"
#include "배열회전.h"
#include "배열할당.h"
#include "정렬.h"

using namespace std;

int main(int argc, char* argv[]) {

	unsigned int c0,c1;//r:행,c:열

	do
	{
		// 단순히 모양 출력용으로 cout 반복으로 쓰는건 성능상 좋지 않음
		// 수학적으로 쓸일이 있다면 모를까
		// 변수에 미리 처리후 한번만 출력하는게 젤 좋음

		// 입력 받기
		cout << "숫자만 입력." << endl;
		cout << "0 입력시 종료" << endl;
		cout << "배열1 갯수:";
		cin >> c0;
		if (c0 == 0)
		{
			break;
		}
		cout << "배열2 갯수:";
		cin >> c1;
		if (c1 == 0)
		{
			break;
		}

		int *arr0 = new int[c0];//원본1
		int *arr1 = new int[c1];//원본2
		int *arr2 ;//병합
		int *arr3 = new int[c0+c1];//병합
		arr_rnd(arr0, c0, c0 * 3);
		arr_rnd(arr1, c1, c1 * 3);

		clock_t begin, end, t0, t1, t2, t3, t4, t5, t6, t7, t8;//시간 측정용

		//copy(arr0, arr0 + c, arr1);
		begin = clock();
		insertion_sort2(arr0, c0);//삽입정렬
		end = clock();          // 시간설정		
		arr_out(arr0, c0);
		t0 = end - begin;

		begin = clock();
		insertion_sort2(arr1, c1);//삽입정렬
		end = clock();          // 시간설정
		arr_out(arr1, c1);
		t1 = end - begin;
				
		begin = clock();
		arr2=merge_sort(arr0,arr1,c0, c1);//병합정렬
		end = clock();          // 시간설정
		arr_out(arr2, c0+c1);
		t2 = end - begin;				

		begin = clock();
		merge_sort(arr0,arr1, arr3,c0, c1);//병합정렬
		end = clock();          // 시간설정
		arr_out(arr3, c0+c1);
		t3 = end - begin;

		cout << "수행시간 : " << t0 << endl;
		cout << "수행시간 : " << t1 << endl;
		cout << "수행시간 : " << t2 << endl;
		cout << "수행시간 : " << t3 << endl;
		//cout << "수행시간 : " << t4 << endl;
		//cout << "수행시간 : " << t5 << endl;
		//cout << "수행시간 : " << t6 << endl;
		//cout << "수행시간 : " << t7 << endl;
		//cout << "수행시간 : " << t8 << endl;

		delete arr0, arr1, arr2, arr3;

	} while (true);
}