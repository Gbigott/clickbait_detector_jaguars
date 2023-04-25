// ClickbaitDetector.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<sstream>
#include<set>
#include<map>


using namespace std;

void printVec(vector<string> row) {
    cout << "Titles:" << endl;
    for (int i = 0; i < row.size(); i++) {
        cout << row[i] << endl;
    }
}

int isClickbaitType(string s) { //Jordan, Amy
    int r = 0;

    // 1
    if (s.find("You won't believe") != std::string::npos) {
        return 1;
        r = 1;
    }

    //2
    if (s.find("This will make you") != std::string::npos) {
        r = 2;
    }

    //3
    if (s.find("This will shock you") != std::string::npos) {
        r = 3;
    }

    //4
    if (s.find("I couldn't believe") != std::string::npos) {
        r = 4;
    }

    //5
    if (s.find("Leading expert reveals the biggest secret") != std::string::npos) {
        r = 5;
    }

    //6
    if (s.find("Find out what happened after") != std::string::npos) {
        r = 6;
    }

    //7
    if (s.find("STORYTIME") != std::string::npos) {
        r = 7;
    }

    //8
    if (s.find("not clickbait") != std::string::npos) {
        r = 8;
    }

    return r;
}

bool isClickbait(string s) {
    if ((isClickbaitType(s)) < 1) {
        return false;
    } 

    return true;
}

set<string> implementSet(vector<string> row) { //Amy

   
    set<string> titles;
    for (int i = 0; i < row.size(); i++) {
        titles.insert(row.at(i));
    }

    cout << "implementSet ran" << endl;

    return titles;
}

int determineMatchSet(set<string> titlesSet, int titleType) {
    int count = 0;

    set<string>::iterator it;

    int temp = 0;

    for (it = titlesSet.begin(); it != titlesSet.end(); it++) {
        temp = isClickbaitType(*it);
        if (temp == titleType) {
            count++;
        }
    }

    return count;
}

map<string, int> implementMap(vector<string> row) { //Gus, Amy
    
    map<string, int> cBaitClassify;
    int type_cbait = 0;

    for (int i = 0; i < row.size(); i++)
    {
        type_cbait = isClickbaitType(row.at(i));
        cBaitClassify.insert({ row.at(i),type_cbait });
    }

    cout << "implementMap ran" << endl;


    return cBaitClassify;
}

int determineMatchMap(map<string, int> titlesMap, int clickbaitType) {
    int count = 0;

    for (auto it : titlesMap) {
        if (it.second == clickbaitType) {
            count++;
        }
    }

    return count;
}

int main(){
    //read in file



    ifstream infile;
    vector<string> row;

    infile.open("examiner-date-text.csv");

   if (!(infile.is_open())) {
        cout << "no file found" << endl;
   } else {
       string s, temp;
       

       cout << "Reading in titles..." << endl;


       while (getline(infile, s)) {
        //   cout << s << endl;

           temp = s.substr(10);
           row.push_back(temp);
       }

       infile.close();

     //  printVec(row); // print the list of titles
    }

   //begin taking user input

   
   
   cout << "Enter a title you suspect may be clickbait..." << endl;
   //read in title and store it

   string title;


  // cin >> title;

   getline(cin, title);

   cout << "Your title is \"" << title << "\"" << endl;
   //check ifClickbait

   int titleType = isClickbaitType(title);
   if (titleType == 0) {
       cout << "Congratulations! Your title was not detected to be clickbait!" << endl;
       return 0;
   }
   else {
       cout << "Oh no! Your title was suspected to be clickbait! Let's check it against other titles!" << endl;
   }


   cout << "Would you like to check via Set or Map? \nSelect 1 for Set and 2 for Map" << endl;
   int sOrM;
   cin >> sOrM;
   if (sOrM == 1) {
       cout << "\nImplementing Set" << endl;
       //implement Set

       
       set<string> titlesS = implementSet(row);
       int count = determineMatchSet(titlesS, titleType);

       cout << "Your entry matched " << count << " other entries in our database!" << endl;

       //output effiency
   } else if (sOrM == 2) {
       cout << "\nImplementing Map" << endl;
       //implement Map

       map<string, int> titlesM = implementMap(row);

       int count = determineMatchMap(titlesM, titleType);
       cout << "Your entry matched " << count << " other entries in our database!" << endl;

   } else {
       cout << "unknown command" << endl;
   }

   //run isClickbait

    return 0;
}