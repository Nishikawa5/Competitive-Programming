#include <stdio.h>
#include <stdlib.h>
#define bool int
#define true 1
#define false 0







// given two words, return true if them are anagrams, false if not
bool isAnagram(char * s, char * t)
{
    // different sizes, so it's not an anagram
    if (strlen(s) != strlen(t)) return false;

    // mapping
    int countLetters[26] = {0};

    // the strings have the same number of letters, so we can pass and record how many letters they have of each type.
    int i = 0;
    while(s[i] != '\0' && t[i] != '\0')
    {
        countLetters[s[i] - 'a']++;
        countLetters[t[i] - 'a']--;
        i++;
    }
    
    // test if they have the same number of letters of each type
    for (int j = 0; j < 26; j++)
    {
        if (countLetters[j]) return false;
    }

    return true;
}



// given a string, return true if alphanumeric characters forms a palindrome, false otherwise
bool isPalindrome(char * s)
{

    for (int start = 0, final = strlen(s) - 1; start < final; start++, final--)
    {
        // goes to the first alphanumeric char to the left
        while (start < final && (s[start] < 'a' || s[start] > 'z') && !(s[start] >= '0' && s[start] <= '9'))
        {
            if (s[start] >= 'A' && s[start] <= 'Z') s[start] += 32;
            else start++;
        }

        // goes to the first alphanumeric char to the right
        while (start < final && (s[final] < 'a' || s[final] > 'z') && !(s[final] >= '0' && s[final] <= '9'))
        {
            if (s[final] >= 'A' && s[final] <= 'Z') s[final] += 32;
            else final--;
        }

        // compare them
        if (start > final || s[start] != s[final]) return false;
    }
    return true;
}



// given a string, count how many palindrome substring it have
int countSubstrings(char * s)
{
    if (!s) return 0;

    int count = 1;

    // every possible substring
    for (int i = 0, len = strlen(s) - 1; i < len; i++)
    {
        count += checksubs(i, i, s, len); // odd
        count += checksubs(i, i + 1, s, len); // even
    }

    return count;
}

int checksubs(int left, int right, char* s, int len)
{
    int count = 0;
    while (left >= 0 && right <= len && s[left] == s[right])
    {
        count++;
        left--;
        right++;
    }

    return count;
}