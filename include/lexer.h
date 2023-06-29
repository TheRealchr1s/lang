#ifndef LEXER_H
#define LEXER_H

#include <string>
#include <vector>

enum class TokenType {
    // todo lol
};

struct Token {
    TokenType type;
    std::string lexeme;

};

class Lexer {
public:
    Lexer(const std::string& sourceCode);

    std::vector<Token> tokenize();

private:
    std::string sourceCode_;

};

#endif  // LEXER_H
