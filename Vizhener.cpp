#include <iostream>
#include <string>

using namespace std;

string ab = "abcdefghijklmnopqrstuvwxyz";

int letternum(char z){
    for (int i = 0; i < ab.size(); i++) {
        if (z == ab[i]) return i;
    }
    return 0;
}

string encode(string text, string key) {
    string s;
    for (int i = 0; i < text.size(); i++) {
        s += ab[(letternum(text[i]) + letternum(key[i % key.size()])) % ab.size()];
    }
    return s;
}

string decode(string text, string key) {
    string s;
    for (int i = 0; i < text.size(); i++) {
        s += ab[(letternum(text[i]) - letternum(key[i % key.size()]) + ab.size()) % ab.size()];
    }
    return s;
}

int main() {
    string text, key;
    int a = 0;
    cout << "Encode or Decode ? [0 / 1]: ";
    cin >> a;
    if (a != 0 and a != 1) {
        exit(0);
    }
    cout << "Enter your text: ";
    cin >> text;
    cout << "Enter your key: ";
    cin >> key;

    for (auto& c : text) {
        c = tolower(c);
        //cout << c;
    }
    for (auto& c : key) {
        c = tolower(c);
        //cout << c;
    }
    if (a == 0) cout << encode(text, key);
    if (a == 1) cout << decode(text, key);
    return 0;
}
