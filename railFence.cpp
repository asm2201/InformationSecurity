#include <iostream>
using namespace std;

int main(){
    string plainText;
    cout << "Enter plaintext string to be encrypted: ";
    cin >> plainText;
    cout << endl;

    int key;
    cout << "Enter the key/depth: ";
    cin >> key;
    cout << endl;

    // construct a matrix with rows=depth and col=length of plaintext
    string matrix[key][(plainText.size())];
    // blank spaces into matrix
    for (int i=0; i < key; i++)
        for (int j = 0; j < plainText.size(); j++)
            matrix[i][j] = "_";
    
    
    int row = 0;
    bool dir_down = false;
    for (int i=0; i < plainText.size(); i++){
       if (row == 0 || row == key-1)
            dir_down = !dir_down;
 
        // fill the corresponding alphabet
        matrix[row][i] = plainText[i];
 
        // find the next row using direction flag
        dir_down?row++ : row--;
    }

    for (int i=0; i < key; i++){
        for (int j = 0; j < plainText.size(); j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    // inserting into cipher text
    string cipherText;
    for (int i=0; i < key; i++){
        for (int j = 0; j < plainText.size(); j++){
            if (matrix[i][j] != "_"){
                cipherText += matrix[i][j];
            }
        }
    }  

    cout << cipherText;

    return 0;
}