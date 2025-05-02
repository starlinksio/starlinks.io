#include <iostream>
#include <string>
#include <curl/curl.h>
#include <nlohmann/json.hpp>

using json = nlohmann::json;
using namespace std;

const string url_api = "localhost:8080";

static size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* output);
json getJsonFromUrl(const std::string& url);