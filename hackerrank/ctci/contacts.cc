// https://www.hackerrank.com/challenges/ctci-contacts

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

class Contacts {
  map<string, unsigned> ctcs;
  
public:
  // Adds a contact to the "list"
  void add(const string& name) {
    // updates the count of all prefixes of the string
    for (int i = 1; i <= name.size(); ++i) {
      string p = name.substr(0, i);
      if (ctcs.find(p) == ctcs.end()) {
        ctcs[p] = 1;   
      } else {
        ctcs[p] += 1;
      }
    }
  }
  // counts the contacts where partial is a prefix
  unsigned find(const string& partial) {
    return ctcs.find(partial) != ctcs.end() ? ctcs[partial] : 0;
  }
};

int main() {
  Contacts agenda;
    
  int queries;
  cin >> queries;
    
  for (int q = 0; q < queries; q += 1) {
    string command, argument;
    cin >> command;
    cin >> argument;
    if (command == "add") {
      agenda.add(argument);
    } else if (command == "find") {
      cout << agenda.find(argument) << endl;
    }
  }
    
  return 0;
}
