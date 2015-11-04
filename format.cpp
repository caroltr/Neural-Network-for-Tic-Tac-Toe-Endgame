#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    char x[9], type[9];

    while (scanf("%c,%c,%c,%c,%c,%c,%c,%c,%c,%s\n", &x[0], &x[1], &x[2], &x[3], &x[4], &x[5], &x[6], &x[7], &x[8], &type) != EOF)
    {
        cout << "-1 ";

        for (int i=0; i<9; i++)
        {
            switch(x[i])
            {
                case 'b':
                    cout << "0 0 ";
                    break;
                case 'x':
                    cout << "1 0 ";
                    break;
                case 'o':
                    cout << "0 1 ";
                    break;
            }
        }

        if (type[0] == 'p')
            cout << "+1" << endl;
        else
            cout << "-1" << endl;
    }

    return 0;
}
