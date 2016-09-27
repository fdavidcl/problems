#include <string>
#include <sstream>
#include <utility>
#include <iostream>
#include <cmath>

/*********************************
* Some sample interview questions from a googler:
* https://www.reddit.com/r/cscareerquestions/comments/1z97rx/from_a_googler_the_google_interview_process
*********************************/

// reverse a string in-place
int reverse_in_place(int argc, char* argv[]) {
  if (argc < 2) {
    std::cerr << "Argument needed" << std::endl;
    return -1;
  }

  char* input = argv[1];
  unsigned size = strlen(input) - 1; // don't count \0 char !

  for (int i = 0; i < size/2; ++i) { // O(n)
    std::swap(input[i], input[size - i]);
  }

  std::cout << input << std::endl;
  return 0;
}

// atoi
// stuff: starts from the end of the string because why not :P
int string_to_i(int argc, char* argv[]) {
  if (argc < 2) {
    std::cerr << "Argument needed" << std::endl;
    return -1;
  }

  char* input = argv[1];
  unsigned size = strlen(input) - 1;
  int num = 0;
  for (int i = size, p = 0; i >= 0; --i, ++p) {
    char digit = input[i];
    if (digit == '-') {
      num = -num;
      break;
    }
    if (digit == '+') {
      break;
    }
    if (digit > '9' || digit < '0') {
      break;
    }
    num += (digit - '0') * pow(10, p);
  }

  std::cout << num << std::endl;

  return 0;
}

int main(int argc, char* argv[]) {
  int (*funcs[])(int c, char** v) = {reverse_in_place, string_to_i};

  if (argc < 2) {
    std::cerr << "Function needed" << std::endl;
    return -1;
  }

  std::stringstream ss;
  ss << argv[1];
  int index;
  ss >> index;

  return funcs[index](argc - 1, argv + 1);
}
