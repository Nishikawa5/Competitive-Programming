#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <limits.h>
#include <map>
#include <iostream>
#include <vector>

#define ui unsigned int
#define si short int

using namespace std;

/*
Ants - We have some ants falling and we want to return the volume of the biggest and fastest ant falling

First we sort the ants by the falling speed, from fastest to slowest and then check the biggest ant

We could also just iterate through all ants and check for the volume
*/
struct Ant {
    int L, W, H;

    Ant(int L, int W, int H) {
        this->L = L;
        this->W = W;
        this->H = H;
    }

    bool operator < (const Ant& a) const {
        if (a.H < H) {
            return true;
        }
        return false;
    }

    int volume() {
        return L * W * H;
    }
};

int FallingAnts(void) {
    int T;
    int L, W, H;

    while (scanf("%d", &T) != EOF && T != 0) {
        vector <Ant> ants;
        while (T--) {
            cin >> L >> W >> H;
            ants.push_back(Ant(L, W, H));
        }
        sort(ants.begin(), ants.end());

        int i = 0;
        int maxvol = INT_MIN;
        while(ants[0].H == ants[i].H) {
            if (ants[i].volume() > maxvol) {
                maxvol = ants[i].volume();
            }
            i++;
        }

        printf("%d\n", maxvol);
    }
}















/*
Birthdates

Given a number of people, with the name and the birthdate of them, output the youngest and oldest amongst them
Very easy to interpret and implement but should use sort?

*/
int Birthdates(void) {
    si n;
    scanf("%hd", &n);

    
    ui yon = UINT_MAX;
    ui old = 0;
    char *namey = (char *) malloc(sizeof(char) * 16);
    char *nameo = (char *) malloc(sizeof(char) * 16);

    // store the values to compare
    char *tempname = (char *) malloc(sizeof(char) * 16);
    ui temp;
    ui tempage;

    const int MULT = 100;
    int norm;

    for (int i = 0; i < n; i++) {
        norm = 1;
        tempage = 0;

        scanf("%s", tempname);
        getchar();

        for (int j = 0; j < 3; j++) {
            scanf("%u", &temp);
            tempage += temp * norm;
            norm *= MULT;
        }

        if (tempage > old) {
            old = tempage;
            strcpy(nameo, tempname);
        }
        if (tempage < yon) {
            yon = tempage;
            strcpy(namey, tempname);
        }
    }
    printf("%s\n%s\n", nameo, namey);
}

/* Another approach using sort */
struct Date {
    string name;
    int day;
    int month;
    int year;
    /* constructor */
    Date(string n, int d, int m, int y){
        name  = n;
        day   = d;
        month = m;
        year  = y;
    }
    /* to use in sort */
    bool operator < (const Date& d) const {
        if(year>d.year) return true;
        if(year==d.year && month>d.month) return true;
        if(year==d.year && month==d.month && day>d.day) return true;
        else return false;
    }
};

int Birthdate2(){
    int n;
    cin>>n;
    vector<Date> v;
    
    while(n--){
        string name;
        int d, m, y;
        cin >> name >>d >> m >> y;
        v.push_back(Date(name, d, m, y));
    }
    
    sort(v.begin(), v.end());
    
    printf("%s\n%s\n", (v.front().name).c_str(), (v.back().name).c_str());
    
    return 0;
}












/*
Easy to understand, a little hard to implement efficiently for me because i used binary seach and 
wasn't so familiar with that

We create an array will contain every number and insert the elements in this array maintaining sorted order
to maintain, we always try to find where the element should be with the binary search (inside the interval of 2
consecutive numbers) and then move every element in the right of array to the right
so its O(logn + n) complexity

could use n_thelement function
*/
int findBin(ui *arr, int low, int high, ui X) {
    int middle = (low + high) / 2;

    if (arr[middle] == X) return middle;
    else if (arr[middle] <= X && arr[middle + 1] >= X) return middle + 1;
    else if (arr[middle - 1] <= X && arr[middle] >= X) return middle;

    if (arr[middle] > X) return findBin(arr, low, middle - 1, X);
    else if (arr[middle] < X) return findBin(arr, middle + 1, high, X);
}


/* Assuming arr is a sorted array of unsigned integers, add a new element to it keeping it sorted */
void insertSort(ui *arr, ui X, int N) {
    // get the point where we need to shift  
    int idx;
    if (X <= arr[0]) idx = 0;
    else if (X >= arr[N - 1]) {
        idx = N;
    } else idx = findBin(arr, 0, N, X);
    // shift elements to right
    ui temp, temp2;
    temp = arr[idx];
    for (int i = idx + 1; i < N + 1; i++) {
        temp2 = arr[i];
        arr[i] = temp; 
        temp = temp2;
    }

    arr[idx] = X;
}


int Median(void) {
    ui X;
    ui *arr;
    arr = (ui *) malloc(sizeof(ui) * 10000);
    arr[0] = UINT32_MAX;

    int N = 0;
    while (scanf("%u", &X) != EOF) {
        insertSort(arr, X, N++);

        if (!(N % 2)) {
            printf("%u\n", (arr[N / 2] + arr[N / 2 - 1]) / 2);
        } else {
            printf("%u\n", arr[N / 2]);
        }
    }
}


















/*
Easy to understand and implement
tried to use most efficient solutions but it may have more efficient
*/

int basicprogramming2(void) {
    int N;
    int t;

    scanf("%d %d", &N, &t);

    if (t == 1) {
        bool map[7778];
        int temp;
        memset(map, 0, sizeof(map));

        for (int i = 0; i < N; i++) {
            scanf("%d", &temp);
            int sub = 7777 - temp;
            if (sub >= 0 && sub < 7778) {
                if (map[sub]) {  // may check if they are equal (i don't think this case exist)
                    printf("Yes\n");
                    return 0;
                } 
            }

            if (temp >= 0 && temp < 7778) {
                map[temp] = 1;
            }
        }
        printf("No\n");
    } else if (t == 2) {
        std::map <int, bool> mapp;
        int temp;
        for (int i = 0; i < N; i++) {
            scanf("%d", &temp);
            if (mapp[temp]) {
                printf("Contains duplicate\n");
                return 0;
            }
            mapp[temp] = 1;
        }
        printf("Unique\n");
    } else if (t == 3) {
        std::map <int, int> count;
        int k;

        for (int i = 0; i < N; i++) {
            scanf("%d", &k);
            if (++count[k] > N / 2) {
                printf("%d\n", k);
                return 0;
            }
        }
        printf("-1\n");
    } else {
        int *arr = (int *) malloc(sizeof(int) * N);
        
        for (int i = 0; i < N; i++) {
            scanf("%d", &arr[i]);
        }
        std::sort(arr, arr + N);

        if (t == 4) {
            if (N % 2) {
                printf("%d\n", arr[N / 2]);
            } else {
                printf("%d %d\n", arr[N / 2 - 1], arr[N / 2]);
            }
        } else {
            int i = 0;
            while (arr[i] < 100 && i < N) i++;
            if (i < N) printf("%d", arr[i++]);
            while (arr[i] <= 999 && i < N) printf(" %d", arr[i++]);
            printf("\n");
        }
    }
}