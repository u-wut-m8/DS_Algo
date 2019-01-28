#include <iostream>

int countSetBits(int num) {
    int sum = 0;
    while(num > 0) {
        sum += num & 1;
        num >>= 1;
    }
    return sum;
}

int alternativeCountSetBits(int num) {
    int sum = 0;
    while(num > 0) {
        num &= (num-1);                 //Any number ANDed with itself-1 will reduce a bit.
        sum += 1;
    }
    return sum;
}

/*Find missing number in an array with positive intergers from 0-n*/
int missingNumber(int *arr, int size) {
    int A = 0;
    for(int i=0;i<size;i++)
        A ^= arr[i];
    int B = 0;
    for(int i=0;i<=size;i++)
        B ^= i;
    return A^B;
}

/*
If a number is even:
Number of set bit of the number = Number of set bits of (number/2)
If a number is odd:
Number of set bit of the number = Number of set bits of (number/2 + 1)
*/
void countSetBitsRange(int num) {
    int *arr = new int[num+1];
    *(arr + 0) = 0;
    for(int i=1;i<=num;i++)
        *(arr + i) = arr[i>>1] + (i&1);
    for(int i=0;i<=num;i++)
        std::cout<<*(arr+i)<<" ";
    std::cout<<std::endl;
    delete[] arr;
}

/*
Given a string array words, find the maximum value of length(word[i]) * length(word[j]) where the two words do not share common letters.
You may assume that each word will contain only lower case letters. If no such two words exist, return 0.
An important thing to note here is that the question simply cares about common characters and not their frequency or their order.

Example 1:

Input: ["abcw","baz","foo","bar","xtfn","abcdef"]
Output: 16
Explanation: The two words can be "abcw", "xtfn".
Example 2:

Input: ["a","ab","abc","d","cd","bcd","abcd"]
Output: 4
Explanation: The two words can be "ab", "cd".
Example 3:

Input: ["a","aa","aaa","aaaa"]
Output: 0
Explanation: No such pair of words.
*/
#include <vector>
#include <map>

template <typename T>
inline T max(const T& a, const T& b) {
    return a > b ? a : b;
}

long long maxProducts(std::vector<std::string> words) {
    std::map<std::string, long long> mp;                        //Map to hold mask of all words.
    for(std::string word : words) {
        long long mask = 0;                                     //All bits from 25th bit to 0th bit will be set if that character is present in word.
        for(char ch : word)
            mask |= (1<<(122-int(ch)));                         //Ex. - if ch = 'a' then 25th bit will be 1, if ch = 'b' then 24th bit will be 1, and so on.
        mp[word] = mask;
    }
    long long ans = 0;
    for(int i=0;i<words.size();i++)
        for(int j=i+1;j<words.size();j++)
            if(!(mp[words[i]] & mp[words[j]]))
                ans = max(ans, (long long)(words[i].size()*words[j].size()));
    return ans;
}

int main() {
    std::cout<<countSetBits(10)<<std::endl;
    std::cout<<alternativeCountSetBits(15)<<std::endl;
    /*Mask bit at ith position if its 1 otherwise unmask it if its 0.  A^(1<<i)*/
    std::cout<<(5^(1<<1))<<std::endl;            //5 is 101 is binary, i.e. - bit at index 1 is 0, XORing with 1 left shifted to 1 positions will set it to 1.
    std::cout<<missingNumber(new int[9]{9, 6, 4, 2, 3, 5, 7, 0, 1}, 9)<<std::endl;
    countSetBitsRange(16);
    std::cout<<maxProducts(std::vector<std::string>({"abcw","baz","foo","bar","xtfn","abcdef"}))<<std::endl;
    std::cout<<maxProducts(std::vector<std::string>({"a","ab","abc","d","cd","bcd","abcd"}))<<std::endl;
    return 0;
}