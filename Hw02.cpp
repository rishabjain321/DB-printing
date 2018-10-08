//Rishabh Jain
//HW2
//Due: Wednesday (9/26) at 11:59pm
//I took help from internet, TA, and friends in same class(Chris, Eric, Kyle).
#include <iostream>
#include <list>
#include <vector>
#include <string>

using namespace std;

//Write code for the following five functions
//In both DB1_print and DB2_print, you are required to use index function (i.e., []) for vector, rather than iterator

void DB1_print(vector<list<list<string>>> &DB1);
void DB1_to_DB2(vector<list<list<string>>> &DB1, list<vector<list<string> * > *> &DB2);
void DB2_print(list<vector<list<string> * > *> &DB2);
void DB2_to_DB3(list<vector<list<string> * > *> &DB2, list < list<list<string *> * > > &DB3);
void DB3_print(list < list<list<string *> * > > &DB3);

int main() {
	vector<list<list<string>>> DB1 = {
		{ { "cat", "dog" },{ "duck", "chicken","pig" } },
	{ { "lion", "tiger", "hyena", "leopard" },{ "Zebra", "elephant" },{ "buffalo" } }
	};
	DB1_print(DB1);
	list<vector<list<string> * > *> DB2;
	DB1_to_DB2(DB1, DB2);
	DB2_print(DB2);
	list < list<list<string *> * > > DB3;
	DB2_to_DB3(DB2, DB3);
	DB3_print(DB3);
	getchar();
	getchar();
	return 0;
}
void DB1_print(vector<list<list<string>>> &DB1) {
	cout << endl;
	for (size_t i = 0; i < DB1.size(); i++) {
		auto ind1 = DB1[i].begin();
		while (ind1 != DB1[i].end()) 
		{
			auto ind2 = ind1->begin();
			while (ind2 != ind1->end())
			{
				cout << *ind2 << " ";
				ind2++;
			}
			ind1++;
			cout << endl;
		}
		cout << endl;
	}

}

void DB1_to_DB2(vector<list<list<string>>> &DB1, list<vector<list<string> * > *> &DB2) {
	for (size_t i = 0; i < DB1.size(); i++)
	{
		auto ind1 = DB1[i].begin();
		vector<list<string>*> *vec1 = new vector<list<string>*>;
		while (ind1 != DB1[i].end())
		{
			auto ind2 = ind1->begin();
			list<string> *list2 = new list<string>;
			while (ind2 != ind1->end())
			{
				list2->push_back(*ind2);
				ind2++;
			}
			vec1->push_back(list2);
			ind1++;
		}
		DB2.push_back(vec1);
	}

}

void DB2_print(list<vector<list<string> * > *> &DB2)
{
	cout << endl;
	auto ind1 = DB2.begin();
	while (ind1 != DB2.end())
	{
		for (size_t i = 0; i < (*ind1)->size(); i++)
		{
			auto ind2 = (**ind1)[i]->begin();
			while (ind2 != (**ind1)[i]->end()) {
				cout << *ind2 << " ";
				ind2++;
			}
			cout << endl;
		}
		cout << endl;
		ind1++;
	}

}

void DB2_to_DB3(list<vector<list<string> * > *> &DB2, list < list<list<string *> * > > &DB3) {
	auto ind1 = DB2.begin();
	while (ind1 != DB2.end())
	{
		list<list<string*>*> list1;
		for (size_t i = 0; i < (*ind1)->size(); i++)
		{
			auto ind2 = (**ind1)[i]->begin();
			list<string*> * list2 = new list<string*>;
			while (ind2 != (**ind1)[i]->end())
			{
				string * p = new string(*ind2);
				list2->push_back(p);
				ind2++;
			}
			list1.push_back(list2);
		}
		DB3.push_back(list1);
		ind1++;
	}

}
void DB3_print(list < list<list<string *> * > > &DB3)
{
	cout << endl;
	auto ind1 = DB3.begin();
	while (ind1 != DB3.end())
	{
		auto ind2 = ind1->begin();
		while (ind2 != ind1->end())
		{
			auto ind3 = (*ind2)->begin();
			while (ind3 != (*ind2)->end())
			{
				cout << **ind3 << " ";
				ind3++;
			}
			cout << endl;
			ind2++;
		}
		cout << endl;
		ind1++;
	}

}

//The following is a sample screenshot
//Your output needs to folloiwng idential format
/*

cat dog
duck chicken pig

lion tiger hyena leopard
Zebra elephant
buffalo


cat dog
duck chicken pig

lion tiger hyena leopard
Zebra elephant
buffalo


cat dog
duck chicken pig

lion tiger hyena leopard
Zebra elephant
buffalo
*/