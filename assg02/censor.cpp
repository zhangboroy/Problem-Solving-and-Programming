#include <iostream>
#include <fstream>
#include <string>
#include "sensitiveWords.h"
#include "message.h"

using namespace std;

///////////////////////////////////////////////////////
//!!
// The 4 functions below should remain in censor.cpp
// The functions and data above should be used to create
// two models, "sensistiveWords" and "message".  Keep the
// cohesion high and the coupling low.

void censorMessage (string& msg, int numSensitiveWords, string sensitiveWords[])
{
  for (int i = 0; i < msg.length(); ++i)
  {
    if (wordBeginsAt(msg, i))
    {
      string word = extractWord(msg, i);
	  if (isSensitive(word, numSensitiveWords, sensitiveWords))
        censorSentenceAt (msg, i);
    }
  }
}

void readSensitiveWords (istream& in, int &numSensitiveWords, string sensitiveWords[])
{
  string word;
  while ((in >> word) && (word != "==="))
    addSensitiveWord (word, numSensitiveWords, sensitiveWords);
  getline (in, word);
}

string readMessage (istream& in)
{
  string msg;
  string line;
  getline (in, line);
  while (in)
  {
    msg = msg + line + "\n";
    getline (in, line);
  }
  return msg;
}

int main()
{
  const int MaxSensitiveWords = 5000;
  int numSensitiveWords = 0;
  string sensitiveWords[MaxSensitiveWords];

  ifstream inData;
  inData.open("input.txt");
  //read sensitive words in an array
  readSensitiveWords(inData, numSensitiveWords, sensitiveWords);
  //read message to a string
  string msg = readMessage(inData);
  inData.close();

  //process the message
  censorMessage (msg, numSensitiveWords, sensitiveWords);
  cout << msg << flush;
  return 0;
}
