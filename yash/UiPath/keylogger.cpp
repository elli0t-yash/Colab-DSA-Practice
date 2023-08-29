#include<bits/stdc++.h>
using namespace std;

vector<string> passwords;

vector<string> generate_passwords(const string &sequence, string current_password = "", int index = 0) {
    if(index == sequence.length()) {
        passwords.push_back(current_password);
        return passwords;
    }

    int digit = sequence[index] - '0';

    if(digit > 0) {
        char c = 'a' + digit - 1;
        generate_passwords(sequence, current_password + c, index + 1);
    }

    if(index < sequence.length() - 1) {
        int two_digit = (sequence[index] - '0') * 10 + (sequence[index + 1] - '0');
        if(10 <= two_digit && two_digit <= 26) {
            char c = 'a' + two_digit - 1;
            generate_passwords(sequence, current_password + c, index + 2);
        }
    }

    return passwords;
}

int main() {
    string sequence;
    cin>>sequence;

    vector<string> passwords;
    passwords = generate_passwords(sequence);

    for (const string &password : passwords) {
        cout << password << endl;
    }
    
    return 0;
}