#include <iostream>
#include <time.h>
using namespace std;


int* createArr(size_t n) {
	int* mas = new int[n] {0};
	return mas;
}
void deleteArr(int* p) {
	delete[] p;
}
void PrintArr(int* p, int size) {
	for (size_t i = 0; i < size; i++)
	{
		//cout << p[i] << '\t';
		//cout << *(p+i) << '\t';
		cout << *(p++) << '\t';

	}
	cout << '\n';
}

int* Push(int* p, int& size, int el) {
	int* mas = createArr(size + 1);
	for (size_t i = 0; i < size; i++)
		*(mas + i) = *(p + i);//	mas[i] =p[i];
	mas[size] = el;
	size++;
	delete[] p;
	return mas;
}
void Push2(int*& p, int& size, int el) {
	int* mas = createArr(size + 1);
	for (size_t i = 0; i < size; i++)
		*(mas + i) = *(p + i);//	mas[i] =p[i];
	mas[size] = el;
	size++;
	delete[] p;
	p = mas;
}

void Test2() {
	int n;
	cout << "Input size array = ";
	cin >> n;
	int* arr = createArr(n);
	*arr = 10;
	*(arr + 1) = 20;
	cout << arr << endl;
	cout << arr + 1 << endl;
	PrintArr(arr, n);
	arr = Push(arr, n, 13);
	PrintArr(arr, n);
	cout << arr << endl;
	cout << arr + 1 << endl;
	Push2(arr, n, 999);
	PrintArr(arr, n);

	deleteArr(arr);
}
void Test1() {
	int mas1[2]{ 100,200 };
	cout << *mas1 << endl;

	int mas2[3][4]{ {10,20,30},{40,50,60} };
	for (size_t i = 0; i < 2; i++)
	{
		for (size_t j = 0; j < 3; j++)
		{
			cout << &mas2[i][j] << '\t';
		}
		cout << endl;
	}


	cout << *mas2[0] << endl;
	int* p = (int*)mas2;
	for (size_t i = 0; i < 6; i++)
		cout << p + i << "\t";
	cout << endl;
	for (size_t i = 0; i < 6; i++) {
		if (i % 3 == 0) {
			i++;
			cout << endl;
		}
		cout << *(p + i) << "\t";
	}
	cout << endl;

}
void Test3() {
	int r = 6, c = 4;
	//int* m1 = new int[4]{ 0 };
	//int* m2 = new int[4]{ 0 };
	//int* m3 = new int[4]{ 0 };

	int** mas = new int* [r];
	for (size_t i = 0; i < r; i++)
		mas[i] = new int[c] { 0 };


	int k = 1;
	for (size_t i = 0; i < r; i++)
		for (size_t j = 0; j < c; j++)
			mas[i][j] = k++;

	//for (size_t i = 0; i < 4; i++)
	//	m1[i] =k++;// rand() % 10;
	//for (size_t i = 0; i < 4; i++)
	//	m2[i] = k++;// rand() % 10;
	//for (size_t i = 0; i < 4; i++)
	//	m3[i] = k++;// rand() % 10;


	/*for (size_t i = 0; i < 4; i++)

		cout << m1[i] << endl;
	for (size_t i = 0; i < 4; i++)
		cout << m2[i] << endl;
	for (size_t i = 0; i < 4; i++)
		cout << m3[i] << endl;*/

	for (size_t i = 0; i < r; i++) {
		//cout << mas[i] << endl;
		//PrintArr(mas[i], 4);
		for (size_t j = 0; j < c; j++)
		{
			cout << mas[i][j] << '\t';
			//cout << *(mas[i]+j) << '\t';
			//cout << *(*(mas + i) +j) << '\t';
		}
		cout << endl;
	}
	for (size_t i = 0; i < r; i++)
		delete[] mas[i];
	delete[] mas;


}
//написати функції:
//1 створення масиву 2д
int** createArr2D(int row, int col) {
	int** mas = new int* [row];
	for (size_t i = 0; i < row; i++)
		mas[i] = new int[col] { 0 };
	return mas;
}
//2 видалення масиву 
void deleteArr2D(int**& mas, int r) {
	if (mas) {
		for (size_t i = 0; i < r; i++)
			delete[] mas[i];
		delete[] mas;
		mas = nullptr;
	}
}
//3 вивід масиву на екран
void PrintArr2D(int** mas, int r, int c) {
	for (size_t i = 0; i < r; i++) {
		for (size_t j = 0; j < c; j++)
			cout << mas[i][j] << '\t';
		cout << endl;
	}
	cout << endl << "-----------------------------------\n";
}
//4 заповнення рандомно
void SetRndArr2D(int** mas, int r, int c, int a, int b) {
	if (a > b) swap(a, b);
	for (size_t i = 0; i < r; i++)
		for (size_t j = 0; j < c; j++)
			mas[i][j] = a + rand() % (b - a + 1);
}
//5 заповнення вручну
void SetArr2D(int** mas, int r, int c) {

	for (size_t i = 0; i < r; i++) {
		cout << "-----------------------------------\n";
		for (size_t j = 0; j < c; j++) {
			cout << "array[" << i << "][" << j << "]=";
			cin >> mas[i][j];
		}
	}
}
void Test4() {
	int r = 6, c = 4;
	cout << "Enter r,c";
	cin >> r >> c;
	int** arr = createArr2D(r, c);
	//PrintArr2D(arr, r, c);
	//SetRndArr2D(arr, r, c, -10, 10);
	SetArr2D(arr, r, c);
	PrintArr2D(arr, r, c);
	//int** arr2 = createArr2D(r, c);
	////PrintArr2D(arr, r, c);
	//SetRndArr2D(arr2, r, c, -10, 10);
	//PrintArr2D(arr2, r, c);
	//deleteArr2D(arr2, r);


	deleteArr2D(arr, r);
}

int main() {
	srand(time(0));
	Test4();
	//Test3();
	//Test1();
	//Test2();
	return 0;
}
