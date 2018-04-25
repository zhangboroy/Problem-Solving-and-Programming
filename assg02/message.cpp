#include "message.h"

bool isAlphanumeric (char c)
{
  return (c >= 'A' && c <= 'Z')
    || (c >= 'a' && c <= 'z')
    || (c >= '0' && c <= '9');
}

/*
 * Return true if the character at position pos is the first character
 * of a word.
 */
bool wordBeginsAt (const std::string& message, int pos)
{
  //!! Fill in the body for this function
  return isAlphanumeric(message[pos]) && (pos==0 || (pos>0 && !isAlphanumeric(message[pos-1])));
  //the character at position pos is an alphabet or numeric,
  //as well as the character at last position is not an alphabet or numeric
}

/*
 * Return the string comprising the word that begins at
 * position beginningAt.
 */
std::string extractWord (const std::string& fromMessage, int beginningAt)
{
  //!! Fill in the body for this function
  //initial the word
  std::string word="";
  int i=0;
  //add every alphabet or numeric to the word until meet a character which is not an alphabet or numeric
  while (isAlphanumeric(fromMessage[beginningAt+i]))
  {
    word=word+fromMessage[beginningAt+i];
    i++;
  }
  return word;
}

bool sentencePunctuation (char c)
{
  return c == '.' || c == '?' || c == '!';
}

bool paragraphStart  (const string& msg, int pos)
{
  if (pos == 0)
    return true;
  if (pos == 1)
    return false;
  return msg[pos-1] == '\n' && msg[pos-2] == '\n';
}

bool paragraphEnd  (const string& msg, int pos)
{
  if (pos == msg.length())
    return true;
  if (pos == msg.length()-1)
    return false;
  return msg[pos] == '\n' && msg[pos+1] == '\n';
}

/*
 * Return the position that denotes the first character of the sentence
 * that begins at or before position pos and that ends at or after
 * that position.
 */
int findSentenceStart (const string& msg, int pos)
{
  while (pos > 0 && !paragraphStart(msg,pos) && !sentencePunctuation(msg[pos]))
    --pos;
  if (sentencePunctuation(msg[pos]))
    ++pos;
  return pos;
}

/*
 * Return the position that denotes the last character of the sentence
 * that begins at or before position pos and that ends at or after
 * that position.
 */
int findSentenceStop (const string& msg, int pos)
{
  while (pos < msg.length()
	 && !paragraphEnd(msg,pos)
	 && !(pos > 0 && sentencePunctuation(msg[pos-1])))
    ++pos;
  return pos;
}

/*
 * Replace by '@' all characters (except '\n') of the sentence
 * that begins at or before position pos and that ends at or after
 * that position.
 */
void censorSentenceAt (string& msg, int pos)
{
  //!! Fill in the body for this function
  int SentenceStop=findSentenceStop(msg, pos);
  for (int i=findSentenceStart(msg, pos);i<SentenceStop;i++)
  {
    if (msg[i]!='\n') msg[i]='@';
  }
}
