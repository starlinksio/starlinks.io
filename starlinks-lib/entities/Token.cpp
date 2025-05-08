#include "Token.hpp"


void Token::generateToken()
{
    json result = generateTokenRequest();

    if (result.contains("token")) {
        token = result["token"];
    } else if (result.contains("message")) {
        throw std::runtime_error(result["message"]);
    } else {
        throw std::runtime_error("Unknown error occurred during token generation.");
    }
}


void Token::getHistory()
{
    json result = getTokenHistoryRequest(token);

    if (result.is_array()) {
        for (const auto& item : result) {
            if (!item.empty() && item.contains("type") && item["type"] == "Link") {
                links.emplace_back(Link(token,item));
            }
        }
    }

}