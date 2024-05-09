// Ryan Krishandi Lukito
// 22/497249/TK/54488
// Teknologi Informasi

#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

// function declarations
char make_lowercase(char ml);
string input_to_vector(const string itv);
void word_counter(string wc);

// main program
int main()
{
    word_counter("input.txt");
    return 0;
}

// function description
string input_to_vector(const string itv)
{
    string temp = "";
    string line;
    vector<string> v1;

    ifstream readFile(itv);
    while (!readFile.eof())
    {
        getline(readFile, line);
        v1.push_back(line);
    }
    readFile.close();

    for (int i = 0; i < v1.size(); i++)
    {
        temp += v1[i] + " ";
    }
    return temp;
}

char make_lowercase(char ml)
{

    if (ml >= 65 && ml <= 92)
    {
        ml += 32;
    }
    else if (ml >= 33 && ml <= 64)
    {
        ml = ' ';
    }
    return ml;
}

void word_counter(string wc)
{
    vector<string> content;
    vector<int> total;
    vector<string>::iterator found;
    string ves, data;

    data = input_to_vector(wc);
    for (int i = 0; i < data.length(); i++)
    {
        data[i] = make_lowercase(data[i]);
    }

    for (int i = 0; i < data.length(); i++)
    {
        if (data[i] != 32)
        {
            ves += data[i];
        }
        else
        {
            if (content.size() == 0)
            {
                content.push_back(ves);
                total.push_back(1);
            }
            else
            {
                found = find(content.begin(), content.end(), ves);
                if (ves != content[found - content.begin()])
                {
                    content.push_back(ves);
                    total.push_back(1);
                }
                else
                {
                    total[found - content.begin()] += 1;
                }
            }
            ves.erase();
        }
    }

    ofstream outfile("WordCounterResult.json");
    outfile << "{\n";
    for (int i = 0; i < content.size(); i++)
    {
        outfile << '"' << content[i] << '"' << ": " << total[i];
        if (i != content.size() - 1)
        {
            outfile << ',';
        }
        outfile << endl;
    }
    outfile << "}";
}