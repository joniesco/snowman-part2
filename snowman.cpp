#include <iostream>
#include <string>
#include "snowman.hpp"
#include <stdexcept>
#include <vector>
#include <algorithm>
using namespace std;
using namespace ariel;
 enum BodyParts{H,N,L,R,X,Y,T,B};
 const int ValidInputSize=8;
 const int zero=0;
 const int Ten=10;
string Nose_Mouth(int n)
{
    switch (n)
    {
    case 1:
        return ",";
        break;
    case 2:
        return ".";
        break;
    case 3:
        return "_";
        break;
    case 4:
        return " ";
        break;
    default:
        break;
    }
    return "";
}
string Eyes(int n)
{
    switch (n)
    {
    case 1:
        return ".";
        break;
    case 2:
        return "o";
        break;
    case 3:
        return "O";
        break;
    case 4:
        return "-";
        break;
    default:
        break;
    }
    return "";
}
string Left_Arm(int n)
{
    switch (n)
    {
    case 1:
        return "<";
        break;
    case 2:
        return "\\";
        break;
    case 3:
        return "/";
        break;
    case 4:
        return "";
        break;
    default:
        break;
    }
    return "";
}
string Right_Arm(int n)
{
    switch (n)
    {
    case 1:
        return ">";
        break;
    case 2:
        return "/";
        break;
    case 3:
        return "\\";
        break;
    case 4:
        return "";
        break;
    default:
        break;
    }
    return "";
}
string Torso(int n)
{
    switch (n)
    {
    case 1:
        return " : ";
        break;
    case 2:
        return "] [";
        break;
    case 3:
        return "> <";
        break;
    case 4:
        return "   ";
        break;
    default:
        break;
    }
    return "";
}
string Base(int n)
{
    switch (n)
    {
    case 1:
        return " : ";
        break;
    case 2:
        return "\" \"";
        break;
    case 3:
        return "___";
        break;
    case 4:
        return "   ";
        break;
    default:
        break;
    }
    return "";
}
bool checkInput(int number)
{
    int n = 0;
    int count = 0;
    while (number!=zero)
    {
        n = number % Ten;
        if (!(n >= N && n <= X))
        {
            return false;
        }
        count++;
        number /= Ten;
    }
   return count == ValidInputSize;
   
}
string BuildHat(int bodtPart)
{
    switch (bodtPart)
    { 
    case 1:
        return "\n_===_\n";
        break;
    case 2:
        return "\n___\n.....\n";
        break;
    case 3:
        
        return "\n_\n/_\\\n";
        break;
    case 4:
       
         return "\n___\n(_*_)\n";
        break;
    default:
        break;
    }
    return "";
}
namespace ariel{
     
	string snowman(int num){
   string snowman;
    if (!checkInput(num))
    {
        throw invalid_argument{"The input must be  from 1 to 4! and have 8 digits\n"};
    }
       vector<int> arr(ValidInputSize);
        int i = 0;
        while (num != zero)
        {
            arr.push_back( num % Ten);
            i++;
            num /= Ten;
        }
        std::reverse(arr.begin(),arr.end());
        bool isLeftArmUp = (arr.at(X)) == 2;//Left Arm is up or down
        bool isRightArmUp = (arr.at(Y)) == 2;//Right Arm is up or down
        bool isLeftArmDown =  (arr.at(X)) == 3;//Left Arm is up or down
        bool isRightArmDown = (arr.at(Y)) == 3;//Right Arm is up or down
        snowman+=BuildHat(arr.at(H))+'\n';
        if(isLeftArmUp&&isRightArmUp)
        {
            snowman+=Left_Arm(arr.at(X))+ '(' + Eyes(arr.at(L)) + Nose_Mouth(arr.at(N)) + Eyes(arr.at(R)) + ')'+Right_Arm(arr.at(Y));
            snowman += '\n';
            snowman+= '(' + Torso(arr.at(T)) + ')';
            snowman += '\n';
            snowman+= '(' + Base(arr.at(B))+ ')';
        }
        else if((isLeftArmUp&&isRightArmDown)||(isLeftArmUp&&!isRightArmUp&&!isRightArmDown))
        {
            snowman+=Left_Arm(arr.at(X))+ '(' + Eyes(arr.at(L)) + Nose_Mouth(arr.at(N)) + Eyes(arr.at(R)) + ')';
            snowman += '\n';
            snowman+= '(' + Torso(arr.at(T)) + ')'+Right_Arm(arr.at(Y));
            snowman += '\n';
            snowman+= '(' + Base(arr.at(B))+ ')';
        }
        else if ((isRightArmUp&&isLeftArmDown)||(isRightArmUp && !isLeftArmUp && !isLeftArmDown))
        {
            snowman+= '(' + Eyes(arr.at(L)) + Nose_Mouth(arr.at(N)) + Eyes(arr.at(R)) + ')'+Right_Arm(arr.at(Y));
            snowman += '\n';
            snowman+= Left_Arm(arr.at(X))+'(' + Torso(arr.at(T)) + ')';
            snowman += '\n';
            snowman+= '(' + Base(arr.at(B))+ ')';
        }
      
        else
        {
            snowman+= '(' + Eyes(arr.at(L)) + Nose_Mouth(arr.at(N)) + Eyes(arr.at(R)) + ')';
            snowman += '\n';
            snowman+=Left_Arm(arr.at(X))+ '(' + Torso(arr.at(T)) + ')'+Right_Arm(arr.at(Y));
            snowman += '\n';
            snowman+= '(' + Base(arr.at(B))+ ')';
        }
        return snowman;
}
};
