#include <iostream>
#include <string>
namespace yikliu{
    namespace leetcode{
        class ReverseString{
        public:
            void reverseString(std::string& s) {
                int head = 0;
                int end = s.size() - 1;
                
                char temp;
                while(head < end) {
                    temp = s[head];
                    s[head] = s[end];
                    s[end] = temp;
                    head++;
                    end--;
                }
                return;
            }
        };
    }
}
