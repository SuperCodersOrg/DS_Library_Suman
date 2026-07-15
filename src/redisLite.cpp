#include "../include/redisLite.h"
string RedisLite::toLower(const string& str){
    string result = str;
    for(int i=0;i<str.size();i++){
        int val=(int)str[i];
        if(65<=val && val<=90){
            result[i]=(char)(val+32);
        }
    }
    return result;
}

void RedisLite::set(string& key, string& value){
    store.insert(key,value);
}
void RedisLite::get(string& key){
    string res=store.get(key);
    cout<<"Value: "<<res<<endl;
    return;
}
void RedisLite::remove(string& key){
    store.remove(key);
    return;
}
void RedisLite::exists(string& key){
    if(store.exists(key)){
        cout << "YES : Key '" << key << "' exists."<<endl;
    }
    else{
        cout << "NO : Key '" << key << "' does not exists."<<endl;
    }
    return;
}
void RedisLite::count(){
    int res=store.getSize();
    cout << "Total Key-Value Pairs : "<<res<< endl;
    return;
}
void RedisLite::clear(){
    store.clear();
    return;
}
void RedisLite::show(){
    store.showAll();
    return;
}
void RedisLite::run(){
    cout << "=============================================\n";
    cout << "           Redis Lite Database\n";
    cout << "=============================================\n";
    cout << "Type 'help' for available commands.\n";
    cout << "Type 'exit' to terminate the application.\n\n";
    string input;
    while (true){
        try{
            cout << "redis-lite> ";
            getline(cin, input);
            stringstream ss(input);
            DynamicArray<string> tokens;
            string word;
            while (ss >> word){
                tokens.push_back(toLower(word));
            }
            if (tokens.isEmpty()){
                cout << "ERROR: No command entered.\n";
                continue;
            }
            if (tokens.getSize() > 3){
                cout << "ERROR: Invalid command format.\n";
                cout << "Expected: <command> <key> <value>\n";
                continue;
            }
            if(tokens[0]=="help"){
                if(tokens.getSize()!=1){
                    cout<<"ERROR: Usage -> help"<<endl;
                    continue;
                }
                cout << "\nAvailable Commands\n";
                cout << "----------------------------------------------------\n";
                cout << "SET <key> <value>     Insert or update a key\n";
                cout << "GET <key>             Retrieve a value\n";
                cout << "DEL <key>             Delete a key\n";
                cout << "EXISTS <key>          Check key existence\n";
                cout << "COUNT                 Display total entries\n";
                cout << "SHOW                  Display all key-value pairs\n";
                cout << "CLEAR                 Remove all entries\n";
                cout << "HELP                  Display this menu\n";
                cout << "EXIT                  Exit Redis Lite\n\n";
            }
            else if (tokens[0] == "exit"){
                cout << "\nThank you for using Redis Lite."<<endl;
                break;
            }
            else if (tokens[0] == "set"){
                if (tokens.getSize() != 3){
                    cout << "ERROR: Usage -> SET <key> <value>"<<endl;
                    continue;
                }
                set(tokens[1], tokens[2]);
                cout << "SUCCESS: Key-value pair stored successfully."<<endl;
            }
            else if (tokens[0] == "get"){
                if (tokens.getSize() != 2){
                    cout << "ERROR: Usage -> GET <key>"<<endl;
                    continue;
                }
                get(tokens[1]);
            }
            else if (tokens[0] == "del"){
                if (tokens.getSize() != 2){
                    cout << "ERROR: Usage -> DEL <key>"<<endl;
                    continue;
                }
                remove(tokens[1]);
                cout << "SUCCESS: Key deleted successfully."<<endl;
            }
            else if (tokens[0] == "exists"){
                if (tokens.getSize() != 2){
                    cout << "ERROR: Usage -> EXISTS <key>"<<endl;
                    continue;
                }
                exists(tokens[1]);
            }
            else if (tokens[0] == "count"){
                if (tokens.getSize() != 1){
                    cout << "ERROR: Usage -> COUNT"<<endl;
                    continue;
                }
                count();
            }
            else if (tokens[0] == "clear"){
                if (tokens.getSize() != 1){
                    cout << "ERROR: Usage -> CLEAR"<<endl;
                    continue;
                }
                clear();
                cout << "SUCCESS: Database cleared successfully."<<endl;
            }
            else if (tokens[0] == "show"){
                if (tokens.getSize() != 1){
                    cout << "ERROR: Usage -> SHOW"<<endl;
                    continue;
                }
                show();
            }
            else{
                cout << "ERROR: Unknown command '" << tokens[0] << "'"<<endl;
            }
        }
        catch (const exception& e){
            cout << "ERROR: " << e.what() << endl;
        }
        catch (...){
            cout << "ERROR: Unknown exception occurred."<<endl;
        }
    }
}

