#include <iostream>
#include <regex>
#include <string>

using namespace std;

int main() {
    string in;
    int sum = 0;
    bool active = true; // State to track whether operations are enabled

    for (int i = 0; i < 6; i++) {
        getline(cin, in);

        // Regex patterns
        regex reg_command(R"(do\(\)|don't\(\)|mul\(([0-9]+),([0-9]+)\))", regex_constants::icase); // Matches "do()", "don't()", or "mul(num1,num2)"

        // Process commands sequentially
        for (sregex_iterator it(in.begin(), in.end(), reg_command), end; it != end; ++it) {
            smatch match = *it;
            string command = match.str();

            if (command == "do()") {
                active = true; // Enable processing
            } else if (command == "don't()") {
                active = false; // Disable processing
            } else if (match.size() == 3 && active) { // Only process "mul()" if active
                int num1 = stoi(match[1].str());
                int num2 = stoi(match[2].str());
                sum += num1 * num2;
            }
        }
    }

    cout << sum << endl;
    return 0;
}

