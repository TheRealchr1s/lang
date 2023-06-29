#include "code_generation.h"

CodeGenerator::CodeGenerator() {}

void CodeGenerator::generate(Node& rootNode) {
    rootNode.accept(*this);
}

void CodeGenerator::visit(PrintStatementNode& node) {
    // Generate code for the PrintStatementNode
    // Example: Emit code to print the expression's value
    std::cout << "print " << generateExpression(node.expression_) << ";" << std::endl;
}

void CodeGenerator::visit(IntegerLiteralNode& node) {
    // Generate code for the IntegerLiteralNode
    // Example: Emit code to load the integer literal value
    std::cout << generateExpression(node) << std::endl;
}

std::string CodeGenerator::generateExpression(ExpressionNode* expression) {
    // Generate code for an expression and return the resulting code as a string
    if (expression->type_ == NodeType::IntegerLiteral) {
        IntegerLiteralNode* literalNode = static_cast<IntegerLiteralNode*>(expression);
        return std::to_string(literalNode->value_);
    }

    return "";
}
