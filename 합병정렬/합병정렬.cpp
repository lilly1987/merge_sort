#include <iostream> //std
#include <string> //getline
#include <time.h>
#include "�迭���.h"
#include "�迭ȸ��.h"
#include "�迭�Ҵ�.h"
#include "����.h"

using namespace std;

int main(int argc, char* argv[]) {

	unsigned int c0,c1;//r:��,c:��

	do
	{
		// �ܼ��� ��� ��¿����� cout �ݺ����� ���°� ���ɻ� ���� ����
		// ���������� ������ �ִٸ� �𸦱�
		// ������ �̸� ó���� �ѹ��� ����ϴ°� �� ����

		// �Է� �ޱ�
		cout << "���ڸ� �Է�." << endl;
		cout << "0 �Է½� ����" << endl;
		cout << "�迭1 ����:";
		cin >> c0;
		if (c0 == 0)
		{
			break;
		}
		cout << "�迭2 ����:";
		cin >> c1;
		if (c1 == 0)
		{
			break;
		}

		int *arr0 = new int[c0];//����1
		int *arr1 = new int[c1];//����2
		int *arr2 ;//����
		int *arr3 = new int[c0+c1];//����
		arr_rnd(arr0, c0, c0 * 3);
		arr_rnd(arr1, c1, c1 * 3);

		clock_t begin, end, t0, t1, t2, t3, t4, t5, t6, t7, t8;//�ð� ������

		//copy(arr0, arr0 + c, arr1);
		begin = clock();
		insertion_sort2(arr0, c0);//��������
		end = clock();          // �ð�����		
		arr_out(arr0, c0);
		t0 = end - begin;

		begin = clock();
		insertion_sort2(arr1, c1);//��������
		end = clock();          // �ð�����
		arr_out(arr1, c1);
		t1 = end - begin;
				
		begin = clock();
		arr2=merge_sort(arr0,arr1,c0, c1);//��������
		end = clock();          // �ð�����
		arr_out(arr2, c0+c1);
		t2 = end - begin;				

		begin = clock();
		merge_sort(arr0,arr1, arr3,c0, c1);//��������
		end = clock();          // �ð�����
		arr_out(arr3, c0+c1);
		t3 = end - begin;

		cout << "����ð� : " << t0 << endl;
		cout << "����ð� : " << t1 << endl;
		cout << "����ð� : " << t2 << endl;
		cout << "����ð� : " << t3 << endl;
		//cout << "����ð� : " << t4 << endl;
		//cout << "����ð� : " << t5 << endl;
		//cout << "����ð� : " << t6 << endl;
		//cout << "����ð� : " << t7 << endl;
		//cout << "����ð� : " << t8 << endl;

		delete arr0, arr1, arr2, arr3;

	} while (true);
}