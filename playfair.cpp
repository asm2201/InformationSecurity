#include <iostream>
using namespace std;

int main(){
    string plainText;
    string key;
    cout << "Enter the plain text to be encrypted: ";
    cin >> plainText;
    cout << endl;
    cout << "Enter the keyword: ";
    cin >> key;
    cout << endl;

    // mapping the occurence of each alphabet in key to frequency
    int alph[26] = {0};
    int var;
    for (int i = 0; i < key.size(); i++){
        var = key[i] - 'a';
        alph[var]++;
    }

    // building a 5x5 matrix
    char matrix[5][5];
    int row = 0;
    int col = 0;
    alph['j'-'a']=99; // flagging 'j' as 99 for not writing in the matrix
    for(int i = 0; i < key.size(); i++){
        if (alph[key[i]-'a']>0 && alph[key[i]-'a']<99){
            matrix[row][col] = key[i];
            alph[key[i]-'a']=99;
            col++;
        }
        if (col == 5){
            row++;
            col = 0;
        }
    }
    for (int i = 0; i < 26; i++){
        if (alph[i]==0){
            matrix[row][col] = char(i+'a');
            col++;
        }
        if (col == 5){
            row++;
            col = 0;
        }
    }
    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    // forming digram - a 2 dimensional array
    char digramMat[100][2];
    int i = 0;
    int counter = plainText.size();
    row = 0;
    col = 0; // resetting their values to 0
    while(i < counter){ // while loop will evaluate counter in every loop
        if (plainText[i] != plainText[i+1]){
            digramMat[row][col] = plainText[i];
            digramMat[row][col+1] = plainText[i+1];
        }
        else{
            string s(1, 'x');
            plainText.insert(i+1, s);
            digramMat[row][col] = plainText[i];
            digramMat[row][col+1] = plainText[i+1];
            counter+=1;
        }
        row++;
        col = 0;  
        i = i+2;
    }
    
    if (plainText.size()%2!=0){
        digramMat[row-1][1] = 'z'; // if the number of alphabets are odd, insert a dummy 'z'
    }
    
    cout << endl;

    for(int i = 0 ; i < row; i++){ // print the matrix
        for(int j = 0; j < 2; j++){
            cout << digramMat[i][j] << " ";
        }
        cout << endl;
    }

    // now creating a 2 dimensional matrix for encrypted data
    char cipherMat[100][2];

    // now specifying rules for creation of cipher matrix
    for (int i = 0; i < row; i++){
        // for each element in the digram matrix, get coordinates from key matrix
        int coordinates1[2];
        int coordinates2[2];
        for (int j = 0; j < 5; j++){
            for (int k = 0 ; k < 5; k++){
                if (digramMat[i][0] == matrix[j][k]){
                    coordinates1[0] = j;
                    coordinates1[1] = k;
                }
                else if (digramMat[i][1] == matrix[j][k]){
                    coordinates2[0] = j;
                    coordinates2[1] = k;
                }
            }
        }
        if (coordinates1[0] == coordinates2[0]){
            // if the elements from digrammat have same row
            if (coordinates1[1] == 4){
                //checking if cipher element 1 is in last column
                cipherMat[i][0] = matrix[coordinates1[0]][0];
                // if yes, then ciphertext is 0th row, same column element
                cipherMat[i][1] = matrix[coordinates2[0]][coordinates2[1]+1];
                // the second element of cipher is going to be in same column, one row below
            }
            else if (coordinates2[1] == 4){
                //checking if cipher element 2 is in last column
                cipherMat[i][1] = matrix[coordinates2[0]][0];
                // if yes, then ciphertext is 0th row, same column element
                cipherMat[i][0] = matrix[coordinates1[0]][coordinates1[1]+1];
                // the second element of cipher is going to be in same column, one row below
            }
            else{
                cipherMat[i][0] = matrix[coordinates1[0]][coordinates1[1]+1];
                cipherMat[i][1] = matrix[coordinates2[0]][coordinates2[1]+1];
            }
            
        }
        else if (coordinates1[1] == coordinates2[1]){
            // if the elements from digrammat have same column
            if (coordinates1[0] == 4){
                //checking if cipher element 1 is in last row
                cipherMat[i][0] = matrix[0][coordinates1[1]];
                // if yes, then ciphertext is 0th row, same column element
                cipherMat[i][1] = matrix[coordinates2[0]+1][coordinates2[1]];
                // the second element of cipher is going to be in same column, one row below
            }
            else if (coordinates2[0] == 4){
                //checking if cipher element 2 is in last row
                cipherMat[i][1] = matrix[0][coordinates2[1]];
                // if yes, then ciphertext is 0th row, same column element
                cipherMat[i][0] = matrix[coordinates1[0]+1][coordinates1[1]];
                // the second element of cipher is going to be in same column, one row below
            }
            else{
                cipherMat[i][0] = matrix[coordinates1[0]+1][coordinates1[1]];
                cipherMat[i][1] = matrix[coordinates2[0]+1][coordinates2[1]];
            }
        }
        else{
            // neither row nor column are same
            cipherMat[i][0] = matrix[coordinates1[0]][coordinates2[1]];
            cipherMat[i][1] = matrix[coordinates2[0]][coordinates1[1]];
        }
    }

    cout << endl << "encrypted text is: " << endl;
    for(int i = 0 ; i < row; i++){ // print the matrix
        for(int j = 0; j < 2; j++){
            cout << cipherMat[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}