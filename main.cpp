#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

class Neuron {
private:
    vector<double> results;
public:
    vector<double> values;
    vector<double> inputs;

    vector<double> activate() {
        results.clear();
        for (size_t x = 0; x < inputs.size() && x < values.size(); ++x) {
            double res = inputs[x] * values[x];
            if (res > -1.0 && res < 1.0) {
                results.push_back(res);
            }
        }
        return results;
    }
};

int main() {
    Neuron neuron;
    string inputLine, valueLine;

    cout << "inputs: ";
    getline(cin, inputLine);
    stringstream ss_in(inputLine);
    double temp;
    while (ss_in >> temp) neuron.inputs.push_back(temp);

    cout << "values: ";
    getline(cin, valueLine);
    stringstream ss_val(valueLine);
    while (ss_val >> temp) neuron.values.push_back(temp);

    for (double el : neuron.activate()) {
        cout << el << endl;
    }

    return 0;
}
