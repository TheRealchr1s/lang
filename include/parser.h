#ifndef PARSER_H
#define PARSER_H

#include <vector>
#include "lexer.h"  
#include "ast.h"  

class Parser {
public:
    Parser(const std::vector<Token>& tokens);

    void parse();

private:
    const std::vector<Token>& tokens_;
    size_t currentPosition_;

    Token getCurrentToken();
    void consumeToken();

    void parseStatement();
    void parseExpression();

    void reportError(const std::string& message);
};

#endif  // PARSER_H
