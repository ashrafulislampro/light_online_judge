#include <iostream>
#include <string>
using namespace std;

int main()
{
    int T;
    cin >> T;
    cin.ignore();

    for (int k = 1; k <= T; k++)
    {
        string main_str, sub_str;
        getline(cin, main_str);
        getline(cin, sub_str);

        int count = 0;
        size_t pos = main_str.find(sub_str);

        while (pos != string::npos)
        {
            count++;
            pos = main_str.find(sub_str, pos + 1);
        }

        cout << "Case " << k << ": " << count << endl;
    }
    return 0;
}