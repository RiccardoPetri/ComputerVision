#include "Helper.h"
#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <vector>
#include <map>

using namespace std;



bool isPalindrome(string world) {
	string worldReverse = "";

	for (int i = world.size() - 1; i >= 0; i--) {
		worldReverse += world[i];
	}
	cout << world << endl;
	return world == worldReverse;
}

int sumNumber(int n) {
	string numberStr = to_string(n);		
	//char const* pchar = numberStr.c_str();
	//cout << (numberStr[0]-'0') << endl;
	//cout << numberStr.size() << endl;
	int total = 0;
	for (int i = 0; i <= numberStr.size()-1; i++) {
		
		total+=(numberStr[i] - '0');	//convert char into an int
		
	}
	return total;
}

// A dummy function
void functionThread(int Z)
{
	for (int i = 0; i < Z; i++) {
		cout << "x";
	}
}

// A dummy function
void functionThread1(int Z)
{
	for (int i = 0; i < Z; i++) {
		//if (i == 1) {
			cout << "y";
			//return;
		//}
	}
}

// A callable object
class thread_obj {
public:
	void operator()(int x)
	{
		for (int i = 0; i < x; i++)
			cout << "o";
	}
};

vector<int> question(int vec[],int size, int target) {
	vector<int> res;
	int counter=0;
	for (int i = 0; i < size-1; i++) {
		for (int j = counter; j < sizeof(vec); j++) {
			if (vec[i] + vec[j] == target) {
				res.push_back(vec[i]);
				res.push_back(vec[j]);
			}
		}
		counter++;
	}
	
	return res; 
}


vector<int> question4(int arr[], int size, int target) {
	map<int, int> myMap;
	int complement, x;
	vector<int> complementVector;
	
	for (int i = 0; i < size; i++) {
		complement = target - arr[i];
		if (myMap.count(complement)) {		//COUNT FOR SEARCHING KEYS!!!
			complementVector.push_back(complement);
		}
		myMap.insert(pair<int, int>(arr[i], i));
		
	}
	return complementVector;
}


bool stringPalindrome(const char* st) {
	const char* pLeft = st;
	const char* pRight = st + strlen(st) - 1;

	while (pRight > pLeft) {

		if (*pLeft != *pRight) {
			return false;
		}
		pLeft++;
		pRight--;
		
	}
	return true;
}








//int main(int argc, char* argv[])
int main()
{
	Helper help;
	help.help();
	int prova1, prova2, prova3;
	/*int* prova = new int[2];
	delete[] prova;*/

	//int a = 7; 
	//int* b = &a;
	////(*b)++;
	//int c = b[0];
	//b[4] = 22;
	//int d = b[4];
	//int e = b[0 + 4];
	//cout << (*b) << endl;


	//std::cin >> prova1 >> prova2 >> prova3; //after every number i have to tap enter!

	//std::cout << prova1 << prova2 << prova3;


	/*string text;
	getline(cin, text);
	cout << text;*/
	
	//int a = 3 + 4;


	/*char text[] = "text";
	cout << text;
	cout << text[1];*/

		
		vector<int> vettore, vet;
		vet.push_back(20);
		vet.push_back(30);
		vet.push_back(7);
		vet.push_back(6);
	
		
		int arrayInput[] = { 20,30,7,6 };

		int min = 0, temp = 0;

		for (int i = 0; i < vet.size() - 1; i++) {
			min = i;

			for (int j = i + 1; j < size(vet); j++) {
				if (vet[j] < vet[min]) { //cambiare questa condizione per invertire l'ordine
					min = j;
				}
			}
			temp = vet[min]; //qui c'è il valore piu piccolo
			vet[min] = vet[i]; //devo switcharli
			vet[i] = temp;
			
		}

		for (int x : vet) {
			cout << x << " ";
		}
		cout << endl;



		//_________________________________________________________________


		int target = 13;
		int array1[] = { 120, 5 , 10, 20, 8, 3};
		int size = sizeof(array1) / sizeof(array1[0]);
		vector<int> v = question(array1,size, target);
		for (int x : v) {
			cout << x << " ";
		}
		cout << endl<< endl;



		vector<int> v4 = question4(array1,size, target);
		
		for (int x : v4) {
			cout << x << " " << target - x<<" ";
		}
		
		//_________________________________________________________________

		cout << endl;

	int total = sumNumber(56);
	isPalindrome(to_string(total)) ? cout << "yes!!" <<endl: cout << "no"<< endl;

	int total1 = sumNumber(123);
	isPalindrome(to_string(total1)) ? cout << "yes!!" << endl: cout << "no"<< endl;

	int total2 = sumNumber(77);
	isPalindrome(to_string(total2)) ? cout << "yes!!" <<endl: cout << "no"<<endl;





	//thread thread1(functionThread, 100);
	//thread thread2(functionThread1, 100);
	//thread thread3(thread_obj(), 300);

	////if i want to wait until the end (i'm sure that the thread do all the work!!!!!)
	//thread1.join(); // Wait for thread t1 to finish
	//thread2.join();
	//thread3.join();

	

	//Separates the thread of execution from the thread object, allowing execution to continue independently. Any allocated resources will be freed once the thread exits. 
	/*thread1.detach();
	thread2.detach();
	thread3.detach();*/
	//this_thread::sleep_for(2000ms);  ALWAYS NEEDED OR THEY HAVE NOT TIME TO END!!!


		const char* s1 = "ossso";
		const char* s2 = "ossi";
		cout << endl;
		stringPalindrome(s1) ? cout << "s1 YESSSS" :cout<< "s1 NO";
		cout << endl;
		stringPalindrome(s2) ? cout << "s2 YESSSS" : cout << "s2 NO";



	return 0;
};