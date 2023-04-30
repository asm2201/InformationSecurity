#include <iostream>
using namespace std;
int main()
{
    int data[10];
    int dataRec[10];
    int c, c1, c2, c3;

    cout << "Enter 4 bits of data one by one \n";
    cin >> data[3];
    cin >> data[5];
    cin >> data[6];
    cin >> data[7];
    data[1] = data[3] ^ data[5] ^ data[7];
    data[2] = data[3] ^ data[6] ^ data[7];
    data[4] = data[5] ^ data[6] ^ data[7];

    for (int i = 1; i < 8; i++)
    {
        cout << data[i] << "\t";
    }
    cout << "\nEnter the 7 bits recieved\n";
    for (int i = 1; i < 8; i++)
    {
        cin >> dataRec[i];
    }

    c1 = dataRec[1] ^ dataRec[3] ^ dataRec[5] ^ dataRec[7];
    c2 = dataRec[2] ^ dataRec[3] ^ dataRec[6] ^ dataRec[7];
    c3 = dataRec[4] ^ dataRec[5] ^ dataRec[6] ^ dataRec[7];

    c = c1 * 1 + c2 * 2 + c3 * 4;
    if (c == 0)
        cout << "No error in the recieved code\n";
    else
    {
        cout << "There is an error at the position " << c << "\n";
        if (dataRec[c] == 1)
            dataRec[c] = 0;
        else
            dataRec[c] = 1;
    }

    cout << "The message after correcting the error is \n";
    for (int i = 1; i < 8; i++)
        cout << dataRec[i] << "\t";

    return 0;
}