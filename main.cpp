#include <iostream>
#include "lexer.h"
#include "parser.h"
#include "semantic_analysis.h"
#include "code_generation.h"

int main() {
    std::string sourceCode = "print 42;";
    
    Lexer lexer(sourceCode);
    std::vector<Token> tokens = lexer.tokenize();

    Parser parser(tokens);
    parser.parse();

    SemanticAnalyzer semanticAnalyzer;
    semanticAnalyzer.analyze(*parser.getRootNode());

    CodeGenerator codeGenerator;
    codeGenerator.generate(*parser.getRootNode());

    return 0;
}
