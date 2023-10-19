#pragma once
#include <iostream>
#include<fstream>
#include <string>
#include <map>
#include "helper.h";

using namespace std;

//polymorphism

class MenuParent {
public: 
	MenuParent() { menuText = "base text for parent object. If you see this the text has not been init"; }
	virtual ~MenuParent() { }
	virtual void getQuestion() { std::cout << menuText << endl; };
	virtual void PrintText() {
		cout<<menuText<<endl;
	}
	virtual void writeSoln(std::map<int, string>& source) { cout << "there has been some error please check code"; }
	virtual void printsoln(map<int, string>& source) { "error with the print soln function of parent class"; }
	std::string menuText;
};



class BaseQuestion : public MenuParent {
public:
	BaseQuestion() {
		menuText = "Welcome To the beal conjecture :p";
	}
	void getQuestion() {
		std::cout << menuText << "Select your question, or press 9 to quit" << endl;
	}
	
};



class QuestionOne : public MenuParent {
public:
	QuestionOne() {
		menuText = "Question 1: Write a C++ program to find the first five distinct, lowest BNTs. \n";

	}
	void writeSoln(map<int, string>& source) {
		int i = 0;
		ofstream sol1("SolutionOne.txt");
		for (auto x : source){
			if (i < 5){
				sol1 << x.first << x.second << endl;
				i++;
			}
		}
		
		sol1.close();
	}
	void printsoln(map<int, string>& source) {
		int i = 0;
		for (auto x : source) {
			if (i > 4)
			{break;}
			i++;		  
			cout << x.first<< x.second<<endl;
		}
	}


};


class QuestionTwo : public MenuParent {
public:
	QuestionTwo() {
		menuText = "Write a C++ program to find the first five distinct, lowest BNTs that are prime numbers. \n";
	}

	void printsoln(map<int, string>& source) {
	
		int i = 0;
		for (auto x : source) {
			if (i > 4)
			{
				break;
			}
			i++;
			cout << x.first << x.second << endl;
		}

	}

	void writeSoln(map<int, string>& source) {
		int i = 0;
		ofstream sol1("SolutionTwo.txt");
		for (auto x : source) {
			if (i < 5) {
				sol1 << x.first << x.second << endl;
				i++;
			}
		}

		sol1.close();
	}
};

class QuestionThree : public MenuParent {
public:
	QuestionThree() {
		menuText = "Question 3";
	}

	void printsoln(map<int, string>& source) {
		for (auto x : source) {
			cout << x.first << x.second << endl;
		}

	}
};
class QuestionFour : public MenuParent {
public:
	QuestionFour() {
		menuText = "WIP to read files. The file is stored as Solution Four";
	}

	

};


class QuestionFive : public MenuParent {
public:
	QuestionFive() {
		menuText = "First 10 distinct BNTs that are composite numbers";
	}

	void printsoln(map<int, string>& source) {
		cout << endl;
		int i = 0;
		for (auto x : source) {
			if (i < 10) {
			cout << x.first << x.second <<endl;
			}
			i++;
		}
	}

	void writeSoln(map<int, string>& source) {
		int i =0;
		ofstream sol("SolutionFive.txt");
		for (auto x : source) {
			if (i < 10) {
				sol << x.first << x.second << endl;
				i++;
			}
		}

		sol.close();
	}

};

class QuestionSix:public MenuParent {
public:
	QuestionSix(){
		menuText = "BNT PEREFECT SQUARES \n";
	}

	void printsoln(map<int, string>& source) {
		for (auto x : source) {
			cout << x.first << x.second << endl;
		}
	}
};

class QuestionSeven : public MenuParent {
public:
	QuestionSeven() {
		menuText = "Histogram between given values \n";
	}
};

