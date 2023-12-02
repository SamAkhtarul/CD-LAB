//
//  main.cpp
//  lab42
//
//  Created by SAM on 1/12/23.
//
#include <iostream>
#include <fstream>
#include <string>
#include <set>

using namespace std;

int main() {
    ifstream inputFile("sam.cpp");

    if (!inputFile.is_open()) {
        cout << "STOP!!!!Error opening the file!" << endl;
        return 1;
    }

    set<string> uniqueFunctionNames;

    string line;
    while (getline(inputFile, line)) {
        size_t pos = line.find('('); // Look for function declaration
        if (pos != string::npos) {
            size_t spacePos = line.rfind(' ', pos);
            if (spacePos != string::npos) {
                string functionName = line.substr(spacePos + 1, pos - spacePos - 1); //  function name
                if (functionName != "main") { // Check if the function name is not "main"
                    uniqueFunctionNames.insert(functionName); // Insert the function name into the set
                }
            }
        }
    }

    cout << "Unique User-Defined Function Names:" << endl;
    for (const auto& functionName : uniqueFunctionNames) {
        cout << functionName << endl;
    }

    int totalFunctions = uniqueFunctionNames.size(); // Get the total number of unique function names

    cout << "Total number of  user-defined functions : " << totalFunctions << endl;

    inputFile.close();
    return 0;
}
