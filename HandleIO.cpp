#include "HandleIO.h"

double HandleIO::validateFileVector(const string &s) const {
    int pointFlag = 0;
    string str;
    for (char i: s) {
        // only if the minus is the first char - it's ok
        if (i == MINUS and str.empty()) {
            str += i;
        } else if (i == POINT) {
            pointFlag += ON;
            if (pointFlag >= (2 * ON)) {
                printBye(4);
            }
            str += i;
        } else if (isdigit(i)) {
            str += i;
            pointFlag = OFF;
        } else if (i != '\n') {
            printBye(4);
        }
    }
    if (!checkSneakyCases(str)) {
        printBye(4);
    }
    normalizeDoubleSize(str);
    // return a guaranteed double
    return stod(str);
}

bool HandleIO::validateUserVector(vector<double> &vector, const string &s_number) const {
    int pointFlag = 0;
    string str;
    for (char i: s_number) {
        // only if the minus is the first char - it's ok
        if (i == MINUS and str.empty()) {
            str += i;
        } else if (i == POINT) {
            pointFlag += ON;
            if (pointFlag >= (2 * ON)) {
                return false;
            }
            str += i;
        } else if (isdigit(i)) {
            str += i;
            pointFlag = OFF;
        } else if (i != '\n') {
            return false;
        }
    }
    if (!checkSneakyCases(str)) {
        return false;
    }
    normalizeDoubleSize(str);
    vector.push_back(stod(str));
    return true;
}

pair <string, vector<double>> HandleIO::pairExtract(string &line, int length) const {
    string number;
    if (line.empty()) {
        printBye(2);
    }
    pair <string, vector<double>> returnPair;
    for (char i: line) {
        if (i == COMMA) {
            returnPair.second.push_back(validateFileVector(number));
            number.clear();
            continue;
        }
        number += i;
    }
    if (returnPair.second.size() != length) {
        printBye(2);
    }
    returnPair.first = number;
    return returnPair;
}

int HandleIO::dataExtract(string &data, vector<double> &pVector, int length, string &algorithm, int &approximation)
const {
    extractVector(pVector, length, data);
    algorithm = extractAlgorithm(data);
    approximation = extractApproximation(data);
    if (approximation == 0) {
        return -1;
    }
    return 1;
}

void HandleIO::extractVector(vector<double> &pVector, int length, string &input) const {
    string s_number;
    bool flag;
    unsigned long inputSize = input.size();
    unsigned long i;
    for (i = 0; i < inputSize; i++) {
        if (input[i] != SPACE && input[i] != MINUS && input[i] != POINT && !isdigit(input[i])) {
            break;
        }
        if (input[i] == SPACE) {
            flag = validateUserVector(pVector, s_number);
            if (!flag) {
                input.clear();
                return;
            }
            s_number.clear();
            continue;
        }
        s_number += input[i];
    }
    if (input[i - 1] != SPACE) {
        input.clear();
        return;
    }
    if (pVector.size() != ((unsigned long) length)) {
        input.clear();
        return;
    }
    input = input.substr(i, inputSize);
}

string HandleIO::extractAlgorithm(string &input) {
    unsigned long inputSize = input.size();
    // we need to have 3 letters and a space + k which at least 1
    if (inputSize < MIN_ALG_K_SIZE) {
        input.clear();
        return "invalid";
    }
    string algorithm = input.substr(0, ALG_SIZE);
    if (!checkAlgo(algorithm)) {
        input.clear();
        return "invalid";
    }
    if (input[ALG_SIZE] != SPACE) {
        input.clear();
        return "invalid";
    }
    // why +2? we want to skip the space straight to the k
    input = input.substr(ALG_SIZE + 1, inputSize);
    return algorithm;
}

int HandleIO::extractApproximation(string &input) {
    if (input.empty() || input[0] == '\n') {
        return 0;
    }
    string k;
    for (char i: input) {
        if (i == '\n') {
            break;
        }
        if (!isdigit(i)) {
            return 0;
        }
        k += i;
    }
    return stoi(k);
}

int HandleIO::checkFile(string vecFile) {
    string isCsv;
    unsigned long pointPlace = 0;
    int index = 0;
    ifstream file(vecFile);
    if (!file.is_open()) {
        return -1;
    }
    // check if it's a csv file
    for (char i: vecFile) {
        if (i == POINT) {
            pointPlace = index;
        }
        index++;
    }
    pointPlace++;
    while (pointPlace < vecFile.size()) {
        isCsv += vecFile[pointPlace];
        pointPlace++;
    }
    if (isCsv != CSV) {
        return -1;
    }
    // check if the file is empty
    if (file.peek() == EOF) {
        return -1;
    }
    return 0;
}

void HandleIO::printBye(int i) const {
    switch (i) {
        case 1:
            cout << "Invalid K\n";
            break;
        case 2:
            cout << "Invalid file or path to file\n";
            break;
        case 3:
            cout << "Invalid algorithm\n";
            break;
        case 4:
            cout << "Invalid input\n";
            break;
        default:
            break;
    }
    cout << "Please restart the program, and try again!\n";
    exit(0);
}

int HandleIO::lengthExtract(const string &firstLine) const {
    if (firstLine.empty()) {
        printBye(4);
    }
    int length = 0;
    // split the line into individual columns
    for (char i: firstLine) {
        if (i == COMMA) {
            length++;
        }
    }
    if ((length) <= 0) {
        printBye(4);
    }
    return length;
}

bool HandleIO::checkAlgo(const string &algorithm) {
    for (string s: ALGO_ARRAY) {
        if (algorithm == s) {
            return true;
        }
    }
    return false;
}

bool HandleIO::checkSneakyCases(string &number) const {
    int pointFlag = 0;
    if (number.empty() or number == STR_POINT or number == STR_MINUS) {
        return false;
    }
    for (char i: number) {
        if (i == POINT) {
            pointFlag++;
        }
    }
    if (pointFlag > 1) {
        return false;
    }
    return true;
}

void HandleIO::normalizeDoubleSize(string &number) const {
    // why the casting? we do an operator between long and double
    if ((double) number.size() >= log(DBL_MAX) - 1) {
        number = number.substr(0, sizeof(double_t));
    }
}

void HandleIO::checkClientArguments(int argc, char *argv[]) const {
    if (argc != NUM_OF_ARGS) {
        printBye(4);
    }
    checkIP(SERVER_IP);
    checkPort(CLIENT_PORT);
}

void HandleIO::checkServerArguments(int argc, char *argv[]) const {
    if (argc != NUM_OF_ARGS) {
        printBye(4);
    }
    checkFile(FILE_NAME);
    checkPort(CLIENT_PORT);
}

void HandleIO::checkIP(const string &ip) const {
    //if its start with .
    int pointsCounter = 0;
    string tempIP;
    for (char i: ip) {
        if (i == POINT) {
            pointsCounter++;
            if (stoi(tempIP) > IP_RANGE) {
                printBye(4);
            }
            tempIP.clear();
            continue;
        }
        if (!isdigit(i)) {
            printBye(4);
        }
        tempIP += i;
    }
    if (stoi(tempIP) > IP_RANGE || pointsCounter != 3) {
        printBye(4);
    }
}

void HandleIO::checkPort(const string &port) const {
    //define 65535
    int portNum = 0;
    try {
        portNum = stoi(port);
    } catch (exception &exception) {
        printBye(4);
    }
    if (portNum < 0 || portNum > 65535) {
        printBye(4);
    }
}

char *HandleIO::convertStringToArray(const string &input) {
    return strcpy(new char[input.size() + 1], input.c_str());
}

int HandleIO::CheckAlgoK(string &str){
    int rv = INVALID_PARAMETERS;
    int i = 0;
    if (str.empty()) {
        return rv;
    }
    string tmp;
    for (; i < str.length(); i++) {
        if (str[i] == SPACE) {
            break;
        }
        tmp += str[i];
    }
    int k = extractApproximation(tmp);
    if (k != 0) {
        rv++;
    }

    i++;
    str = str.substr(i, str.size());
    i -= 2;
    if (str.empty()) {
        return rv;
    }
    string alg = extractAlgorithm(str);
    if (alg == "invalid") {
        return rv;
    }
    return i;
}

vector<vector<double>> HandleIO::createTestVectors(const string& basicString) {
    vector<vector<double>> rv;
    string temp;
    int prev = 0;
    for (int i = 0; i < basicString.size(); i++) {
        if (basicString[i] == '\n') {
            temp = basicString.substr(prev, i - 1);
            rv.push_back(vectorFromString(temp));
            prev = i + 1;
        }
    }
    return rv;
}

vector<double> HandleIO::vectorFromString(const string& vecString) {
    vector<double> vec;
    string temp;
    for (char c : vecString) {
        if (c == SPACE) {
            vec.push_back(stod(temp));
            temp.clear();
            continue;
        }
        temp += c;
    }
    vec.push_back(stod(temp));
    return vec;

}

SpecialVector HandleIO::createTrainDB(const string& basicString) {
    SpecialVector rv;
    string temp;
    int prev = 0;
    for (int i = 0; i < basicString.size(); i++) {
        if (basicString[i] == '\n') {
            temp = basicString.substr(prev, i - 1);
            rv.getProperties().push_back(pairFromString(temp));
            prev = i + 1;
        }
    }
    return rv;
}

pair<string, vector<double>> HandleIO::pairFromString(const string& vecString) {
    vector<double> vec;
    pair<string, vector<double>> rv;
    string temp;
    for (char c : vecString) {
        if (c == SPACE) {
            vec.push_back(stod(temp));
            temp.clear();
            continue;
        }
        temp += c;
    }
    rv.first = temp;
    rv.second = vec;
    return rv;
}
