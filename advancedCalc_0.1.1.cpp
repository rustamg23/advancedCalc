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
    int len, count = 0, j;
    string line;
    getline(cin, line);
    line = space(line);
    len = line.length();

    stack <int> digs;
    stack <char> symbs;

    for (int i = 0; i < len; i++)
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
                    //cout << digs.top() << endl;
                    if (i < len) i = i + 1;
                }
            }
        }
            
        if ((line[i]) == '-' || line[i] == '+' || 
            line[i] == '/' || line[i] == '*') 
            symbs.push(line[i]);

        if (!symbs.empty() && !digs.empty())
        {
            if (symbs.top() == '*')
            {
                digs.top() *= (line[i + 1] - 48);
                symbs.pop();
                i++;
            }
            else if (symbs.top() == '/')
            {
                digs.top() /= (line[i + 1] - 48);
                symbs.pop();
                i++;
            }
        }
    }
    int ex;
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
