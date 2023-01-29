#include <iostream>
#include <set>
#include <string>
#include <sstream>
#include <tuple>
#include <fstream>

using namespace std;

// 1.3
set<std::string> make_exit_commands()
{
    return { "q", "e", "exit", "quit" };
}

bool run_translation(std::istream& input, 
                    set<tuple<string, string, string>>& history,
                    set<pair<string, string>>& key_value)
{
    set<string> exitList = make_exit_commands();
    auto command = string{};
    input >> command;
    if(exitList.find(command) != exitList.end())
    {
        return false;
    }
    // 2.1
    if(command == "add")
    {
        auto w1 = string{};
        input >> w1;
        auto w2 = string{};
        input >> w2;
        cout << w1 << " => " << w2 << endl;
        key_value.insert(make_pair(w1,w2));
        // 3.1
        history.insert(make_tuple(command, w1, w2));
    }
    else if(command == "translate")
    {
        /*

        // 2.2
        auto w1 = string{};
        cin >> w1;
        auto exist_entry = false;
        for(auto entry : key_value)
        {
            if(entry.first == w1)
            {
                cout << entry.second << endl;
                exist_entry = true;
            }
        }
        if(!exist_entry)
        {
            cout << "???" << endl;
        }

        */
        // 2.3
        cout << command << endl;
        auto line = string{};
        getline(input, line);
        auto keys = stringstream{};
        keys << line;
        while(!keys.eof())
        {
            auto w = string{};
            keys >> w;
            auto exist_entry = false;
            for(auto entry : key_value)
            {
                if(entry.first == w)
                {
                    cout << w << " => " << entry.second << endl;
                    exist_entry = true;
                }
            }
            if(!exist_entry)
            {
                cout << w << " => ??? " << endl;
            }
        }
    }
    else if(command == "print")// 2.4
    {
        for(auto entry : key_value)
        {
            cout << entry.first << " => " << entry.second << endl;
        }
    }
    else if(command == "save") // 3.2
    {
        auto name = string{};
        input >> name;
        auto file = ofstream{ name };
        for(const auto& command : history)
        {
            file << get<0>(command) << " " << get<1>(command) << " " << get<2>(command) << "\n";
        }
    }
    else if(command == "load")     // 3.3
    {
        auto name = string{};
        input >> name;
        auto file = ifstream{ name };
        while (!file.eof())
        {
            run_translation(file, history, key_value);
        }
    }
    else if(command == "clear") // 4.1
    {
        history.clear();
        key_value.clear();
    }
    else if(command == "remove") // 4.2
    { 
        auto w = string{};
        input >> w;
        for(auto it = key_value.begin(); it != key_value.end();)
        {
            if((it)->first == w || (it)->second == w)
            {
                it = key_value.erase(it);
                
            }
            ++it;
        }
    
        for(auto it = history.begin(); it != history.end();)
        {
            if(get<1>(*it) == w || get<2>(*it) == w)
            {
                it = history.erase(it);
            }
            ++it;
        }
    }
    return true;
}

int main()
{
        //3.1
    set<tuple<string, string, string>> history{};
    set<pair<string, string>> key_value;
    while(true)
    {
        cout << "Enter the command !" << endl;
        if(!run_translation(cin, history, key_value))
        {
            break;
        }
    }
}