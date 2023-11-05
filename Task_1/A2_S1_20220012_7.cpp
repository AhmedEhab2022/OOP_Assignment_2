// File: A2_S1_20220012_7.cpp
// Purpose: Solve problem 7
// Author: Ahmed Ehab Shehata Ali
// Section: S1
// ID: 20220012
// TA: Khaled Ibrahem
// Date: 27 Oct 2023

#include <iostream>
#include <vector>

using namespace std;

struct dominoT {
    int leftDots;
    int rightDots;
};

// counter to indecate that the function is have to check if
// the dominos is formed or not
int cnt = 0;

bool FormsDominoChain(vector<dominoT> & dominos)
{
    int i, j;

    i = 0;
    j = dominos.size() - 1;
    // return true if the number of dominos pieces is 1
    if (dominos.size() == 1)
        return (true);

    while (i < j)
    {
        // if the right dots in the ith piece equal to the left dots to the last one
        if (dominos[i].rightDots == dominos[j].leftDots)
        {
            // insert the last piece to the next to ith piece
            dominos.insert(dominos.begin() + i + 1, dominos[j]);
            // remove the last piece that already inserted
            dominos.pop_back();
            // increase the counter of operation by 1
            cnt++;
            // end the loop
            break;
        }
        // if the left dots in the ith piece equal to the right dots to the last one
        else if (dominos[i].leftDots == dominos[j].rightDots)
        {
            // insert the last piece before to ith piece
            dominos.insert(dominos.begin() + i, dominos[j]);
            // remove the last piece after it was inserted
            dominos.pop_back();
            // increase the counter of operation by 1
            cnt++;
            // end the loop
            break;
        }
        else
            // increase i by 1 to check for the next piece
            i++;
    }
    // no operation was done then cannot be formed
    if (i == j)
        return (false);

    // check for any piece if it is in the right position
    for (i = 0; i < j; i++)
    {
        // if any piece is not in the right position then end the loop
        if (dominos[i].rightDots != dominos[i + 1].leftDots)
            break;
    }
    // if reaches to the end of the loop then the dominos pieces is formed
    if (i == j)
        return (true);

    // if the counter equal to number of pieces - 1 then the
    else if (cnt == dominos.size() - 1)
        return (false);

    FormsDominoChain(dominos);
}

int main()
{
    int n, i;

    cout << "Enter the number of dominos pieces: ";
    cin >> n;
    if (n > 28)
    {
        cout << "The number of pieces cannot exceed 28\n";
        return (0);
    }
    cout << '\n';
    vector<dominoT> dominos(n);

    for (i = 0; i < n; i++)
    {
        dominoT dom;
        cout << "Enter the number of dots in left and right(numL numR): ";
        cin >> dom.leftDots >> dom.rightDots;
        if (dom.leftDots > 6 || dom.rightDots > 6)
        {
            cout << "The number of dots cannot exceed 6\n";
            return (0);
        }
        dominos[i] = dom;
    }
    cout << '\n';
    if (FormsDominoChain(dominos))
    {
        cout << "It can be formed \\o/\n";
        cout << "The form is: ";
        for (i = 0; i < dominos.size(); i++)
        {
            cout << dominos[i].leftDots << '|' << dominos[i].rightDots;
            if (i < dominos.size() - 1)
                cout << " - ";
        }
        cout << '\n';
    }
    else
        cout << "It can't be formed\n";
}
