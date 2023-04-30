#include <iostream>
using namespace std;

int main(){
    string plainText;

    cout << "Enter plaintext string to be encrypted: ";
    getline(cin, plainText);
    cout << endl;

    int i = 0;
    string cipherText = "";
    cout << plainText.length() << endl;
    while(i < plainText.size()){
        if(!isspace(plainText[i])){
            cipherText += ((plainText[i]-'a')+3)+'a';
            i++;
        }
        else{
            cipherText += " ";
            i++;
        }
        
    }
    cout << "The cipher text is: " << cipherText;
    return 0;
}