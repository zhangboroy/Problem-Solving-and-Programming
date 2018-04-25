#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>
using namespace std;

// Functions for manipulating a message
//
// A message in this case is a single long string
// containing \n characters separating the lines.

bool wordBeginsAt (const std::string& message, int pos);
std::string extractWord (const std::string& fromMessage, int beginningAt);
void censorSentenceAt (string& msg, int pos);

#endif
