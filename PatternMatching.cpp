/* QUESTION:
 * ? -> match 1 any char
 * * -> match 0,1 or more any char
 * pattern = a*? , string = axyzb , return TRUE
 * pattern = ax? , string = axyzb , return FALSE
 */

#include <iostream>
#include <string>

using namespace std;

bool match(char const *p, char const *s){
    
    if(p == NULL || s == NULL)
        return false;
    
    //This is a corner case, look at last test case in main func.
    if(s[0] == '\0' && p[0] != '\0')
        return false;
    
    switch(p[0]){
        case '*':
            // we will either consume the star now OR consume it in the future.
            return match(p + 1, s + 1) || match(p, s + 1);

        case '?':
            return match(p + 1, s + 1);
        
        case '\0':
            return s[0] == '\0';
        
        // Unfortunately, case expr has to be constant, 
        // meaning that expr has to be known at compile time.
        // Handled this case under default case instead.
        //case s[0]:
        //    return match(p + 1, s + 1);
        
        default:
            if(p[0] == s[0]){
                return match(p + 1, s + 1);
            } else {
                return false;
            }
    }
}


int main()
{
    cout << "Result: ";
    char const *p = "a*b";
    char const *s = "axyzb";
    cout << match(p, s) << endl;
    
    cout << "Result: ";
    p = "a*?b";
    s = "axyzb";
    cout << match(p, s) << endl;
    
    cout << "Result: ";
    p = "a*?b";
    s = "cxyzb";
    cout << match(p, s) << endl;
    
    cout << "Result: ";
    p = "a?*b?z";
    s = "axyzbbb";
    cout << match(p, s) << endl;
    
    return 0;
}
