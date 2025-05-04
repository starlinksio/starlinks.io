#include "Requests.hpp"
#include <iostream>
#include <string>
#include <curl/curl.h>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

const std::string url_api = "localhost:8080";

// Callback function for CURL to write data into a string
static size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* output) {
    size_t totalSize = size * nmemb;
    output->append((char*)contents, totalSize);
    return totalSize;
}

// Function to perform a GET request and return JSON
json getJsonFromUrl(const std::string& url) {
    CURL* curl = curl_easy_init();
    string responseStr;
    json result = json::value_t::null;

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &responseStr);
        curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10L);
        curl_easy_setopt(curl, CURLOPT_CONNECTTIMEOUT, 5L);
        curl_easy_setopt(curl, CURLOPT_NOSIGNAL, 1L);

        CURLcode res = curl_easy_perform(curl);
        if (res == CURLE_OK) {
            try {
                result = json::parse(responseStr);
            } catch (const json::parse_error& e) {
                //cerr << "JSON parse error: " << e.what() << endl;
            }
        } else {
            //cerr << "CURL error: " << curl_easy_strerror(res) << endl;
        }

        curl_easy_cleanup(curl);
    }

    return result;
}
