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