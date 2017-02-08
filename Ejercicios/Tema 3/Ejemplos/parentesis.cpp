#include <iostream>
using namespace std;

int main()
{
   char c;
   int anidamiento = 0, pos = 0;
   bool error = false;
   do {
      cin >> c;
      pos++;
      if (c == '(')
         anidamiento = anidamiento + 1;
      else if (c == ')')
         anidamiento = anidamiento - 1;
      if (anidamiento < 0)
         error = true;
   } while ((c != '#') && !error);
   if (error)
      cout << "Error: cierre sin apertura (pos. " << pos << ")";
   else if (anidamiento > 0)
      cout << "Error: apertura sin cierre";
   else
      cout << "Correcto";
   cout << endl;

   return 0;
}
