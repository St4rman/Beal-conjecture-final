#pragma once
#include <numeric>
#include <map>
#include <fstream> 
#include <sstream>
#include <vector>
using namespace std;
std::map<int, int> histo;



//For general prime checking 
bool checkPrime(int x) {
    if (x == 0 || x == 1) {
        return false;
    }
    for (int i = 2; i <= x / 2; i++) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

//Reduced Beal checker
bool checkBealReduced(unsigned long long int a, unsigned long long int b, unsigned long long int c, unsigned long long int x, unsigned long long int y, unsigned long long int z){
    //smallest common power
    int scp = min(min(x, y), z);
    int comdiv = gcd(gcd(a, b),c);

    if (comdiv == 1) {
        return false;
    }

    unsigned long long int left = static_cast<unsigned long long int>(std::pow((a / comdiv), x)) * static_cast<unsigned long long int>(std::pow((comdiv), x - scp)) +
        static_cast<unsigned long long int>(std::pow((b / comdiv), y)) * static_cast<unsigned long long int>(std::pow((comdiv), y - scp));
    unsigned long long int right = std::pow((c / comdiv), z) * std::pow((comdiv), z - scp);

    return left == right;
}

void createHist(){//(std::map<int, int> source) {
    int min, max;
    cout << "Enter the range of BNTs you'd like. From 0-100\n";
    cout << "Minimum: ";
    cin >> min;
    cout << "\n Maximum: ";
    cin >> max;
    cout << "  |"<<endl;
    for (auto x : histo) {
        if ((x.first) > min && (x.first) < max) {
        cout << x.first << "|";
        int i = 0;
        for (i = 0; i < x.second; i++) { cout << "O"; }
        cout << "   " << i;
        cout << endl;
        }
        continue;
    }
    cout << "  |" << endl;
}


void cleanFiles() {
    remove("SolutionOne.txt");
    remove("SolutionTwo.txt");
    remove("SolutionThree.txt");
    remove("SolutionFour.txt");
}
    
//Question 4 file read
bool fileread(string filename) {
    
    fstream nfile;
    nfile.open(filename);

    if (nfile.is_open()) {

        
        string temp;

        while (getline(nfile, temp)) {

            vector <int> vect;
            //temp is our current line
            int pos = temp.find("\:");
            string BNTs = ( temp.substr(0, pos));
            int BNT = stoi(BNTs);
            
            string rest = temp.substr(pos+1);

            //cout << rest <<endl;

            
            stringstream ss(rest);
            for (int i; ss >> i;) {
                vect.push_back(i);
                if (ss.peek() == ',') {
                    ss.ignore();
                }  
            }


            if ((BNT != std::accumulate(vect.begin(), vect.end(), 0))) { return false; }

        }
    }
    nfile.close();
    return true;

}

bool isperfectSquare(int tar) {
    if (tar >= 0) {
        long long temp = sqrt(tar);

        return(temp * temp == tar);
    }
    return false;
}

void pophistogram() {
    for (int A = 3; A <= 20; A++) {
        for (int B = 3; B <= 20; B++) {
            for (int C = 2; C <= 20; C++) {
                for (int x = 3; x <= 20; x++) {
                    for (int y = 3; y <= 20; y++) {
                        for (int z = 3; z <= 20; z++) {
                            if (x == y && x == z) {
                                continue;
                            }
                            if (checkBealReduced(A, B, C, x, y, z)) {
                                int BNT = A + B + C + x + y + z;
                                histo[BNT]++;
                            }
                        }
                    }
                }
            }
        }
    }

    cout << "processing complete";
}