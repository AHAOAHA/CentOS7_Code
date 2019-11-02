#include <json/json.h>
#include <iostream>
using namespace std;

Json::Value json_str;

int main() {
    json_str["name"] = "ahaoo";
    json_str["age"] = "18";

    cout << json_str << endl;
    return 0;
}