#include "Token.hpp"


void Token::generateToken()
{
    json result = generateTokenRequest();

    if(result.contains("token")){
        token = result["token"];
    }else if(result.contains("message")){
        std::cout << result["message"] << endl;
    }
}


void Token::getHistory()
{
    json result = getHistoryRequest(token);


    if (result.is_array()) {
        for (const auto& item : result) {
            if (!item.empty() && item.contains("type") && item["type"] == "Link") {
                links.emplace_back(Link(item["id"],item["createAt"]));
            }
        }
    }

}