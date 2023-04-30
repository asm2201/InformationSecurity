#include <iostream>
using namespace std;

int main(){
    string plainText;
    cout << "Enter the plain text to be encrypted: ";
    cin >> plainText;
    cout << endl;

    // adding 'x' to make the plaintext divisible in groups of 3
    int counter = plainText.size();
    while(counter%3!=0){
        string s(1, 'x');
        plainText.insert(counter, s);
        counter++;
    }
    cout << plainText;
    
    // creating a trigram matrix
    int trigramMat[100][3];
    int index = 0;
    int row = 0;
    int col = 0;
    for(int i = 0; i < int(counter/3); i++){
        // 'i' will keep track of number of iterations and 'index' will take care of elements
        trigramMat[row][col] = plainText[index]-'A'; //stores the ascii representations directly
        trigramMat[row][col+1] = plainText[index+1]-'A';
        trigramMat[row][col+2] = plainText[index+2]-'A';
        index+=3;
        row+=1;
        col = 0;
    }

    // creating a 3x3 matrix
    cout << endl << "Creating a 3x3 matrix for key... " << endl;
    int matrix[3][3];
    for (int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            cout << "Enter the integer for " << i << ", " << j << "index: ";
            cin >> matrix[i][j];
            cout << endl;
        }
    }
    
    // encrypting the data using matrix multiplication
    char cipherTrigram[100][3]; //to store the resultant ciphertext
    for (int trigramRows = 0; trigramRows < row; trigramRows++){
        for (int rowMat = 0; rowMat < 3; rowMat++){
            int sum = 0; //this will store the ascii value for each character for every column
            for (int colMat = 0; colMat < 3; colMat++){
                sum+=(trigramMat[trigramRows][colMat]*matrix[rowMat][colMat]);
            }
            sum = sum%26;
            cipherTrigram[trigramRows][rowMat] = sum+'A';
        }
    }

    for (int i = 0; i < row; i++){
       for (int j = 0; j < 3; j++){
           cout << cipherTrigram[i][j] << " ";
       }
       cout << endl;
    }

    return 0;
}