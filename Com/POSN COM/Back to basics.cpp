// my first program in C++
#include <iostream>
using namespace std;

int main()
{
  string name,password;
  cout << "Hello World!"<< endl;
  cout << "Username: ";
  cin >> name;
  cout << "Password: ";
  cin >> password;
  if (name == "Pun")
  {
      if (password == "9393")
        {cout << "Hi Pun";}
      else {cout << "Incorrect password";}
  }
  else {cout << "Get out";};
  return 0;
}
