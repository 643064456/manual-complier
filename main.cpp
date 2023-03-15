#include <iostream>
#include "Lexer.h"
#include "Parser.h"
#include "Print.h"
#include "CodeGen.h"

int main() {
    const char *code = " 5 + 1 - 3 * 4 / 2";
    compiler::Lexer lexer(code);
    //test lexer
//    do{
//        lexer.GetNextToken();
//        std::cout << lexer.GetCurrentToken()->content << std::endl;
//    } while (lexer.GetCurrentToken()->kind != compiler::TokenKind::Eof);
    //test parser，后序遍历
    lexer.GetNextToken();
    compiler::Parser parser(lexer);
//    compiler::Print visitor;
//    auto root = parser.Parse();
//    root->Accept(&visitor);
    //test codeGen
    compiler::CodeGen codeGen;
    auto root = parser.Parse();
    root->Accept(&codeGen);
    //execute
//    make
//    ./compiler "5+1-3*4/2" > tmp.s
//    clang tmp.s ../driver.c -o tmp.out
//    ./tmp.out
//    0
    return 0;
}
