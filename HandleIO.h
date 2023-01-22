#ifndef CLASSIFIERVECTORS_HANDLEIO_H
#define CLASSIFIERVECTORS_HANDLEIO_H

#include <vector>
#include <sstream>
#include <iostream>
#include <cfloat>
#include <cmath>
#include <cstring>
#include <fstream>
#include <iostream>
#include <sys/socket.h>
#include <cstdio>
#include <netinet/in.h>
#include <unistd.h>
#include <cstring>
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
#define INVALID_APPROXIMATION (-1)
#define INVALID_ALGORITHM (-2)
#define INVALID_PARAMETERS (-3)

// define for all the arguments from the user
#define FILE_NAME argv[1]
#define NUM_OF_ARGS 2
#define IP_RANGE 255
#define ALG_SIZE 3

// sockets logics
#define SERVER_IP argv[2]
#define PORT argv[1]
#define BUFFER_SIZE 4096

// define for the commands
#define COMMAND_1 0
#define COMMAND_3 2
#define COMMAND_4 3
#define COMMAND_5 4

// define for search in strings
#define LETTERS_AND_NUMBERS " \n\r\t"

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
    static pair<string, vector<double>> pairExtract(string &line, unsigned long length) ;

    /**
     * the function checks if the file we got is valid.
     * we check the following cases:
     * 1. we can open the file.
     * 2. it's a csv file.
     * 3. it's not an empty file.
     * @param file (string)
     */
    static int checkFile(string file, int indicator);

    /**
     * the function checks the length of the vectors in the file by the first line.
     * @param firstLine (string)
     * @return int - the length of the vectors in the file.
     */
    static int lengthExtract(const string &firstLine);

    /**
     * the function prints an exit massage and close the program.
     * we call this function while we have invalid input.
     */
    static void printBye(int i);

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
    static int validateFileVector(const string &line);

    /**
     * the function checks the user vector.
     * @param vector (vector<double>)
     * @param s_number (string)
     * @return bool - if the input is valid.
     */
    static bool validateUserVector(vector<double> &vector, const string &s_number);

    /**
     * the function checks the following cases in the process of validating a string as a double:
     * 1. if the string contains only '.' or only '-'.
     * 2. if the string contains more than one '.'.
     * @param number (string)
     */
    static bool checkSneakyCases(string &number);

    /**
     * the function checks if the string is to big.
     * @param number (string)
     */
    static void normalizeDoubleSize(string &number);

    /**
     * the function validates the input from the user.
     * @param argc (int)
     * @param argv (char**)
     */
    static void checkClientArguments(int argc, char *argv[]);

    /**
     * the function checks the validation of ip address.
     * @param ip (string)
     */
    static void checkIP(const string &ip);

    /**
     * the function checks the validation of port address.
     * @param port (string)
     */
    static void checkPort(const string &port);

    /**
     * the function checks the validation of the arguments the server gets.
     * @param argc (int)
     * @param argv (char**)
     */
    static void checkServerArguments(int argc, char **argv);

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

    /**
     * the function creates a DB to classify with.
     * @param basicString (string)
     * @return rv - a Special vector which is the DB.
     */
    static SpecialVector createTrainDB(const string &basicString);

    /**
     * the function creates a vector of unclassified vectors.
     * @param basicString (string)
     * @return rv - a vector of unclassified vectors.
     */
    static vector<vector<double>> createTestVectors(const string &basicString);

    /**
     * the function creates a  pair of string and vector.
     * @param vector (string)
     * @return rv - a pair of string and a vector (a classified vector)
     */
    static pair<string, vector<double>> pairFromString(const string &vector);

    /**
     * the function creates a vector from a string.
     * @param vecString (string)
     * @return rv - a vector of double.
     */
    static vector<double> vectorFromString(const string &vecString);

    /**
     * the function sends data to a socket.
     * @param socket (int)
     * @param send_data (string)
     */
    static void sendProtocol(int socket, string send_data);

    /**
     * the function receives data from a socket and put the data in a given string.
     * @param socket (int)
     * @param receive_data (string)
     */
    static bool receiveProtocol(int socket, string &receive_data);

    /**
     * the function check if a request is valid. if so - updates the array in the relevant place.
     * @param array (bool*)
     * @param toCheck (string)
     * @param socket (int)
     * @return rv - an indicator if the demand id valid.
     */
    static int checkDemand(bool (&array)[5], string toCheck, int socket);

    static int extractChoice(const string &choice);

    static int checkDBLine(const string &line, int length, int file);
};

#endif
