#include "sensitiveWords.h"

std::string toLowerCase (std::string word)
{
  string result = word;
  for (int i = 0; i < word.length(); ++i)
    if (word[i] >= 'A' && word[i] <= 'Z')
      result[i] = result[i] + 'a' - 'A';
  return result;
}

bool isSensitive(std::string& wordFromMessage, int &numSensitiveWords, string sensitiveWords[])
{
  string word = toLowerCase(wordFromMessage);
  for (int i = 0; i < numSensitiveWords; ++i)
    if (word == sensitiveWords[i])
      return true;
  return false;
}

void addSensitiveWord (std::string& wordFromMessage, int &numSensitiveWords, string sensitiveWords[])
{
  string word = toLowerCase(wordFromMessage);
  if (!isSensitive(word, numSensitiveWords, sensitiveWords))
  {
    sensitiveWords[numSensitiveWords] = word;
    ++numSensitiveWords;
  }
}
