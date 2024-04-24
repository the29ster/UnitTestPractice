#include "Password.h"
#include <string>
#include <vector>

using std::string;

int Password::count_leading_characters(string phrase){
  int repetition = 0;

  if(phrase != "")
    repetition = 1;

  int index = 0;
  while( index < phrase.length()-1 && phrase[index] == phrase[index+1] ){
    repetition++;
    index++;
  }
  return repetition;
}

bool Password::has_mixed_case(string temp)
{
  bool hasUpper = false;
  bool hasLower = false;

  for(int i = 0; i < temp.length(); i++)
  {
    if(std::isupper(temp[i]))
      hasUpper = true;

    if(std::islower(temp[i]))
      hasLower = true;
  }

  if(hasUpper && hasLower)
    return true;
  else
    return false;
}

Password::Password()
{
  pass_history.push_back("ChicoCA-95929");
};

void Password::set(string temp)
{
  if(temp.length() >= 8 || temp.length() <= 20)
  {
    if(count_leading_characters(temp) <= 3)
    {
      bool hasUpperAndLower = has_mixed_case(temp);

      if(hasUpperAndLower)
      {
        bool isUnique = authenticate(temp);

        if(isUnique)
        {
          pass_history.push_back(temp);
        }
      }
    }
  }
}

bool Password::authenticate(string temp)
{
  bool isUnique = true;

  if(temp == pass_history[pass_history.size()])
    isUnique = false;

  return isUnique;
}
