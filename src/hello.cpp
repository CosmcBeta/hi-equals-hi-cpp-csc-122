#include "hello.hpp"

int strcmp_case_insensitive(std::string stringOne, std::string stringTwo, bool skipSpaces)
{  
   if (stringOne == "" && stringTwo == "")
      return 0;

   std::string first = "";
   std::string second = "";
   
   if (skipSpaces)
   {
      for (char c : stringOne)
      {
         if (!isspace(c))
            first += c;
      }

      for (char c : stringTwo)
      {
         if (!isspace(c))
            second += c;
      }
   }
   else
   {
      first = stringOne;
      second = stringTwo;
   }

   if (first == "")
      return 0 - second[0];

   if (second == "")
      return first[0] - 0;

   int i = 0;
   while (true)
   {
      if (tolower(first[i]) != tolower(second[i]))
         return first[i] - second[i];

      i++;

      if (first.length() == i || second.length() == i)
      {
         if (first.length() > second.length())
            return first[i] - 0;
         else if (first.length() < second.length())
            return 0 - second[i];
         else
            return 0;
      }
   }
}