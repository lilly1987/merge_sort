#include <time.h>
#include <iterator>

// 코드가 단순할수록 코드 한줄 차이가 속도차이로 이어짐
// swap도 함수보단 그냥 코딩을 하는게 더 빠름
// 함수를 호출하는것 자체가 속도 저하
// for,while문 내에 변수 선언하지 말자. 변수 같은건 가급적 밖에서 선언하는게 빠름
/* 기본 제공하는 swap 사용시
배열 갯수:40000
수행시간 : 22694
수행시간 : 1687
수행시간 : 30715
수행시간 : 30620
수행시간 : 21504
수행시간 : 1109
수행시간 : 622
배열 갯수:20000
수행시간 : 6751
수행시간 : 430
수행시간 : 8006
수행시간 : 8049
수행시간 : 5472
수행시간 : 283
수행시간 : 159
배열 갯수:10000
수행시간 : 1671
수행시간 : 107
수행시간 : 1912
수행시간 : 1921
수행시간 : 1358
수행시간 : 70
수행시간 : 37
배열 갯수:5000
수행시간 : 431
수행시간 : 27
수행시간 : 481
수행시간 : 476
수행시간 : 358
수행시간 : 22
수행시간 : 10
*/

/* 변수를 이용한 swap시
배열 갯수:40000
수행시간 : 4612
수행시간 : 1681
수행시간 : 4525
수행시간 : 4474
수행시간 : 9748
수행시간 : 1161
수행시간 : 659
배열 갯수:20000
수행시간 : 1178
수행시간 : 432
수행시간 : 1085
수행시간 : 1073
수행시간 : 2409
수행시간 : 281
수행시간 : 158
배열 갯수:10000
수행시간 : 285
수행시간 : 103
수행시간 : 248
수행시간 : 240
수행시간 : 601
수행시간 : 68
insertion_sort2 수행시간 : 38
*/
// 교체
template<typename T>
void swap_my(T &a, T &b) {
	T t = a;
	a = b;
	b = t;
}

#pragma once
// 뒤커서를 옮긴후 숫자가 다를때마다 swap이 일어남
// 복잡도 O(n^{2})
// 2만건 1190ms
template<typename T>
void sort_Select(T *&arr, const unsigned int length) {
	T t;
	unsigned int i, j;
	for (i = 0; i < length - 1; i++)
	{
		for (j = i + 1; j < length; j++)
		{
			if (arr[i] > arr[j])
			{
				t = arr[i];
				arr[i] = arr[j];
				arr[j] = t;
				//swap(arr[i], arr[j]);
			}
		}
	}
}

// https://ko.wikipedia.org/wiki/%EC%84%A0%ED%83%9D_%EC%A0%95%EB%A0%AC
// 앞커서가 옮길때마다 swap 이 한번만 일어남
// 복잡도 O(n^{2}) 이지만 swap 횟수차이로 인해 속도가 빨라짐
// 2만건 433ms
template<typename T>
void sort_Select2(T *&list, const unsigned int n) {
	int indexMin;
	T t;
	unsigned int i, j;
	for (i = 0; i < n - 1; i++)
	{
		indexMin = i;
		for (j = i + 1; j < n; j++)
		{
			if (list[j] < list[indexMin])
			{
				indexMin = j;
			}
		}
		t = list[indexMin];
		list[indexMin] = list[i];
		list[i] = t;
		//swap(list[indexMin], list[i]);
	}
}

// 복잡도 O(n^{2})
// 2만건 1117ms
template<typename T>
void sort_Bubble(T *&list, const unsigned int c) {
	T t = 0;
	unsigned int loop, i;
	for (loop = 0; loop < c - 1; loop++) {
		for (i = 0; i < c - 1 - loop; i++) {
			if (list[i] > list[i + 1]) {
				t = list[i];
				list[i] = list[i + 1];
				list[i + 1] = t;
				//swap(list[i], list[i + 1]);
			}
		}
	}
}

// 정렬이 다 됐을경우에 패스라서 사실상 위 로직과 별차이 없음
// 2만건 1079ms
template<typename T>
void sort_Bubble2(T *&arr, const unsigned int c) {
	T t;
	unsigned int j, i, f = 1;
	for (i = c - 1; f > 0; i--)
	{
		f = 0;
		for (j = 0; j < i; j++)// 여기에서 if 문이 한번도 진입 안하면 정렬 다 되었다는뜻
		{
			if (arr[j] > arr[j + 1])
			{
				t = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = t;
				//swap(arr[j], arr[j + 1]);
				f = 1;
			}
		}
	}
}

// 좌우 버블 정렬
// 2만건 825ms
template<typename T>
void sort_Bubble3(T *&arr, const unsigned int c) {
	T t;
	unsigned int i, s, st = 0, ed = c - 1;
	while (st < ed)
	{
		for (i = st; i < ed; i++)
		{
			//cout << arr[i] << "\t" << arr[i + 1];
			if (arr[i] > arr[i + 1])
			{
				t = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = t;
				//swap(arr[i], arr[i + 1]);
				s = i;
				//cout << "\t" << s;
			}
			//cout << endl;
		}
		ed = s;
		//arr_out(arr, c);
		for (i = ed; i > st; i--)
		{
			//cout << arr[i - 1] << "\t" << arr[i];
			if (arr[i - 1] > arr[i])
			{
				t = arr[i - 1];
				arr[i - 1] = arr[i];
				arr[i] = t;
				swap(arr[i - 1], arr[i]);
				s = i;
				//cout << "\t" << s;
			}
			//cout << endl;
		}
		st = s;
		//arr_out(arr, c);
	}
}

//2만건 286
template<typename T>
void insertion_sort(T *&arr, int c)
{
	int i, j;
	T remember;
	for (i = 1; i < c; i++)
	{
		//cout << "i:" << i << endl;
		//arr_out(arr, c);
		remember = arr[(j = i)];
		while (--j >= 0 && remember < arr[j]) {
			//cout << "j :"<< j << endl;
			arr[j + 1] = arr[j];
			arr[j] = remember;
			//arr_out(arr, c);
		}
	}
}

//2만건 162
template<typename T>
void insertion_sort2(T *&data, int n)
{
	int i, j;
	T remember;
	i = n - 1;
	while (i-- > 0)
	{
		remember = data[(j = i)];
		while (++j < n && remember > data[j]);

		if (--j == i) continue;
		memcpy(data + i, data + i + 1, sizeof(*data) * (j - i));
		data[j] = remember;
	}
}

// 이건 어떻게 쓰는것인가
template<typename T>
void insertion_sort3(T begin, T end)
{
	T bond = begin;
	for (++bond; bond != end; ++bond)
	{
		typename std::iterator_traits<T>::value_type key = *bond;
		T ins = bond;
		T pre = ins;
		for (--pre; ins != begin && *pre > key; *ins-- = *pre--);
		*ins = key;
	}
}

// 이미 정렬된 두 배열 병합
template<typename T>
void merge_sort(T *&a, T *&b, T *&c, const unsigned an, const unsigned bn) {
	unsigned int i = 0, j = 0, k = 0,p;	
	while (true)
	{
		if (a[i] < b[j]) {// a:n , b:m
			
			c[k++] = a[i++];
			if (i >= an)
			{
				for (T p = j; p < bn; p++)
				{
					c[k++] = b[p];
				}
				break;
			}
		}
		else {
			c[k++] = b[j++];
			if (j >= bn)
			{
				for (T p = i; p < an; p++)
				{
					c[k++] = a[p];
				}
				break;
			}
		}

	}

}
template<typename T>
T* merge_sort(T *&a, T *&b, const unsigned an, const unsigned bn) {
	T *c = new T[an + bn];
	merge_sort(a, b, c, an, bn);
	return c;
}