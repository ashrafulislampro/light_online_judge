#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    int T, n;
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        cin >> n;
        cin.ignore();
        string main_str, sub_str;
        vector<int> arr;
        // int *arr = new int(n);
        getline(cin, main_str);
        for (int j = 0; j < n; j++)
        {
            getline(cin, sub_str);
            int count = 0;
            size_t pos = main_str.find(sub_str);
            while (pos != string::npos)
            {
                count++;
                pos = main_str.find(sub_str, pos + 1);
            }
            arr.push_back(count);
        }
        int len = arr.size();
        cout << "Case " << i << ":" << endl;
        for (int k = 0; k < len; k++)
        {
            cout << arr[k] << endl;
        }
    }
    return 0;
}

