#include "HandleIO.h"

int HandleIO::validateFileVector(const string &s) {
    int pointFlag = 0;
    string str;
    for (char i: s) {
        // only if the minus is the first char - it's ok
        if (i == MINUS and str.empty()) {
            str += i;
        } else if (i == POINT) {
            pointFlag += ON;
            if (pointFlag >= (2 * ON)) {
                return -1;
            }
            str += i;
        } else if (isdigit(i)) {
            str += i;
            pointFlag = OFF;
        } else if (i != '\n') {
            return -1;
        }
    }
    if (!checkSneakyCases(str)) {
        return -1;
    }
    normalizeDoubleSize(str);
    // return a guaranteed double
    return 0;
}

bool HandleIO::validateUserVector(vector<double> &vector, const string &sNumber) {
    int pointFlag = 0;
    string str;
    for (char i: sNumber) {
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

pair<string, vector<double>> HandleIO::pairExtract(string &line, unsigned long length) {
    string number;
    if (line.empty()) {
        printBye(2);
    }
    pair<string, vector<double>> returnPair;
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


int HandleIO::extractAlgorithm(string &input) {
    unsigned long inputSize = input.size();
    // we need to have 3 letters and a space + k which at least 1
    if (inputSize != ALG_SIZE) {
        return -2;
    }
    if (!checkAlgo(input)) {
        return -2;
    }
    // why +2? we want to skip the space straight to the k
    return 0;
}

int HandleIO::extractApproximation(string &input) {
    int rv;
    try {
        rv = stoi(input);
    } catch (exception &e) {
        return -1;
    }
    if (rv <= 0) {
        return -1;
    }
    return 0;
}

int HandleIO::checkFile(string vecFile, int indicator) {
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
    if (indicator > 0) {
        if (file.peek() == EOF) return -1;
    } else {
        if (file.peek() != EOF) return -1;
    }
    return 0;
}

void HandleIO::printBye(int i) {
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

int HandleIO::lengthExtract(const string &firstLine) {
    if (firstLine.empty()) {
        return -1;
    }
    int length = 0;
    // split the line into individual columns
    for (char i: firstLine) {
        if (i == COMMA) {
            length++;
        }
    }
    if ((length) <= 0) {
        return -1;
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

bool HandleIO::checkSneakyCases(string &number) {
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

void HandleIO::normalizeDoubleSize(string &number) {
    // why the casting? we do an operator between long and double
    if ((double) number.size() >= log(DBL_MAX) - 1) {
        number = number.substr(0, sizeof(double_t));
    }
}

void HandleIO::checkClientArguments(int argc, char *argv[]) {
    if (argc != NUM_OF_ARGS + 1) {
        printBye(4);
    }
    checkIP(SERVER_IP);
    checkPort(PORT);
}

void HandleIO::checkServerArguments(int argc, char *argv[]) {
    if (argc != NUM_OF_ARGS) {
        printBye(4);
    }
    checkPort(PORT);
}

void HandleIO::checkIP(const string &ip) {
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

void HandleIO::checkPort(const string &port) {
    // define 65535
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

int HandleIO::CheckAlgoK(string &str) {
    string kString;
    string algString;
    int kFlag;
    int algFlag;
    int rv = INVALID_PARAMETERS;
    int i = 0;
    for (; i < str.length(); i++) {
        if (str[i] == SPACE) {
            break;
        }
        kString += str[i];
    }
    rv = i;
    i++;
    for (; i < str.length(); i++) {
        if (str[i] == SPACE) {
            break;
        }
        algString += str[i];
    }
    if (rv == str.length()) {
        algString = kString;
        return extractApproximation(kString) + extractAlgorithm(algString);
    }
    kFlag = max(extractApproximation(kString), extractApproximation(algString));
    algFlag = max(extractAlgorithm(algString), extractAlgorithm(kString));
    if (kFlag < 0 || algFlag < 0) {
        return kFlag + algFlag;
    }
    return rv - 1;
}

vector<vector<double>> HandleIO::createTestVectors(const string &basicString) {
    istringstream ss(basicString);
    vector<vector<double>> rv;
    for (string line; getline(ss, line);) {
        rv.push_back(vectorFromString(line));
    }
    return rv;
}

vector<double> HandleIO::vectorFromString(const string &vecString) {
    vector<double> vec;
    string temp;
    for (char c: vecString) {
        if (c == COMMA) {
            vec.push_back(stod(temp));
            temp.clear();
            continue;
        }
        temp += c;
    }
    temp = temp.substr(0, temp.size());
    vec.push_back(stod(temp));
    return vec;

}

SpecialVector HandleIO::createTrainDB(const string &basicString) {
    SpecialVector rv;
    istringstream ss(basicString);
    for (string line; getline(ss, line);) {
        rv.getProperties().push_back(pairFromString(line));
    }
    return rv;
}

pair<string, vector<double>> HandleIO::pairFromString(const string &vecString) {
    vector<double> vec;
    pair<string, vector<double>> rv;
    string temp;
    for (char c: vecString) {
        if (c == COMMA) {
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

void HandleIO::sendProtocol(int socket, string sendData) {
    sendData += "\n\r";
    string segment;
    const char *data;
    while (sendData.size() > BUFFER_SIZE) {
        segment = sendData.substr(0, BUFFER_SIZE);
        data = convertStringToArray(segment);
        long sent_bytes = send(socket, data, strlen(data), 0);
        if (sent_bytes < 0) {
            perror("Fail sending to server");
        }
        sendData = sendData.substr(BUFFER_SIZE, sendData.length() - 1);
    }
    data = convertStringToArray(sendData);
    long sentBytes = send(socket, data, strlen(data), 0);
    if (sentBytes < 0) {
        perror("Fail sending to client");
    }
}

bool HandleIO::receiveProtocol(int socket, string &receiveData) {
    int flag = 0;
    char buffer[BUFFER_SIZE] = {};
    for (char & i : buffer) {
        i = '\0';
    }
    receiveData.clear();
    long readBytes = recv(socket, buffer, sizeof(buffer), 0);
    while (readBytes == BUFFER_SIZE && buffer[BUFFER_SIZE - 1] != '\r') {
        flag = 1;
        receiveData += buffer;
        for (char & i : buffer) {
            i = '\0';
        }
        readBytes = recv(socket, buffer, sizeof(buffer), 0);
        if (readBytes < 0) {
            perror("Fail reading data");
            close(socket);
            return false;
        }
    }
    receiveData += buffer;
    receiveData.erase(receiveData.find_last_not_of(LETTERS_AND_NUMBERS) + 1);
    if (flag == 1) {
        removeLastLine(receiveData);
    }
    return true;
}

int HandleIO::checkDemand(bool (&array)[5], string toCheck, int socket, const string& menu) {
    if (toCheck.empty() or toCheck.size() > 1) {
        sendProtocol(socket, "invalid input");
        return OFF;
    }
    char condition = toCheck[0];
    switch (condition) {
        case '1':
            array[COMMAND_1] = true;
            return ON;
        case '2':
            return ON;
        case '3':
            if (!array[COMMAND_1]) {
                sendProtocol(socket, "please upload data\n" + menu);
                return OFF;
            }
            array[COMMAND_3] = true;
            return ON;
        case '4':
            if (!array[COMMAND_1]) {
                sendProtocol(socket, "please upload data\n" + menu);
                return OFF;
            }
            if (!array[COMMAND_3]) {
                sendProtocol(socket, "please classify the data\n" + menu);
                return OFF;
            }
            array[COMMAND_4] = true;
            return ON;
        case '5':
            if (!array[COMMAND_1]) {
                sendProtocol(socket, "please upload data\n" + menu);
                return OFF;
            }
            if (!array[COMMAND_3]) {
                sendProtocol(socket, "please classify the data\n" + menu);
                return OFF;
            }
            array[COMMAND_5] = true;
            return ON;
        case '8':
            return -1;
        default:
            sendProtocol(socket, "invalid input\n" + menu);
            return 0;
    }
}

int HandleIO::extractChoice(const string &choice) {
    try {
        return stoi(choice);
    } catch (exception &e) {
        return -1;
    }
}

int HandleIO::checkDBLine(const string &line, int length, int file) {
    int counter = 0;
    if (line.empty()) {
        return -1;
    }
    string temp;
    for (char c: line) {
        if (c == COMMA) {
            counter++;
            if (validateFileVector(temp) == -1){
                return -1;
            }
            temp.clear();
            continue;
        }
        temp += c;
    }
    if (file == 1) {
        if (temp.empty()) {
            return -1;
        }
    } else {
        temp = temp.substr(0, temp.size() - 1);
        if (validateFileVector(temp) == -1){
            return -1;
        }
        counter++;
    }
    if (counter != length){
        return -1;
    }
    return 1;
}

void HandleIO::removeLastLine(string & data) {
    size_t secondLastNewlinePos = data.rfind('\n', data.rfind('\n') - 1);
    if (secondLastNewlinePos != std::string::npos) {
        data.erase(secondLastNewlinePos);
    }
}


