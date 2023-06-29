#include <iostream>
#include <vector>
#include "lexer.h"

class Parser {
public:
    Parser(const std::vector<Token>& tokens) : tokens_(tokens), currentPosition_(0) {}

    void parse() {
        // Start parsing from the top-level grammar rule
        // Call the corresponding functions
        while (currentPosition_ < tokens_.size()) {
            parseStatement();
        }
    }

private:
    const std::vector<Token>& tokens_;
    size_t currentPosition_;

    Token getCurrentToken() {
        return tokens_[currentPosition_];
    }

    void consumeToken() {
        ++currentPosition_;
    }

    void parseStatement() {
        // Handle parsing of statements
        if (getCurrentToken().type == TokenType::Keyword && getCurrentToken().lexeme == "print") {
            consumeToken();
            parseExpression();
            if (getCurrentToken().type == TokenType::Punctuation && getCurrentToken().lexeme == ";") {
                consumeToken();
            } else {
                reportError("Expected ';' after print statement");
            }
        } else {
            reportError("Invalid statement");
        }
    }

    void parseExpression() {
        // Handle parsing of expressions
        if (getCurrentToken().type == TokenType::Integer) {
            consumeToken();
        } else {
            reportError("Invalid expression");
        }
    }

    void reportError(const std::string& message) {
        std::cerr << "Parser Error: " << message << std::endl;

    }
};

int main() {
    std::string sourceCode = "print 42;";
    Lexer lexer(sourceCode);
    std::vector<Token> tokens = lexer.tokenize();

    Parser parser(tokens);
    parser.parse();

    return 0;
}
