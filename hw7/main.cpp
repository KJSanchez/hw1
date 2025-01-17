// -----------------------------------------------------------------
// HOMEWORK 7 WORD FREQUENCY MAPS
//
// You may use all of, some of, or none of the provided code below.
// You may edit it as you like (provided you follow the homework
// instructions).
// -----------------------------------------------------------------

#include <cassert>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <string>
#include <vector>

using std::string, std::map;

typedef map<string, map<string, int>> MY_MAP;

// Custom helper function that reads the input stream looking for
// double quotes (a special case delimiter needed below), and white
// space.  Contiguous blocks of alphabetic characters are lowercased &
// packed into the word.
bool ReadNextWord(std::istream &istr, std::string &word) {
  char c;
  word.clear();
  while (istr) {
    // just "peek" at the next character in the stream
    c = istr.peek();
    if (isspace(c)) {
      // skip whitespace before a word starts
      istr.get(c);
      if (word != "") {
        // break words at whitespace
        return true;
      }
    } else if (c == '"') {
      // double quotes are a delimiter and a special "word"
      if (word == "") {
        istr.get(c);
        word.push_back(c);
      }
      return true;
    } else if (isalpha(c)) {
      // this a an alphabetic word character
      istr.get(c);
      word.push_back(tolower(c));
    } else {
      // ignore this character (probably punctuation)
      istr.get(c);
    }
  }
  return false;
}

// Custom helper function that reads the input stream looking a
// sequence of words inside a pair of double quotes.  The words are
// separated by white space, but the double quotes might not have
// space between them and the neighboring word.  Punctuation is
// ignored and words are lowercased.
std::vector<std::string> ReadQuotedWords(std::istream &istr) {
  // returns a vector of strings of the different words
  std::vector<std::string> answer;
  std::string word;
  bool open_quote = false;
  while (ReadNextWord(istr, word)) {
    if (word == "\"") {
      if (open_quote == false) {
        open_quote = true;
      } else {
        break;
      }
    } else {
      // add each word to the vector
      answer.push_back(word);
    }
  }
  return answer;
}

// Loads the sample text from the file, storing it in the map data
// structure Window specifies the width of the context (>= 2) of the
// sequencing stored in the map.  parse_method is a placeholder for
// optional extra credit extensions that use punctuation.
void LoadSampleText(MY_MAP &data, const std::string &filename, int window,
                    const std::string &parse_method) {
  // open the file stream
  std::ifstream istr(filename.c_str());
  if (!istr) {
    std::cerr << "ERROR cannot open file: " << filename << std::endl;
    exit(1);
  }
  // verify the window parameter is appropriate
  if (window < 2) {
    std::cerr << "ERROR window size must be >= 2:" << window << std::endl;
  }
  // verify that the parse method is appropriate
  bool ignore_punctuation = false;
  if (parse_method == "ignore_punctuation") {
    ignore_punctuation = true;
  } else {
    std::cerr << "ERROR unknown parse method: " << parse_method << std::endl;
    exit(1);
  }

  //
  // ASSIGNMENT:SETUP YOUR MAP DATA AS NEEDED
  //

  std::string word;
  while (ReadNextWord(istr, word)) {
    // skip the quotation marks (not used for this part)
    if (word == "\"")
      continue;

    //
    // ASSIGNMENT: PROCESS ALL THE NON PUNCTUATION WORDS
    // INSERTING THESE WORDS INTO THE DATA STRUCTURE
    //
  }
}

int main() {
  MY_MAP data;

  // Parse each command
  std::string command;
  while (std::cin >> command) {

    // load the sample text file
    if (command == "load") {
      std::string filename;
      int window;
      std::string parse_method;
      std::cin >> filename >> window >> parse_method;

      //
      // ASSIGNMENT: ADD YOUR COMMANDS HERE
      //

    }

    // print the portion of the map structure with the choices for the
    // next word given a particular sequence.
    else if (command == "print") {
      std::vector<std::string> sentence = ReadQuotedWords(std::cin);

      //
      // ASSIGNMENT: ADD YOUR COMMANDS HERE
      //

    }

    // generate the specified number of words
    else if (command == "generate") {
      std::vector<std::string> sentence = ReadQuotedWords(std::cin);
      // how many additional words to generate
      int length;
      std::cin >> length;
      std::string selection_method;
      std::cin >> selection_method;
      bool random_flag;
      if (selection_method == "random") {
        random_flag = true;
      } else {
        assert(selection_method == "most_common");
        random_flag = false;
      }

      //
      // ASSIGNMENT: ADD YOUR COMMANDS HERE
      //

    } else if (command == "quit") {
      break;
    } else {
      std::cout << "WARNING: Unknown command: " << command << std::endl;
    }
  }
}
