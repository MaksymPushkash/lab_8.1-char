#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring> 
using namespace std;


int CountOGOAGA(char* s) 
{
    int count = 0;
    int pos = 0; 

    
    while (s[pos + 2] != '\0') 
    {
        if ((s[pos] == 'O' && s[pos + 1] == 'G' && s[pos + 2] == 'O') || (s[pos] == 'A' && s[pos + 1] == 'G' && s[pos + 2] == 'A')) 
        {
            count++;
            pos += 2; 
        } 
        else 
        {
            pos++;
        }
    }
    return count;
}


char* ReplaceOGOAGA(char* s) 
{
    char* result = new char[strlen(s) * 2]; 
    result[0] = '\0'; 

    int pos = 0; 
    int destPos = 0; 

    
    while (s[pos + 2] != '\0') 
    {
        if ((s[pos] == 'O' && s[pos + 1] == 'G' && s[pos + 2] == 'O') || (s[pos] == 'A' && s[pos + 1] == 'G' && s[pos + 2] == 'A')) 
        {
            strcat(result, "**"); 
            destPos += 2;
            pos += 3; 
        } 
        else 
        {
            result[destPos++] = s[pos++];
        }
    }


    while (s[pos] != '\0') 
    {
        result[destPos++] = s[pos++];
    }

    result[destPos] = '\0'; 
    strcpy(s, result); 
    return result;
}

int main() 
{
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    
    int count = CountOGOAGA(str);
    cout << "String contains " << count << " groups of 'OGO' or 'AGA'" << endl;

    
    char* modifiedStr = ReplaceOGOAGA(str);
    cout << "Modified string (param) : " << str << endl;
    cout << "Modified string (result): " << modifiedStr << endl;

    delete[] modifiedStr;
    return 0;
}
