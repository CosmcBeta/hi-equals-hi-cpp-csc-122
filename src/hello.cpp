#include "hello.hpp"

int strcmp_case_insensitive(std::string stringOne, std::string stringTwo)
{  
   if (stringOne == "" && stringTwo == "")
      return 0;

   if (stringOne == "")
      return 0 - stringTwo[0];

   if (stringTwo == "")
      return stringOne[0] - 0;

   int i = 0;
   while (true)
   {
      if (tolower(stringOne[i]) != tolower(stringTwo[i]))
         return stringOne[i] - stringTwo[i];

      i++;

      if (stringOne.length() == i || stringTwo.length() == i)
      {
         if (stringOne.length() > stringTwo.length())
            return stringOne[i] - 0;
         else if (stringOne.length() < stringTwo.length())
            return 0 - stringTwo[i];
         else
            return 0;
      }
   }
}