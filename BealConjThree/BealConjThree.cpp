// BealConjThree.cpp : main file
//

using namespace std;
#include "Menu.h"
#include "bigNumber.h"
#include "helper.h"
#include <map>
#include <iostream>
#include <fstream>
#include <set>
#include <cmath>
#include <map>
#include <vector>
#include <iterator>
#include <numbers>
#include <math.h>
#include <numeric>
#include <thread>

std::map<int, string> testmap;
std::map<int, string> map2;
std::map<int, string> map3;
std::map<int, string> onekmap;


//std::map<int, int> histo; //BNT AND ITS FREQUENCY

int min_base = 2;
int max_base = 10;
int min_exp = 3;
int max_exp = 15;

bool singleHist = false;
bool threadsafe = false;
bool ques3 = false;

void insertIntoGram(int BNT) {
    histo[BNT]++;
}

//Templated function for converting it into beal
template <typename T> string toStringbeal(T a, T b, T c, T x, T y, T z){
    string val;
    val += ":" + to_string(a) + "," + to_string(x) + "," + to_string(b) + "," + to_string(y) + "," + to_string(c) + "," + to_string(z);
    return val;
}


void CheckBeal(int a, int b, int c) {

    ofstream f1("SolutionThree.txt", ios::app);

    for (int x = min_exp; x <= max_exp; x++) {
        for (int y = min_exp; y <= max_exp; y++) {
            for (int z = min_exp; z <= max_exp; z++) {
                if (x == y && x == z) {
                    continue;
                }
                if (checkBealReduced(a, b, c, x, y, z)) {
                    
                    //printf("%i ^ %i + %i ^ %i =%i ^ %i  BNT= %i\n ", a, x, b, y, c, z, (a + b + c + x + y + z));
                    //cout << BNT<< ;

                    int BNT = (a + b + c + x + y + z);
                    testmap[BNT] = toStringbeal(a, b, c, x, y, z);
                   
                    if (checkPrime(BNT)) {
                        map2[BNT] = toStringbeal(a, b, c, x, y, z);
                        
                    }
                    else {
                        map3[BNT] = toStringbeal(a, b, c, x, y, z);
                    }

                    if (ques3) {
                        printf("%i ^ %i + %i ^ %i =%i ^ %i  BNT= %i\n ", a, x, b, y, c, z, (BNT));
                        //writefileq3(BNT, toStringbeal(a, b, c, x, y, z));
                        string val = to_string(BNT);                        
                        f1 << val + toStringbeal(a, b, c, x, y, z) << endl;
                    }

                    //CODE FOR HISTOGRAM
                    //THIS IS RUNNING 4 TIMES IF YOU CALL IT BEFORE SO WE CAN RESET IT IF YOU WANT
                    //WHAT THE FUCK SHOULD I DO NOW MAN 
                    if (singleHist) {
                        insertIntoGram(BNT);
                    }
                    
                }
    
            }
        }
    }
    f1.close();
}

void iteratebases() {
    for (int A = min_base; A <= max_base; A++) {
        for (int B = min_base; B <= max_base; B++) {
            for (int C = min_base; C <= max_base; C++) {
                CheckBeal(A, B, C);
            }
        }
    }
}


void printsoln() {
   for (auto i : histo) {
       cout << "key"<<i.first<<  "value" << i.second<< endl;
   }
}

void q1()
{
    min_base = 2;
    max_base = 4;
    min_exp = 3;
    max_exp = 10;

    iteratebases();
}

void q2() {
    max_base = 10;
    iteratebases();
}

void q3() {
    min_base = 3;
    max_base = 20;
    min_exp = 3;
    max_exp = 15;
    testmap.clear();
    ques3 =true;
    iteratebases();
}

void q4() {
    string st = "SolutionFour.txt";
    string op = fileread(st) ? "The file satisfies beal conjecture" : "The file doesnt satisfy Beal conjecture";
    cout<< op <<endl;
}

void q5() {
    min_base = 2;
    max_base = 10;
    min_exp = 3;
    max_exp = 15;
    iteratebases();
}

void q6() {
    vector<int> psqaure;
    for (int i = 1000; i <= 100000; i++) {
        if (isperfectSquare(i)){
            //cout << i << endl;
            psqaure.push_back(i);
        }
    }


    for (auto x : psqaure) {
        int pow = (x - 7) / 3;

        if (pow * 3 + 7 == x) {
            //soemthing
            //cout << x << endl;
            onekmap[x] = toStringbeal(2, 2, 2, pow - 1, pow - 1, pow);
            continue;
        }

        pow = (x - 18) / 9;
        if (pow * 9 + 18 == x) {
            //cout << x << endl;
            onekmap[x] = toStringbeal(2, 2, 16, pow * 4 - 1, pow * 4 - 1, pow);
           
            continue;
        }
    }
    
}



void q7() {
    //set the values of cringe stuff
    min_base = 2;
    max_base = 20;
    min_exp = 3;
    max_exp = 40;

    if (histo.size() == 0) {
        histo.clear();
        singleHist = true;
        iteratebases();
    }

}

//object orientation
void menuSwitcher()
{
    singleHist = false;
    ques3 = false;
    MenuParent* currentMenu = new BaseQuestion;
    currentMenu->getQuestion();
    /*string str = currentMenu + currentMenu;*/
    //cout << str;

    int input = 0;
    cin >> input;
    switch (input)
    {
    case 1:
    {
        currentMenu = new QuestionOne;
        currentMenu->getQuestion();
        
        q1();
        currentMenu->writeSoln(testmap);
        currentMenu->printsoln(testmap);
        menuSwitcher();
        break;
    }

    

    case 2:
        
        currentMenu = new QuestionTwo;
        currentMenu->getQuestion();
        q2();
        currentMenu->printsoln(map2);
        currentMenu->writeSoln(map2);
        menuSwitcher();
        break;
    case 3:
        currentMenu = new QuestionThree;
        currentMenu->getQuestion();
        q3();
        menuSwitcher();
        break;

    case 4: 
        currentMenu = new QuestionFour;
        currentMenu->getQuestion();
        q4();
        menuSwitcher();
        break;

    case 5:
        currentMenu = new QuestionFive;
        currentMenu->getQuestion();
        q5();
        //printsoln();
        currentMenu->printsoln(map3);
        currentMenu->writeSoln(map3);
        menuSwitcher();
        break;


    case 6:
        currentMenu = new QuestionSix;
        currentMenu->getQuestion();
        q6();
        currentMenu->printsoln(onekmap);
        cout<<"total count of BNTs: " << onekmap.size() <<"\n";
        menuSwitcher();
        break;

    case 7:
        currentMenu = new QuestionSeven;
        createHist();
        menuSwitcher();
        break;

    case 8:
        //checkBigBoy();
        menuSwitcher();
        break;
   
    case 9:
        cleanFiles();
        exit(1);
        break;

    default:
        cout << "Please pick a number that is correct!";
        break;
    }
}

int main()
{
    //thread p(pophistogram);
    menuSwitcher();
    //q6();
    
}