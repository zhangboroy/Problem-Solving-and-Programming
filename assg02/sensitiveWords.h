#ifndef SENSITIVEWORDS_H
#define SENSITIVEWORDS_H

#include <string>
using namespace std;

/*
 * Functions & data for maintaining and checking a list of
 * sensitive words.
 *
 */
void addSensitiveWord (std::string& wordFromMessage, int &numSensitiveWords, string sensitiveWords[]);
bool isSensitive(std::string& wordFromMessage, int &numSensitiveWords, string sensitiveWords[]);

#endif
