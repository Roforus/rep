#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(){
    string str, word;
    cout << "Enter string: ";
    getline(cin, str);
    ofstream file1("File1.txt", ios_base::out);
    ofstream file2("File2.txt", ios_base::out);
    int count_words = 0;
    
    if (!file1.is_open() or !file2.is_open()){
        cout << "File error\n";
        return 1; 
    }
    
    for(int i = 0; i < str.length(); i++){
        if(str[i] == '.' and str[i+1] == '.'){
            if(count_words < 2) file1 << word << endl;
            else if (count_words < 4) file2 << word << endl;
            cout << word << endl;
            word = "";
            i++;
            count_words++;
        } else word.push_back(str[i]);
    };

    file1.close();
    file2.close();

    return 0;
}