// File: A2_S1_20220012_7.cpp
// Purpose: Solve problem 7
// Author: Ahmed Ehab Shehata Ali
// Section: S1
// ID: 20220012
// TA: Maya Ahmed Kamal
// Date: 27 Oct 2023

#include <iostream>
#include <vector>

using namespace std;

struct dominoT {
    int leftDots;
    int rightDots;
};

int cnt = 0;

bool FormsDominoChain(vector<dominoT> & dominos)
{
    int i, j;

    i = 0;
    j = dominos.size() - 1;
    if (dominos.size() == 1)
        return (true);

    while (i < j)
    {
        if (dominos[i].rightDots == dominos[j].leftDots)
        {
            dominos.insert(dominos.begin() + i + 1, dominos[j]);
            dominos.pop_back();
            cnt++;
            break;
        }
        else if (dominos[i].leftDots == dominos[j].rightDots)
        {
            dominos.insert(dominos.begin() + i, dominos[j]);
            dominos.pop_back();
            cnt++;
            break;
        }
        else
            i++;
    }
    if (i == j)
        return (false);

    for (i = 0; i < j; i++)
    {
        if (dominos[i].rightDots != dominos[i + 1].leftDots)
            break;
    }
    if (i == j)
        return (true);

    else if (cnt == dominos.size() - 1)
        return (false);

    FormsDominoChain(dominos);
}

int main()
{
    int n, i;

    cout << "Enter the number of dominos pieces: ";
    cin >> n;
    cout << '\n';
    vector<dominoT> dominos(n);

    for (i = 0; i < n; i++)
    {
        dominoT dom;
        cout << "Enter the number of dots in left and right(numL numR): ";
        cin >> dom.leftDots >> dom.rightDots;
        if (dom.leftDots > 6 || dom.rightDots > 6)
        {
            cout << "Invalid number\n";
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
    {
        cout << "It can't be formed!!!\n";
    }
}