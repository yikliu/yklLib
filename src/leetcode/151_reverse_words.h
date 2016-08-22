#include <iostream>
#include <string>
namespace yikliu{
    namespace leetcode{
        class ReverseWords{
        public:
            void reverse(std::string &s, int i, int length){
                char temp;
                int j = length -1;
                while(i < j){
                    temp = s[i];
                    s[i] = s[j];
                    s[j] = temp;
                    i++;
                    j--;
                }
            }
            
            void reverseWords(std::string &s) {
                // first remove all leading, tailing and duplicate spaces
                bool firstNonSpace = false;
                int len = 0;
                for (int j = 0; j < s.length(); j++) {
                    if (!firstNonSpace) {
                        if (s[j] != ' '){
                            firstNonSpace = true;
                            s[len++] = s[j]; // remove leading spaces
                        }
                    }
                    else if (s[j] != ' ' || s[len-1] != ' ') {
                        s[len++] = s[j]; // remove all duplicate spaces, i.e. "    " -> " "
                    }
                }
                
                if (len > 0 && s[len-1] == ' ') {
                    --len;
                }
                
                s.resize(len);
                
                for (int i = -1, j = 0; j <= s.length(); ++j) {
                    if (s[j] == ' ' || s[j] == '\0') {
                        reverse(s, i + 1, j);
                        i = j;
                    }
                }
                // reverse the whole string
                reverse(s, 0, s.length());
            }
        };
    }
}