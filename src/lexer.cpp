#include <iostream>
#include <string>
#include <vector>

enum class TokenType {
    // Example token types
    Identifier,
    Integer,
    Operator,
    Keyword,
    Punctuation
};

struct Token {
    TokenType type;
    std::string lexeme;
};

class Lexer {
public:
    Lexer(const std::string& sourceCode) : sourceCode_(sourceCode), currentPosition_(0) {}

    std::vector<Token> tokenize() {
        std::vector<Token> tokens;

        while (currentPosition_ < sourceCode_.size()) {
            char currentChar = sourceCode_[currentPosition_];

            if (isWhitespace(currentChar)) {
                // Ignore whitespace
                ++currentPosition_;
            }
            else if (isLetter(currentChar)) {
                std::string identifier = extractIdentifier();
                TokenType type = getIdentifierType(identifier);
                tokens.push_back({ type, identifier });
            }
            else if (isDigit(currentChar)) {
                std::string number = extractNumber();
                tokens.push_back({ TokenType::Integer, number });
            }
            else {
                // Handle other token types (operators, punctuation, etc.)
                // Add code here to handle other token types
                // For simplicity, we'll assume a single-character operator or punctuation token
                std::string lexeme(1, currentChar);
                TokenType type = getTokenTypeFromChar(currentChar);
                tokens.push_back({ type, lexeme });
                ++currentPosition_;
            }
        }

        return tokens;
    }

private:
    const std::string sourceCode_;
    size_t currentPosition_;

    bool isWhitespace(char ch) {
        return ch == ' ' || ch == '\t' || ch == '\n';
    }

    bool isLetter(char ch) {
        return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
    }

    bool isDigit(char ch) {
        return ch >= '0' && ch <= '9';
    }

    std::string extractIdentifier() {
        size_t startPosition = currentPosition_;
        while (currentPosition_ < sourceCode_.size() && isLetter(sourceCode_[currentPosition_])) {
            ++currentPosition_;
        }
        return sourceCode_.substr(startPosition, currentPosition_ - startPosition);
    }

    std::string extractNumber() {
        size_t startPosition = currentPosition_;
        while (currentPosition_ < sourceCode_.size() && isDigit(sourceCode_[currentPosition_])) {
            ++currentPosition_;
        }
        return sourceCode_.substr(startPosition, currentPosition_ - startPosition);
    }

    TokenType getTokenTypeFromChar(char ch) {
        // Example implementation
        switch (ch) {
            case '+':
            case '-':
            case '*':
            case '/':
                return TokenType::Operator;
            case '(':
            case ')':
            case '{':
            case '}':
                return TokenType::Punctuation;
            default:
                // Handle other token types
                // ...
                return TokenType::Keyword; // Assuming unrecognized characters are keywords
        }
    }
};

int main() {
    std::string sourceCode = "int main() { return 0; }";
    Lexer lexer(sourceCode);
    std::vector<Token> tokens = lexer.tokenize();

    for (const Token& token : tokens) {
        std::cout << "Type: " << static_cast<int>(token.type) << ", Lexeme: " << token.lexeme << std::endl;
    }

    return 0;
}
