#ifndef CLASSIFIERVECTORS_HANDLEIO_H
#define CLASSIFIERVECTORS_HANDLEIO_H

#include <vector>
#include <sstream>
#include <iostream>
#include <cfloat>
#include <cmath>
#include <cstring>
#include <fstream>
#include "Algorithms/EuclideanDistance.h"
#include "Sprites/AlgoMap.h"
#include "Sprites/SpecialVector.h"

// special characters
#define MINUS '-'
#define STR_MINUS "-"
#define POINT '.'
#define STR_POINT "."
#define COMMA ','
#define SPACE ' '
#define CSV "csv"

// flags logic
#define ON 1
#define OFF 0
#define ALGO_ARRAY {"AUC", "MAN", "CHB", "CAN", "MIN"}
#define INVALID_ALGORITHM (-1)
#define INVALID_APPROXIMATION (-2)
#define INVALID_PARAMETERS (-3)

// define for all the arguments from the user
#define FILE_NAME argv[1]
#define NUM_OF_ARGS 3
#define IP_RANGE 255
#define MIN_ALG_K_SIZE 5
#define ALG_SIZE 3

// sockets logics
#define SERVER_IP argv[1]
#define CLIENT_PORT argv[2]

using namespace std;

/**
 * a class which manages all the inputs & outputs of the project.
 */
class HandleIO {
public:

    /**
     * the function gets a line as a string and extract a matching pair.
     * @param line (string)
     * @param length (int)
     * @return pair<string,vector<double>> - a pair of the vector and it's name.
     */
    pair<string, vector<double>> pairExtract(string &line, int length) const;

    /**
     * the function checks if the file we got is valid.
     * we check the following cases:
     * 1. we can open the file.
     * 2. it's a csv file.
     * 3. it's not an empty file.
     * @param file (string)
     */
    static int checkFile(string file);

    /**
     * the function checks the length of the vectors in the file by the first line.
     * @param firstLine (string)
     * @return int - the length of the vectors in the file.
     */
    int lengthExtract(const string &firstLine) const;

    /**
     * the function prints an exit massage and close the program.
     * we call this function while we have invalid input.
     */
    void printBye(int i) const;

    /**
     * the function checks the input from the user.
     * @param pVector (vector<double>)
     * @param length (int)
     */
    void extractVector(vector<double> &pVector, int length, string &input) const;

    /**
     * the function checks if the algorithm given is a valid one.
     * @param algorithm (const string)
     * @return bool - if the algorithm is valid.
     */
    static bool checkAlgo(const string &algorithm);

    /**
     * the function checks if a string is a valid double.
     * @param line (string)
     * @return double - a valid double.
     */
    double validateFileVector(const string &line) const;

    /**
     * the function checks the user vector.
     * @param vector (vector<double>)
     * @param s_number (string)
     * @return bool - if the input is valid.
     */
    bool validateUserVector(vector<double> &vector, const string &s_number) const;

    /**
     * the function checks the following cases in the process of validating a string as a double:
     * 1. if the string contains only '.' or only '-'.
     * 2. if the string contains more than one '.'.
     * @param number (string)
     */
    bool checkSneakyCases(string &number) const;

    /**
     * the function checks if the string is to big.
     * @param number (string)
     */
    void normalizeDoubleSize(string &number) const;

    /**
     * the function validates the input from the user.
     * @param argc (int)
     * @param argv (char**)
     */
    void checkClientArguments(int argc, char *argv[]) const;

    /**
     * the function checks the validation of ip address.
     * @param ip (string)
     */
    void checkIP(const string &ip) const;

    /**
     * the function checks the validation of port address.
     * @param port (string)
     */
    void checkPort(const string &port) const;

    /**
     * the function checks the validation of the arguments the server gets.
     * @param argc (int)
     * @param argv (char**)
     */
    void checkServerArguments(int argc, char **argv) const;

    /**
     * the function extract the algorithm from a string.
     * @param input (string)
     * @return string - the algorithm key (if it's valid).
     */
    static string extractAlgorithm(string &input);

    /**
     * the function extract the approximation from a string.
     * @param input (string)
     * @return int - the approximation after checks.
     */
    static int extractApproximation(string &input);

    /**
     * the function manages all the data extract from the general input.
     * @param data (string)
     * @param pVector (vector<double>)
     * @param length (int)
     * @param algorithm (string)
     * @param approximation (approximation)
     * @return int - 1 for success, -1 for failure.
     */
    int dataExtract(string &data, vector<double> &pVector, int length, string &algorithm, int &approximation) const;

    /**
     * the function convert a string to char*.
     * @param input (string)
     * @return char* - the string as char*.
     */
    static char *convertStringToArray(const string &input);

    /**
     * the function check if the algorithm and the k are valid.
     * @param str (string)
     * @return index - an int that indicates if the input is valid and if so - in what index the k ends.
     */
    static int CheckAlgoK(string &str);

    static SpecialVector createTrainDB(string basicString);

    static vector<vector<double>> createTestVectors(string basicString);
};

#endif
