  
#include <iostream>  
#include <vector>  
#include <unordered_map>  
#include <string>  
#include <sstream>  
using namespace std;  
  
int evaluateGate(const string& op, int input1, int input2) {  
    if (op == "AND") return input1 & input2;  
    if (op == "OR") return input1 | input2;  
    if (op == "NAND") return !(input1 & input2);  
    if (op == "NOR") return !(input1 | input2);  
    if (op == "XOR") return input1 ^ input2;  
    return 0; 
}  
  
int main() {  
    int N;   
    cin >> N;  
    cin.ignore();   
  
    unordered_map<string, pair<string, pair<string, string>>> gates;  
    vector<string> gateOrder;   
    for (int i = 0; i < N; ++i) {  
        string line;  
        getline(cin, line);  
  
        size_t eqPos = line.find('=');  
        string gate = line.substr(0, eqPos);  
        size_t openPos = line.find('(', eqPos);  
        size_t commaPos = line.find(',', openPos);  
        size_t closePos = line.find(')', commaPos);  
  
        string operation = line.substr(eqPos + 1, openPos - eqPos - 1);  
        string input1 = line.substr(openPos + 1, commaPos - openPos - 1);  
        string input2 = line.substr(commaPos + 1, closePos - commaPos - 1);  
  
        gates[gate] = {operation, {input1, input2}};  
        gateOrder.push_back(gate);  
    }  
  
    int T;   
    cin >> T;  
  
    unordered_map<string, vector<int>> inputs;   
    vector<int> defaultCycle(T, 0);   
  
    string signalLine;  
    cin.ignore();  
    while (getline(cin, signalLine)) {  
        if (signalLine.find(' ') == string::npos) break;   
  
        stringstream ss(signalLine);  
        string signalName;  
        ss >> signalName;  
  
        vector<int> cycles(T);  
        for (int t = 0; t < T; ++t) {  
            ss >> cycles[t];  
        }  
        inputs[signalName] = cycles;  
    }  
  
    string targetGate = signalLine;   
  
    unordered_map<string, vector<int>> outputs;  
    for (const auto& gate : gates) {  
        outputs[gate.first] = defaultCycle;  
    }  
  
    for (int t = 1; t < T; ++t) {   
        for (const auto& gate : gateOrder) {  
            string op = gates[gate].first;  
            string input1 = gates[gate].second.first;  
            string input2 = gates[gate].second.second;  
  
            int val1 = (inputs.count(input1) ? inputs[input1][t - 1] : outputs[input1][t - 1]);  
            int val2 = (inputs.count(input2) ? inputs[input2][t - 1] : outputs[input2][t - 1]);  
  
            outputs[gate][t] = evaluateGate(op, val1, val2);  
        }  
    }  
  
    for (int t = 0; t < T; ++t) {  
        cout << outputs[targetGate][t] << (t == T - 1 ? "" : " ");  
    }  
  
    return 0;  
}