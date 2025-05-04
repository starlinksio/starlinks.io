#include <iostream>
#include <string>
#include <curl/curl.h>
#include <nlohmann/json.hpp>

using json = nlohmann::json;
using namespace std;

extern const std::string url_api;

static size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* output);
json getJsonFromUrl(const std::string& url);