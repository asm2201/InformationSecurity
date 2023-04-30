// called row transpose but is working on order of columns
#include <iostream>
using namespace std;

int main(){
    string plainText;
    cout << "Enter the plain text to be encrypted: ";
    cin >> plainText;
    cout << endl;
    int counter = plainText.size();

    string key;
    cout << "Enter the key for encryption: ";
    cin >> key;
    cout << endl;
    int keyLen = key.size();// determining length of key

    // converting the length of plaintext into a multiple of the key length
    while(counter%keyLen!=0){
        string s(1,'x');
        plainText.insert(counter, s);
        counter++;
    }

    // creating a matrix of plain text where no. of columns = key length
    char matrix[100][keyLen];
    int i = 1;
    int index = 0;
    for (int j = 0; j < keyLen; j++){
        matrix[0][j] = key[j];
    }
    while(i <= (counter/keyLen)){ // number of rows = counter/key length
        // to determine the number of rows we use 'i'
        // to iterate through text, we use 'index'
        for (int j = 0; j < keyLen; j++){
            matrix[i][j] = plainText[index];
            index++;
        }
        i++;
    }

    for (int x = 0; x<=(counter/keyLen); x++){
        for (int j = 0; j < keyLen; j++){
            cout << matrix[x][j] <<" ";
        }
        cout << endl;
    }

    // now creating list for alphabetical order for key char
    // the 3d array has following structure -> {ranking of alphabet, column number}

    string cipherText;
    for (int alph = 0; alph < 26; alph++){
        for (int j = 0; j < keyLen; j++){
            if (alph==matrix[0][j]-'a'){
                for (int x = 1; x <= (counter/keyLen); x++){
                    cipherText+=matrix[x][j];
                }
            }
        }
    }

    cout << endl << cipherText;
    
    return 0;
}