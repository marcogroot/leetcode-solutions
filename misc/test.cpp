#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <mutex>
#include <set>
#include <thread>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Temp {

public:
  int age;
  // Temp() : age{10} {};

  Temp() : age(10){};
};

int main() {
  for (int i = 0; i < 10; i++) {
    cout << "Hello\n";
  }

  Temp t = Temp();
  cout << t.age << endl;
};
