#include <iostream>
#include <string>
#include <curl/curl.h>
#include <nlohmann/json.hpp>

using json = nlohmann::json;
using namespace std;

extern const std::string url_api;

static size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* output);
json getRequest(const std::string& url);
json postRequest(const std::string& url, const json& payload);
json deleteRequest(const std::string& url);