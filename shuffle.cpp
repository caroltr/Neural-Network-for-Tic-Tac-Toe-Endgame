#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

int main()
{

    vector<string> lines;
    string line;

    while (!getline(cin,line).eof())
        lines.push_back(line);

    int n = lines.size();

    srand(time(NULL));
    for (int i=n-1; i>0; i--)
    {
        int j = rand() % (i+1);
        string aux = lines[i];
        lines[i] = lines[j];
        lines[j] = aux;
    }

    for (int i=0; i<n; i++)
        cout << lines[i] << endl;

    return 0;
}
