#include <iostream>
using namespace std;

int main(){
    string plainText;
    cout << "Enter plaintext string to be encrypted: ";
    getline(cin,plainText);
    cout << endl;

    string key;
    cout << "Enter the key: ";
    cin >> key;
    cout << endl;
    int i = 0;
    if (key.size()<plainText.size()){
        int differenceLength = plainText.size()-key.size();
        while (i < differenceLength){
            key += key[i];
            i++;
        }
    }

    int x = 0;
    string cipherText = "";
    while(x < plainText.size()){
        cipherText += char(((int(plainText[x])+int(key[x]))-2 * 'a') % 26 + 'a');
        x++;
    }
    cout << "The cipher text is: " << cipherText;
    return 0;
}