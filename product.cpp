#include <iostream>
using namespace std;

int main(){
    string plainText;
    cout << "Enter the plain text: ";
    cin >> plainText;
    cout << endl;

    string key;
    cout << "Enter the key: ";
    cin >> key;
    cout << endl;

    int alphabets[26] = {0}; // to store frequency of alphabets
    for (int i = 0; i < key.size(); i++){
        alphabets[key[i]-'A']=1;
    }
    
    // construct a 6x6 matrix 
    char matrix[7][7];
    matrix[0][0] = '_'; // CREATING MATRIX AS PER RULES FOR THIS ENCRYPTION TECHNIQUE
    matrix[1][0] = matrix[0][1] = 'A';
    matrix[2][0] = matrix[0][2] = 'D';
    matrix[3][0] = matrix[0][3] = 'F';
    matrix[4][0] = matrix[0][4] = 'G';
    matrix[5][0] = matrix[0][5] = 'V';
    matrix[6][0] = matrix[0][6] = 'X';
    int row = 1;
    int col = 1;
    for (int i = 0; i < key.size(); i++){
        if (alphabets[key[i]-'A'] == 1){
            matrix[row][col] = key[i];
            alphabets[key[i]-'A'] = 99;
            col++;
        }
        if (col == 7){
            row++;
            col = 1;
        }
    }
    
    // filling up alphabets and digits from 0-9 in the matrix
    for (int i = 0; i < 26; i++){
        if (alphabets[i]==0){
            matrix[row][col] = char(i+'A');
            col++;
        }
        if (col == 7){
            row++;
            col = 1;
        }
    }

    for (int i = 0; i < 10; i++){ // equating lowercase alphabets from 0 - 9 index for creating matrix
        matrix[row][col] = char(i+'a'); // lowercase alphabets a-j
        col++;
        if (col == 7){
            row++;
            col = 1;
        }
    }

    for (int i = 0; i < 7; i++){ // to print the matrix craeted
        for (int j = 0; j < 7; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // locating the row and col index for each alphabet in plain text and appending to ciphertext
    string cipherText = "";
    for (int i = 0; i < plainText.size(); i++){
        for (int matRow = 1; matRow < 7; matRow++){
           for (int matCol = 1; matCol < 7; matCol++){
               if (matrix[matRow][matCol] == plainText[i] || matrix[matRow][matCol]-'a' == plainText[i]){
                   string element1(1,matrix[matRow][0]); // converting char to string for concatenation
                   string element2(1,matrix[0][matCol]); // converting char to string for concatenation
                   string combined = element1+element2;
                   cipherText += combined;
               }
           } 
        }
    }

    cout << "The encrypted message is: " << cipherText << endl;

    // creating a row column transpose based on second keyword 
    string keyTwo;
    cout << "Enter a second key: ";
    cin >> keyTwo;
    cout << endl;

    // creating a matrix based on key length
    int keyLen = keyTwo.size();
    int counter = cipherText.size();
    // adding 'x' to encrypted data to make it as long as ultiple of keyword2 length
    while(counter%keyLen!=0){
        string s(1,'x');
        cipherText.insert(counter, s);
        counter++;
    }
    char rowMatrix[100][keyLen];
    for (int i = 0; i < keyLen; i++){
        rowMatrix[0][i] = keyTwo[i];
    }
    int index = 0; // to iterate through ciphertext
    for (int i = 1; i <= (counter/keyLen); i++){
        for (int j = 0; j < keyLen; j++){
            rowMatrix[i][j] = cipherText[index];
            index++;
        }
    }
    cout << endl;
    for (int i = 0; i <= (counter/keyLen); i++){
        for (int j = 0; j < keyLen; j++){
            cout << rowMatrix[i][j]<< " ";
        }
        cout << endl;
    }
    string cipherTextTwo;
    for (int i = 0; i <  26; i++){
        for (int j = 0; j < keyLen; j++){
            if(char(i+'A') == rowMatrix[0][j]){
                for (int k = 1; k <= (counter/keyLen); k++){
                    cipherTextTwo += rowMatrix[k][j]; 
                }
            }
        }
    }
    
    cout << "The final encrypted text is: " << cipherTextTwo; 

    return 0;
}