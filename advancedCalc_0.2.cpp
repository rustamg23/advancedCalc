#include <string>
#include <stack>
#include <iostream>
using namespace std;

string space(string str)
{
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == ' ')
        {
            str.erase(i, 1);
            i--;
        }
    }
    return str;
}

int main()
{
    int len, count = 0, ex;
    string line;

    getline(cin, line);
    line = space(line);
    len = line.length();

    stack <long long> digs;
    stack <char> symbs;

    for (int i = 0; i < 2*len; i++)
    {
        if (i < len)
        {
            if (isdigit(line[i]))
            {
                digs.push(line[i] - 48);
                if (isdigit(line[i + 1]))
                {
                    i = i + 1;
                    while (isdigit(line[i]))
                    {
                        digs.top() = digs.top() * 10 + line[i] - 48;
                        if (i < len) i = i + 1;
                    }
                }
            }

            if (line[i] == '/' || line[i] == '*')
            {
                symbs.push(line[i]);
                continue;
            }
            if ((line[i] == '+' || line[i] == '-') && i < len)
            {
                symbs.push(line[i]);
            }
        }

        if (!symbs.empty() && !digs.empty())
        {
            ex = digs.top();
            if (symbs.top() == '*')
            {
                digs.pop();
                digs.top() *= ex;
                symbs.pop();
            }
            else if (symbs.top() == '/')
            {
                digs.pop();
                digs.top() /= ex;
                symbs.pop();
            }
        }

        
    }
    while (symbs.empty() != true)
    {
        
        if (symbs.top() == '-')
        {
            ex = digs.top();
            digs.pop();
            digs.top() -= ex;
            symbs.pop();
        }
        
        else if (symbs.top() == '+')
        {
            ex = digs.top();
            digs.pop();
            digs.top() += ex;
            symbs.pop();
        }
    }
    
    cout << digs.top() << endl;
    
    return 0;

}
