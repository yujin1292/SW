#include <iostream>
#include <string>
#include <vector>

#define ALPHABETS 27
using namespace std;

int K;
string input;
vector<char> p;
int number  = 0;

int char_to_index(char c) {
	return c - 'a';
}
class Trie {

public :
	char c;
	Trie * children[ALPHABETS];


	Trie() {
		c = ' ';
		for (int i = 0; i < ALPHABETS; i++) {
			children[i] = NULL;
		}

	}
	Trie(int cc) {
		c = cc;
		for (int i = 0; i < ALPHABETS; i++) {
			children[i] = NULL;
		}
	}
	void init(int cc) {
		c = cc;
		for (int i = 0; i < ALPHABETS; i++) {
			children[i] = NULL;
		}
	}
	void insert(char a , string s) {
	//	cout << "insert " << a << " , " << s << endl;
		
		if (a == '$') {
			Trie*t = (Trie*)malloc(sizeof(Trie));
			t->init(a);
			children[26] = t;
			return;
		}


		if (children[char_to_index(a)] == NULL) {
			Trie*t = (Trie*)malloc(sizeof(Trie));
			t->init(a);
			children[char_to_index(a)] = t;
			t->insert(s[1] , s.substr(1, s.size() - 1) );
		}
		else {
			children[char_to_index(a)]->insert(s[1], s.substr(1, s.size() - 1));
		}
	}
	
	void insert(string s) {
		
		for (int i = 0; i < s.size()-1; i++) {
			//cout << "insert "<< s[i] << ", " << s.substr(i, s.size() - i )<< "=============\n" << endl;
			this->insert(s[i] , s.substr( i ,s.size()-i) );

			// cout << endl;
		}
	}
	
	void print() {
		//printc();
		for (int i = 0; i < ALPHABETS; i++) {
			if (children[i] != NULL) {
				if (i == 26) {
					number++;

					if (number == K) {
						for (int j = 0; j < p.size(); j++)
							cout << p[j];
					}
				/*	for (int j = 0; j < p.size(); j++)
						cout << p[j] << " ";
					cout << endl*/;
				}
				else {
					p.push_back(i + 'a');
					children[i]->print();
					p.pop_back();
				}
			}
		}
	}
	void printc() {
		cout <<"\n" << c  << "--> ";
		for (int i = 0; i < ALPHABETS; i++) {
			if (children[i] != NULL)
				cout << char(i + 'A') << " ";
		}
		cout << endl;
	}
};

void find() {
	input.append("$");
	string result;

	Trie root;
	
	root.insert(input);
	root.print();
	if (K > number)
		cout << "none";

}

int main() {
	int testcase;
	cin >> testcase;
	for (int t = 0; t < testcase; t++) {
		cin >> K >> input;
		cout << "#" << t + 1 << " ";
		find();
		cout << endl;
		number = 0;
	}

	return 0;
}