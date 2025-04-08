#include <iostream>
#include <fstream>
#include <clocale>
#include <string>

using namespace std;
int main()
{
    setlocale(LC_ALL, "rus");

    string currentFileString;
    fstream inputFile("F1.txt", std::ios::in);
    fstream outputFile("F2.txt", std::ios::out);
    while (getline(inputFile, currentFileString)) {
        if (currentFileString.front() == 'А')
            outputFile << currentFileString <<endl;
    }
    inputFile.close();
    outputFile.close();

    cout << "Файл записан!" << endl;

    //system("pause");
    return 0;
}