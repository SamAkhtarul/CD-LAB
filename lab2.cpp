//
//  main.cpp
//  lab week 3
//
//  Created by SAM on 1/10/23.
//

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream file("output.txt");
    if (!file) {
        cout << "Error opening file." << endl;
        return 1;
    }

    string searchWords[] = {"while", "main", "if", "cout", "else", "do", "while", "return", "cin", "iostream", "int"};
    string searchWords1[] = {"sum", "x", "y", "mul","sub"};
    string line;
    int maxKeywords = 100;
    int maxPunctuations = 100;
    int maxOperators = 100;
    int maxConstants = 100;  // Maximum number of constants expected
    int maxIdentifiers = 100;  // Maximum number of identifiers expected
    int maxComments = 100;  // Maximum number of comments expected
    string foundKeywords[maxKeywords];
    string foundIdentifiers[maxIdentifiers];
    char foundPunctuations[maxPunctuations];
    char foundOperators[maxOperators];
    string foundConstants[maxConstants];
    string foundComments[maxComments]; 
    int invalidIdentifierCount = 0;
    string invalidIdentifiers[100];

    while (getline(file, line)) {
        // Search for keywords
        for (int i = 0; i < sizeof(searchWords) / sizeof(searchWords[0]); i++) {
            size_t found = line.find(searchWords[i]);
            while (found != string::npos) {
                if (maxKeywords > 0) {
                    foundKeywords[maxKeywords - 1] = searchWords[i];
                    maxKeywords--;
                }
                found = line.find(searchWords[i], found + 1);
            }
        }

        // Search identifiers
        for (int i = 0; i < sizeof(searchWords1) / sizeof(searchWords1[0]); i++) {
            size_t found = line.find(searchWords1[i]);
            while (found != string::npos) {
                if (maxIdentifiers > 0) {
                    foundIdentifiers[maxIdentifiers - 1] = searchWords1[i];
                    maxIdentifiers--;
                }
                found = line.find(searchWords1[i], found + 1);
            }
        }

        // Search for punctuations
        for (int i = 0; i < line.size(); i++) {
            if (line[i] == '(' || line[i] == ')' || line[i] == '{' || line[i] == '}' || line[i] == ':' || line[i] == ';') {
                if (maxPunctuations > 0) {
                    foundPunctuations[maxPunctuations - 1] = line[i];
                    maxPunctuations--;
                }
            }
        }

        // Search for operators
        for (int i = 0; i < line.size(); i++) {
            if (line[i] == '+' || line[i] == '-' || line[i] == '/' || line[i] == '*' || line[i] == '%' || line[i] == '=') {
                if (maxOperators > 0) {
                    foundOperators[maxOperators - 1] = line[i];
                    maxOperators--;
                }
            }
        }

        // Check for invalid identifiers
        size_t found = line.find_first_not_of(" abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_");
        while (found != string::npos) {
            if (line[found] != '+' && line[found] != '-' && line[found] != '/' && line[found] != '*' && line[found] != '%' && line[found] != '='
                && line[found] != '(' && line[found] != ')' && line[found] != '{' && line[found] != '}' && line[found] != ':' && line[found] != ';') {
                invalidIdentifierCount++;
                invalidIdentifiers[invalidIdentifierCount - 1] = line.substr(found, 1);
            }
            found = line.find_first_not_of(" abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_", found + 1);
        }

        // Search for constants
        for (int i = 0; i < line.size(); i++) {
            if (isdigit(line[i]) || line[i] == '.') {
                size_t endPos;
                double constant = stod(line.substr(i), &endPos);
                if (maxConstants > 0) {
                    foundConstants[maxConstants - 1] = to_string(constant);
                    maxConstants--;
                }
                i += endPos - 1;  // Move the index to the end of the constant
            }
        }

        // Search for comments
        size_t singleLineCommentPos = line.find("//");
        if (singleLineCommentPos != string::npos) {
            if (maxComments > 0) {
                foundComments[maxComments - 1] = line.substr(singleLineCommentPos);
                maxComments--;
            }
            // Skip the rest of the line as it is part of a comment
            continue;
        }
    }

    // Output results (keywords, punctuations, operators, constants, identifiers, comments, and invalid identifiers)

    cout << "Found keywords:" << endl;
    for (int i = maxKeywords; i < 100; i++) {
        if (!foundKeywords[i].empty()) {
            cout << "Keyword: '" << foundKeywords[i] << "'" << endl;
        }
    }
    cout<<endl;
    cout << "Found Identifiers :" << endl;
    for (int i = maxIdentifiers; i < 100; i++) {
        if (!foundIdentifiers[i].empty()) {
            cout << "Identifiers: '" << foundIdentifiers[i] << "'" << endl;
        }
    }
    
    cout << "\nFound punctuations:" << endl;
    for (int i = maxPunctuations; i < 100; i++) {
        if (foundPunctuations[i] != '\0') {
            cout << "Punctuation: '" << foundPunctuations[i] << "'" << endl;
        }
    }

    cout << "\nFound operators:" << endl;
    for (int i = maxOperators; i < 100; i++) {
        if (foundOperators[i] != '\0') {
            cout << "Operator: '" << foundOperators[i] << "'" << endl;
        }
    }

    cout << "\nFound constants:" << endl;
    for (int i = maxConstants; i < 100; i++) {
        if (!foundConstants[i].empty()) {
            cout << "Constant: '" << foundConstants[i] << "'" << endl;
        }
    }

    cout << "\nFound comments:" << endl;
    for (int i = maxComments; i < 100; i++) {
        if (!foundComments[i].empty()) {
            cout << "Comment: '" << foundComments[i] << "'" << endl;
        }
    }

    cout << "\nFound invalid identifiers:" << endl;
    for (int i = 0; i < invalidIdentifierCount; i++) {
        cout << "Invalid Identifier: '" << invalidIdentifiers[i] << "'" << endl;
    }

    file.close();
    return 0;
}
