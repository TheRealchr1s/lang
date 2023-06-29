#ifndef CODE_GENERATION_H
#define CODE_GENERATION_H

#include <iostream>
#include <string>
#include "ast.h"

class CodeGenerator : public Visitor {
public:
    CodeGenerator();

    void generate(Node& rootNode);

    void visit(PrintStatementNode& node);
    void visit(IntegerLiteralNode& node);

    std::string generateExpression(ExpressionNode* expression);
};

#endif  // CODE_GENERATION_H
