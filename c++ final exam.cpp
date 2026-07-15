#include <iostream>
#include <string>
#include <cctype>

using namespace std;

void ANALyzetoken(const std::string&token) {
    cout<<"Token Analysis: " << token << "\n";
     
     for (char ch : token) {
         if (isalpha(ch)){
            cout << "Lexeme: " << ch << "(Type: Letter)\n";
            } else if (isdigit(ch)){
                   cout << "Lexeme: " << ch << "(Type: Digit)\n";
            } else {
                    cout << "Lexeme:" << ch << " (Type: Special Character)\n";
            }
         }
         cout<<endl;
         }
         
int main() {
    string username, password;
    
    cout << "Enter your username: ";
    getline(std::cin, password);
    
    cout << "\nAnalyzing Username:\n";
    ANALyzetoken(username);
    
    cout << "Analyzing Password:\n";
    ANALyzeToken(password);
    
    return 0;
}
         
