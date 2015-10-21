// i1: "alias(abovePercentile(nonZero('a.b.c'), 50, 76), 'cool')"
// o1: "Target('a.b.c').nonZero().abovePercentile(50, 76).alias('cool')"
// alias -> func
//  abovePercentile(nonZero('a.b.c'), 50, 76), 'cool' ; 'cool' -> param
//   abovePercentile(nonZero('a.b.c'), 50, 76); aboveP.. -> func
//    nonZero('a.b.c'), 50, 76; 50,76 -> param
//     nonZero(xx('a.b.c')) ; nonZero -> func
//      xx('a.b.c'); "" -> param

// i2: "nonZero('a.b.c')"
// o2: "Target('a.b.c').nonZero()"

// i3: "alias(nonZero('a.b.c'),'cool1')"
// o3: "Target('a.b.c').nonZero().alias('cool1')"

// i4: "alias(nonZero('a.b.c'),2343,'w234')"
// o4: "Target('a.b.c').noneZero().alias(2343, 'w234')"

#include <iostream>
#include <stack>
#include <string>

using namespace std;

stack<string> func;
stack<string> params;

// To execute C++, please define "int main()"
void GetFunc(string s);
void GetParam(string s);

void GetParam(string s)
{
  int pos = 0;
  int n = s.size();
  int br = 0;
  
  while (pos<n && !(br==0 && s[pos]==',')) 
  {
    if (s[pos] == '(') br++;
    else if (s[pos] == ')') br--;
    pos ++;
  }
  
  if (pos != n)
  {
    params.push(s.substr(pos+1, n-pos-1));
  } else
  {
    params.push("");
  }
  GetFunc(s.substr(0,pos));
}

void GetFunc(string s)
{
  int pos = 0;
  int n = s.size();
  
  while (pos<n && s[pos]!='(')
  {
    pos ++;
  }
  
  if (pos != n)
  {
    func.push(s.substr(0, pos));
    GetParam(s.substr(pos+1, n-pos-2));
  } else
  {
    func.push("Target");
    params.push(s);
  }
  
}

string Print(string s)
{ 
  GetFunc(s);
  
  string out;
  
  while(!func.empty())
  {
    out += func.top();
    out += '(' + params.top() + ')';
    func.pop();
    params.pop();
    if (!func.empty()) out += '.';
  }
  
  return out;
  
}

int main() {
  
  cout << Print("alias(abovePercentile(nonZero(xx('a.b.c')),50,76),'cool')") << endl;
  cout << Print("nonZero('a.b.c')") << endl;
  cout << Print("alias(nonZero('a.b.c'),'cool1')") << endl;
  cout << Print("alias(nonZero('a.b.c'),2343,'w234')") << endl;
  
  
  return 0;
}
