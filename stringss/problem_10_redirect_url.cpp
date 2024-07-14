#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

string split(const string &str, char delimiter)
{
    vector<string> tokens;
    string token;
    stringstream ss(str);
    string result = "";
    while (getline(ss, token, delimiter))
    {
        if (token == "http" || token == "https")
        {
            result += "https:";
        }
        else
        {
            result += token;
        }
    }
    return result;
}

int main()
{
    int T;
    cin >> T;
    cin.ignore();
    for (int i = 1; i <= T; i++)
    {
        string str;
        getline(cin, str);

        string result = split(str, ':');
        cout << "Case " << i << ": " << result << endl;
    }
    return 0;
}
