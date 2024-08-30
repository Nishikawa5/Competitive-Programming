



int checkInclusion(char * s1, char * s2)
{
    // sliding window
    int len = strlen(s1);
    int c;

    int s1char[26] = {0};
    int s2char[26] = {0};

    // count every char in s1 in a vector
    for (int i = 0; i < len; i++)
    {
        s1char[s1[i] - 'a']++;
    }

    // count the chars in s2 in the size of len (lenght of s1) and then compare them
    for (int i = 0, n = strlen(s2); i < n; i++)
    {
        c = 0;
        if (i < len)
        {
            s2char[s2[i] - 'a']++;
        }
        else
        {
            s2char[s2[i - len] - 'a']--;
            s2char[s2[i] - 'a']++;
        }

        for (int j = 0; j < 26; j++)
        {
            if (s1char[j] == s2char[j]) c++;
            else break;
        }
        // if c = 26, it means both vectors are equal
        if (c == 26) return 1;
    }
    return 0;
}


// given a string, return the lenght of max substring
int lengthOfLongestSubstring(char * s)
{
    int start = 0;
    int max = 0;
    // create a vector to store the character values
    int countchar[256] = {0};

    // goes through all characters in string
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        // increase 1 to the value corresponding to s[i] (character)
        countchar[s[i]]++;

        // while the value is 2, continues increasing start and decreases by 1 every value before the s[i] character
        // that has value 2
        while (countchar[s[i]] == 2)
        {
            countchar[s[start++]]--;
        }

        // stores the max substring lenght
        if (max < i - start + 1) max = i - start + 1;
    }

    return max;
}



int checkboard(char** board, int i, int j, int boardSize, int boardColSize, char * word, int len, int temp);

// given a board, its sizes and a word, return true if the word can be formed moving up/down/left/right
int exist(char** board, int boardSize, int* boardColSize, char * word)
{
    int len = strlen(word);
    for (int i = 0; i < boardSize; i++)
    {
        for (int j = 0; j < * boardColSize; j++)
        {
            if (checkboard(board, i, j, boardSize, * boardColSize, word, len, 0)) return 1;
        }
    }
    return 0;
}

// dfs
int checkboard(char** board, int i, int j, int boardSize, int boardColSize, char * word, int len, int temp)
{
    // passed through all letters in word
    if (temp == len) return 1;
    // index outside the board
    else if (i < 0 || i >= boardSize || j < 0 || j >= boardColSize)
    {
        return 0;
    }

    // stores the board letter
    char reuse = board[i][j];
    
    if (board[i][j] == word[temp])
    {
        // the letter is encountered, so continue the bfs
        temp++;
        // put a "#" to don't reuse the character
        board[i][j] = '#';
        // check every step, if it return true means the word can be formed, so return true
        if (checkboard(board, i + 1, j, boardSize, boardColSize, word, len, temp) || 
        checkboard(board, i - 1, j, boardSize, boardColSize, word, len, temp) || 
        checkboard(board, i, j - 1, boardSize, boardColSize, word, len, temp) || 
        checkboard(board, i, j + 1, boardSize, boardColSize, word, len, temp)) return 1;
        // failed, so readjust the letter missing
        else board[i][j] = reuse;
    }
    // not encountered
    return 0;
}