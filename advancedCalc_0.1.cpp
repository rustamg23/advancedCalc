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

//class Calc
//{
//public:
//    string type;
//    string value;
//};

int main()
{
    int len, count = 0;
    string line;
    getline(cin, line);
    line = space(line);
    len = line.length();

    //cout << line << endl;

    //Calc arr[100];
    stack <int> digs;
    stack <char> symbs;
    
    /*for (int i = 0; i < len; i++)
    {
        if (line[i] == '*' || line[i] == '/')
            count++;
        if (isdigit(line[i]))
            arr[i].type = "digit";
        else
            arr[i].type = "operator";
        arr[i].value = line[i];
    }*/

    for (int i = 0; i < len; i++)
    {
        if (isdigit(line[i])) digs.push(line[i] - 48);
        else symbs.push(line[i]);

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
    
    
    /*for (int i = 0; i < len; i++)
    {
        cout << "type of operand: " << arr[i].type << endl;
        cout << "value of operand: " << arr[i].value << endl << endl;
    }*/
    
    return 0;
}
