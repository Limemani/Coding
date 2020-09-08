#include <iostream>
#include <string>

using namespace std;

string ShifrChezar(string& text, int& key) {
	string done_text_shifr = "";
	int temp;
	for (int i = 0; i < text.size(); i++) {
		temp = (int)text[i] + key;
		if (temp > 96 && temp < 123) {
			if (temp > 122) {
				temp -= 26;
			}
		}
		else if (temp > 64 && temp < 91) {
			if (temp > 90) {
				temp -= 26;
			}
		}
		done_text_shifr += (char)temp;
	}
	return done_text_shifr;
}

string DeshifrChezar(string text, int& key) {
	string done_text_shifr = "";
	int temp;
	for (int i = 0; i < text.size(); i++) {
		temp = (int)text[i] - key;
		if (temp > 96 && temp < 123) {
			if (temp < 97) {
				temp += 26;
			}
		}
		else if (temp > 64 && temp < 91) {
			if (temp < 65) {
				temp += 26;
			}
		}
		done_text_shifr += (char)temp;
	}
	return done_text_shifr;
}

int main() {
	string text;
	int key;
	getline(cin, text);
	cin >> key;
	cout << ShifrChezar(text, key) << endl;
	cout << DeshifrChezar(ShifrChezar(text, key), key);
}