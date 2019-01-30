#include <iostream>

int *computeTempArray(std::string pattern) {
    int *lps = new int[pattern.size()];
    int j = 0;
    for(int i=1;i<pattern.size();) {
        if(pattern[i] == pattern[j]){
            lps[i++] = j + 1;
            j++;
        } else {
            if (j != 0)
                j = lps[j-1];
            else
                lps[i++] = 0;
        }
    }
    return lps;
}

bool KMP(std::string text, std::string pattern) {
    int *lps = computeTempArray(pattern);                           //Holds the computed longest prefix/suffix array.
    int i = 0, j = 0;
    while(i < text.size() && j < pattern.size()){
        if(text[i] == pattern[j]){
            i++;
            j++;
        }else{
            if(j != 0)
                j = lps[j-1];
            else
                i++;
        }
    }
    if (j == pattern.size())
        return true;
    return false;
}

int main(int argc, char *argv[]) {
    std::string str = "abcxabcdabcdabcy";
    std::string subString = "abcdabcy";
    bool result = KMP(str, subString);
    std::cout<<result<<std::endl;
    std::cout<<KMP("potato", "banana")<<std::endl;
    return 0;
}